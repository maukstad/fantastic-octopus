#!/usr/bin/python3

#vpnmanager.py program to check and restart vpn connection
#set up on once an hour cronjob

import datetime, os, subprocess, re

#location of log file
#comment out below, it is a test file
logFileLoc = '/home/mauks/Documents/projects/vpnmanagerlog'
#uncomment out below, it is real file
#logFileLoc = '/var/log/openvpn

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
#TODO when opvpn called try func works and opens vpn but still moves to except
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

locNetConfig = subprocess.check_output('ifconfig')

#by ifconfig
tun = str('tun0')
pram = re.compile(r"(192\............)|(172\............)")
locNetConfig = str(locNetConfig)
repram = pram.findall(locNetConfig)
if tun in locNetConfig:
    log('tun0 up')
elif len(repram) >= 1:
    log('tun0 down but network is up, calling opvpn func')
    log(locNetConfig)
    opvpn()
else:
    log('tun0 down, network down')
    log(locNetConfig)
    log('attempting network startup')
    subprocess.call(
            ['service',
                'network-manager',
                'start']
            )
    opvpn()


