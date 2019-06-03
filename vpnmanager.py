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
        logfile.write(str(event) + '\n')
        logfile.close()
    else:
        logfile = open(logFileLoc, 'w')
        logfile.write(str(date) + '\n')
        logfile.write(str(event) + '\n')
        logfile.close()

#func for starting vpn, changes active dir to openvpn dir
def opvpn():
    log('opvpn called to start vpn')
    os.chdir('/etc/openvpn')
    try:
        subprocess.call([
                'openvpn',
                '/etc/openvpn/client.ovpn'
               ])
    except:
        log('failed to run openvpn subprocess')

#vpnconnection check

locNetStatus = subprocess.check_output(
        ['ping', '-c5', '-w20', '192.168.0.1']
       )
locNetConfig = subprocess.check_output('ifconfig')

#by ping 
#TODO fix error thrown when network off, ping does not
#return correctly
#TODO fix error in subprocess.check_output call
try:
    subprocess.check_output(
            ['ping', '-c5', '-w20', '192.168.0.1']
           )
    log('net up, data from ping')
    log(locNetStatus)
    log(locNetConfig)
    network = 'up'
except:
    log('net down, data from ping')
    log(locNetStatus)
    log(locNetConfig)
    network = 'down'

#by ifconfig
#TODO add ifconfig test for tun0
tun = str('tun0')
locNetConfig = str(locNetConfig)
if tun in locNetConfig:
    log('tun0 up')
else:
    log('tun0 down, calling opvpn func')
    opvpn()


