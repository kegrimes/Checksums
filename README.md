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

![image](https://github.com/kegrimes/Checksums/assets/117098682/a8f7f4b7-5df9-4efa-b940-84ef35991ec7)

### Examples of a Checksum:
Using _i2.txt_ input file, below will show how each checksum will work...  

i2.txt --> `aa`  

**8 bit checksum:** 
1. Find the binary representation of all the characters inside the file.  
a = 0110 0001
a = 0110 0001
0A = 0000 1010 (newline character)

2. Add all binary numbers together, starting with the first 2 characters.

![image](https://github.com/kegrimes/System-Software/assets/117098682/23828bfb-efd5-47f4-962f-f93160ac9d08)

**16 bit checksum:**
Use the same binary representation of the characters!  

2. Set up the binary addition with 16 bits...
*NOTE: Use `X` as a pad if there is not enough input characters to do a 16 bit addition
X = 0101 1000  

![image](https://github.com/kegrimes/System-Software/assets/117098682/19f910cb-4dae-445b-b4a9-c2b6811cefec)

32 bit is very similar to 16 bit checksum, just use padding as needed.  


### Test Files:
There are multiple textfiles that are used for testing: _i1.txt_, _i2.txt_, _i3.txt_, _i4.txt_, _i5.txt_, _in10A.txt_, _in17A.txt_, _in18A.txt_, _in19A.txt_, _inRF1.txt_, _inRF2.txt_, _inWC1.txt_, and _inWC2.txt_

### Terminal Commands:
```
gcc -o pa02 pa02.c
./pa02 inputFile.txt 8
```
*NOTE: To run the program, the last argument can either be 8, 16, or 32. These are the options for which bit checksum to use for a specific textfile.

### Output:
The results will be printed on the terminal screen as well as written to a textfile called _"output.txt"_. 
