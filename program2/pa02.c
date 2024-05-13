/*========================================================================
|   Assignment: pa02 - Calculating an 8, 16, or 32 bit
|                      checksum on an ASCII input file
|
|       Author: Katelyn Grimes
|     Language: C
|
|   To Complie: gcc -o pa02 pa02.c
|
|   To Execute: ./pa02 inputFile.txt 8
|
|         Note: All input files are simple 8 bit ASCII input
|
|        Class: CIS3360 - Security in Computing - Fall 2023
|   Instructor: McAplin
|     Due Date: November 12, 2023
========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000

//KG: character input file is stored into input array
char input[MAX] = {};
//KG: corresponding hexadecimal values are stored into this array
char hex[MAX] = {};
//KG: checksum is stored in this array
char checksum[MAX] = {};

//KG: values used for array counts and padding count
int inputSize = 0;
int hexSize = 0;
int tempHex = 0;
int checkCount = 0;
int pad = 0;


//KG: reads the input file and stores into input array
void readInput(FILE *ifp){
    char c;
    int i = 0;

    if(ifp == NULL){
        printf("Failed to open file!\n");
    }

    while((c = fgetc(ifp)) != EOF){
        input[i] = c;
        i++;
        inputSize++;
    }
}

//KG: prints to the screen and an output file the read in array
void printInputArr(FILE *ofp){
    for(int i = 0; input[i] != 0; i++){
        int mod = i % 80;
        if(i == 0 || mod != 0){
            printf("%c", input[i]);
            fprintf(ofp, "%c", input[i]);
        }
        else{
            printf("\n");
            fprintf(ofp, "\n");
            printf("%c", input[i]);
            fprintf(ofp, "%c", input[i]);
        }
    }
}

//KG: gets the corresponding hex value of a decimal number
void getHex(char ch){
    char hexArr[3] = {};
    int decimal = ch;
    tempHex = 0;
    int temp = 0;

    while(decimal != 0){
        temp = decimal % 16;

        if(temp < 10){
            hexArr[tempHex] = temp + 48;
        }
        else{
            hexArr[tempHex] = temp + 55;
        }

        decimal = decimal / 16;
        tempHex++;
    }

    if(hexArr[0] == 'A'){
        //KG: adds the new line character hex value
        hex[hexSize] = '0';
        hexSize++;
        hex[hexSize] = 'a';
        hexSize++;
    }
    else{
        //KG: insert into main hex array
        for(int i = tempHex - 1; i >= 0; i--){
            if(isalpha(hexArr[i])){
                if(toupper(hexArr[i])){
                    hexArr[i] = tolower(hexArr[i]);
                    hex[hexSize] = hexArr[i];
                    hexSize++;
                }
            }
            else{
                hex[hexSize] = hexArr[i];
                hexSize++;
            }
        }
    }

}

//KG: creates the hex array after finding hex value of character
void createHexArray(){
    for(int i = 0; i < inputSize; i++){
        getHex(input[i]);
    }
}

//KG: prints to the screen and an output file the hex array
void printHex(FILE *ofp){
    for(int i = 0; hex[i] != 0; i++){
        printf("%c", hex[i]);
        fprintf(ofp, "%c", hex[i]);
    }
    printf("\n");
    fprintf(ofp, "\n");
}

//KG: gets the binary representation of the characters in the hex array
void getBinaryRep(char ch, int arr[], int index){
    switch(ch){
    case '0':
        arr[index] = 0;
        arr[index + 1] = 0;
        arr[index + 2] = 0;
        arr[index + 3] = 0;
        break;
    case '1':
        arr[index] = 0;
        arr[index + 1] = 0;
        arr[index + 2] = 0;
        arr[index + 3] = 1;
        break;
    case '2':
        arr[index] = 0;
        arr[index + 1] = 0;
        arr[index + 2] = 1;
        arr[index + 3] = 0;
        break;
    case '3':
        arr[index] = 0;
        arr[index + 1] = 0;
        arr[index + 2] = 1;
        arr[index + 3] = 1;
        break;
    case '4':
        arr[index] = 0;
        arr[index + 1] = 1;
        arr[index + 2] = 0;
        arr[index + 3] = 0;
        break;
    case '5':
        arr[index] = 0;
        arr[index + 1] = 1;
        arr[index + 2] = 0;
        arr[index + 3] = 1;
        break;
    case '6':
        arr[index] = 0;
        arr[index + 1] = 1;
        arr[index + 2] = 1;
        arr[index + 3] = 0;
        break;
    case '7':
        arr[index] = 0;
        arr[index + 1] = 1;
        arr[index + 2] = 1;
        arr[index + 3] = 1;
        break;
    case '8':
        arr[index] = 1;
        arr[index + 1] = 0;
        arr[index + 2] = 0;
        arr[index + 3] = 0;
        break;
    case '9':
        arr[index] = 1;
        arr[index + 1] = 0;
        arr[index + 2] = 0;
        arr[index + 3] = 1;
        break;
    case 'a':
        arr[index] = 1;
        arr[index + 1] = 0;
        arr[index + 2] = 1;
        arr[index + 3] = 0;
        break;
    case 'b':
        arr[index] = 1;
        arr[index + 1] = 0;
        arr[index + 2] = 1;
        arr[index + 3] = 1;
        break;
    case 'c':
        arr[index] = 1;
        arr[index + 1] = 1;
        arr[index + 2] = 0;
        arr[index + 3] = 0;
        break;
    case 'd':
        arr[index] = 1;
        arr[index + 1] = 1;
        arr[index + 2] = 0;
        arr[index + 3] = 1;
        break;
    case 'e':
        arr[index] = 1;
        arr[index + 1] = 1;
        arr[index + 2] = 1;
        arr[index + 3] = 0;
        break;
    case 'f':
        arr[index] = 1;
        arr[index + 1] = 1;
        arr[index + 2] = 1;
        arr[index + 3] = 1;
        break;
    default:
        return;
    }
}

//KG: gets the hexadecimal representation of the checksum (in binary)
int getHexRep(int i, int add[]){
    if(add[i] == 0 && add[i+1] == 0 && add[i+2] == 0 && add[i+3] == 0){
        checksum[checkCount] = '0';
        checkCount++;
    }
    if(add[i] == 0 && add[i+1] == 0 && add[i+2] == 0 && add[i+3] == 1){
        checksum[checkCount] = '1';
        checkCount++;
    }
    if(add[i] == 0 && add[i+1] == 0 && add[i+2] == 1 && add[i+3] == 0){
        checksum[checkCount] = '2';
        checkCount++;
    }
    if(add[i] == 0 && add[i+1] == 0 && add[i+2] == 1 && add[i+3] == 1){
        checksum[checkCount] = '3';
        checkCount++;
    }
    if(add[i] == 0 && add[i+1] == 1 && add[i+2] == 0 && add[i+3] == 0){
        checksum[checkCount] = '4';
        checkCount++;
    }
    if(add[i] == 0 && add[i+1] == 1 && add[i+2] == 0 && add[i+3] == 1){
        checksum[checkCount] = '5';
        checkCount++;
    }
    if(add[i] == 0 && add[i+1] == 1 && add[i+2] == 1 && add[i+3] == 0){
        checksum[checkCount] = '6';
        checkCount++;
    }
    if(add[i] == 0 && add[i+1] == 1 && add[i+2] == 1 && add[i+3] == 1){
        checksum[checkCount] = '7';
        checkCount++;
    }
    if(add[i] == 1 && add[i+1] == 0 && add[i+2] == 0 && add[i+3] == 0){
        checksum[checkCount] = '8';
        checkCount++;
    }
    if(add[i] == 1 && add[i+1] == 0 && add[i+2] == 0 && add[i+3] == 1){
        checksum[checkCount] = '9';
        checkCount++;
    }
    if(add[i] == 1 && add[i+1] == 0 && add[i+2] == 1 && add[i+3] == 0){
        checksum[checkCount] = 'a';
        checkCount++;
    }
    if(add[i] == 1 && add[i+1] == 0 && add[i+2] == 1 && add[i+3] == 1){
        checksum[checkCount] = 'b';
        checkCount++;
    }
    if(add[i] == 1 && add[i+1] == 1 && add[i+2] == 0 && add[i+3] == 0){
        checksum[checkCount] = 'c';
        checkCount++;
    }
    if(add[i] == 1 && add[i+1] == 1 && add[i+2] == 0 && add[i+3] == 1){
        checksum[checkCount] = 'd';
        checkCount++;
    }
    if(add[i] == 1 && add[i+1] == 1 && add[i+2] == 1 && add[i+3] == 0){
        checksum[checkCount] = 'e';
        checkCount++;
    }
    if(add[i] == 1 && add[i+1] == 1 && add[i+2] == 1 && add[i+3] == 1){
        checksum[checkCount] = 'f';
        checkCount++;
    }

    i = i + 3;
    return i;
}

//KG: prints to the screen and an output file the binary number
void printBinary(int bin[], int check, FILE *ofp){
    for(int i = 0; i < check; i++){
        printf("%d", bin[i]);
        fprintf(ofp, "%d", bin[i]);
    }
    printf("\n");
    fprintf(ofp, "\n");
}

//KG: adds binary numbers together and stores the result in an array called add
void addBinary(int b1[], int b2[], int check, int add[]){
    int carry = 0;

    for(int i = check - 1; i >= 0; i--){
        //KG: both 0's case
        if(b1[i] == 0 && b2[i] == 0){
            if(carry == 0){
                add[i] = 0;
                carry = 0;
            }
            else{
               add[i] = 1;
                carry = 0;
            }
        }
        //KG: one 0 and one 1
        else if(b1[i] == 0 && b2[i] == 1){
            if(carry == 0){
                add[i] = 1;
                carry = 0;
            }
            else{
                add[i] = 0;
                carry = 1;
            }
        }
        //KG: one 1 and one 0
        else if(b1[i] == 1 && b2[i] == 0){
            if(carry == 0){
                add[i] = 1;
                carry = 0;
            }
            else{
                add[i] = 0;
                carry = 1;
            }
        }
        //KG: both 1's case
        else{
            if(carry == 0){
                add[i] = 0;
                carry = 1;
            }
            else{
                add[i] = 1;
                carry = 1;
            }
        }
    }
}

//KG: prints to the screen and an output file the checksum
void printCheck(FILE *ofp){
    for(int i = 0; i < checkCount; i++){
        printf("%c", checksum[i]);
        fprintf(ofp, "%c", checksum[i]);
    }
    printf("\n");
    fprintf(ofp, "\n");
}

//KG: checks how many 'X' to pad in a 16 and 32 bit checksum
void checkPad(int check){
    if(check == 16){
        //KG: if the inputSize is odd, there is a pad needed
        if(inputSize % 2 != 0){
            hex[hexSize] = '5';
            hex[hexSize + 1] = '8';
            hexSize = hexSize + 2;
            pad++;
            inputSize++;
        }
    }

    if(check == 32){
        //KG: if inputSize is a multiple of 4, then no pad is needed
        if((inputSize & 3) == 0){
            return;
        }
        else{
            //KG: get the number of padding needed
            int temp = inputSize;
            while((temp & 3) != 0){
                temp = temp + 1;
                pad++;
            }

            if(pad == 1){
                hex[hexSize] = '5';
                hex[hexSize + 1] = '8';
                hexSize = hexSize + 2;
                inputSize++;
            }
            if(pad == 2){
                hex[hexSize] = '5';
                hex[hexSize + 1] = '8';
                hex[hexSize + 2] = '5';
                hex[hexSize + 3] = '8';
                hexSize = hexSize + 4;
                inputSize = inputSize + 2;
            }
            if(pad == 3){
                hex[hexSize] = '5';
                hex[hexSize + 1] = '8';
                hex[hexSize + 2] = '5';
                hex[hexSize + 3] = '8';
                hex[hexSize + 4] = '5';
                hex[hexSize + 5] = '8';
                hexSize = hexSize + 6;
                inputSize = inputSize + 3;
            }
        }
    }
}

//KG: 8 bit checksum
void eightChecksum(){
    int check = 8;

    //KG: keep track of index in hex array
    int count = 0;
    int input = 0;
    int binary1[7] = {};
    int binary2[7] = {};
    //KG: sum of binary being stored here
    int add[7] = {};

    //KG: one character (and new line) case
    for(int i = 0; i < 2; i++){
        getBinaryRep(hex[i], binary1, input);
        input = input + 4;
        count++;
    }
    input = 0;
    for(int j = count; j < count + 2; j++){
        getBinaryRep(hex[j], binary2, input);
        input = input + 4;
    }
    count = count + 2;

    addBinary(binary1, binary2, check, add);

    //KG: more than one character case
    if(inputSize > 2){
        while(hex[count] != 0){
            //reset
            memset(binary1, '\0', sizeof binary1);
            memset(binary2, '\0', sizeof binary2);

            //KG: copies add array into binary1 array to keep adding
            for(int i = 0; i < check; i++){
                binary1[i] = add[i];
            }

            memset(add, '\0', sizeof add);

            input = 0;
            for(int k = count; k < count + 2; k++){
                getBinaryRep(hex[k], binary2, input);
                input = input + 4;
            }
            count = count + 2;

            addBinary(binary1, binary2, check, add);
        }
    }

    //KG: get the hex representation
    for(int i = 0; i < check; i++){
        i = getHexRep(i, add);
    }

}

//KG: 16 bit checksum
void sixteenChecksum(){
    int check = 16;

    //KG: keep track of index in hex array
    int count = 0;
    int input = 0;
    int binary1[15] = {};
    int binary2[15] = {};
    //KG: sum of binary being stored here
    int add[15] = {};

    //KG: check if pad is needed
    checkPad(check);

    //KG: base case
    if(inputSize == 2){
      for(int i = 0; i < 4; i++){
            getBinaryRep(hex[i], binary1, input);
            input = input + 4;
            count++;
        }

        //KG: get the hex representation
        for(int i = 0; i < check; i++){
            i = getHexRep(i, binary1);
        }
    }
    else{
        //KG: do the first calculation
        for(int i = 0; i < 4; i++){
            getBinaryRep(hex[i], binary1, input);
            input = input + 4;
            count++;
        }
        input = 0;
        for(int j = count; j < count + 4; j++){
            getBinaryRep(hex[j], binary2, input);
            input = input + 4;
        }
        count = count + 4;

        addBinary(binary1, binary2, check, add);

        while(hex[count] != 0){
            //reset
            memset(binary1, '\0', sizeof binary1);
            memset(binary2, '\0', sizeof binary2);

            //KG: copies add array into binary1 array to keep adding
            for(int i = 0; i < check; i++){
                binary1[i] = add[i];
            }

            memset(add, '\0', sizeof add);

            input = 0;
            for(int k = count; k < count + 4; k++){
                getBinaryRep(hex[k], binary2, input);
                input = input + 4;
            }
            count = count + 4;

            addBinary(binary1, binary2, check, add);
        }

        //KG: get the hex representation
        for(int i = 0; i < check; i++){
            i = getHexRep(i, add);
        }
    }
}

//KG: 32 bit checksum
void thirtytwoChecksum(){
    int check = 32;

    //KG: keep track of index in hex array
    int count = 0;
    int input = 0;
    int binary1[31] = {};
    int binary2[31] = {};
    //KG: sum of binary being stored here
    int add[31] = {};

    //KG: check if pad is needed
    checkPad(check);

    //KG: base cases
    if(inputSize == 2 || inputSize == 3 || inputSize == 4){
      for(int i = 0; i < 8; i++){
            getBinaryRep(hex[i], binary1, input);
            input = input + 4;
            count++;
        }

        //KG: get the hex representation
        for(int i = 0; i < check; i++){
            i = getHexRep(i, binary1);
        }
    }
    else{
        //KG: do the first calculation
        for(int i = 0; i < 8; i++){
            getBinaryRep(hex[i], binary1, input);
            input = input + 4;
            count++;
        }
        input = 0;
        for(int j = count; j < count + 8; j++){
            getBinaryRep(hex[j], binary2, input);
            input = input + 4;
        }
        count = count + 8;

        addBinary(binary1, binary2, check, add);

        while(hex[count] != 0){
            //reset
            memset(binary1, '\0', sizeof binary1);
            memset(binary2, '\0', sizeof binary2);

            //KG: copies add array into binary1 array to keep adding
            for(int i = 0; i < check; i++){
                binary1[i] = add[i];
            }

            memset(add, '\0', sizeof add);

            input = 0;
            for(int k = count; k < count + 8; k++){
                getBinaryRep(hex[k], binary2, input);
                input = input + 4;
            }
            count = count + 8;

            addBinary(binary1, binary2, check, add);
        }

        //KG: get the hex representation
        for(int i = 0; i < check; i++){
            i = getHexRep(i, add);
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *ifp = fopen(argv[1], "r");
    FILE *ofp = fopen("output.txt", "w");
    char *temp = argv[2];
    int check = atoi(temp);
    readInput(ifp);

    int error = 0;

    printf("\n");
    fprintf(ofp, "\n");
    printInputArr(ofp);

    createHexArray();

    if(check == 8){
        eightChecksum();
    }
    else if(check == 16){
        sixteenChecksum();
    }
    else if(check == 32){
        thirtytwoChecksum();
    }
    else{
        printf("\n");
        fprintf(ofp, "\n");
        fprintf(ofp, "Valid checksum sizes are 8, 16, or 32\n");
        fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
        error = 1;
    }

    if(error != 1){

       if(pad == 1){
            printf("X\n");
            fprintf(ofp, "X\n");
        }
        else if(pad == 2){
            printf("XX\n");
            fprintf(ofp, "XX\n");
        }
        else if(pad == 3){
            printf("XXX\n");
            fprintf(ofp, "XXX\n");
        }
        else{
            printf("\n");
            fprintf(ofp, "\n");
        }

        printf("%2d bit checksum is ", check);
        fprintf(ofp, "%2d bit checksum is ", check);
        for(int i = 0; i < 8 - checkCount; i++){
            printf(" ");
            fprintf(ofp, " ");
        }
        for(int j = 0; checksum[j] != 0; j++){
            printf("%c", checksum[j]);
            fprintf(ofp, "%c", checksum[j]);
        }
        printf(" for all %4d chars\n", inputSize);
        fprintf(ofp, " for all %4d chars\n", inputSize);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}

/*========================================================================
|   I, Katelyn Grimes (ka685531), affirm that this program is entirely
| my own work and that I have neither developed my code together with
| any other person, nor copied any code from any other person, nor
| permitted my code to be copied or otherwise used by any other person,
| nor have I copied, modified, or otherwise used programs created by
| others. I acknowledge that any violation of the above terms will be
| treated as academic dishonesty.
========================================================================*/
