# Summer Poissonnier
# May 25, 2021
# COP 4045
# A2

#description of app
print("The purpose of this app is to encrypt and decrypt plaintext\n" 
"where a letter is replaced by another letter fixed positions away and the number of\n"
"positions becomes the key used to solve the cyper.\n")

# prompts the user to play
option = input("Do you want to play? (Y) or (N): ")

#if the user wants to play then run this loop
while option == 'Y':
    #prompt the user for a phrase
    input_phrase = input("\nPlease enter a phrase: ")
    #prompt the user for a key
    key = input("\nPlease enter a number for the key: ")
    #prompt the user for encrypt or decrypt
    operation = input("\nWould you like to encrypt (E) or decrypt (D)?: ")
    #make sure encrypt and plain text are emtpy strings
    encrypt = ""
    decrypt = ""

    #conditional for encryption
    if operation == 'E':

        #loop to check each letter 
        for i in input_phrase:

            #check if char is an uppercase letter
            if i.isupper():

                #find position in 0-25
                i_unicode = ord(i)

                i_index = ord(i) - ord("A")

                #make the shift
                new_index = (i_index + int(key)) % 26

                #new character
                new_unicode = new_index + ord("A")

                new_char = chr(new_unicode)

                #add to encrypt string
                encrypt = encrypt + new_char

            #character is not uppercase
            else:

                i_unicode = ord(i)

                i_index = ord(i) - ord("a")

                #do the shift
                new_index = (i_index + int(key)) % 26

                #new character
                new_unicode = new_index + ord("a")

                new_char = chr(new_unicode)

                #add to encrypted string
                encrypt = encrypt + new_char

        #print the input and the encrypted phrase
        print("\nInput text:",input_phrase)
        print("\nEncrypted text:",encrypt)

    #if user chooses decrypt
    else:

        for i in input_phrase:

            #check for uppercase
            if i.isupper():

                #find position in 0-25
                i_unicode = ord(i)

                i_index = ord(i) - ord("A")

                #do the negative shift
                new_index = (i_index - int(key)) % 26

                #new character
                new_unicode = new_index + ord("A")

                new_char = chr(new_unicode)

                #add to plain text
                decrypt = decrypt + new_char

            #since character is not uppercase
            else:
        
                i_unicode = ord(i)

                i_index = ord(i) - ord("a")

                #do the shift
                new_index = (i_index - int(key)) % 26

                #new character
                new_unicode = new_index + ord("a")

                new_char = chr(new_unicode)

                #add to encrypted string
                decrypt = decrypt + new_char
        #Print the input text and decrypted text
        print("\nInput text:",input_phrase)
        print("\nDecrypted text:",decrypt)

    #prompt for playing again
    option = input("\nDo you want to play again? (Y) or (N): ")




