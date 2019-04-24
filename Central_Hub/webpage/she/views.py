# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.shortcuts import render

from django.http import HttpResponse
	
import subprocess

import sys

from wifi import Cell, Scheme

curSSID = ""

def index(request):
    context = {

    }
    return render(request, 'she/main.html', context)

def hubconnection1(request):
	output = subprocess.check_output(["iw", "dev", "wlan1", "link"])
	SSID = []
	if not "Not connected." in output:
		SSID = (((output.splitlines())[1]).split())[1]
	context = {
		'SSID': SSID
	}
	return render(request, 'she/hubconnection1.html', context)

def hubconnection2(request):
	ssids = []
	for network in Cell.all('wlan1'):
		ssids.append(network.ssid)
	context = {
			'ssids': ssids,
	}
	print ssids
	return render(request, 'she/hubconnection2.html', context)

def hubconnection3(request):
	global curSSID
	try:
		curSSID =  request.GET['radio']
	except:
		curSSID = []
	context = {
			'curSSID' : curSSID,
	}
	return render(request, 'she/hubconnection3.html', context)

def hubconnection4(request):
	try:
		curPassword =  request.GET['password']
		curCell = []
		for cell in Cell.all('wlan1'):
			if cell.ssid == curSSID:
				curCell = cell
		scheme = Scheme.for_cell('wlan1', curSSID, curCell, curPassword)
		scheme.activate()
	except:
		curPassword = []
	context = {
		'curSSID' : curSSID,
		'curPassword' : curPassword,
	}
	return render(request, 'she/hubconnection4.html', context)

def smartplugconnection(request):
	output = subprocess.check_output(["ip", "neigh", "show", "dev", "wlan0"])
	for line in output.splitlines():
		print (line.split())[0]
	context = {

	}
	return render(request, 'she/smartplugconnection.html', context)
