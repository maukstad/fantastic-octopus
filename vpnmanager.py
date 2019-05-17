#!/usr/bin/python3

#vpnmanager.py program to check and restart vpn connection

import datetime, os

#local log device
def log(event):
    data = event
    date = datetime.datetime.now()
    if os.path.isfile('/var/log/vpnmanagerlog'):
        logfile = open('/var/log/vpnmanagerlog', 'a')
        logfile.write(date)
        logfile.write(event)
        logfile.close()
    else:
        logfile = open('/var/log/vpnmanagerlog', 'w')
        logfile.write(str(date))
        logfile.write(event)
        logfile.close()
    print(date)
    print(str(date))
