#!/usr/bin/env python
import sys
import pandas as pd
import os
import webbrowser
import datetime
class RevisonDiary:
    'Diary for Revison'
    def __init__(self,folder='./'):
        if folder[-1] != '/':
            folder += '/'
        self.dir = folder
        self.nit = folder +'.nit/'
        self.files = self.nit+'.files.csv'
        self.revise_file = self.nit+'.revise.csv'

        if os.path.exists(folder):
            print("using existing folder "+folder)
        else:
            os.mkdir(folder)
        if os.path.exists(self.nit):
            print(".nit exists already")
        else:
            os.mkdir(self.nit)
            f = open(self.files,'w')
            #f.write("timestamp,filename\n")
            #x = datetime.datetime.now()
            #f.write(str(x.timestamp()))
            f.write("date,filename\n")
            #f.write(str(datetime.date.today()))
            #f.write(',.files.csv\n')
            f.close()

            f = open(self.revise_file,'w')
            #print(self.revise_file)
            f.write("date,filename,1d,7d,30d\n")
            f.close()
    def add_file(self,file):
        if os.path.exists(file):
            files = pd.read_csv(self.files)
            flag = True
            if file in files['filename'].values:
                update = input("File already added want to add again ? y/n ")
                if update != 'y' and update != 'Y':
                    flag = False
            if flag:
                f = open(self.files,'a')
                #x = datetime.datetime.now()
                #f.write(str(x.timestamp()))
                td = str(datetime.date.today())+","+file
                f.write(td+'\n')
                f.close()
                f = open(self.revise_file,'a')
                f.write(td+",0,0,0\n")
                f.close()
                print('added '+file)

        else:
            print("File doesn't exists :"+file)
    def open_file(self,file):
        'file : filename of file to open'
        file = self.dir+file
        if os.path.exists(file):
            #f = open(file,'r')
            #print(f.read())
            #f.close()
            path = 'file://'+os.path.realpath(file)
            #input('Enter anything to open : '+path+' ')
            return webbrowser.open(path)
        else:
            print("File doesn't exists : "+file)
        return False
    def revise(self,pending=False):
        'Revise all files'
        print(pending)
        files = pd.read_csv(self.files)
        revise = pd.read_csv(self.revise_file)
        today = datetime.date.today()
        for i,row in files.iterrows():
            diff = today - datetime.date.fromisoformat(row['date'])
            if diff.days in [1,7,30]:
                if self.open_file(row['filename']):
                    for rev_i,rev_row in revise.iterrows():
                        print(rev_i)
                        if rev_row['filename'] == row['filename']:
                            s = input("Done revision? y/n")
                            if s == 'y' or s=='Y':
                                revise[str(diff.days)+'d'][rev_i] = 1
                else:
                    print("Error opening file "+row['filename'])
        revise.to_csv(self.revise_file,index=False)
    def list_df(self):
        return pd.read_csv(self.files)
    def list(self):
        r = str()
        for _,row in self.list_df().iterrows():
            r += row['filename']+'\n'
        return r
argv = sys.argv
if len(sys.argv) <= 1:
    print("Try add, list, revise")
else:
    rd = RevisonDiary()
    if sys.argv[1] == "list":
        print(rd.list())
    elif sys.argv[1] == "list_df":
        print(rd.list_df())
    else:
        if len(sys.argv) == 2:
            print("No file specified")
        else:
            if sys.argv[1] == "add":
                #print("adding"+sys.argv[2])
                rd.add_file(sys.argv[2])
