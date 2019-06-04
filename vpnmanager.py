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

#locNetStatus = subprocess.check_output(
#        ['ping', '-c5', '-w20', '192.168.0.1']
#       )
locNetConfig = subprocess.check_output('ifconfig')

#by ping 
#TODO fix error thrown when network off, ping does not
#return correctly
#TODO fix error in subprocess.check_output call
#try:
#    subprocess.check_output(
#            ['ping', '-c5', '-w20', '192.168.0.1']
#           )
#    log('net up, data from ping')
#    log(locNetStatus)
#    log(locNetConfig)
#    network = 'up'
#except:
#    log('net down, data from ping')
#    log(locNetStatus)
#    log(locNetConfig)
#    network = 'down'

#by ifconfig
#TODO fix error with elif command
tun = str('tun0')
pram = re.compile(r"(192\............)|(172\............)")
repram = pram.findall(locNetConfig)
locNetConfig = str(locNetConfig)
if tun in locNetConfig:
    log('tun0 up')
elif pram :   #if repram has value then true else go to else?
    log('tun0 down but network is up, calling opvpn func')
    log(locNetConfig)
    opvpn()
else:
    log('tun0 down, network down')
    log(locNetConfig)
    


