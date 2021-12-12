import csv
from statistics import mean

###########################################################################
### COP 4045 - Python Programming - Bryan Perdomo - FAU - Summer 2021 ###
###            Assignment 5: Iris Data Dictionaries - 7/1/2021       ###
###########################################################################

print("""\nHello, and welcome to my demo for Assignment 5. This program does a couple of things:
Firstly, it leverages the csv library to read through the Iris data-set csv file, and stores all values into a
hard coded dictionary. It then makes use of the statistics module and a clever dictionary comprehension to create a new
dictionary that maps to each species of flower's average of a particular feature(length, width,etc)
Finally, the averages are then printed out to the screen in a 'neat' format.""")

#hard-coded dictionary to store all csvs'
initial_dict = {
    'setosa' : {'sepal_length':[], 'sepal_width':[], 'petal_length':[], 'petal_width':[]},
    'versicolor' : {'sepal_length':[], 'sepal_width':[], 'petal_length':[], 'petal_width':[]},
    'virginica': {'sepal_length':[], 'sepal_width':[], 'petal_length':[], 'petal_width':[]}
}

#this function both parses the csv file and builds a new dictionary with average values
def read_csv():
    dest=('C:\\Users\poiss\OneDrive\Desktop\COP4655\EGN4950C\COP4045\A5\\')
    iris_file = open(dest + "iris.csv", "r")
    reader =  csv.reader(iris_file)

    next(reader)
    for row in reader:

        species = row[4]
        sepal_length = row[0]
        sepal_width = row[1]
        petal_length = row[2]
        petal_width = row[3]

        initial_dict[species]['sepal_length'].append(float(sepal_length))
        initial_dict[species]['sepal_width'].append(float(sepal_width))
        initial_dict[species]['petal_length'].append(float(petal_length))
        initial_dict[species]['petal_width'].append(float(petal_width))
    
    #dictionary comprehension
    #This is the secret sauce that allows me to both compress csv parsing and computing averages into one function
    #and build a new dictionary at the same time
    iris_dict = {idx: {key: mean(idx) for key, idx in j.items()} for idx, j in initial_dict.items()}
    return iris_dict

#iterates through iris_dict and prints averages to the screen neatly
def print_dict(iris_dict):

    sep_len = []
    sep_wid = []
    petal_length = []
    petal_width = []
    #key is 's'
    for key in iris_dict:
        
        for value in iris_dict[key]:
            if value == 'sepal_length':

                sep_len.append(iris_dict[key][value])
            elif value == 'sepal_width':
                sep_wid.append(iris_dict[key][value])
            elif value == 'petal_length':
                petal_length.append(iris_dict[key][value])
            elif value == 'petal_width':
                petal_width.append(iris_dict[key][value])

    print("----------------------------------------------------------")
    print("Species:\t", '{:>12}'.format("Setosa"), '{:>10}'.format("Setosa"), '{:>10}'.format("Virginica"))
    print("----------------------------------------------------------")

    print("Attributes(cm):")
    print("avg sepal length:",*sep_len, sep="{:<7}".format(" "))
    print("avg sepal width: ",*sep_wid, sep="{:<7}".format(" "))
    print("avg petal length:",*petal_length, sep="{:<7}".format(" "))
    print("avg petal width: ",*petal_width, sep="{:<7}".format(" "))


    
iris_dict = read_csv()
print_dict(iris_dict)

