# Summer Poissonnier
# June 9, 2021
# COP 4045
# A4

import csv
#import matplotlib.pyplot as plt 

#function definitions for option 1
#to make a list of mileage values
def Mileage(csvfile):
    mileage_list = []
    header = csvfile.readline()
    for line in csvfile:
        line_list = line.split(',')
        if 'Car' in line_list[70]:
            vehicle_tuple = (int(line_list[10]),line_list[2],line_list[3])
            mileage_list.append(vehicle_tuple)
    return mileage_list
#to make a list of mileage values in range user provides
def find_range_mileage(mileage_list, interval):
    #list of car tuples
    interval_mile_list = []
    #find cars within the range and append them to list
    for vehicle_tuple in mileage_list:
        if vehicle_tuple[0] in interval:
            interval_mile_list.append(vehicle_tuple)
    return interval_mile_list

#function definition for option 2
#def plot():
    #set dest and open file
    dest=('C:\\Users\poiss\OneDrive\Desktop\COP4655\EGN4950C\COP4045\A4\\')
    csvfile = open(dest+'epadata2020.csv', 'r')
    x,y = [], []
    for line in csvfile:
        line_list = line.strip().split()
        #year
        x.append(int(line_list[0]))
        #MP
        y.append(float(line_list[2]))
    csvfile.close()
    pylab.plot(x,y)


#description of app
print("The purpose of this app is to query the Environmental Protection Agency (EPA)\n" 
"fuel consumption data and to produce customizable plots of relevant trends over time")

#ask the user if they want to query the data or create a trend plot
userInput = int(input("\nEnter (1) for Mileage Info and (2) for Trend Plot : "))

#conditional statements depending on which option user chooses
if userInput == 1:
    #formatting the print statements
    print("\nEPA Car Mileage")
    print()
    #get the max and min for the interval
    max = int(input("\nEnter the maximum MPG mileage you are interested in: "))
    min = int(input("\nEnter the minimum MPG mileage you are interested in: "))
    #create a range with the max and min
    interval = range(min,max)
   #path to the file
    dest=('C:\\Users\poiss\OneDrive\Desktop\COP4655\EGN4950C\COP4045\A4\\')
    # reading csv file
    csvfile = open(dest+'epadata2015.csv', 'r')
    mileage_list=Mileage(csvfile)
    #display the interval
    print('Interval: ', interval)
    print()
    #create an interval list
    interval_mile_list = find_range_mileage(mileage_list, interval)
    #display the cars
    print("Cars within the interval:")
    #format the information
    for vehicle_tuple in interval_mile_list:
        print(" ",vehicle_tuple[1], vehicle_tuple[2])
#for option 2
elif userInput == 2:
    #prompt the user for their measure
    userInput = input("\nPlease input the measure you are interested in, (H)ighway MPG,"
    "(C)ity MPG, or (O)verall MPG: ")
    
    #prompt the user to display or save to file
    option = input("\nDo you want to (S)ave to file or (D)isplay on screen? ")
    #print the plot
    #print(plot())
#redirect the user
else: 
    print("\nPlease choose option 1 or 2")
