import paho.mqtt.client as mqtt

from time import sleep

import requests

broker_address = "192.168.5.1"
ON_OFF_FLAG = 0


while(1):

	client = mqtt.Client("P1")
	client.connect(broker_address)
	client.subscribe("/leds/esp8266")

	URL = "http://72.199.201.49:8081/getdevicedata.php"

	info = {'id': '1'}

	r = requests.post(URL, data = info)

	Last_Flag = ON_OFF_FLAG

	print(r.text)

	if "OFF" in r.text:
		ON_OFF_FLAG = 0
	if "ON" in r.text:
		ON_OFF_FLAG = 1

	if (Last_Flag != ON_OFF_FLAG):
		if(ON_OFF_FLAG):
			client.publish("/leds/esp8266", "ON")
		else:
			client.publish("/leds/esp8266", "OFF")

	sleep(1)



