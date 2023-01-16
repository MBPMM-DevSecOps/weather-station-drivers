import os
import sys
import csv
import time
import calendar
from random import randrange
from datetime import datetime
starttime = time.time()
csvDataWeather = '/data/weather-station/data-weather-station.csv'
while True:
	print("Récupération des données")
	time.sleep(15.0 - ((time.time() - starttime) % 15.0))
	current_GMT = time.gmtime()
	time_stamp = calendar.timegm(current_GMT)
	time_stamp = time_stamp * 1000
	driverHygro = randrange(10)
	driverTemp = randrange(40)
	driverSensVent = randrange(360)
	driverForceVent = randrange(5)
	header = ['hygrometrie','temperature','sensDuVent','forceDuVent','timeStamp']
	data = [driverHygro,driverTemp,driverSensVent,driverForceVent,time_stamp]
	with open(csvDataWeather, 'a') as f:
		writer = csv.writer(f)

		file_is_empty = os.stat(csvDataWeather).st_size == 0

		if file_is_empty:
			print("header placed")
			writer.writerow(header)

		writer.writerow(data)
