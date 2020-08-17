import csv, re, os



#finding length of scan
with open('PURCH.csv', newline='', encoding="utf8") as purch:
        preader = csv.DictReader(purch)
        ptotal = 0
        n = 1
        for row in preader:
                ptotal = ptotal + 1


#just to initailize csv doc
def purchscan_create():
        with open("purchscan_output.csv", "w", newline='') as purchscan_output:
                fieldnames = ['Container_Code',
                              'FUZE_ID',
                              'Location_Code',
                              'Move_To_Status',
                              'PO_Code',
                              'Part_Code',
                              'FUZE_Part_Code',
                              'Qty',
                              'Project_Name',
                              'Project_Number',
                              'Project_Status',
                              'Avalible_to_Whom',
                              'Original_Buyer',
                              'Days_Until_Non_Compliant',
                              'Notes'
                              ]
                output = csv.DictWriter(purchscan_output, fieldnames=fieldnames)
                output.writeheader()
                
#appends doc with data from scan
def purchscan_add():
        with open("purchscan_output.csv", "a+", newline='') as purchscan_output:
                fieldnames = ['Container_Code',
                              'FUZE_ID',
                              'Location_Code',
                              'Move_To_Status',
                              'PO_Code',
                              'Part_Code',
                              'FUZE_Part_Code',
                              'Qty',
                              'Project_Name',
                              'Project_Number',
                              'Project_Status',
                              'Avalible_to_Whom',
                              'Original_Buyer',
                              'Days_Until_Non_Compliant',
                              'Notes'
                              ]
                output = csv.DictWriter(purchscan_output, fieldnames=fieldnames)
                output.writerow({
                        'Container_Code': fco,
                        'FUZE_ID': fid,
                        'Location_Code': lo,
                        'Move_To_Status': mvs,
                        'PO_Code': po,
                        'Part_Code': equip,
                        'FUZE_Part_Code': fequip,
                        'Qty': qtyr,
                        'Project_Name': page,
                        'Project_Number': pn,
                        'Project_Status': pps,
                        'Avalible_to_Whom': avl,
                        'Original_Buyer': ogb,
                        'Days_Until_Non_Compliant': fdu,
                        'Notes': notes
                        })


#scans fuze file to compare data vs purch file 
def purchscan(po):
        with open('FUZE.csv', newline='') as fuze:
                freader = csv.DictReader(fuze)
                for row in freader:
                        global fco, flo, fdu, fid, avl, notes, fequip, ogb, mvs
                        notes = ""
                        fdu = float(row[" Days Until Non Compliant"])
                        flo = row[" Location Detail Code"]
                        fpo = row[" PO Code"]
                        fpo = fpo.strip()
                        fequip = row[" Part Code"]
                        fco = row[" Container Code"]
                        fco = fco.strip()
                        ogb = row[" Original Buyer"]
                        fid = row[" Fuze Project Id"]
                        avl = row[" Avail To Whom"]
                        mvs = row[" Move To Status"]
                        fqty = row[" Qty"]
                        offset = float(-10)
                        if re.match(r'^EA', flo):
                                if po == fpo:
                                        if equip == fequip:

                                                purchscan_add()


                                elif po == fco:
                                        if equip == fequip:

                                                purchscan_add()

                                                
                        elif re.match(r'^ER', flo):
                                if fdu >= offset:
                                        if po == fpo:
                                                if equip == fequip:

                                                        purchscan_add()

                               
                                        elif po == fco:
                                                if equip == fequip:

                                                        purchscan_add()
        

        

with open('PURCH.csv', newline='', encoding="utf8") as purch:
        preader = csv.DictReader(purch)
        po = ""
        fpo = ""
        it = 0
        purchscan_create()
        for row in preader:
                po = row["po_number"]
                lo = row["people_soft_location_code"]
                qtyo = row["qty_required"]
                qtyr = row["qty_received"]
                qtymr = row["material_request_quantity"]
                page = row["project_name"]
                equip = row["part_number_human"]
                pn = row["project_number"]
                pps = row["project_received_status"]
                po = po.strip()
                if qtymr < qtyr:
                        purchscan(po)

                elif qtyr == 0:
                        if po != "":
                                purchscan(po)


                print("scan", it, " out of ", ptotal)
                it = it + 1
                
                os.system('cls')
                
                        
                
                


print(pinfo)


                        

       

        
