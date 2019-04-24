import paho.mqtt.client as mqtt

from time import sleep

import requests

broker_address = "192.168.5.1"

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
		client.subscribe("/she/plug_receive")
		client.publish("/she/plug_receive", "40")
		client.subscribe("/she/plug_send")
	if(flag2):
		currentMAC = message.payload
	if(flag1):
		currentIP = message.payload
		flag2 = 1
		flag1 = 0
	if "START" in message.payload:
		flag1 = 1

    

client = mqtt.Client("P1")
client.on_message=on_message
client.connect(broker_address)
client.loop_start()
client.subscribe("/she/plug_send")

while(1):
	print currentIP
	print currentMAC
	sleep(1)

client.loop_stop()




