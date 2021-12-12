# Summer Poissonnier
# June 2, 2021
# COP 4045
# A3

#definitions for functions

#encrypt function
def encrypt(text,key):
    encryption =""
    for i in text:
    #check if uppercase letter
        if i.isupper():
        #position in 0-25
            i_unicode = ord(i)
            i_index = ord(i) - ord("A")
        #shift
            new_index = (i_index + key) % 26
        #new character
            new_unicode = new_index + ord("A")
            new_char = chr(new_unicode)
        #encrypted string
            encryption = encryption + new_char
        #for lowercase
        elif i.islower():
                i_unicode = ord(i)
                i_index = ord(i) - ord("a")
                #shift
                new_index = (i_index + key) % 26
                #new character
                new_unicode = new_index + ord("a")
                new_char = chr(new_unicode)
                #encrypted string
                encryption = encryption + new_char
        #for any other symbol
        else:
            encryption = encryption + i
    return encryption

#decrypt function
def decrypt(text,key):
    decryption =""
    for i in text:
    #if uppercase letter
        if i.isupper():
        #position in 0-25
            i_unicode = ord(i)
            i_index = ord(i) - ord("A")
        #shift
            new_index = (i_index - key) % 26
        #new character
            new_unicode = new_index + ord("A")
            new_char = chr(new_unicode)
        #encrypted string
            decryption = decryption + new_char
        #for lowercase
        elif i.islower():
                i_unicode = ord(i)
                i_index = ord(i) - ord("a")
                #do the shift
                new_index = (i_index - key) % 26
                #new character
                new_unicode = new_index + ord("a")
                new_char = chr(new_unicode)
                #add to encrypted string
                decryption = decryption + new_char
        #if char is a symbol
        else:
            decryption = decryption + i
    return decryption

#description of app
print("The purpose of this app is to encrypt and decrypt plaintext\n" 
"where a letter is replaced by another letter fixed positions away and the number of\n"
"positions becomes the key used to solve the cyper.\n")

#ask the user if they want to play 
play = input("\nDo you want to choose a file (Y) or (N)?: ")

#loop if the user wants to play
while play == 'Y':

    #set the path for the file
    dest=('C:\\Users\poiss\OneDrive\Desktop\COP4655\EGN4950C\COP4045\A3\\')
    #prompt user for filename
    filename = input("Please enter a filename: ")
    #open the file
    input_file = open(dest+filename,'r')
    #testing the file
    text = input_file.read()
    #prompt the user for encrypt or decrypt
    operation = input("\nWould you like to encrypt (E) or decrypt (D)?: ")
    #set the key to 3
    key = 3

    if operation == 'E':
        #call encrypt function
        print("Shift key : " + str(key))
        print("Input text : " + text)
        enc = encrypt(text,key)
        print("Encryption: " + enc)
        #open the output file and write to it
        output_file = open(dest+filename+'_enc'+'.txt', 'w')
        output_file.write("Encryption: " + enc)
        output_file.close
    else:
        #call decrypt function
        print("Shift key : " + str(key))
        print("Input text : " + text)
        dec = decrypt(text,key)
        print("Decryption: " + dec)
        #open the output file and write to it
        output_file = open(dest+filename+'_dec'+'.txt', 'w')
        output_file.write("Decryption: " + dec)
        output_file.close

    #ask the user if they want to play again
    play = input("\nYou have succeeded in encrypting/decrypting the text."
        "\nDo you want to choose a file (Y) or (N)?: ")
    #close the file
    input_file.close



