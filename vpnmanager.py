#!/usr/bin/python3

#vpnmanager.py program to check and restart vpn connection

import datetime, os

#location of log file
logFileLoc = '/home/mauks/Documents/projects/vpnmanagerlog'

#local log device, will make new file at location of
#log file, "logFileLoc" if none exists
def log(event):
    data = event
    date = datetime.datetime.now()
    if os.path.isfile(logFileLoc):
        logfile = open(logFileLoc, 'a')
        logfile.write(str(date) + '\n')
        logfile.write(event + '\n')
        logfile.close()
    else:
        logfile = open(logFileLoc, 'w')
        logfile.write(str(date) + '\n')
        logfile.write(event + '\n')
        logfile.close()

#vpnconnection check
