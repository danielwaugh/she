import paho.mqtt.client as mqtt

from time import sleep

import requests

import MySQLdb

broker_address = "192.168.5.1"

Remote = [0,0,0,0,0,0]
RemoteNew = [0,0,0,0,0,0]

global currentIP
currentIP = ""
global currentMAC
currentMAC = ""
global flag1
flag1 = 0
global flag2
flag2 = 0

def on_message(client, userdata, message):
	global currentIP
	global currentMAC
	global flag2
	global flag1
	if "STOP" in message.payload:
		flag2 = 0
		db = MySQLdb.connect(host="localhost", user="pi", passwd="sheisveryhot", db="she")
		cur = db.cursor();
		cur.execute("select id from plugs where mac='" + currentMAC + "';")
		if not cur.fetchall():
			cur.execute("insert into plugs (ip, mac) values ('" + currentIP + "','" + currentMAC + "');")
			db.commit()
			cur.execute("select id from plugs where mac='" + currentMAC + "';")
			client.publish("/she/plug_receive", "S" + str(cur.fetchall()[0][0]) + "0")
		else:
			cur.execute("select id from plugs where mac='" + currentMAC + "';")
			curid = cur.fetchall()[0][0]
			cur.execute("select status from remote where id='" + str(curid) + "';")
			curstatus = cur.fetchall()[0][0]
			client.publish("/she/plug_receive", "S" + str(curid) + str(curstatus))
		db.close()
	if(flag2):
		currentMAC = message.payload
	if(flag1):
		currentIP = message.payload
		flag2 = 1
		flag1 = 0
	if "START" in message.payload:
		flag1 = 1
	if "DATA" in message.payload:
		db = MySQLdb.connect(host="localhost", user="pi", passwd="sheisveryhot", db="she")
		cur = db.cursor();
		cur.execute("select status from remote")
		startupData = "D"
		for row in cur.fetchall():
			startupData += str(row[0])
		client.publish("/she/remote_receive", startupData)
		db.close()
	if "R00" in message.payload[:3]:
		RemoteNew[0] = int(message.payload[-1])
	elif "R01" in message.payload[:3]:
		RemoteNew[1] = int(message.payload[-1])
	elif "R02" in message.payload[:3]:
		RemoteNew[2] = int(message.payload[-1])
	elif "R10" in message.payload[:3]:
		RemoteNew[3] = int(message.payload[-1])
	elif "R11" in message.payload[:3]:
		RemoteNew[4] = int(message.payload[-1])
	elif "R12" in message.payload[:3]:
		RemoteNew[5] = int(message.payload[-1])

client = mqtt.Client("P1")
client.on_message=on_message
client.connect(broker_address)
client.loop_start()
client.subscribe("/she/remote_send")
client.subscribe("/she/plug_send")
client.subscribe("/she/remote_receive")
client.subscribe("/she/plug_receive")

while(1):
	i = 0
	for row in RemoteNew:
		if(row != Remote[i]):
			client.publish("/she/plug_receive", "T" + str(i+1) + str(row))
			db = MySQLdb.connect(host="localhost", user="pi", passwd="sheisveryhot", db="she")
			cur = db.cursor();
			cur.execute("update remote set status = " + str(row) + " where id = " + str(i + 1))
			db.commit()
			db.close()
			Remote[i] = row
		i += 1

client.loop_stop()