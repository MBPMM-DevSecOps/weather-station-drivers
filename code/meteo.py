
import sys
import csv
import time
import calendar
from random import randrange
from datetime import datetime
starttime = time.time()
current_GMT = time.gmtime()
time_stamp = calendar.timegm(current_GMT)
driverHygro = randrange(10)
driverTemp = randrange(40)
driverSensVent = randrange(360)
driverForceVent = randrange(5)
header = ['hygrometrie','temperature','sensDuVent','forceDuVent','timeStamp']
data = [driverHygro,driverTemp,driverSensVent,driverForceVent,time_stamp]
while True:
	print("Récupération des données")
	time.sleep(15.0 - ((time.time() - starttime) % 15.0))
	with open('/data/weather-station/data-weather-station.csv', 'a') as f:
		writer = csv.writer(f)

		writer.writerow(header)

		writer.writerow(data)
