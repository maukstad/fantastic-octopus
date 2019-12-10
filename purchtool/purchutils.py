#!/usr/bin/python3

import csv
from os import listdir

#basic utils for PURCH

#TODO load csv docs for processing
local_files = listdir()
load_file_count = len(local_files)


#TODO user picks files
print('Please choose the PURCH equipment report csv from the following ' 
        + str(load_file_count) + ' files')
n = 0
while n < load_file_count:
    print("(" + str(n) + ") " + local_files[n])
    n = n + 1
user_selection = input('please select number:')
if int(user_selection) >= 0 and int(user_selection) <= load_file_count -1:
    print("Please confirm " + local_files[int(user_selection)] + " is the PURCH equipment report csv")
#    input("Yes/No")


#TODO find parts in both PURCH and FUZE data with expiring dates



#TODO find parts in PURCH but missing from FUZE to show lost parts



#TODO find parts overallocated in PURCH
