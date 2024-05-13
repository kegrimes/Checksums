# **Checksums**
Assignment 2 from CIS3360, Security in Computing

### Overview:
The goal of this assignment is to create a program that calculates an 8, 16, or 32 bit checksum for any input textfile. A checksum is used in cybersecurity to ensure that no data contained inside a file was altered. It is benefical to have some sort of error check to verify no content was changed in the process of transmission from the sender to the reciever. Therefore, checksums can detect if there was an interception from a "man in the middle".

### Adding Binary Numbers:
Ex. _a_ + _b_
a = 0110 0001
b = 0110 0010  

Adding binary numbers together follows a few rules...
1. 0 + 0 = 0
2. 0 + 1 = 1 (vise versa)
3. 1 + 1 = 0, but you carry a 1 to the next group. If there is an odd number of 1's in that adding group, then you continue to carry the 1
4. Start from right side

11   
0110 0001  
0110 0010  
========= 
1100 0011 --> _C3_  

### Examples of a Checksum:
Using _i2.txt_ input file, below will show how each checksum will work...  

i2.txt --> `aa`  

**8 bit checksum:** 
1. Find the binary representation of all the characters inside the file.  
a = 0110 0001
a = 0110 0001
0A = 0000 1010 (newline character)

2. Add all binary numbers together, starting with the first 2 characters.  
11     1
0110 0001
0110 0001
=========
      10
1100 0010
0000 1010 
=========
1100 1100 --> `cc` 

**16 bit checksum:**
Use the same binary representation of the characters!  

2. Set up the binary addition with 16 bits...
*NOTE: Use `X` as a pad if there is not enough input characters to do a 16 bit addition
X = 0101 1000
          1
0110 0001 0110 0001
0000 1010 0101 1000
-------------------
0110 1011 1011 1001 --> `6bb9`

32 bit is very similar to 16 bit checksum, just use padding as needed.  


### Test Files:
There are 

### Terminal Commands:
```
gcc -o pa02 pa02.c
./pa02 inputFile.txt 8
```
*NOTE: To run the program, the last argument can either be 8, 16, or 32. These are the options for which bit checksum to use for a specific textfile.

### Output:
