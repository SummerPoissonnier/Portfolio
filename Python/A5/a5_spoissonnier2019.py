# Summer Poissonnier
# June 25, 2021
# COP 4045
# A5

import csv
from statistics import mean

#dictionary to store the species attributes/features
speciesDict = {
    'versicolor' : {'sepal_length':[],'petal_length':[], 'sepal_width':[], 'petal_width':[]},
    'setosa' : {'sepal_length':[],'petal_length':[],'sepal_width':[], 'petal_width':[]},
    'virginica': {'sepal_length':[],'petal_length':[], 'sepal_width':[], 'petal_width':[]}
}

#function to get the averages of the attributes
def Averages():
    #get the next element in the file
    next(csvRead)
    #iterate through the file
    for row in csvRead:
        sep_len = row[0]
        sep_wid = row[1]
        pet_len = row[2]
        pet_wid = row[3]
        spec = row[4]
        
        #append the species data to their attributes
        speciesDict[spec]['sepal_length'].append(float(sep_len))
        speciesDict[spec]['petal_length'].append(float(pet_len))
        speciesDict[spec]['sepal_width'].append(float(sep_wid))
        speciesDict[spec]['petal_width'].append(float(pet_wid))
    #new dictionary to store the key for computing averages
    newDict = {
        id: 
        {key: mean(id) for key, id in x.items()} for id, x in speciesDict.items()}
    return newDict

#prints averages neatly
def printResults(newDict):

    #sets attributes to null
    sep_len = []
    pet_len = []
    sep_wid = []
    pet_wid = []
    
    for key in newDict:
        for v in newDict[key]:
            if v == 'sepal_width':
                sep_wid.append(newDict[key][v])
            elif v == 'petal_width':
                pet_wid.append(newDict[key][v])
            elif v == 'petal_length':
                pet_len.append(newDict[key][v])
            elif v == 'sepal_length':
                sep_len.append(newDict[key][v])
           
    #formatting
    print("-------------------------------------------------------------")
    print("Species:\t", '{:>18}'.format("Versicolor"), '{:>9}'.format("Setosa"), '{:>13}'.format("Virginica"))
    print("-------------------------------------------------------------")

    print("Attributes (cm):")
    print('{:>20}'.format("Avg petal length:"),*pet_len, sep="{:<7}".format(" "))
    print('{:>20}'.format("Avg petal width: "),*pet_wid, sep="{:<7}".format(" "))
    print('{:>20}'.format("Avg sepal length:"),*sep_len, sep="{:<7}".format(" "))
    print('{:>20}'.format("Avg sepal width: "),*sep_wid, sep="{:<7}".format(" "))

#description of app
print("\nThe purpose of this app is to display data from the iris dataset\n" 
"by building a dictionary and displaying summary statistics.\n")
#destination to the file
dest=('C:\\Users\poiss\OneDrive\Desktop\COP4655\EGN4950C\COP4045\A5\\')
#open the file
csvFile = open(dest + "iris.csv", "r") 
#read the file info
csvRead =  csv.reader(csvFile)
#set the new dictionary to calculate the averages
newDict = Averages()
#print the formatted averages
printResults(newDict)
