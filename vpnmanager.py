#!/usr/bin/python3

#vpnmanager.py program to check and restart vpn connection

import datetime, os, subprocess

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

locNetStatus = subprocess.check_output(['ping', '-c5', '192.168.0.1'])
locNetConfig = subprocess.check_output('ifconfig')

#by ping
try subprocess.check_output(['ping', '-c5', '192.168.0.1']):
    log('net up, data from ping')
    log(locNetStatus)
    log(locNetConfig)
except:
    log('net down, data from ping')
    log(locNetStatus)
    log(locNetConfig)

#by ifconfig

