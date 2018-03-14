import os

years = [2015, 2016, 2017]
months = ['01', '02', '03', '04', '05', '06', '07', '08', '09']

finput = ''
output = ''

for year in years:
    for month in months:
        finput = str(year) + month + 'result.csv'
        output = str(year) + month + 'fullroad.csv'
        #print(data)
        try:
            f = open(finput)
            f.close()
            os.system("./connect_pieces " + finput + ' ' + output)
            print("./connect_pieces " + finput + ' ' + output + " is ready!")
            
        except FileNotFoundError:
            print("File is not found.")