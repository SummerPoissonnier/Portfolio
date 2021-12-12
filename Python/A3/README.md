Ceasar Cipher A3 Project Notes:

While creating the code for this assignment, I decided to design my
program with the same code I used in A2. I used the same encryption
and decryption algorithm; however, in A3 I created a decrypt and encrypt
function. I created my two functions first and put them at the beginning
of my code. I used the algorithms from A2 in this code. I noticed
that I needed to code for spaces and other characters that are not
letters in this assignment so I added that line in at the end of my 
functions. After I created my functions, I gave a description of the
cipher and then prompted the user to open a file. I had trouble with 
If the user input 'Y', then I set up a while loop to perform the
encryption or decryption. In my while loop I opened the file that the 
user gave to me. This was complicated for me because I had to figure out
how to code for the exact destination since my program would not open
the file any other way. After I set the destination, I asked for the 
filename, opened the file, read the file, and then prompted for encrypt
or decrypt. I used conditionals to perform the encryption if the user
chose 'E' and decryption if the user chose 'D'. In the conditionals I
called the encrypt and decrypt function and wrote to and opened an output
file. I then asked the user if they wanted to choose another file and
then after the while loop I closed the input file. 