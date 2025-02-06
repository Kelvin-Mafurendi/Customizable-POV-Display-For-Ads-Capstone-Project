#include "mbed.h"
#include "ShiftOut.h"
#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>


// ***** Object definitions *****
BufferedSerial blueTooth(PB_6, PA_10);//BufferedSerial object for HC‐0X bluetooth module (PC10=Tx pin; PC11=Rx pin)
ShiftOut povRightRed(PA_8, PA_9, PC_7, PB_8, PA_7);
ShiftOut povRightGreen(PB_10, PA_9, PC_7, PB_8, PA_7);
ShiftOut povRightBlue(PB_4, PA_9, PC_7, PB_8, PA_7);
ShiftOut povLeftRed(PA_6, PB_5, PB_3, PB_8, PA_7);
ShiftOut povLeftGreen(PA_5, PB_5, PB_3, PB_8, PA_7);
ShiftOut povLeftBlue(PB_9, PB_5, PB_3,PB_8, PA_7);

//enum Message_state {Message, String, Shift};
//Message_state state;
char newString[10] = " ";//user input to be splitted
char newString2[10] = " ";//user input to be splitted

int colour = 2;
int colour2 =2;
bool newMsgFlag = false;

char a;

//arrays for letter 'A'
char arrA1[] = {0,1,1,1,1,1,1,1,0};
char arrA2[] = {0,0,0,0,1,0,0,0,1};
char arrA3[] = {0,0,0,0,1,0,0,0,1};
char arrA4[] = {0,0,0,0,1,0,0,0,1};
char arrA5[] = {0,1,1,1,1,1,1,1,0};

// Arrays for letter 'B'
char arrB1[] = {0,0,1,1,1,0,1,1,0};
char arrB2[] = {0,1,0,0,0,1,0,0,1};
char arrB3[] = {0,1,0,0,0,1,0,0,1};
char arrB4[] = {0,1,0,0,0,1,0,0,1};
char arrB5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'C'
char arrC1[] = {0,0,1,0,0,0,0,1,0};
char arrC2[] = {0,1,0,0,0,0,0,0,1};
char arrC3[] = {0,1,0,0,0,0,0,0,1};
char arrC4[] = {0,1,0,0,0,0,0,0,1};
char arrC5[] = {0,0,1,1,1,1,1,1,0};

// Arrays for letter 'D'
char arrD1[] = {0,0,1,1,1,1,1,1,0};
char arrD2[] = {0,1,0,0,0,0,0,0,1};
char arrD3[] = {0,1,0,0,0,0,0,0,1};
char arrD4[] = {0,1,1,1,1,1,1,1,1};
char arrD5[] = {0,0,0,0,0,0,0,0,0};

// Arrays for letter 'E'
char arrE1[] = {0,1,0,0,0,1,0,0,1};
char arrE2[] = {0,1,0,0,0,1,0,0,1};
char arrE3[] = {0,1,0,0,0,1,0,0,1};
char arrE4[] = {0,1,0,0,0,1,0,0,1};
char arrE5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'F'
char arrF1[] = {0,0,0,0,0,1,0,0,1};
char arrF2[] = {0,0,0,0,0,1,0,0,1};
char arrF3[] = {0,0,0,0,0,1,0,0,1};
char arrF4[] = {0,0,0,0,0,1,0,0,1};
char arrF5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'G'
char arrG1[] = {0,1,1,1,1,1,0,0,1};
char arrG2[] = {0,1,0,0,0,1,0,0,1};
char arrG3[] = {0,1,0,0,0,0,0,0,1};
char arrG4[] = {0,1,0,0,0,0,0,0,1};
char arrG5[] = {0,1,1,1,1,1,1,1,0};

// Arrays for letter 'H'
char arrH1[] = {0,1,1,1,1,1,1,1,1};
char arrH2[] = {0,0,0,0,1,0,0,0,0};
char arrH3[] = {0,0,0,0,1,0,0,0,0};
char arrH4[] = {0,0,0,0,1,0,0,0,0};
char arrH5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'I'
char arrI1[] = {0,0,0,0,0,0,0,0,0};
char arrI2[] = {0,1,0,0,0,0,0,0,1};
char arrI3[] = {0,1,1,1,1,1,1,1,1};
char arrI4[] = {0,1,0,0,0,0,0,0,1};
char arrI5[] = {0,0,0,0,0,0,0,0,0};

// Arrays for letter 'J'
char arrJ1[] = {0,0,0,0,0,0,0,0,0};
char arrJ2[] = {0,1,0,0,0,0,0,0,1};
char arrJ3[] = {0,1,1,1,1,1,1,1,1};
char arrJ4[] = {0,1,0,0,0,0,0,0,1};
char arrJ5[] = {0,1,0,0,0,0,0,0,0};

// Arrays for letter 'K'
char arrK1[] = {0,0,0,0,0,0,0,0,0};
char arrK2[] = {0,1,1,0,0,0,0,1,1};
char arrK3[] = {0,0,0,1,0,0,1,0,0};
char arrK4[] = {0,0,0,0,1,1,0,0,0};
char arrK5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'L'
char arrL1[] = {0,1,0,0,0,0,0,0,0};
char arrL2[] = {0,1,0,0,0,0,0,0,};
char arrL3[] = {0,1,0,0,0,0,0,0,0};
char arrL4[] = {0,1,1,1,1,1,1,1,1};
char arrL5[] = {0,0,0,0,0,0,0,0,0};

// Arrays for letter 'M'
char arrM1[] = {0,1,1,1,1,1,1,1,1};
char arrM2[] = {0,0,0,0,0,0,0,1,1};
char arrM3[] = {0,0,0,0,1,1,1,0,0};
char arrM4[] = {0,0,0,0,0,0,0,1,1};
char arrM5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'N'
char arrN1[] = {0,1,1,1,1,1,1,1,1};
char arrN2[] = {0,1,1,1,0,0,0,0,0};
char arrN3[] = {0,0,0,0,1,1,0,0,0};
char arrN4[] = {0,0,0,0,0,0,1,1,1};
char arrN5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'O'
char arrO1[] = {0,0,1,1,1,1,1,1,0};
char arrO2[] = {0,1,0,0,0,0,0,0,1};
char arrO3[] = {0,1,0,0,0,0,0,0,1};
char arrO4[] = {0,1,0,0,0,0,0,0,1};
char arrO5[] = {0,0,1,1,1,1,1,1,0};

// Arrays for letter 'P'
char arrP1[] = {0,0,0,0,0,1,1,1,0};
char arrP2[] = {0,0,0,0,1,0,0,0,1};
char arrP3[] = {0,0,0,0,1,0,0,0,1};
char arrP4[] = {0,1,1,1,1,1,1,1,1};
char arrP5[] = {0,0,0,0,0,0,0,0,0};

// Arrays for letter 'Q'
char arrQ1[] = {0,0,0,1,1,1,1,1,0};
char arrQ2[] = {0,0,1,0,0,0,0,0,1};
char arrQ3[] = {0,1,1,1,0,0,0,0,1};
char arrQ4[] = {0,0,1,0,1,0,0,0,1};
char arrQ5[] = {0,0,0,1,1,1,1,1,0};

// Arrays for letter 'R'
char arrR1[] = {0,1,0,0,0,1,1,1,0};
char arrR2[] = {0,0,1,0,1,0,0,0,1};
char arrR3[] = {0,0,0,1,1,0,0,0,1};
char arrR4[] = {0,0,0,0,1,0,0,0,1};
char arrR5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'S'
char arrS1[] = {0,0,0,0,0,0,0,0,0};
char arrS2[] = {0,0,1,1,1,0,0,0,1};
char arrS3[] = {0,1,0,0,1,0,0,0,1};
char arrS4[] = {0,1,0,0,1,0,0,0,1};
char arrS5[] = {0,1,0,0,0,1,1,1,0};

// Arrays for letter 'T'
char arrT1[] = {0,0,0,0,0,0,0,0,1};
char arrT2[] = {0,0,0,0,0,0,0,0,1};
char arrT3[] = {0,1,1,1,1,1,1,1,1};
char arrT4[] = {0,0,0,0,0,0,0,0,1};
char arrT5[] = {0,0,0,0,0,0,0,0,1};

// Arrays for letter 'U'
char arrU1[] = {0,0,1,1,1,1,1,1,1};
char arrU2[] = {0,1,0,0,0,0,0,0,0};
char arrU3[] = {0,1,0,0,0,0,0,0,0};
char arrU4[] = {0,1,0,0,0,0,0,0,0};
char arrU5[] = {0,0,1,1,1,1,1,1,1};

// Arrays for letter 'V'
char arrV1[] = {0,0,0,0,0,0,0,1,1};
char arrV2[] = {0,0,0,0,0,1,1,0,0};
char arrV3[] = {0,0,0,1,1,0,0,0,0};
char arrV4[] = {0,1,1,0,0,0,0,0,0};
char arrV5[] = {0,0,0,1,1,0,0,0,0};
char arrV6[] = {0,0,0,0,0,1,1,0,0};
char arrV7[] = {0,0,0,0,0,0,0,1,1};

// Arrays for letter 'W'
char arrW1[] = {0,1,1,1,1,1,1,1,1};
char arrW2[] = {0,1,1,0,0,0,0,0,0};
char arrW3[] = {0,0,0,1,1,1,0,0,0};
char arrW4[] = {0,1,1,0,0,0,0,0,0};
char arrW5[] = {0,1,1,1,1,1,1,1,1};

// Arrays for letter 'X'
char arrX1[] = {0,1,1,1,0,0,1,1,1};
char arrX2[] = {0,0,0,0,1,1,0,0,0};
char arrX3[] = {0,1,1,1,0,0,1,1,1};
char arrX4[] = {0,0,0,0,0,0,0,0,0};
char arrX5[] = {0,0,0,0,0,0,0,0,0};

// Arrays for letter 'Y'
char arrY1[] = {0,0,0,0,0,0,0,1,1};
char arrY2[] = {0,0,0,0,0,1,1,0,0};
char arrY3[] = {0,1,1,1,1,0,0,0,0};
char arrY4[] = {0,0,0,0,0,1,1,0,0};
char arrY5[] = {0,0,0,0,0,0,0,1,1};

// Arrays for letter 'Z'
char arrZ1[] = {0,1,0,0,0,0,0,1,1};
char arrZ2[] = {0,1,0,0,0,1,1,0,1};
char arrZ3[] = {0,1,0,1,1,0,0,0,1};
char arrZ4[] = {0,1,1,0,0,0,0,0,1};
char arrZ5[] = {0,0,0,0,0,0,0,0,0};

// Arrays for number '0'
char arr0_1[] = {0,1,1,1,1,1,1,1,0};
char arr0_2[] = {1,0,0,0,0,0,0,0,1};
char arr0_3[] = {1,0,0,0,0,0,0,0,1};
char arr0_4[] = {1,0,0,0,0,0,0,0,1};
char arr0_5[] = {0,1,1,1,1,1,1,1,0};

// Arrays for number '1'
char arr1_1[] = {0,0,0,0,1,0,0,0,0};
char arr1_2[] = {0,0,0,1,1,0,0,0,0};
char arr1_3[] = {0,0,1,1,1,0,0,0,0};
char arr1_4[] = {0,1,0,0,1,0,0,0,0};
char arr1_5[] = {1,1,1,1,1,1,1,1,1};

// Arrays for number '2'
char arr2_1[] = {0,1,1,1,0,0,1,1,0};
char arr2_2[] = {1,0,0,0,0,0,0,0,1};
char arr2_3[] = {0,0,0,0,0,0,0,1,0};
char arr2_4[] = {0,0,0,0,0,0,1,0,0};
char arr2_5[] = {1,1,1,1,1,1,1,1,1};

// Arrays for number '3'
char arr3_1[] = {0,1,1,1,0,0,0,1,0};
char arr3_2[] = {1,0,0,0,0,0,0,0,1};
char arr3_3[] = {0,0,0,0,0,0,1,1,0};
char arr3_4[] = {0,0,0,0,0,0,0,1,0};
char arr3_5[] = {0,1,1,1,0,0,0,0,0};

// Arrays for number '4'
char arr4_1[] = {1,0,0,0,0,0,0,0,1};
char arr4_2[] = {1,0,0,0,0,0,0,0,1};
char arr4_3[] = {1,0,0,0,0,0,0,0,1};
char arr4_4[] = {1,1,1,1,1,1,1,1,1};
char arr4_5[] = {0,0,0,0,0,0,0,0,1};

// Arrays for number '5'
char arr5_1[] = {1,1,1,1,1,1,1,1,0};
char arr5_2[] = {1,0,0,0,0,0,0,0,0};
char arr5_3[] = {1,0,0,0,0,0,0,0,0};
char arr5_4[] = {0,1,1,1,0,0,0,0,0};
char arr5_5[] = {0,0,0,0,0,0,0,0,1};

// Arrays for number '6'
char arr6_1[] = {0,0,0,0,0,0,1,1,0};
char arr6_2[] = {0,0,0,0,0,0,0,0,1};
char arr6_3[] = {0,1,1,1,1,1,1,1,0};
char arr6_4[] = {1,0,0,0,0,0,0,0,1};
char arr6_5[] = {0,1,1,1,1,1,1,1,0};

// Arrays for number '7'
char arr7_1[] = {1,1,1,1,1,1,1,1,1};
char arr7_2[] = {0,0,0,0,0,0,0,1,0};
char arr7_3[] = {0,0,0,0,0,0,0,1,0};
char arr7_4[] = {0,0,0,0,0,0,1,0,0};
char arr7_5[] = {0,0,0,0,0,0,0,0,0};

// Arrays for number '8'
char arr8_1[] = {0,1,1,1,0,0,1,1,0};
char arr8_2[] = {1,0,0,0,0,0,0,0,1};
char arr8_3[] = {0,1,1,1,0,0,1,1,0};
char arr8_4[] = {1,0,0,0,0,0,0,0,1};
char arr8_5[] = {0,1,1,1,0,0,1,1,0};

// Arrays for number '9'
char arr9_1[] = {0,1,1,1,0,0,1,1,0};
char arr9_2[] = {1,0,0,0,0,0,0,0,1};
char arr9_3[] = {0,1,1,1,1,1,1,1,0};
char arr9_4[] = {0,0,0,0,0,0,0,0,1};
char arr9_5[] = {0,0,0,0,0,0,0,0,1};            

// Arrays for Space
char space1[] = {0,0,0,0,0,0,0,0,0};
char space2[] = {0,0,0,0,0,0,0,0,0};
char space3[] = {0,0,0,0,0,0,0,0,0};
char space4[] = {0,0,0,0,0,0,0,0,0};
char space5[] = {0,0,0,0,0,0,0,0,0};            


int columnData[8][5];
//Variable for the Individual Characters of the received message for coloumn 1
char a0;
char a1;
char a2;
char a3;
char a4;
char a5;
char a6;
char a7;
char a8;
char a9;
//Variable for the Individual Characters of the received message for coloumn 2
char aa;
char ab;
char ac;
char ad;
char ae;
char af;
char ag;
char ah;
char ai;
char aj;

void alphaR(char letter){
letter = toupper(letter);

switch(letter){
    case 'A':{
        if (colour == 1) { // Red
            povRightRed.writeArrayRight(arrA1);
            //povLeftRed.writeArrayRight(arrA1);
            wait_us(4000);
            povRightRed.writeArrayRight(arrA2);
            //povLeftRed.writeArrayRight(arrA2);
            wait_us(4000);
            povRightRed.writeArrayRight(arrA3);
            //povLeftRed.writeArrayRight(arrA3);
            wait_us(4000);
            povRightRed.writeArrayRight(arrA4);
            //povLeftRed.writeArrayRight(arrA4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrA5);
            //povLeftRed.writeArrayRight(arrA5);
            wait_us(4000);
        } else if (colour == 2) { // Green
            povRightGreen.writeArrayRight(arrA1);
            wait_us(4000);
            //povLeftGreen.writeArrayRight(arrA2);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrA3);
            wait_us(4000);
            //povLeftGreen.writeArrayRight(arrA4);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrA5);
            wait_us(4000);
            /*//povLeftGreen.writeArrayRight(arrA3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrA4);
            //povLeftGreen.writeArrayRight(arrA4);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrA5);
            //povLeftGreen.writeArrayRight(arrA5);*/
        } else if (colour == 3) { // Blue
            povRightBlue.writeArrayRight(arrA1);
            //povLeftBlue.writeArrayRight(arrA1);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrA2);
            //povLeftBlue.writeArrayRight(arrA2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrA3);
            //povLeftBlue.writeArrayRight(arrA3);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrA4);
            //povLeftBlue.writeArrayRight(arrA4);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrA5);
            //povLeftBlue.writeArrayRight(arrA5);
            wait_us(4000);
        } else { // Disco
            povRightRed.writeArrayRight(arrA1);
            //povLeftRed.writeArrayRight(arrA1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrA2);
            //povLeftGreen.writeArrayRight(arrA2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrA3);
            //povLeftBlue.writeArrayRight(arrA3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrA4);
            //povLeftGreen.writeArrayRight(arrA4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrA5);
            //povLeftRed.writeArrayRight(arrA5);
            wait_us(4000);
        }
        break;
case 'B':
        if (colour == 1) { // Red
            povRightRed.writeArrayRight(arrB1);
            //povLeftRed.writeArrayRight(arrB1);
            wait_us(4000);
            povRightRed.writeArrayRight(arrB2);
            //povLeftRed.writeArrayRight(arrB2);
            wait_us(4000);
            povRightRed.writeArrayRight(arrB3);
            //povLeftRed.writeArrayRight(arrB3);
            wait_us(4000);
            povRightRed.writeArrayRight(arrB4);
            //povLeftRed.writeArrayRight(arrB4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrB5);
            //povLeftRed.writeArrayRight(arrB5);
            wait_us(4000);
        } else if (colour == 2) { // Green
            povRightGreen.writeArrayRight(arrB1);
            //povLeftGreen.writeArrayRight(arrB1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrB2);
            //povLeftGreen.writeArrayRight(arrB2);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrB3);
            //povLeftGreen.writeArrayRight(arrB3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrB4);
            //povLeftGreen.writeArrayRight(arrB4);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrB5);
            //povLeftGreen.writeArrayRight(arrB5);
            wait_us(4000);
        } else if (colour == 3) { // Blue
            povRightBlue.writeArrayRight(arrB1);
            //povLeftBlue.writeArrayRight(arrB1);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrB2);
            //povLeftBlue.writeArrayRight(arrB2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrB3);
            //povLeftBlue.writeArrayRight(arrB3);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrB4);
            //povLeftBlue.writeArrayRight(arrB4);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrB5);
            //povLeftBlue.writeArrayRight(arrB5);
            wait_us(4000);
        } else { // Disco
            povRightRed.writeArrayRight(arrB1);
            //povLeftRed.writeArrayRight(arrB1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrB2);
            //povLeftGreen.writeArrayRight(arrB2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrB3);
            //povLeftBlue.writeArrayRight(arrB3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrB4);
            //povLeftGreen.writeArrayRight(arrB4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrB5);
            //povLeftRed.writeArrayRight(arrB5);
            wait_us(4000);
        }
        break;

    case 'C':
        if (colour == 1) { // Red
            povRightRed.writeArrayRight(arrC1);
            //povLeftRed.writeArrayRight(arrC1);
            wait_us(4000);
            povRightRed.writeArrayRight(arrC2);
            //povLeftRed.writeArrayRight(arrC2);
            wait_us(4000);
            povRightRed.writeArrayRight(arrC3);
            //povLeftRed.writeArrayRight(arrC3);
            wait_us(4000);
            povRightRed.writeArrayRight(arrC4);
            //povLeftRed.writeArrayRight(arrC4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrC5);
            //povLeftRed.writeArrayRight(arrC5);
            wait_us(4000);
        } else if (colour == 2) { // Green
            povRightGreen.writeArrayRight(arrC1);
            //povLeftGreen.writeArrayRight(arrC1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrC2);
            //povLeftGreen.writeArrayRight(arrC2);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrC3);
            //povLeftGreen.writeArrayRight(arrC3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrC4);
            //povLeftGreen.writeArrayRight(arrC4);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrC5);
            //povLeftGreen.writeArrayRight(arrC5);
            wait_us(4000);
        } else if (colour == 3) { // Blue
            povRightBlue.writeArrayRight(arrC1);
            //povLeftBlue.writeArrayRight(arrC1);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrC2);
            //povLeftBlue.writeArrayRight(arrC2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrC3);
            //povLeftBlue.writeArrayRight(arrC3);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrC4);
            //povLeftBlue.writeArrayRight(arrC4);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrC5);
            //povLeftBlue.writeArrayRight(arrC5);
            wait_us(4000);
        } else { // Disco
            povRightRed.writeArrayRight(arrC1);
            //povLeftRed.writeArrayRight(arrC1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrC2);
            //povLeftGreen.writeArrayRight(arrC2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrC3);
            //povLeftBlue.writeArrayRight(arrC3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrC4);
            //povLeftGreen.writeArrayRight(arrC4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrC5);
            //povLeftRed.writeArrayRight(arrC5);
            wait_us(4000);
        }
        break;

    case 'D':
        if (colour == 1) { // Red
            povRightRed.writeArrayRight(arrD1);
            //povLeftRed.writeArrayRight(arrD1);
            wait_us(4000);
            povRightRed.writeArrayRight(arrD2);
            //povLeftRed.writeArrayRight(arrD2);
            wait_us(4000);
            povRightRed.writeArrayRight(arrD3);
            //povLeftRed.writeArrayRight(arrD3);
            wait_us(4000);
            povRightRed.writeArrayRight(arrD4);
            //povLeftRed.writeArrayRight(arrD4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrD5);
            //povLeftRed.writeArrayRight(arrD5);
            wait_us(4000);
        } else if (colour == 2) { // Green
            povRightGreen.writeArrayRight(arrD1);
            //povLeftGreen.writeArrayRight(arrD1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrD2);
            //povLeftGreen.writeArrayRight(arrD2);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrD3);
            //povLeftGreen.writeArrayRight(arrD3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrD4);
            //povLeftGreen.writeArrayRight(arrD4);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrD5);
            //povLeftGreen.writeArrayRight(arrD5);
            wait_us(4000);
        } else if (colour == 3) { // Blue
            povRightBlue.writeArrayRight(arrD1);
            //povLeftBlue.writeArrayRight(arrD1);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrD2);
            //povLeftBlue.writeArrayRight(arrD2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrD3);
            //povLeftBlue.writeArrayRight(arrD3);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrD4);
            //povLeftBlue.writeArrayRight(arrD4);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrD5);
            //povLeftBlue.writeArrayRight(arrD5);
            wait_us(4000);
        } else { // Disco
            povRightRed.writeArrayRight(arrD1);
            //povLeftRed.writeArrayRight(arrD1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrD2);
            //povLeftGreen.writeArrayRight(arrD2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrD3);
            //povLeftBlue.writeArrayRight(arrD3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrD4);
            //povLeftGreen.writeArrayRight(arrD4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrD5);
            //povLeftRed.writeArrayRight(arrD5);
            wait_us(4000);
        }
        break;

    case 'E':
        if (colour == 1) { // Red
            povRightRed.writeArrayRight(arrE1);
            //povLeftRed.writeArrayRight(arrE1);
            wait_us(4000);
            povRightRed.writeArrayRight(arrE2);
            //povLeftRed.writeArrayRight(arrE2);
            wait_us(4000);
            povRightRed.writeArrayRight(arrE3);
            //povLeftRed.writeArrayRight(arrE3);
            wait_us(4000);
            povRightRed.writeArrayRight(arrE4);
            //povLeftRed.writeArrayRight(arrE4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrE5);
            //povLeftRed.writeArrayRight(arrE5);
            wait_us(4000);


            
        } else if (colour == 2) { // Green
           povRightGreen.writeArrayRight(arrE1);
            //povLeftGreen.writeArrayRight(arrE1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrE2);
            //povLeftGreen.writeArrayRight(arrE2);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrE3);
            //povLeftGreen.writeArrayRight(arrE3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrE4);
            //povLeftGreen.writeArrayRight(arrE4);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrE5);
            //povLeftGreen.writeArrayRight(arrE5);
            wait_us(4000);
        } else if (colour == 3) { // Blue
            povRightBlue.writeArrayRight(arrE1);
            //povLeftBlue.writeArrayRight(arrE1);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrE2);
            //povLeftBlue.writeArrayRight(arrE2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrE3);
            //povLeftBlue.writeArrayRight(arrE3);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrE4);
            //povLeftBlue.writeArrayRight(arrE4);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrE5);
            //povLeftBlue.writeArrayRight(arrE5);
            wait_us(4000);
            
        }
        else { // Disco
            povRightRed.writeArrayRight(arrE1);
            //povLeftRed.writeArrayRight(arrE1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrE2);
            //povLeftGreen.writeArrayRight(arrE2);
            wait_us(4000);
             povRightBlue.writeArrayRight(arrE3);
            //povLeftBlue.writeArrayRight(arrE3);
            wait_us(4000);
             povRightGreen.writeArrayRight(arrE4);
            //povLeftGreen.writeArrayRight(arrE4);
            wait_us(4000);
             povRightRed.writeArrayRight(arrE5);
            //povLeftRed.writeArrayRight(arrE5);
            wait_us(4000);
            
        }
        break;

    case 'F':
        if (colour == 1) { // Red
            povRightRed.writeArrayRight(arrF1);
            //povLeftRed.writeArrayRight(arrF1);
            wait_us(4000);
            povRightRed.writeArrayRight(arrF2);
            //povLeftRed.writeArrayRight(arrF2);
            wait_us(4000);
            povRightRed.writeArrayRight(arrF3);
            //povLeftRed.writeArrayRight(arrF3);
            wait_us(4000);
            povRightRed.writeArrayRight(arrF4);
            //povLeftRed.writeArrayRight(arrF4);
            wait_us(4000);
            povRightRed.writeArrayRight(arrF5);
            //povLeftRed.writeArrayRight(arrF5);
            wait_us(4000);
            
        } else if (colour == 2) { // Green
            povRightGreen.writeArrayRight(arrF1);
            //povLeftGreen.writeArrayRight(arrF1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrF2);
            //povLeftGreen.writeArrayRight(arrF2);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrF3);
            //povLeftGreen.writeArrayRight(arrF3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrF4);
            //povLeftGreen.writeArrayRight(arrF4);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrF5);
            //povLeftGreen.writeArrayRight(arrF5);
            wait_us(4000);

        } else if (colour == 3) { // Blue
            povRightBlue.writeArrayRight(arrF1);
            //povLeftBlue.writeArrayRight(arrF1);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrF2);
            //povLeftBlue.writeArrayRight(arrF2);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrF3);
            //povLeftBlue.writeArrayRight(arrF3);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrF4);
            //povLeftBlue.writeArrayRight(arrF4);
            wait_us(4000);
            povRightBlue.writeArrayRight(arrF5);
            //povLeftBlue.writeArrayRight(arrF5);
            wait_us(4000);
            
        } else { // Disco
            povRightBlue.writeArrayRight(arrF1);
            //povLeftBlue.writeArrayRight(arrF1);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrF2);
            //povLeftGreen.writeArrayRight(arrF2);
            wait_us(4000);
            povRightRed.writeArrayRight(arrF3);
            //povLeftBlue.writeArrayRight(arrF3);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrF4);
            //povLeftBlue.writeArrayRight(arrF4);
            wait_us(4000);
            povRightGreen.writeArrayRight(arrF5);
            //povLeftRed.writeArrayRight(arrF5);
            wait_us(4000);
            
        }
        break;

   case 'G':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrG1);
        //povLeftRed.writeArrayRight(arrG1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrG2);
        //povLeftRed.writeArrayRight(arrG2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrG3);
        //povLeftRed.writeArrayRight(arrG3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrG4);
        //povLeftRed.writeArrayRight(arrG4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrG5);
        //povLeftRed.writeArrayRight(arrG5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrG1);
        //povLeftGreen.writeArrayRight(arrG1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrG2);
        //povLeftGreen.writeArrayRight(arrG2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrG3);
        //povLeftGreen.writeArrayRight(arrG3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrG4);
        //povLeftGreen.writeArrayRight(arrG4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrG5);
        //povLeftGreen.writeArrayRight(arrG5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrG1);
        //povLeftBlue.writeArrayRight(arrG1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrG2);
        //povLeftBlue.writeArrayRight(arrG2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrG3);
        //povLeftBlue.writeArrayRight(arrG3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrG4);
        //povLeftBlue.writeArrayRight(arrG4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrG5);
        //povLeftBlue.writeArrayRight(arrG5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrG1);
        //povLeftBlue.writeArrayRight(arrG1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrG2);
        //povLeftBlue.writeArrayRight(arrG2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrG3);
        //povLeftRed.writeArrayRight(arrG3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrG4);
        //povLeftRed.writeArrayRight(arrG4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrG5);
        //povLeftRed.writeArrayRight(arrG5);
        wait_us(4000);
    }
    break;

    case 'H':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrH1);
        //povLeftRed.writeArrayRight(arrH1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrH2);
        //povLeftRed.writeArrayRight(arrH2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrH3);
        //povLeftRed.writeArrayRight(arrH3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrH4);
        //povLeftRed.writeArrayRight(arrH4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrH5);
        //povLeftRed.writeArrayRight(arrH5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrH1);
        //povLeftGreen.writeArrayRight(arrH1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrH2);
        //povLeftGreen.writeArrayRight(arrH2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrH3);
        //povLeftGreen.writeArrayRight(arrH3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrH4);
        //povLeftGreen.writeArrayRight(arrH4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrH5);
        //povLeftGreen.writeArrayRight(arrH5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrH1);
        //povLeftBlue.writeArrayRight(arrH1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrH2);
        //povLeftBlue.writeArrayRight(arrH2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrH3);
        //povLeftBlue.writeArrayRight(arrH3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrH4);
        //povLeftBlue.writeArrayRight(arrH4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrH5);
        //povLeftBlue.writeArrayRight(arrH5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrH1);
        //povLeftBlue.writeArrayRight(arrH1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrH2);
        //povLeftBlue.writeArrayRight(arrH2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrH3);
        //povLeftRed.writeArrayRight(arrH3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrH4);
        //povLeftRed.writeArrayRight(arrH4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrH5);
        //povLeftBlue.writeArrayRight(arrH5);
        wait_us(4000);
    }
    break;

    case 'I':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrI1);
        //povLeftRed.writeArrayRight(arrI1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrI2);
        //povLeftRed.writeArrayRight(arrI2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrI3);
        //povLeftRed.writeArrayRight(arrI3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrI4);
        //povLeftRed.writeArrayRight(arrI4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrI5);
        //povLeftRed.writeArrayRight(arrI5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrI1);
        //povLeftGreen.writeArrayRight(arrI1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrI2);
        //povLeftGreen.writeArrayRight(arrI2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrI3);
        //povLeftGreen.writeArrayRight(arrI3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrI4);
        //povLeftGreen.writeArrayRight(arrI4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrI5);
        //povLeftGreen.writeArrayRight(arrI5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrI1);
        //povLeftBlue.writeArrayRight(arrI1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrI2);
        //povLeftBlue.writeArrayRight(arrI2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrI3);
        //povLeftBlue.writeArrayRight(arrI3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrI4);
        //povLeftBlue.writeArrayRight(arrI4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrI5);
        //povLeftBlue.writeArrayRight(arrI5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrI1);
        //povLeftBlue.writeArrayRight(arrI1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrI2);
        //povLeftBlue.writeArrayRight(arrI2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrI3);
        //povLeftRed.writeArrayRight(arrI3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrI4);
        //povLeftRed.writeArrayRight(arrI4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrI5);
        //povLeftBlue.writeArrayRight(arrI5);
        wait_us(4000);
    }
    break;

   case 'J':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrJ1);
        //povLeftRed.writeArrayRight(arrJ1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrJ2);
        //povLeftRed.writeArrayRight(arrJ2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrJ3);
        //povLeftRed.writeArrayRight(arrJ3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrJ4);
        //povLeftRed.writeArrayRight(arrJ4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrJ5);
        //povLeftRed.writeArrayRight(arrJ5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrJ1);
        //povLeftGreen.writeArrayRight(arrJ1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrJ2);
        //povLeftGreen.writeArrayRight(arrJ2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrJ3);
        //povLeftGreen.writeArrayRight(arrJ3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrJ4);
        //povLeftGreen.writeArrayRight(arrJ4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrJ5);
        //povLeftGreen.writeArrayRight(arrJ5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrJ1);
        //povLeftBlue.writeArrayRight(arrJ1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrJ2);
        //povLeftBlue.writeArrayRight(arrJ2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrJ3);
        //povLeftBlue.writeArrayRight(arrJ3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrJ4);
        //povLeftBlue.writeArrayRight(arrJ4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrJ5);
        //povLeftBlue.writeArrayRight(arrJ5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrJ1);
        //povLeftBlue.writeArrayRight(arrJ1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrJ2);
        //povLeftBlue.writeArrayRight(arrJ2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrJ3);
        //povLeftRed.writeArrayRight(arrJ3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrJ4);
        //povLeftRed.writeArrayRight(arrJ4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrJ5);
        //povLeftBlue.writeArrayRight(arrJ5);
        wait_us(4000);
    }
    break;

case 'K':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrK1);
        //povLeftRed.writeArrayRight(arrK1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrK2);
        //povLeftRed.writeArrayRight(arrK2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrK3);
        //povLeftRed.writeArrayRight(arrK3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrK4);
        //povLeftRed.writeArrayRight(arrK4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrK5);
        //povLeftRed.writeArrayRight(arrK5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrK1);
        //povLeftGreen.writeArrayRight(arrK1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrK2);
        //povLeftGreen.writeArrayRight(arrK2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrK3);
        //povLeftGreen.writeArrayRight(arrK3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrK4);
        //povLeftGreen.writeArrayRight(arrK4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrK5);
        //povLeftGreen.writeArrayRight(arrK5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrK1);
        //povLeftBlue.writeArrayRight(arrK1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrK2);
        //povLeftBlue.writeArrayRight(arrK2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrK3);
        //povLeftBlue.writeArrayRight(arrK3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrK4);
        //povLeftBlue.writeArrayRight(arrK4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrK5);
        //povLeftBlue.writeArrayRight(arrK5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrK1);
        //povLeftBlue.writeArrayRight(arrK1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrK2);
        //povLeftBlue.writeArrayRight(arrK2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrK3);
        //povLeftRed.writeArrayRight(arrK3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrK4);
        //povLeftRed.writeArrayRight(arrK4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrK5);
        //povLeftBlue.writeArrayRight(arrK5);
        wait_us(4000);
    }
    break;

case 'L':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrL1);
        //povLeftRed.writeArrayRight(arrL1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrL2);
        //povLeftRed.writeArrayRight(arrL2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrL3);
        //povLeftRed.writeArrayRight(arrL3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrL4);
        //povLeftRed.writeArrayRight(arrL4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrL5);
        //povLeftRed.writeArrayRight(arrL5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrL1);
        //povLeftGreen.writeArrayRight(arrL1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrL2);
        //povLeftGreen.writeArrayRight(arrL2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrL3);
        //povLeftGreen.writeArrayRight(arrL3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrL4);
        //povLeftGreen.writeArrayRight(arrL4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrL5);
        //povLeftGreen.writeArrayRight(arrL5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrL1);
        //povLeftBlue.writeArrayRight(arrL1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrL2);
        //povLeftBlue.writeArrayRight(arrL2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrL3);
        //povLeftBlue.writeArrayRight(arrL3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrL4);
        //povLeftBlue.writeArrayRight(arrL4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrL5);
        //povLeftBlue.writeArrayRight(arrL5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrL1);
        //povLeftBlue.writeArrayRight(arrL1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrL2);
        //povLeftBlue.writeArrayRight(arrL2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrL3);
        //povLeftRed.writeArrayRight(arrL3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrL4);
        //povLeftRed.writeArrayRight(arrL4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrL5);
        //povLeftBlue.writeArrayRight(arrL5);
        wait_us(4000);
    }
    break;

  case 'M':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrM1);
        //povLeftRed.writeArrayRight(arrM1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrM2);
        //povLeftRed.writeArrayRight(arrM2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrM3);
        //povLeftRed.writeArrayRight(arrM3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrM4);
        //povLeftRed.writeArrayRight(arrM4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrM5);
        //povLeftRed.writeArrayRight(arrM5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrM1);
        //povLeftGreen.writeArrayRight(arrM1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrM2);
        //povLeftGreen.writeArrayRight(arrM2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrM3);
        //povLeftGreen.writeArrayRight(arrM3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrM4);
        //povLeftGreen.writeArrayRight(arrM4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrM5);
        //povLeftGreen.writeArrayRight(arrM5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrM1);
        //povLeftBlue.writeArrayRight(arrM1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrM2);
        //povLeftBlue.writeArrayRight(arrM2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrM3);
        //povLeftBlue.writeArrayRight(arrM3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrM4);
        //povLeftBlue.writeArrayRight(arrM4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrM5);
        //povLeftBlue.writeArrayRight(arrM5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrM1);
        //povLeftBlue.writeArrayRight(arrM1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrM2);
        //povLeftBlue.writeArrayRight(arrM2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrM3);
        //povLeftRed.writeArrayRight(arrM3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrM4);
        //povLeftRed.writeArrayRight(arrM4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrM5);
        //povLeftBlue.writeArrayRight(arrM5);
        wait_us(4000);
    }
    break;

case 'N':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrN1);
        //povLeftRed.writeArrayRight(arrN1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrN2);
        //povLeftRed.writeArrayRight(arrN2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrN3);
        //povLeftRed.writeArrayRight(arrN3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrN4);
        //povLeftRed.writeArrayRight(arrN4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrN5);
        //povLeftRed.writeArrayRight(arrN5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrN1);
        //povLeftGreen.writeArrayRight(arrN1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrN2);
        //povLeftGreen.writeArrayRight(arrN2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrN3);
        //povLeftGreen.writeArrayRight(arrN3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrN4);
        //povLeftGreen.writeArrayRight(arrN4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrN5);
        //povLeftGreen.writeArrayRight(arrN5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrN1);
        //povLeftBlue.writeArrayRight(arrN1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrN2);
        //povLeftBlue.writeArrayRight(arrN2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrN3);
        //povLeftBlue.writeArrayRight(arrN3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrN4);
        //povLeftBlue.writeArrayRight(arrN4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrN5);
        //povLeftBlue.writeArrayRight(arrN5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrN1);
        //povLeftBlue.writeArrayRight(arrN1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrN2);
        //povLeftBlue.writeArrayRight(arrN2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrN3);
        //povLeftRed.writeArrayRight(arrN3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrN4);
        //povLeftRed.writeArrayRight(arrN4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrN5);
        //povLeftBlue.writeArrayRight(arrN5);
        wait_us(4000);
    }
    break;

case 'O':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arrO1);
        //povLeftRed.writeArrayRight(arrO1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrO2);
        //povLeftRed.writeArrayRight(arrO2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrO3);
        //povLeftRed.writeArrayRight(arrO3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrO4);
        //povLeftRed.writeArrayRight(arrO4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrO5);
        //povLeftRed.writeArrayRight(arrO5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arrO1);
        //povLeftGreen.writeArrayRight(arrO1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrO2);
        //povLeftGreen.writeArrayRight(arrO2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrO3);
        //povLeftGreen.writeArrayRight(arrO3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrO4);
        //povLeftGreen.writeArrayRight(arrO4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrO5);
        //povLeftGreen.writeArrayRight(arrO5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arrO1);
        //povLeftBlue.writeArrayRight(arrO1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrO2);
        //povLeftBlue.writeArrayRight(arrO2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrO3);
        //povLeftBlue.writeArrayRight(arrO3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrO4);
        //povLeftBlue.writeArrayRight(arrO4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrO5);
        //povLeftBlue.writeArrayRight(arrO5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arrO1);
        //povLeftBlue.writeArrayRight(arrO1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrO2);
        //povLeftBlue.writeArrayRight(arrO2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrO3);
        //povLeftRed.writeArrayRight(arrO3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrO4);
        //povLeftRed.writeArrayRight(arrO4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrO5);
        //povLeftBlue.writeArrayRight(arrO5);
        wait_us(4000);
    }
    break;

case 'P':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrP1);
        //povLeftRed.writeArrayRight(arrP1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrP2);
        //povLeftRed.writeArrayRight(arrP2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrP3);
        //povLeftRed.writeArrayRight(arrP3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrP4);
        //povLeftRed.writeArrayRight(arrP4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrP5);
        //povLeftRed.writeArrayRight(arrP5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrP1);
        //povLeftGreen.writeArrayRight(arrP1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrP2);
        //povLeftGreen.writeArrayRight(arrP2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrP3);
        //povLeftGreen.writeArrayRight(arrP3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrP4);
        //povLeftGreen.writeArrayRight(arrP4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrP5);
        //povLeftGreen.writeArrayRight(arrP5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrP1);
        //povLeftBlue.writeArrayRight(arrP1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrP2);
        //povLeftBlue.writeArrayRight(arrP2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrP3);
        //povLeftBlue.writeArrayRight(arrP3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrP4);
        //povLeftBlue.writeArrayRight(arrP4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrP5);
        //povLeftBlue.writeArrayRight(arrP5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrP1);
        //povLeftBlue.writeArrayRight(arrP1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrP2);
        //povLeftBlue.writeArrayRight(arrP2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrP3);
        //povLeftRed.writeArrayRight(arrP3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrP4);
        //povLeftRed.writeArrayRight(arrP4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrP5);
        //povLeftBlue.writeArrayRight(arrP5);
        wait_us(4000);
    }
    break;

case 'Q':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrQ1);
        //povLeftRed.writeArrayRight(arrQ1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrQ2);
        //povLeftRed.writeArrayRight(arrQ2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrQ3);
        //povLeftRed.writeArrayRight(arrQ3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrQ4);
        //povLeftRed.writeArrayRight(arrQ4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrQ5);
        //povLeftRed.writeArrayRight(arrQ5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrQ1);
        //povLeftGreen.writeArrayRight(arrQ1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrQ2);
        //povLeftGreen.writeArrayRight(arrQ2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrQ3);
        //povLeftGreen.writeArrayRight(arrQ3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrQ4);
        //povLeftGreen.writeArrayRight(arrQ4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrQ5);
        //povLeftGreen.writeArrayRight(arrQ5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrQ1);
        //povLeftBlue.writeArrayRight(arrQ1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrQ2);
        //povLeftBlue.writeArrayRight(arrQ2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrQ3);
        //povLeftBlue.writeArrayRight(arrQ3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrQ4);
        //povLeftBlue.writeArrayRight(arrQ4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrQ5);
        //povLeftBlue.writeArrayRight(arrQ5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrQ1);
        //povLeftBlue.writeArrayRight(arrQ1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrQ2);
        //povLeftBlue.writeArrayRight(arrQ2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrQ3);
        //povLeftRed.writeArrayRight(arrQ3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrQ4);
        //povLeftRed.writeArrayRight(arrQ4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrQ5);
        //povLeftBlue.writeArrayRight(arrQ5);
        wait_us(4000);
    }
    break;

case 'R':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrR1);
        //povLeftRed.writeArrayRight(arrR1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrR2);
        //povLeftRed.writeArrayRight(arrR2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrR3);
        //povLeftRed.writeArrayRight(arrR3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrR4);
        //povLeftRed.writeArrayRight(arrR4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrR5);
        //povLeftRed.writeArrayRight(arrR5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrR1);
        //povLeftGreen.writeArrayRight(arrR1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrR2);
        //povLeftGreen.writeArrayRight(arrR2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrR3);
        //povLeftGreen.writeArrayRight(arrR3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrR4);
        //povLeftGreen.writeArrayRight(arrR4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrR5);
        //povLeftGreen.writeArrayRight(arrR5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrR1);
        //povLeftBlue.writeArrayRight(arrR1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrR2);
        //povLeftBlue.writeArrayRight(arrR2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrR3);
        //povLeftBlue.writeArrayRight(arrR3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrR4);
        //povLeftBlue.writeArrayRight(arrR4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrR5);
        //povLeftBlue.writeArrayRight(arrR5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrR1);
        //povLeftBlue.writeArrayRight(arrR1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrR2);
        //povLeftBlue.writeArrayRight(arrR2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrR3);
        //povLeftRed.writeArrayRight(arrR3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrR4);
        //povLeftRed.writeArrayRight(arrR4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrR5);
        //povLeftBlue.writeArrayRight(arrR5);
        wait_us(4000);
    }
    break;

case 'S':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrS1);
        //povLeftRed.writeArrayRight(arrS1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrS2);
        //povLeftRed.writeArrayRight(arrS2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrS3);
        //povLeftRed.writeArrayRight(arrS3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrS4);
        //povLeftRed.writeArrayRight(arrS4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrS5);
        //povLeftRed.writeArrayRight(arrS5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrS1);
        //povLeftGreen.writeArrayRight(arrS1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrS2);
        //povLeftGreen.writeArrayRight(arrS2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrS3);
        //povLeftGreen.writeArrayRight(arrS3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrS4);
        //povLeftGreen.writeArrayRight(arrS4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrS5);
        //povLeftGreen.writeArrayRight(arrS5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrS1);
        //povLeftBlue.writeArrayRight(arrS1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrS2);
        //povLeftBlue.writeArrayRight(arrS2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrS3);
        //povLeftBlue.writeArrayRight(arrS3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrS4);
        //povLeftBlue.writeArrayRight(arrS4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrS5);
        //povLeftBlue.writeArrayRight(arrS5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrS1);
        //povLeftBlue.writeArrayRight(arrS1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrS2);
        //povLeftBlue.writeArrayRight(arrS2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrS3);
        //povLeftRed.writeArrayRight(arrS3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrS4);
        //povLeftRed.writeArrayRight(arrS4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrS5);
        //povLeftBlue.writeArrayRight(arrS5);
        wait_us(4000);
    }
    break;

case 'T':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrT1);
        //povLeftRed.writeArrayRight(arrT1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrT2);
        //povLeftRed.writeArrayRight(arrT2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrT3);
        //povLeftRed.writeArrayRight(arrT3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrT4);
        //povLeftRed.writeArrayRight(arrT4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrT5);
        //povLeftRed.writeArrayRight(arrT5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrT1);
        //povLeftGreen.writeArrayRight(arrT1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrT2);
        //povLeftGreen.writeArrayRight(arrT2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrT3);
        //povLeftGreen.writeArrayRight(arrT3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrT4);
        //povLeftGreen.writeArrayRight(arrT4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrT5);
        //povLeftGreen.writeArrayRight(arrT5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrT1);
        //povLeftBlue.writeArrayRight(arrT1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrT2);
        //povLeftBlue.writeArrayRight(arrT2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrT3);
        //povLeftBlue.writeArrayRight(arrT3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrT4);
        //povLeftBlue.writeArrayRight(arrT4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrT5);
        //povLeftBlue.writeArrayRight(arrT5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrT1);
        //povLeftBlue.writeArrayRight(arrT1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrT2);
        //povLeftBlue.writeArrayRight(arrT2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrT3);
        //povLeftRed.writeArrayRight(arrT3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrT4);
        //povLeftRed.writeArrayRight(arrT4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrT5);
        //povLeftBlue.writeArrayRight(arrT5);
        wait_us(4000);
    }
    break;

case 'U':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrU1);
        //povLeftRed.writeArrayRight(arrU1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrU2);
        //povLeftRed.writeArrayRight(arrU2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrU3);
        //povLeftRed.writeArrayRight(arrU3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrU4);
        //povLeftRed.writeArrayRight(arrU4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrU5);
        //povLeftRed.writeArrayRight(arrU5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrU1);
        //povLeftGreen.writeArrayRight(arrU1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrU2);
        //povLeftGreen.writeArrayRight(arrU2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrU3);
        //povLeftGreen.writeArrayRight(arrU3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrU4);
        //povLeftGreen.writeArrayRight(arrU4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrU5);
        //povLeftGreen.writeArrayRight(arrU5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrU1);
        //povLeftBlue.writeArrayRight(arrU1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrU2);
        //povLeftBlue.writeArrayRight(arrU2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrU3);
        //povLeftBlue.writeArrayRight(arrU3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrU4);
        //povLeftBlue.writeArrayRight(arrU4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrU5);
        //povLeftBlue.writeArrayRight(arrU5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrU1);
        //povLeftBlue.writeArrayRight(arrU1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrU2);
        //povLeftBlue.writeArrayRight(arrU2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrU3);
        //povLeftRed.writeArrayRight(arrU3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrU4);
        //povLeftRed.writeArrayRight(arrU4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrU5);
        //povLeftBlue.writeArrayRight(arrU5);
        wait_us(4000);
    }
    break;

case 'V':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrV1);
        //povLeftRed.writeArrayRight(arrV1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrV2);
        //povLeftRed.writeArrayRight(arrV2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrV3);
        //povLeftRed.writeArrayRight(arrV3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrV4);
        //povLeftRed.writeArrayRight(arrV4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrV5);
        //povLeftRed.writeArrayRight(arrV5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrV1);
        //povLeftGreen.writeArrayRight(arrV1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrV2);
        //povLeftGreen.writeArrayRight(arrV2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrV3);
        //povLeftGreen.writeArrayRight(arrV3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrV4);
        //povLeftGreen.writeArrayRight(arrV4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrV5);
        //povLeftGreen.writeArrayRight(arrV5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrV1);
        //povLeftBlue.writeArrayRight(arrV1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrV2);
        //povLeftBlue.writeArrayRight(arrV2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrV3);
        //povLeftBlue.writeArrayRight(arrV3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrV4);
        //povLeftBlue.writeArrayRight(arrV4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrV5);
        //povLeftBlue.writeArrayRight(arrV5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrV1);
        //povLeftBlue.writeArrayRight(arrV1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrV2);
        //povLeftBlue.writeArrayRight(arrV2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrV3);
        //povLeftRed.writeArrayRight(arrV3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrV4);
        //povLeftRed.writeArrayRight(arrV4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrV5);
        //povLeftBlue.writeArrayRight(arrV5);
        wait_us(4000);
    }
    break;

case 'W':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrW1);
        //povLeftRed.writeArrayRight(arrW1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrW2);
        //povLeftRed.writeArrayRight(arrW2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrW3);
        //povLeftRed.writeArrayRight(arrW3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrW4);
        //povLeftRed.writeArrayRight(arrW4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrW5);
        //povLeftRed.writeArrayRight(arrW5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrW1);
        //povLeftGreen.writeArrayRight(arrW1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrW2);
        //povLeftGreen.writeArrayRight(arrW2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrW3);
        //povLeftGreen.writeArrayRight(arrW3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrW4);
        //povLeftGreen.writeArrayRight(arrW4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrW5);
        //povLeftGreen.writeArrayRight(arrW5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrW1);
        //povLeftBlue.writeArrayRight(arrW1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrW2);
        //povLeftBlue.writeArrayRight(arrW2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrW3);
        //povLeftBlue.writeArrayRight(arrW3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrW4);
        //povLeftBlue.writeArrayRight(arrW4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrW5);
        //povLeftBlue.writeArrayRight(arrW5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrW1);
        //povLeftBlue.writeArrayRight(arrW1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrW2);
        //povLeftBlue.writeArrayRight(arrW2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrW3);
        //povLeftRed.writeArrayRight(arrW3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrW4);
        //povLeftRed.writeArrayRight(arrW4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrW5);
        //povLeftBlue.writeArrayRight(arrW5);
        wait_us(4000);
    }
    break;

case 'X':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrX1);
        //povLeftRed.writeArrayRight(arrX1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrX2);
        //povLeftRed.writeArrayRight(arrX2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrX3);
        //povLeftRed.writeArrayRight(arrX3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrX4);
        //povLeftRed.writeArrayRight(arrX4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrX5);
        //povLeftRed.writeArrayRight(arrX5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrX1);
        //povLeftGreen.writeArrayRight(arrX1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrX2);
        //povLeftGreen.writeArrayRight(arrX2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrX3);
        //povLeftGreen.writeArrayRight(arrX3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrX4);
        //povLeftGreen.writeArrayRight(arrX4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrX5);
        //povLeftGreen.writeArrayRight(arrX5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrX1);
        //povLeftBlue.writeArrayRight(arrX1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrX2);
        //povLeftBlue.writeArrayRight(arrX2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrX3);
        //povLeftBlue.writeArrayRight(arrX3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrX4);
        //povLeftBlue.writeArrayRight(arrX4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrX5);
        //povLeftBlue.writeArrayRight(arrX5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrX1);
        //povLeftBlue.writeArrayRight(arrX1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrX2);
        //povLeftBlue.writeArrayRight(arrX2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrX3);
        //povLeftRed.writeArrayRight(arrX3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrX4);
        //povLeftRed.writeArrayRight(arrX4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrX5);
        //povLeftBlue.writeArrayRight(arrX5);
        wait_us(4000);
    }
    break;

case 'Y':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrY1);
        //povLeftRed.writeArrayRight(arrY1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrY2);
        //povLeftRed.writeArrayRight(arrY2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrY3);
        //povLeftRed.writeArrayRight(arrY3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrY4);
        //povLeftRed.writeArrayRight(arrY4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrY5);
        //povLeftRed.writeArrayRight(arrY5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrY1);
        //povLeftGreen.writeArrayRight(arrY1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrY2);
        //povLeftGreen.writeArrayRight(arrY2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrY3);
        //povLeftGreen.writeArrayRight(arrY3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrY4);
        //povLeftGreen.writeArrayRight(arrY4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrY5);
        //povLeftGreen.writeArrayRight(arrY5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrY1);
        //povLeftBlue.writeArrayRight(arrY1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrY2);
        //povLeftBlue.writeArrayRight(arrY2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrY3);
        //povLeftBlue.writeArrayRight(arrY3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrY4);
        //povLeftBlue.writeArrayRight(arrY4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrY5);
        //povLeftBlue.writeArrayRight(arrY5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrY1);
        //povLeftBlue.writeArrayRight(arrY1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrY2);
        //povLeftBlue.writeArrayRight(arrY2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrY3);
        //povLeftRed.writeArrayRight(arrY3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrY4);
        //povLeftRed.writeArrayRight(arrY4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrY5);
        //povLeftBlue.writeArrayRight(arrY5);
        wait_us(4000);
    }
    break;

case 'Z':
    if (colour == 1) {
        povRightRed.writeArrayRight(arrZ1);
        //povLeftRed.writeArrayRight(arrZ1);
        wait_us(4000);
        povRightRed.writeArrayRight(arrZ2);
        //povLeftRed.writeArrayRight(arrZ2);
        wait_us(4000);
        povRightRed.writeArrayRight(arrZ3);
        //povLeftRed.writeArrayRight(arrZ3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrZ4);
        //povLeftRed.writeArrayRight(arrZ4);
        wait_us(4000);
        povRightRed.writeArrayRight(arrZ5);
        //povLeftRed.writeArrayRight(arrZ5);
        wait_us(4000);
    } else if (colour == 2) {
        povRightGreen.writeArrayRight(arrZ1);
        //povLeftGreen.writeArrayRight(arrZ1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrZ2);
        //povLeftGreen.writeArrayRight(arrZ2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrZ3);
        //povLeftGreen.writeArrayRight(arrZ3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrZ4);
        //povLeftGreen.writeArrayRight(arrZ4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrZ5);
        //povLeftGreen.writeArrayRight(arrZ5);
        wait_us(4000);
    } else if (colour == 3) {
        povRightBlue.writeArrayRight(arrZ1);
        //povLeftBlue.writeArrayRight(arrZ1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrZ2);
        //povLeftBlue.writeArrayRight(arrZ2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrZ3);
        //povLeftBlue.writeArrayRight(arrZ3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrZ4);
        //povLeftBlue.writeArrayRight(arrZ4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrZ5);
        //povLeftBlue.writeArrayRight(arrZ5);
        wait_us(4000);
    } else {
        povRightRed.writeArrayRight(arrZ1);
        //povLeftBlue.writeArrayRight(arrZ1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrZ2);
        //povLeftBlue.writeArrayRight(arrZ2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arrZ3);
        //povLeftRed.writeArrayRight(arrZ3);
        wait_us(4000);
        povRightRed.writeArrayRight(arrZ4);
        //povLeftRed.writeArrayRight(arrZ4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arrZ5);
        //povLeftBlue.writeArrayRight(arrZ5);
        wait_us(4000);
    }
    break;

    case '0':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr0_1);
        //povLeftRed.writeArrayRight(arr0_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr0_2);
        //povLeftRed.writeArrayRight(arr0_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr0_3);
        //povLeftRed.writeArrayRight(arr0_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr0_4);
        //povLeftRed.writeArrayRight(arr0_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr0_5);
        //povLeftRed.writeArrayRight(arr0_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr0_1);
        //povLeftGreen.writeArrayRight(arr0_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr0_2);
        //povLeftGreen.writeArrayRight(arr0_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr0_3);
        //povLeftGreen.writeArrayRight(arr0_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr0_4);
        //povLeftGreen.writeArrayRight(arr0_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr0_5);
        //povLeftGreen.writeArrayRight(arr0_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr0_1);
        //povLeftBlue.writeArrayRight(arr0_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr0_2);
        //povLeftBlue.writeArrayRight(arr0_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr0_3);
        //povLeftBlue.writeArrayRight(arr0_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr0_4);
        //povLeftBlue.writeArrayRight(arr0_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr0_5);
        //povLeftBlue.writeArrayRight(arr0_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr0_1);
        //povLeftBlue.writeArrayRight(arr0_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr0_2);
        //povLeftBlue.writeArrayRight(arr0_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr0_3);
        //povLeftRed.writeArrayRight(arr0_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr0_4);
        //povLeftRed.writeArrayRight(arr0_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr0_5);
        //povLeftBlue.writeArrayRight(arr0_5);
        wait_us(4000);
    }
    break;
case '1':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr1_1);
        //povLeftRed.writeArrayRight(arr1_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr1_2);
        //povLeftRed.writeArrayRight(arr1_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr1_3);
        //povLeftRed.writeArrayRight(arr1_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr1_4);
        //povLeftRed.writeArrayRight(arr1_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr1_5);
        //povLeftRed.writeArrayRight(arr1_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr1_1);
        //povLeftGreen.writeArrayRight(arr1_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr1_2);
        //povLeftGreen.writeArrayRight(arr1_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr1_3);
        //povLeftGreen.writeArrayRight(arr1_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr1_4);
        //povLeftGreen.writeArrayRight(arr1_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr1_5);
        //povLeftGreen.writeArrayRight(arr1_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr1_1);
        //povLeftBlue.writeArrayRight(arr1_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr1_2);
        //povLeftBlue.writeArrayRight(arr1_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr1_3);
        //povLeftBlue.writeArrayRight(arr1_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr1_4);
        //povLeftBlue.writeArrayRight(arr1_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr1_5);
        //povLeftBlue.writeArrayRight(arr1_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr1_1);
        //povLeftBlue.writeArrayRight(arr1_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr1_2);
        //povLeftBlue.writeArrayRight(arr1_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr1_3);
        //povLeftRed.writeArrayRight(arr1_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr1_4);
        //povLeftRed.writeArrayRight(arr1_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr1_5);
        //povLeftBlue.writeArrayRight(arr1_5);
        wait_us(4000);
    }
    break;

case '2':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr2_1);
        //povLeftRed.writeArrayRight(arr2_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr2_2);
        //povLeftRed.writeArrayRight(arr2_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr2_3);
        //povLeftRed.writeArrayRight(arr2_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr2_4);
        //povLeftRed.writeArrayRight(arr2_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr2_5);
        //povLeftRed.writeArrayRight(arr2_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr2_1);
        //povLeftGreen.writeArrayRight(arr2_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr2_2);
        //povLeftGreen.writeArrayRight(arr2_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr2_3);
        //povLeftGreen.writeArrayRight(arr2_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr2_4);
        //povLeftGreen.writeArrayRight(arr2_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr2_5);
        //povLeftGreen.writeArrayRight(arr2_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr2_1);
        //povLeftBlue.writeArrayRight(arr2_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr2_2);
        //povLeftBlue.writeArrayRight(arr2_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr2_3);
        //povLeftBlue.writeArrayRight(arr2_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr2_4);
        //povLeftBlue.writeArrayRight(arr2_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr2_5);
        //povLeftBlue.writeArrayRight(arr2_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr2_1);
        //povLeftBlue.writeArrayRight(arr2_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr2_2);
        //povLeftBlue.writeArrayRight(arr2_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr2_3);
        //povLeftRed.writeArrayRight(arr2_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr2_4);
        //povLeftRed.writeArrayRight(arr2_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr2_5);
        //povLeftBlue.writeArrayRight(arr2_5);
        wait_us(4000);
    }
    break;

case '3':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr3_1);
        //povLeftRed.writeArrayRight(arr3_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr3_2);
        //povLeftRed.writeArrayRight(arr3_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr3_3);
        //povLeftRed.writeArrayRight(arr3_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr3_4);
        //povLeftRed.writeArrayRight(arr3_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr3_5);
        //povLeftRed.writeArrayRight(arr3_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr3_1);
        //povLeftGreen.writeArrayRight(arr3_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr3_2);
        //povLeftGreen.writeArrayRight(arr3_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr3_3);
        //povLeftGreen.writeArrayRight(arr3_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr3_4);
        //povLeftGreen.writeArrayRight(arr3_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr3_5);
        //povLeftGreen.writeArrayRight(arr3_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr3_1);
        //povLeftBlue.writeArrayRight(arr3_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr3_2);
        //povLeftBlue.writeArrayRight(arr3_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr3_3);
        //povLeftBlue.writeArrayRight(arr3_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr3_4);
        //povLeftBlue.writeArrayRight(arr3_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr3_5);
        //povLeftBlue.writeArrayRight(arr3_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr3_1);
        //povLeftBlue.writeArrayRight(arr3_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr3_2);
        //povLeftBlue.writeArrayRight(arr3_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr3_3);
        //povLeftRed.writeArrayRight(arr3_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr3_4);
        //povLeftRed.writeArrayRight(arr3_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr3_5);
        //povLeftBlue.writeArrayRight(arr3_5);
        wait_us(4000);
    }
    break;

case '4':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr4_1);
        //povLeftRed.writeArrayRight(arr4_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr4_2);
        //povLeftRed.writeArrayRight(arr4_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr4_3);
        //povLeftRed.writeArrayRight(arr4_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr4_4);
        //povLeftRed.writeArrayRight(arr4_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr4_5);
        //povLeftRed.writeArrayRight(arr4_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr4_1);
        //povLeftGreen.writeArrayRight(arr4_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr4_2);
        //povLeftGreen.writeArrayRight(arr4_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr4_3);
        //povLeftGreen.writeArrayRight(arr4_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr4_4);
        //povLeftGreen.writeArrayRight(arr4_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr4_5);
        //povLeftGreen.writeArrayRight(arr4_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr4_1);
        //povLeftBlue.writeArrayRight(arr4_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr4_2);
        //povLeftBlue.writeArrayRight(arr4_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr4_3);
        //povLeftBlue.writeArrayRight(arr4_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr4_4);
        //povLeftBlue.writeArrayRight(arr4_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr4_5);
        //povLeftBlue.writeArrayRight(arr4_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr4_1);
        //povLeftBlue.writeArrayRight(arr4_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr4_2);
        //povLeftBlue.writeArrayRight(arr4_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr4_3);
        //povLeftRed.writeArrayRight(arr4_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr4_4);
        //povLeftRed.writeArrayRight(arr4_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr4_5);
        //povLeftBlue.writeArrayRight(arr4_5);
        wait_us(4000);
    }
    break;
case '5':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr5_1);
        //povLeftRed.writeArrayRight(arr5_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr5_2);
        //povLeftRed.writeArrayRight(arr5_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr5_3);
        //povLeftRed.writeArrayRight(arr5_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr5_4);
        //povLeftRed.writeArrayRight(arr5_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr5_5);
        //povLeftRed.writeArrayRight(arr5_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr5_1);
        //povLeftGreen.writeArrayRight(arr5_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr5_2);
        //povLeftGreen.writeArrayRight(arr5_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr5_3);
        //povLeftGreen.writeArrayRight(arr5_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr5_4);
        //povLeftGreen.writeArrayRight(arr5_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr5_5);
        //povLeftGreen.writeArrayRight(arr5_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr5_1);
        //povLeftBlue.writeArrayRight(arr5_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr5_2);
        //povLeftBlue.writeArrayRight(arr5_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr5_3);
        //povLeftBlue.writeArrayRight(arr5_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr5_4);
        //povLeftBlue.writeArrayRight(arr5_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr5_5);
        //povLeftBlue.writeArrayRight(arr5_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr5_1);
        //povLeftBlue.writeArrayRight(arr5_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr5_2);
        //povLeftBlue.writeArrayRight(arr5_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr5_3);
        //povLeftRed.writeArrayRight(arr5_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr5_4);
        //povLeftRed.writeArrayRight(arr5_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr5_5);
        //povLeftBlue.writeArrayRight(arr5_5);
        wait_us(4000);
    }
    break;

case '6':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr6_1);
        //povLeftRed.writeArrayRight(arr6_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr6_2);
        //povLeftRed.writeArrayRight(arr6_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr6_3);
        //povLeftRed.writeArrayRight(arr6_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr6_4);
        //povLeftRed.writeArrayRight(arr6_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr6_5);
        //povLeftRed.writeArrayRight(arr6_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr6_1);
        //povLeftGreen.writeArrayRight(arr6_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr6_2);
        //povLeftGreen.writeArrayRight(arr6_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr6_3);
        //povLeftGreen.writeArrayRight(arr6_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr6_4);
        //povLeftGreen.writeArrayRight(arr6_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr6_5);
        //povLeftGreen.writeArrayRight(arr6_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr6_1);
        //povLeftBlue.writeArrayRight(arr6_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr6_2);
        //povLeftBlue.writeArrayRight(arr6_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr6_3);
        //povLeftBlue.writeArrayRight(arr6_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr6_4);
        //povLeftBlue.writeArrayRight(arr6_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr6_5);
        //povLeftBlue.writeArrayRight(arr6_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr6_1);
        //povLeftBlue.writeArrayRight(arr6_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr6_2);
        //povLeftBlue.writeArrayRight(arr6_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr6_3);
        //povLeftRed.writeArrayRight(arr6_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr6_4);
        //povLeftRed.writeArrayRight(arr6_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr6_5);
        //povLeftBlue.writeArrayRight(arr6_5);
        wait_us(4000);
    }
    break;

case '7':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr7_1);
        //povLeftRed.writeArrayRight(arr7_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr7_2);
        //povLeftRed.writeArrayRight(arr7_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr7_3);
        //povLeftRed.writeArrayRight(arr7_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr7_4);
        //povLeftRed.writeArrayRight(arr7_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr7_5);
        //povLeftRed.writeArrayRight(arr7_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr7_1);
        //povLeftGreen.writeArrayRight(arr7_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr7_2);
        //povLeftGreen.writeArrayRight(arr7_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr7_3);
        //povLeftGreen.writeArrayRight(arr7_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr7_4);
        //povLeftGreen.writeArrayRight(arr7_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr7_5);
        //povLeftGreen.writeArrayRight(arr7_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr7_1);
        //povLeftBlue.writeArrayRight(arr7_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr7_2);
        //povLeftBlue.writeArrayRight(arr7_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr7_3);
        //povLeftBlue.writeArrayRight(arr7_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr7_4);
        //povLeftBlue.writeArrayRight(arr7_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr7_5);
        //povLeftBlue.writeArrayRight(arr7_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr7_1);
        //povLeftBlue.writeArrayRight(arr7_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr7_2);
        //povLeftBlue.writeArrayRight(arr7_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr7_3);
        //povLeftRed.writeArrayRight(arr7_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr7_4);
        //povLeftRed.writeArrayRight(arr7_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr7_5);
        //povLeftBlue.writeArrayRight(arr7_5);
        wait_us(4000);
    }
    break;

case '8':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr8_1);
        //povLeftRed.writeArrayRight(arr8_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr8_2);
        //povLeftRed.writeArrayRight(arr8_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr8_3);
        //povLeftRed.writeArrayRight(arr8_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr8_4);
        //povLeftRed.writeArrayRight(arr8_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr8_5);
        //povLeftRed.writeArrayRight(arr8_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr8_1);
        //povLeftGreen.writeArrayRight(arr8_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr8_2);
        //povLeftGreen.writeArrayRight(arr8_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr8_3);
        //povLeftGreen.writeArrayRight(arr8_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr8_4);
        //povLeftGreen.writeArrayRight(arr8_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr8_5);
        //povLeftGreen.writeArrayRight(arr8_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr8_1);
        //povLeftBlue.writeArrayRight(arr8_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr8_2);
        //povLeftBlue.writeArrayRight(arr8_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr8_3);
        //povLeftBlue.writeArrayRight(arr8_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr8_4);
        //povLeftBlue.writeArrayRight(arr8_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr8_5);
        //povLeftBlue.writeArrayRight(arr8_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr8_1);
        //povLeftBlue.writeArrayRight(arr8_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr8_2);
        //povLeftBlue.writeArrayRight(arr8_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr8_3);
        //povLeftRed.writeArrayRight(arr8_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr8_4);
        //povLeftRed.writeArrayRight(arr8_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr8_5);
        //povLeftBlue.writeArrayRight(arr8_5);
        wait_us(4000);
    }
    break;

case '9':
    if (colour == 1) { // Red
        povRightRed.writeArrayRight(arr9_1);
        //povLeftRed.writeArrayRight(arr9_1);
        wait_us(4000);
        povRightRed.writeArrayRight(arr9_2);
        //povLeftRed.writeArrayRight(arr9_2);
        wait_us(4000);
        povRightRed.writeArrayRight(arr9_3);
        //povLeftRed.writeArrayRight(arr9_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr9_4);
        //povLeftRed.writeArrayRight(arr9_4);
        wait_us(4000);
        povRightRed.writeArrayRight(arr9_5);
        //povLeftRed.writeArrayRight(arr9_5);
        wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(arr9_1);
        //povLeftGreen.writeArrayRight(arr9_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr9_2);
        //povLeftGreen.writeArrayRight(arr9_2);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr9_3);
        //povLeftGreen.writeArrayRight(arr9_3);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr9_4);
        //povLeftGreen.writeArrayRight(arr9_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr9_5);
        //povLeftGreen.writeArrayRight(arr9_5);
        wait_us(4000);
    } else if (colour == 3) { // Blue
        povRightBlue.writeArrayRight(arr9_1);
        //povLeftBlue.writeArrayRight(arr9_1);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr9_2);
        //povLeftBlue.writeArrayRight(arr9_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr9_3);
        //povLeftBlue.writeArrayRight(arr9_3);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr9_4);
        //povLeftBlue.writeArrayRight(arr9_4);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr9_5);
        //povLeftBlue.writeArrayRight(arr9_5);
        wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(arr9_1);
        //povLeftBlue.writeArrayRight(arr9_1);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr9_2);
        //povLeftBlue.writeArrayRight(arr9_2);
        wait_us(4000);
        povRightBlue.writeArrayRight(arr9_3);
        //povLeftRed.writeArrayRight(arr9_3);
        wait_us(4000);
        povRightRed.writeArrayRight(arr9_4);
        //povLeftRed.writeArrayRight(arr9_4);
        wait_us(4000);
        povRightGreen.writeArrayRight(arr9_5);
        //povLeftBlue.writeArrayRight(arr9_5);
        wait_us(4000);
    }
    break;
    
        


    default: {
        if (colour == 1) { // Red
        
        povRightRed.writeArrayRight(space1);
       wait_us(4000);
    } else if (colour == 2) { // Green
        povRightGreen.writeArrayRight(space1);
       wait_us(4000);
    } else if (colour == 3) { // Blue
         povRightBlue.writeArrayRight(space1);
       wait_us(4000);
    } else { // Disco
        povRightRed.writeArrayRight(space1);
       wait_us(4000);
        povRightBlue.writeArrayRight(space1);
       wait_us(4000);
        povRightGreen.writeArrayRight(space1);
       wait_us(4000);
    }
    }
        break;
    
}
}
}

void alphaL(char letter){
letter = toupper(letter);

switch(letter){
    case 'A':{
        if (colour2 == 1) { // Red
            //povRightRed.writeArrayRight(arrA1);
            povLeftRed.writeArrayRight(arrA1);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrA2);
            povLeftRed.writeArrayRight(arrA2);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrA3);
            povLeftRed.writeArrayRight(arrA3);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrA4);
            povLeftRed.writeArrayRight(arrA4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrA5);
            povLeftRed.writeArrayRight(arrA5);
            wait_us(4000);
        } else if (colour2 == 2) { // Green
            //povRightGreen.writeArrayRight(arrA1);
            wait_us(4000);
            povLeftGreen.writeArrayRight(arrA2);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrA3);
            wait_us(4000);
            povLeftGreen.writeArrayRight(arrA4);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrA5);
            wait_us(4000);
            /*povLeftGreen.writeArrayRight(arrA3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrA4);
            povLeftGreen.writeArrayRight(arrA4);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrA5);
            povLeftGreen.writeArrayRight(arrA5);*/
        } else if (colour2 == 3) { // Blue
            //povRightBlue.writeArrayRight(arrA1);
            povLeftBlue.writeArrayRight(arrA1);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrA2);
            povLeftBlue.writeArrayRight(arrA2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrA3);
            povLeftBlue.writeArrayRight(arrA3);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrA4);
            povLeftBlue.writeArrayRight(arrA4);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrA5);
            povLeftBlue.writeArrayRight(arrA5);
            wait_us(4000);
        } else { // Disco
            //povRightRed.writeArrayRight(arrA1);
            povLeftRed.writeArrayRight(arrA1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrA2);
            povLeftGreen.writeArrayRight(arrA2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrA3);
            povLeftBlue.writeArrayRight(arrA3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrA4);
            povLeftGreen.writeArrayRight(arrA4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrA5);
            povLeftRed.writeArrayRight(arrA5);
            wait_us(4000);
        }
        break;
case 'B':
        if (colour2 == 1) { // Red
            //povRightRed.writeArrayRight(arrB1);
            povLeftRed.writeArrayRight(arrB1);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrB2);
            povLeftRed.writeArrayRight(arrB2);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrB3);
            povLeftRed.writeArrayRight(arrB3);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrB4);
            povLeftRed.writeArrayRight(arrB4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrB5);
            povLeftRed.writeArrayRight(arrB5);
            wait_us(4000);
        } else if (colour2 == 2) { // Green
            //povRightGreen.writeArrayRight(arrB1);
            povLeftGreen.writeArrayRight(arrB1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrB2);
            povLeftGreen.writeArrayRight(arrB2);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrB3);
            povLeftGreen.writeArrayRight(arrB3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrB4);
            povLeftGreen.writeArrayRight(arrB4);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrB5);
            povLeftGreen.writeArrayRight(arrB5);
            wait_us(4000);
        } else if (colour2 == 3) { // Blue
            //povRightBlue.writeArrayRight(arrB1);
            povLeftBlue.writeArrayRight(arrB1);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrB2);
            povLeftBlue.writeArrayRight(arrB2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrB3);
            povLeftBlue.writeArrayRight(arrB3);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrB4);
            povLeftBlue.writeArrayRight(arrB4);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrB5);
            povLeftBlue.writeArrayRight(arrB5);
            wait_us(4000);
        } else { // Disco
            //povRightRed.writeArrayRight(arrB1);
            povLeftRed.writeArrayRight(arrB1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrB2);
            povLeftGreen.writeArrayRight(arrB2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrB3);
            povLeftBlue.writeArrayRight(arrB3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrB4);
            povLeftGreen.writeArrayRight(arrB4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrB5);
            povLeftRed.writeArrayRight(arrB5);
            wait_us(4000);
        }
        break;

    case 'C':
        if (colour2 == 1) { // Red
            //povRightRed.writeArrayRight(arrC1);
            povLeftRed.writeArrayRight(arrC1);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrC2);
            povLeftRed.writeArrayRight(arrC2);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrC3);
            povLeftRed.writeArrayRight(arrC3);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrC4);
            povLeftRed.writeArrayRight(arrC4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrC5);
            povLeftRed.writeArrayRight(arrC5);
            wait_us(4000);
        } else if (colour2 == 2) { // Green
            //povRightGreen.writeArrayRight(arrC1);
            povLeftGreen.writeArrayRight(arrC1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrC2);
            povLeftGreen.writeArrayRight(arrC2);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrC3);
            povLeftGreen.writeArrayRight(arrC3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrC4);
            povLeftGreen.writeArrayRight(arrC4);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrC5);
            povLeftGreen.writeArrayRight(arrC5);
            wait_us(4000);
        } else if (colour2 == 3) { // Blue
            //povRightBlue.writeArrayRight(arrC1);
            povLeftBlue.writeArrayRight(arrC1);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrC2);
            povLeftBlue.writeArrayRight(arrC2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrC3);
            povLeftBlue.writeArrayRight(arrC3);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrC4);
            povLeftBlue.writeArrayRight(arrC4);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrC5);
            povLeftBlue.writeArrayRight(arrC5);
            wait_us(4000);
        } else { // Disco
            //povRightRed.writeArrayRight(arrC1);
            povLeftRed.writeArrayRight(arrC1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrC2);
            povLeftGreen.writeArrayRight(arrC2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrC3);
            povLeftBlue.writeArrayRight(arrC3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrC4);
            povLeftGreen.writeArrayRight(arrC4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrC5);
            povLeftRed.writeArrayRight(arrC5);
            wait_us(4000);
        }
        break;

    case 'D':
        if (colour2 == 1) { // Red
            //povRightRed.writeArrayRight(arrD1);
            povLeftRed.writeArrayRight(arrD1);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrD2);
            povLeftRed.writeArrayRight(arrD2);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrD3);
            povLeftRed.writeArrayRight(arrD3);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrD4);
            povLeftRed.writeArrayRight(arrD4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrD5);
            povLeftRed.writeArrayRight(arrD5);
            wait_us(4000);
        } else if (colour2 == 2) { // Green
            //povRightGreen.writeArrayRight(arrD1);
            povLeftGreen.writeArrayRight(arrD1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrD2);
            povLeftGreen.writeArrayRight(arrD2);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrD3);
            povLeftGreen.writeArrayRight(arrD3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrD4);
            povLeftGreen.writeArrayRight(arrD4);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrD5);
            povLeftGreen.writeArrayRight(arrD5);
            wait_us(4000);
        } else if (colour2 == 3) { // Blue
            //povRightBlue.writeArrayRight(arrD1);
            povLeftBlue.writeArrayRight(arrD1);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrD2);
            povLeftBlue.writeArrayRight(arrD2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrD3);
            povLeftBlue.writeArrayRight(arrD3);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrD4);
            povLeftBlue.writeArrayRight(arrD4);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrD5);
            povLeftBlue.writeArrayRight(arrD5);
            wait_us(4000);
        } else { // Disco
            //povRightRed.writeArrayRight(arrD1);
            povLeftRed.writeArrayRight(arrD1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrD2);
            povLeftGreen.writeArrayRight(arrD2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrD3);
            povLeftBlue.writeArrayRight(arrD3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrD4);
            povLeftGreen.writeArrayRight(arrD4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrD5);
            povLeftRed.writeArrayRight(arrD5);
            wait_us(4000);
        }
        break;

    case 'E':
        if (colour2 == 1) { // Red
            //povRightRed.writeArrayRight(arrE1);
            povLeftRed.writeArrayRight(arrE1);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrE2);
            povLeftRed.writeArrayRight(arrE2);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrE3);
            povLeftRed.writeArrayRight(arrE3);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrE4);
            povLeftRed.writeArrayRight(arrE4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrE5);
            povLeftRed.writeArrayRight(arrE5);
            wait_us(4000);


            
        } else if (colour2 == 2) { // Green
           //povRightGreen.writeArrayRight(arrE1);
            povLeftGreen.writeArrayRight(arrE1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrE2);
            povLeftGreen.writeArrayRight(arrE2);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrE3);
            povLeftGreen.writeArrayRight(arrE3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrE4);
            povLeftGreen.writeArrayRight(arrE4);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrE5);
            povLeftGreen.writeArrayRight(arrE5);
            wait_us(4000);
        } else if (colour2 == 3) { // Blue
            //povRightBlue.writeArrayRight(arrE1);
            povLeftBlue.writeArrayRight(arrE1);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrE2);
            povLeftBlue.writeArrayRight(arrE2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrE3);
            povLeftBlue.writeArrayRight(arrE3);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrE4);
            povLeftBlue.writeArrayRight(arrE4);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrE5);
            povLeftBlue.writeArrayRight(arrE5);
            wait_us(4000);
            
        }
        else { // Disco
            //povRightRed.writeArrayRight(arrE1);
            povLeftRed.writeArrayRight(arrE1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrE2);
            povLeftGreen.writeArrayRight(arrE2);
            wait_us(4000);
             //povRightBlue.writeArrayRight(arrE3);
            povLeftBlue.writeArrayRight(arrE3);
            wait_us(4000);
             //povRightGreen.writeArrayRight(arrE4);
            povLeftGreen.writeArrayRight(arrE4);
            wait_us(4000);
             //povRightRed.writeArrayRight(arrE5);
            povLeftRed.writeArrayRight(arrE5);
            wait_us(4000);
            
        }
        break;

    case 'F':
        if (colour2 == 1) { // Red
            //povRightRed.writeArrayRight(arrF1);
            povLeftRed.writeArrayRight(arrF1);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrF2);
            povLeftRed.writeArrayRight(arrF2);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrF3);
            povLeftRed.writeArrayRight(arrF3);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrF4);
            povLeftRed.writeArrayRight(arrF4);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrF5);
            povLeftRed.writeArrayRight(arrF5);
            wait_us(4000);
            
        } else if (colour2 == 2) { // Green
            //povRightGreen.writeArrayRight(arrF1);
            povLeftGreen.writeArrayRight(arrF1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrF2);
            povLeftGreen.writeArrayRight(arrF2);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrF3);
            povLeftGreen.writeArrayRight(arrF3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrF4);
            povLeftGreen.writeArrayRight(arrF4);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrF5);
            povLeftGreen.writeArrayRight(arrF5);
            wait_us(4000);

        } else if (colour2 == 3) { // Blue
            //povRightBlue.writeArrayRight(arrF1);
            povLeftBlue.writeArrayRight(arrF1);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrF2);
            povLeftBlue.writeArrayRight(arrF2);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrF3);
            povLeftBlue.writeArrayRight(arrF3);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrF4);
            povLeftBlue.writeArrayRight(arrF4);
            wait_us(4000);
            //povRightBlue.writeArrayRight(arrF5);
            povLeftBlue.writeArrayRight(arrF5);
            wait_us(4000);
            
        } else { // Disco
            //povRightBlue.writeArrayRight(arrF1);
            povLeftBlue.writeArrayRight(arrF1);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrF2);
            povLeftGreen.writeArrayRight(arrF2);
            wait_us(4000);
            //povRightRed.writeArrayRight(arrF3);
            povLeftBlue.writeArrayRight(arrF3);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrF4);
            povLeftBlue.writeArrayRight(arrF4);
            wait_us(4000);
            //povRightGreen.writeArrayRight(arrF5);
            povLeftRed.writeArrayRight(arrF5);
            wait_us(4000);
            
        }
        break;

   case 'G':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrG1);
        povLeftRed.writeArrayRight(arrG1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrG2);
        povLeftRed.writeArrayRight(arrG2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrG3);
        povLeftRed.writeArrayRight(arrG3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrG4);
        povLeftRed.writeArrayRight(arrG4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrG5);
        povLeftRed.writeArrayRight(arrG5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrG1);
        povLeftGreen.writeArrayRight(arrG1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrG2);
        povLeftGreen.writeArrayRight(arrG2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrG3);
        povLeftGreen.writeArrayRight(arrG3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrG4);
        povLeftGreen.writeArrayRight(arrG4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrG5);
        povLeftGreen.writeArrayRight(arrG5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrG1);
        povLeftBlue.writeArrayRight(arrG1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrG2);
        povLeftBlue.writeArrayRight(arrG2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrG3);
        povLeftBlue.writeArrayRight(arrG3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrG4);
        povLeftBlue.writeArrayRight(arrG4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrG5);
        povLeftBlue.writeArrayRight(arrG5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrG1);
        povLeftBlue.writeArrayRight(arrG1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrG2);
        povLeftBlue.writeArrayRight(arrG2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrG3);
        povLeftRed.writeArrayRight(arrG3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrG4);
        povLeftRed.writeArrayRight(arrG4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrG5);
        povLeftRed.writeArrayRight(arrG5);
        wait_us(4000);
    }
    break;

    case 'H':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrH1);
        povLeftRed.writeArrayRight(arrH1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrH2);
        povLeftRed.writeArrayRight(arrH2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrH3);
        povLeftRed.writeArrayRight(arrH3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrH4);
        povLeftRed.writeArrayRight(arrH4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrH5);
        povLeftRed.writeArrayRight(arrH5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrH1);
        povLeftGreen.writeArrayRight(arrH1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrH2);
        povLeftGreen.writeArrayRight(arrH2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrH3);
        povLeftGreen.writeArrayRight(arrH3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrH4);
        povLeftGreen.writeArrayRight(arrH4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrH5);
        povLeftGreen.writeArrayRight(arrH5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrH1);
        povLeftBlue.writeArrayRight(arrH1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrH2);
        povLeftBlue.writeArrayRight(arrH2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrH3);
        povLeftBlue.writeArrayRight(arrH3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrH4);
        povLeftBlue.writeArrayRight(arrH4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrH5);
        povLeftBlue.writeArrayRight(arrH5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrH1);
        povLeftBlue.writeArrayRight(arrH1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrH2);
        povLeftBlue.writeArrayRight(arrH2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrH3);
        povLeftRed.writeArrayRight(arrH3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrH4);
        povLeftRed.writeArrayRight(arrH4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrH5);
        povLeftBlue.writeArrayRight(arrH5);
        wait_us(4000);
    }
    break;

    case 'I':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrI1);
        povLeftRed.writeArrayRight(arrI1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrI2);
        povLeftRed.writeArrayRight(arrI2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrI3);
        povLeftRed.writeArrayRight(arrI3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrI4);
        povLeftRed.writeArrayRight(arrI4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrI5);
        povLeftRed.writeArrayRight(arrI5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrI1);
        povLeftGreen.writeArrayRight(arrI1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrI2);
        povLeftGreen.writeArrayRight(arrI2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrI3);
        povLeftGreen.writeArrayRight(arrI3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrI4);
        povLeftGreen.writeArrayRight(arrI4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrI5);
        povLeftGreen.writeArrayRight(arrI5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrI1);
        povLeftBlue.writeArrayRight(arrI1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrI2);
        povLeftBlue.writeArrayRight(arrI2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrI3);
        povLeftBlue.writeArrayRight(arrI3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrI4);
        povLeftBlue.writeArrayRight(arrI4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrI5);
        povLeftBlue.writeArrayRight(arrI5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrI1);
        povLeftBlue.writeArrayRight(arrI1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrI2);
        povLeftBlue.writeArrayRight(arrI2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrI3);
        povLeftRed.writeArrayRight(arrI3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrI4);
        povLeftRed.writeArrayRight(arrI4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrI5);
        povLeftBlue.writeArrayRight(arrI5);
        wait_us(4000);
    }
    break;

   case 'J':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrJ1);
        povLeftRed.writeArrayRight(arrJ1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrJ2);
        povLeftRed.writeArrayRight(arrJ2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrJ3);
        povLeftRed.writeArrayRight(arrJ3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrJ4);
        povLeftRed.writeArrayRight(arrJ4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrJ5);
        povLeftRed.writeArrayRight(arrJ5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrJ1);
        povLeftGreen.writeArrayRight(arrJ1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrJ2);
        povLeftGreen.writeArrayRight(arrJ2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrJ3);
        povLeftGreen.writeArrayRight(arrJ3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrJ4);
        povLeftGreen.writeArrayRight(arrJ4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrJ5);
        povLeftGreen.writeArrayRight(arrJ5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrJ1);
        povLeftBlue.writeArrayRight(arrJ1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrJ2);
        povLeftBlue.writeArrayRight(arrJ2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrJ3);
        povLeftBlue.writeArrayRight(arrJ3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrJ4);
        povLeftBlue.writeArrayRight(arrJ4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrJ5);
        povLeftBlue.writeArrayRight(arrJ5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrJ1);
        povLeftBlue.writeArrayRight(arrJ1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrJ2);
        povLeftBlue.writeArrayRight(arrJ2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrJ3);
        povLeftRed.writeArrayRight(arrJ3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrJ4);
        povLeftRed.writeArrayRight(arrJ4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrJ5);
        povLeftBlue.writeArrayRight(arrJ5);
        wait_us(4000);
    }
    break;

case 'K':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrK1);
        povLeftRed.writeArrayRight(arrK1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrK2);
        povLeftRed.writeArrayRight(arrK2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrK3);
        povLeftRed.writeArrayRight(arrK3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrK4);
        povLeftRed.writeArrayRight(arrK4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrK5);
        povLeftRed.writeArrayRight(arrK5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrK1);
        povLeftGreen.writeArrayRight(arrK1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrK2);
        povLeftGreen.writeArrayRight(arrK2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrK3);
        povLeftGreen.writeArrayRight(arrK3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrK4);
        povLeftGreen.writeArrayRight(arrK4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrK5);
        povLeftGreen.writeArrayRight(arrK5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrK1);
        povLeftBlue.writeArrayRight(arrK1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrK2);
        povLeftBlue.writeArrayRight(arrK2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrK3);
        povLeftBlue.writeArrayRight(arrK3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrK4);
        povLeftBlue.writeArrayRight(arrK4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrK5);
        povLeftBlue.writeArrayRight(arrK5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrK1);
        povLeftBlue.writeArrayRight(arrK1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrK2);
        povLeftBlue.writeArrayRight(arrK2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrK3);
        povLeftRed.writeArrayRight(arrK3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrK4);
        povLeftRed.writeArrayRight(arrK4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrK5);
        povLeftBlue.writeArrayRight(arrK5);
        wait_us(4000);
    }
    break;

case 'L':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrL1);
        povLeftRed.writeArrayRight(arrL1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrL2);
        povLeftRed.writeArrayRight(arrL2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrL3);
        povLeftRed.writeArrayRight(arrL3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrL4);
        povLeftRed.writeArrayRight(arrL4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrL5);
        povLeftRed.writeArrayRight(arrL5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrL1);
        povLeftGreen.writeArrayRight(arrL1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrL2);
        povLeftGreen.writeArrayRight(arrL2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrL3);
        povLeftGreen.writeArrayRight(arrL3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrL4);
        povLeftGreen.writeArrayRight(arrL4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrL5);
        povLeftGreen.writeArrayRight(arrL5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrL1);
        povLeftBlue.writeArrayRight(arrL1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrL2);
        povLeftBlue.writeArrayRight(arrL2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrL3);
        povLeftBlue.writeArrayRight(arrL3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrL4);
        povLeftBlue.writeArrayRight(arrL4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrL5);
        povLeftBlue.writeArrayRight(arrL5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrL1);
        povLeftBlue.writeArrayRight(arrL1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrL2);
        povLeftBlue.writeArrayRight(arrL2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrL3);
        povLeftRed.writeArrayRight(arrL3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrL4);
        povLeftRed.writeArrayRight(arrL4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrL5);
        povLeftBlue.writeArrayRight(arrL5);
        wait_us(4000);
    }
    break;

  case 'M':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrM1);
        povLeftRed.writeArrayRight(arrM1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrM2);
        povLeftRed.writeArrayRight(arrM2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrM3);
        povLeftRed.writeArrayRight(arrM3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrM4);
        povLeftRed.writeArrayRight(arrM4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrM5);
        povLeftRed.writeArrayRight(arrM5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrM1);
        povLeftGreen.writeArrayRight(arrM1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrM2);
        povLeftGreen.writeArrayRight(arrM2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrM3);
        povLeftGreen.writeArrayRight(arrM3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrM4);
        povLeftGreen.writeArrayRight(arrM4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrM5);
        povLeftGreen.writeArrayRight(arrM5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrM1);
        povLeftBlue.writeArrayRight(arrM1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrM2);
        povLeftBlue.writeArrayRight(arrM2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrM3);
        povLeftBlue.writeArrayRight(arrM3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrM4);
        povLeftBlue.writeArrayRight(arrM4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrM5);
        povLeftBlue.writeArrayRight(arrM5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrM1);
        povLeftBlue.writeArrayRight(arrM1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrM2);
        povLeftBlue.writeArrayRight(arrM2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrM3);
        povLeftRed.writeArrayRight(arrM3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrM4);
        povLeftRed.writeArrayRight(arrM4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrM5);
        povLeftBlue.writeArrayRight(arrM5);
        wait_us(4000);
    }
    break;

case 'N':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrN1);
        povLeftRed.writeArrayRight(arrN1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrN2);
        povLeftRed.writeArrayRight(arrN2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrN3);
        povLeftRed.writeArrayRight(arrN3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrN4);
        povLeftRed.writeArrayRight(arrN4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrN5);
        povLeftRed.writeArrayRight(arrN5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrN1);
        povLeftGreen.writeArrayRight(arrN1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrN2);
        povLeftGreen.writeArrayRight(arrN2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrN3);
        povLeftGreen.writeArrayRight(arrN3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrN4);
        povLeftGreen.writeArrayRight(arrN4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrN5);
        povLeftGreen.writeArrayRight(arrN5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrN1);
        povLeftBlue.writeArrayRight(arrN1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrN2);
        povLeftBlue.writeArrayRight(arrN2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrN3);
        povLeftBlue.writeArrayRight(arrN3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrN4);
        povLeftBlue.writeArrayRight(arrN4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrN5);
        povLeftBlue.writeArrayRight(arrN5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrN1);
        povLeftBlue.writeArrayRight(arrN1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrN2);
        povLeftBlue.writeArrayRight(arrN2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrN3);
        povLeftRed.writeArrayRight(arrN3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrN4);
        povLeftRed.writeArrayRight(arrN4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrN5);
        povLeftBlue.writeArrayRight(arrN5);
        wait_us(4000);
    }
    break;

case 'O':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arrO1);
        povLeftRed.writeArrayRight(arrO1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrO2);
        povLeftRed.writeArrayRight(arrO2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrO3);
        povLeftRed.writeArrayRight(arrO3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrO4);
        povLeftRed.writeArrayRight(arrO4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrO5);
        povLeftRed.writeArrayRight(arrO5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arrO1);
        povLeftGreen.writeArrayRight(arrO1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrO2);
        povLeftGreen.writeArrayRight(arrO2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrO3);
        povLeftGreen.writeArrayRight(arrO3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrO4);
        povLeftGreen.writeArrayRight(arrO4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrO5);
        povLeftGreen.writeArrayRight(arrO5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arrO1);
        povLeftBlue.writeArrayRight(arrO1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrO2);
        povLeftBlue.writeArrayRight(arrO2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrO3);
        povLeftBlue.writeArrayRight(arrO3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrO4);
        povLeftBlue.writeArrayRight(arrO4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrO5);
        povLeftBlue.writeArrayRight(arrO5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arrO1);
        povLeftBlue.writeArrayRight(arrO1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrO2);
        povLeftBlue.writeArrayRight(arrO2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrO3);
        povLeftRed.writeArrayRight(arrO3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrO4);
        povLeftRed.writeArrayRight(arrO4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrO5);
        povLeftBlue.writeArrayRight(arrO5);
        wait_us(4000);
    }
    break;

case 'P':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrP1);
        povLeftRed.writeArrayRight(arrP1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrP2);
        povLeftRed.writeArrayRight(arrP2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrP3);
        povLeftRed.writeArrayRight(arrP3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrP4);
        povLeftRed.writeArrayRight(arrP4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrP5);
        povLeftRed.writeArrayRight(arrP5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrP1);
        povLeftGreen.writeArrayRight(arrP1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrP2);
        povLeftGreen.writeArrayRight(arrP2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrP3);
        povLeftGreen.writeArrayRight(arrP3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrP4);
        povLeftGreen.writeArrayRight(arrP4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrP5);
        povLeftGreen.writeArrayRight(arrP5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrP1);
        povLeftBlue.writeArrayRight(arrP1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrP2);
        povLeftBlue.writeArrayRight(arrP2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrP3);
        povLeftBlue.writeArrayRight(arrP3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrP4);
        povLeftBlue.writeArrayRight(arrP4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrP5);
        povLeftBlue.writeArrayRight(arrP5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrP1);
        povLeftBlue.writeArrayRight(arrP1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrP2);
        povLeftBlue.writeArrayRight(arrP2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrP3);
        povLeftRed.writeArrayRight(arrP3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrP4);
        povLeftRed.writeArrayRight(arrP4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrP5);
        povLeftBlue.writeArrayRight(arrP5);
        wait_us(4000);
    }
    break;

case 'Q':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrQ1);
        povLeftRed.writeArrayRight(arrQ1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrQ2);
        povLeftRed.writeArrayRight(arrQ2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrQ3);
        povLeftRed.writeArrayRight(arrQ3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrQ4);
        povLeftRed.writeArrayRight(arrQ4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrQ5);
        povLeftRed.writeArrayRight(arrQ5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrQ1);
        povLeftGreen.writeArrayRight(arrQ1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrQ2);
        povLeftGreen.writeArrayRight(arrQ2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrQ3);
        povLeftGreen.writeArrayRight(arrQ3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrQ4);
        povLeftGreen.writeArrayRight(arrQ4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrQ5);
        povLeftGreen.writeArrayRight(arrQ5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrQ1);
        povLeftBlue.writeArrayRight(arrQ1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrQ2);
        povLeftBlue.writeArrayRight(arrQ2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrQ3);
        povLeftBlue.writeArrayRight(arrQ3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrQ4);
        povLeftBlue.writeArrayRight(arrQ4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrQ5);
        povLeftBlue.writeArrayRight(arrQ5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrQ1);
        povLeftBlue.writeArrayRight(arrQ1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrQ2);
        povLeftBlue.writeArrayRight(arrQ2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrQ3);
        povLeftRed.writeArrayRight(arrQ3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrQ4);
        povLeftRed.writeArrayRight(arrQ4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrQ5);
        povLeftBlue.writeArrayRight(arrQ5);
        wait_us(4000);
    }
    break;

case 'R':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrR1);
        povLeftRed.writeArrayRight(arrR1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrR2);
        povLeftRed.writeArrayRight(arrR2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrR3);
        povLeftRed.writeArrayRight(arrR3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrR4);
        povLeftRed.writeArrayRight(arrR4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrR5);
        povLeftRed.writeArrayRight(arrR5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrR1);
        povLeftGreen.writeArrayRight(arrR1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrR2);
        povLeftGreen.writeArrayRight(arrR2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrR3);
        povLeftGreen.writeArrayRight(arrR3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrR4);
        povLeftGreen.writeArrayRight(arrR4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrR5);
        povLeftGreen.writeArrayRight(arrR5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrR1);
        povLeftBlue.writeArrayRight(arrR1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrR2);
        povLeftBlue.writeArrayRight(arrR2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrR3);
        povLeftBlue.writeArrayRight(arrR3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrR4);
        povLeftBlue.writeArrayRight(arrR4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrR5);
        povLeftBlue.writeArrayRight(arrR5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrR1);
        povLeftBlue.writeArrayRight(arrR1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrR2);
        povLeftBlue.writeArrayRight(arrR2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrR3);
        povLeftRed.writeArrayRight(arrR3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrR4);
        povLeftRed.writeArrayRight(arrR4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrR5);
        povLeftBlue.writeArrayRight(arrR5);
        wait_us(4000);
    }
    break;

case 'S':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrS1);
        povLeftRed.writeArrayRight(arrS1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrS2);
        povLeftRed.writeArrayRight(arrS2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrS3);
        povLeftRed.writeArrayRight(arrS3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrS4);
        povLeftRed.writeArrayRight(arrS4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrS5);
        povLeftRed.writeArrayRight(arrS5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrS1);
        povLeftGreen.writeArrayRight(arrS1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrS2);
        povLeftGreen.writeArrayRight(arrS2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrS3);
        povLeftGreen.writeArrayRight(arrS3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrS4);
        povLeftGreen.writeArrayRight(arrS4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrS5);
        povLeftGreen.writeArrayRight(arrS5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrS1);
        povLeftBlue.writeArrayRight(arrS1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrS2);
        povLeftBlue.writeArrayRight(arrS2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrS3);
        povLeftBlue.writeArrayRight(arrS3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrS4);
        povLeftBlue.writeArrayRight(arrS4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrS5);
        povLeftBlue.writeArrayRight(arrS5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrS1);
        povLeftBlue.writeArrayRight(arrS1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrS2);
        povLeftBlue.writeArrayRight(arrS2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrS3);
        povLeftRed.writeArrayRight(arrS3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrS4);
        povLeftRed.writeArrayRight(arrS4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrS5);
        povLeftBlue.writeArrayRight(arrS5);
        wait_us(4000);
    }
    break;

case 'T':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrT1);
        povLeftRed.writeArrayRight(arrT1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrT2);
        povLeftRed.writeArrayRight(arrT2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrT3);
        povLeftRed.writeArrayRight(arrT3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrT4);
        povLeftRed.writeArrayRight(arrT4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrT5);
        povLeftRed.writeArrayRight(arrT5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrT1);
        povLeftGreen.writeArrayRight(arrT1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrT2);
        povLeftGreen.writeArrayRight(arrT2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrT3);
        povLeftGreen.writeArrayRight(arrT3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrT4);
        povLeftGreen.writeArrayRight(arrT4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrT5);
        povLeftGreen.writeArrayRight(arrT5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrT1);
        povLeftBlue.writeArrayRight(arrT1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrT2);
        povLeftBlue.writeArrayRight(arrT2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrT3);
        povLeftBlue.writeArrayRight(arrT3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrT4);
        povLeftBlue.writeArrayRight(arrT4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrT5);
        povLeftBlue.writeArrayRight(arrT5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrT1);
        povLeftBlue.writeArrayRight(arrT1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrT2);
        povLeftBlue.writeArrayRight(arrT2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrT3);
        povLeftRed.writeArrayRight(arrT3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrT4);
        povLeftRed.writeArrayRight(arrT4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrT5);
        povLeftBlue.writeArrayRight(arrT5);
        wait_us(4000);
    }
    break;

case 'U':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrU1);
        povLeftRed.writeArrayRight(arrU1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrU2);
        povLeftRed.writeArrayRight(arrU2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrU3);
        povLeftRed.writeArrayRight(arrU3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrU4);
        povLeftRed.writeArrayRight(arrU4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrU5);
        povLeftRed.writeArrayRight(arrU5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrU1);
        povLeftGreen.writeArrayRight(arrU1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrU2);
        povLeftGreen.writeArrayRight(arrU2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrU3);
        povLeftGreen.writeArrayRight(arrU3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrU4);
        povLeftGreen.writeArrayRight(arrU4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrU5);
        povLeftGreen.writeArrayRight(arrU5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrU1);
        povLeftBlue.writeArrayRight(arrU1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrU2);
        povLeftBlue.writeArrayRight(arrU2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrU3);
        povLeftBlue.writeArrayRight(arrU3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrU4);
        povLeftBlue.writeArrayRight(arrU4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrU5);
        povLeftBlue.writeArrayRight(arrU5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrU1);
        povLeftBlue.writeArrayRight(arrU1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrU2);
        povLeftBlue.writeArrayRight(arrU2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrU3);
        povLeftRed.writeArrayRight(arrU3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrU4);
        povLeftRed.writeArrayRight(arrU4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrU5);
        povLeftBlue.writeArrayRight(arrU5);
        wait_us(4000);
    }
    break;

case 'V':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrV1);
        povLeftRed.writeArrayRight(arrV1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrV2);
        povLeftRed.writeArrayRight(arrV2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrV3);
        povLeftRed.writeArrayRight(arrV3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrV4);
        povLeftRed.writeArrayRight(arrV4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrV5);
        povLeftRed.writeArrayRight(arrV5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrV1);
        povLeftGreen.writeArrayRight(arrV1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrV2);
        povLeftGreen.writeArrayRight(arrV2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrV3);
        povLeftGreen.writeArrayRight(arrV3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrV4);
        povLeftGreen.writeArrayRight(arrV4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrV5);
        povLeftGreen.writeArrayRight(arrV5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrV1);
        povLeftBlue.writeArrayRight(arrV1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrV2);
        povLeftBlue.writeArrayRight(arrV2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrV3);
        povLeftBlue.writeArrayRight(arrV3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrV4);
        povLeftBlue.writeArrayRight(arrV4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrV5);
        povLeftBlue.writeArrayRight(arrV5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrV1);
        povLeftBlue.writeArrayRight(arrV1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrV2);
        povLeftBlue.writeArrayRight(arrV2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrV3);
        povLeftRed.writeArrayRight(arrV3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrV4);
        povLeftRed.writeArrayRight(arrV4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrV5);
        povLeftBlue.writeArrayRight(arrV5);
        wait_us(4000);
    }
    break;

case 'W':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrW1);
        povLeftRed.writeArrayRight(arrW1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrW2);
        povLeftRed.writeArrayRight(arrW2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrW3);
        povLeftRed.writeArrayRight(arrW3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrW4);
        povLeftRed.writeArrayRight(arrW4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrW5);
        povLeftRed.writeArrayRight(arrW5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrW1);
        povLeftGreen.writeArrayRight(arrW1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrW2);
        povLeftGreen.writeArrayRight(arrW2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrW3);
        povLeftGreen.writeArrayRight(arrW3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrW4);
        povLeftGreen.writeArrayRight(arrW4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrW5);
        povLeftGreen.writeArrayRight(arrW5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrW1);
        povLeftBlue.writeArrayRight(arrW1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrW2);
        povLeftBlue.writeArrayRight(arrW2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrW3);
        povLeftBlue.writeArrayRight(arrW3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrW4);
        povLeftBlue.writeArrayRight(arrW4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrW5);
        povLeftBlue.writeArrayRight(arrW5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrW1);
        povLeftBlue.writeArrayRight(arrW1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrW2);
        povLeftBlue.writeArrayRight(arrW2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrW3);
        povLeftRed.writeArrayRight(arrW3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrW4);
        povLeftRed.writeArrayRight(arrW4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrW5);
        povLeftBlue.writeArrayRight(arrW5);
        wait_us(4000);
    }
    break;

case 'X':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrX1);
        povLeftRed.writeArrayRight(arrX1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrX2);
        povLeftRed.writeArrayRight(arrX2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrX3);
        povLeftRed.writeArrayRight(arrX3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrX4);
        povLeftRed.writeArrayRight(arrX4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrX5);
        povLeftRed.writeArrayRight(arrX5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrX1);
        povLeftGreen.writeArrayRight(arrX1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrX2);
        povLeftGreen.writeArrayRight(arrX2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrX3);
        povLeftGreen.writeArrayRight(arrX3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrX4);
        povLeftGreen.writeArrayRight(arrX4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrX5);
        povLeftGreen.writeArrayRight(arrX5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrX1);
        povLeftBlue.writeArrayRight(arrX1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrX2);
        povLeftBlue.writeArrayRight(arrX2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrX3);
        povLeftBlue.writeArrayRight(arrX3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrX4);
        povLeftBlue.writeArrayRight(arrX4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrX5);
        povLeftBlue.writeArrayRight(arrX5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrX1);
        povLeftBlue.writeArrayRight(arrX1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrX2);
        povLeftBlue.writeArrayRight(arrX2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrX3);
        povLeftRed.writeArrayRight(arrX3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrX4);
        povLeftRed.writeArrayRight(arrX4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrX5);
        povLeftBlue.writeArrayRight(arrX5);
        wait_us(4000);
    }
    break;

case 'Y':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrY1);
        povLeftRed.writeArrayRight(arrY1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrY2);
        povLeftRed.writeArrayRight(arrY2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrY3);
        povLeftRed.writeArrayRight(arrY3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrY4);
        povLeftRed.writeArrayRight(arrY4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrY5);
        povLeftRed.writeArrayRight(arrY5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrY1);
        povLeftGreen.writeArrayRight(arrY1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrY2);
        povLeftGreen.writeArrayRight(arrY2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrY3);
        povLeftGreen.writeArrayRight(arrY3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrY4);
        povLeftGreen.writeArrayRight(arrY4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrY5);
        povLeftGreen.writeArrayRight(arrY5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrY1);
        povLeftBlue.writeArrayRight(arrY1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrY2);
        povLeftBlue.writeArrayRight(arrY2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrY3);
        povLeftBlue.writeArrayRight(arrY3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrY4);
        povLeftBlue.writeArrayRight(arrY4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrY5);
        povLeftBlue.writeArrayRight(arrY5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrY1);
        povLeftBlue.writeArrayRight(arrY1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrY2);
        povLeftBlue.writeArrayRight(arrY2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrY3);
        povLeftRed.writeArrayRight(arrY3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrY4);
        povLeftRed.writeArrayRight(arrY4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrY5);
        povLeftBlue.writeArrayRight(arrY5);
        wait_us(4000);
    }
    break;

case 'Z':
    if (colour2 == 1) {
        //povRightRed.writeArrayRight(arrZ1);
        povLeftRed.writeArrayRight(arrZ1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrZ2);
        povLeftRed.writeArrayRight(arrZ2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrZ3);
        povLeftRed.writeArrayRight(arrZ3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrZ4);
        povLeftRed.writeArrayRight(arrZ4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrZ5);
        povLeftRed.writeArrayRight(arrZ5);
        wait_us(4000);
    } else if (colour2 == 2) {
        //povRightGreen.writeArrayRight(arrZ1);
        povLeftGreen.writeArrayRight(arrZ1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrZ2);
        povLeftGreen.writeArrayRight(arrZ2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrZ3);
        povLeftGreen.writeArrayRight(arrZ3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrZ4);
        povLeftGreen.writeArrayRight(arrZ4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrZ5);
        povLeftGreen.writeArrayRight(arrZ5);
        wait_us(4000);
    } else if (colour2 == 3) {
        //povRightBlue.writeArrayRight(arrZ1);
        povLeftBlue.writeArrayRight(arrZ1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrZ2);
        povLeftBlue.writeArrayRight(arrZ2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrZ3);
        povLeftBlue.writeArrayRight(arrZ3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrZ4);
        povLeftBlue.writeArrayRight(arrZ4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrZ5);
        povLeftBlue.writeArrayRight(arrZ5);
        wait_us(4000);
    } else {
        //povRightRed.writeArrayRight(arrZ1);
        povLeftBlue.writeArrayRight(arrZ1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrZ2);
        povLeftBlue.writeArrayRight(arrZ2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arrZ3);
        povLeftRed.writeArrayRight(arrZ3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arrZ4);
        povLeftRed.writeArrayRight(arrZ4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arrZ5);
        povLeftBlue.writeArrayRight(arrZ5);
        wait_us(4000);
    }
    break;

    case '0':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr0_1);
        povLeftRed.writeArrayRight(arr0_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr0_2);
        povLeftRed.writeArrayRight(arr0_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr0_3);
        povLeftRed.writeArrayRight(arr0_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr0_4);
        povLeftRed.writeArrayRight(arr0_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr0_5);
        povLeftRed.writeArrayRight(arr0_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr0_1);
        povLeftGreen.writeArrayRight(arr0_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr0_2);
        povLeftGreen.writeArrayRight(arr0_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr0_3);
        povLeftGreen.writeArrayRight(arr0_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr0_4);
        povLeftGreen.writeArrayRight(arr0_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr0_5);
        povLeftGreen.writeArrayRight(arr0_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr0_1);
        povLeftBlue.writeArrayRight(arr0_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr0_2);
        povLeftBlue.writeArrayRight(arr0_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr0_3);
        povLeftBlue.writeArrayRight(arr0_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr0_4);
        povLeftBlue.writeArrayRight(arr0_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr0_5);
        povLeftBlue.writeArrayRight(arr0_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr0_1);
        povLeftBlue.writeArrayRight(arr0_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr0_2);
        povLeftBlue.writeArrayRight(arr0_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr0_3);
        povLeftRed.writeArrayRight(arr0_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr0_4);
        povLeftRed.writeArrayRight(arr0_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr0_5);
        povLeftBlue.writeArrayRight(arr0_5);
        wait_us(4000);
    }
    break;
case '1':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr1_1);
        povLeftRed.writeArrayRight(arr1_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr1_2);
        povLeftRed.writeArrayRight(arr1_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr1_3);
        povLeftRed.writeArrayRight(arr1_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr1_4);
        povLeftRed.writeArrayRight(arr1_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr1_5);
        povLeftRed.writeArrayRight(arr1_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr1_1);
        povLeftGreen.writeArrayRight(arr1_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr1_2);
        povLeftGreen.writeArrayRight(arr1_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr1_3);
        povLeftGreen.writeArrayRight(arr1_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr1_4);
        povLeftGreen.writeArrayRight(arr1_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr1_5);
        povLeftGreen.writeArrayRight(arr1_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr1_1);
        povLeftBlue.writeArrayRight(arr1_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr1_2);
        povLeftBlue.writeArrayRight(arr1_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr1_3);
        povLeftBlue.writeArrayRight(arr1_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr1_4);
        povLeftBlue.writeArrayRight(arr1_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr1_5);
        povLeftBlue.writeArrayRight(arr1_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr1_1);
        povLeftBlue.writeArrayRight(arr1_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr1_2);
        povLeftBlue.writeArrayRight(arr1_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr1_3);
        povLeftRed.writeArrayRight(arr1_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr1_4);
        povLeftRed.writeArrayRight(arr1_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr1_5);
        povLeftBlue.writeArrayRight(arr1_5);
        wait_us(4000);
    }
    break;

case '2':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr2_1);
        povLeftRed.writeArrayRight(arr2_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr2_2);
        povLeftRed.writeArrayRight(arr2_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr2_3);
        povLeftRed.writeArrayRight(arr2_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr2_4);
        povLeftRed.writeArrayRight(arr2_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr2_5);
        povLeftRed.writeArrayRight(arr2_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr2_1);
        povLeftGreen.writeArrayRight(arr2_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr2_2);
        povLeftGreen.writeArrayRight(arr2_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr2_3);
        povLeftGreen.writeArrayRight(arr2_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr2_4);
        povLeftGreen.writeArrayRight(arr2_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr2_5);
        povLeftGreen.writeArrayRight(arr2_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr2_1);
        povLeftBlue.writeArrayRight(arr2_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr2_2);
        povLeftBlue.writeArrayRight(arr2_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr2_3);
        povLeftBlue.writeArrayRight(arr2_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr2_4);
        povLeftBlue.writeArrayRight(arr2_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr2_5);
        povLeftBlue.writeArrayRight(arr2_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr2_1);
        povLeftBlue.writeArrayRight(arr2_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr2_2);
        povLeftBlue.writeArrayRight(arr2_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr2_3);
        povLeftRed.writeArrayRight(arr2_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr2_4);
        povLeftRed.writeArrayRight(arr2_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr2_5);
        povLeftBlue.writeArrayRight(arr2_5);
        wait_us(4000);
    }
    break;

case '3':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr3_1);
        povLeftRed.writeArrayRight(arr3_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr3_2);
        povLeftRed.writeArrayRight(arr3_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr3_3);
        povLeftRed.writeArrayRight(arr3_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr3_4);
        povLeftRed.writeArrayRight(arr3_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr3_5);
        povLeftRed.writeArrayRight(arr3_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr3_1);
        povLeftGreen.writeArrayRight(arr3_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr3_2);
        povLeftGreen.writeArrayRight(arr3_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr3_3);
        povLeftGreen.writeArrayRight(arr3_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr3_4);
        povLeftGreen.writeArrayRight(arr3_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr3_5);
        povLeftGreen.writeArrayRight(arr3_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr3_1);
        povLeftBlue.writeArrayRight(arr3_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr3_2);
        povLeftBlue.writeArrayRight(arr3_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr3_3);
        povLeftBlue.writeArrayRight(arr3_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr3_4);
        povLeftBlue.writeArrayRight(arr3_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr3_5);
        povLeftBlue.writeArrayRight(arr3_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr3_1);
        povLeftBlue.writeArrayRight(arr3_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr3_2);
        povLeftBlue.writeArrayRight(arr3_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr3_3);
        povLeftRed.writeArrayRight(arr3_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr3_4);
        povLeftRed.writeArrayRight(arr3_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr3_5);
        povLeftBlue.writeArrayRight(arr3_5);
        wait_us(4000);
    }
    break;

case '4':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr4_1);
        povLeftRed.writeArrayRight(arr4_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr4_2);
        povLeftRed.writeArrayRight(arr4_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr4_3);
        povLeftRed.writeArrayRight(arr4_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr4_4);
        povLeftRed.writeArrayRight(arr4_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr4_5);
        povLeftRed.writeArrayRight(arr4_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr4_1);
        povLeftGreen.writeArrayRight(arr4_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr4_2);
        povLeftGreen.writeArrayRight(arr4_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr4_3);
        povLeftGreen.writeArrayRight(arr4_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr4_4);
        povLeftGreen.writeArrayRight(arr4_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr4_5);
        povLeftGreen.writeArrayRight(arr4_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr4_1);
        povLeftBlue.writeArrayRight(arr4_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr4_2);
        povLeftBlue.writeArrayRight(arr4_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr4_3);
        povLeftBlue.writeArrayRight(arr4_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr4_4);
        povLeftBlue.writeArrayRight(arr4_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr4_5);
        povLeftBlue.writeArrayRight(arr4_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr4_1);
        povLeftBlue.writeArrayRight(arr4_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr4_2);
        povLeftBlue.writeArrayRight(arr4_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr4_3);
        povLeftRed.writeArrayRight(arr4_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr4_4);
        povLeftRed.writeArrayRight(arr4_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr4_5);
        povLeftBlue.writeArrayRight(arr4_5);
        wait_us(4000);
    }
    break;
case '5':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr5_1);
        povLeftRed.writeArrayRight(arr5_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr5_2);
        povLeftRed.writeArrayRight(arr5_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr5_3);
        povLeftRed.writeArrayRight(arr5_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr5_4);
        povLeftRed.writeArrayRight(arr5_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr5_5);
        povLeftRed.writeArrayRight(arr5_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr5_1);
        povLeftGreen.writeArrayRight(arr5_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr5_2);
        povLeftGreen.writeArrayRight(arr5_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr5_3);
        povLeftGreen.writeArrayRight(arr5_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr5_4);
        povLeftGreen.writeArrayRight(arr5_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr5_5);
        povLeftGreen.writeArrayRight(arr5_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr5_1);
        povLeftBlue.writeArrayRight(arr5_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr5_2);
        povLeftBlue.writeArrayRight(arr5_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr5_3);
        povLeftBlue.writeArrayRight(arr5_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr5_4);
        povLeftBlue.writeArrayRight(arr5_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr5_5);
        povLeftBlue.writeArrayRight(arr5_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr5_1);
        povLeftBlue.writeArrayRight(arr5_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr5_2);
        povLeftBlue.writeArrayRight(arr5_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr5_3);
        povLeftRed.writeArrayRight(arr5_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr5_4);
        povLeftRed.writeArrayRight(arr5_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr5_5);
        povLeftBlue.writeArrayRight(arr5_5);
        wait_us(4000);
    }
    break;

case '6':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr6_1);
        povLeftRed.writeArrayRight(arr6_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr6_2);
        povLeftRed.writeArrayRight(arr6_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr6_3);
        povLeftRed.writeArrayRight(arr6_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr6_4);
        povLeftRed.writeArrayRight(arr6_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr6_5);
        povLeftRed.writeArrayRight(arr6_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr6_1);
        povLeftGreen.writeArrayRight(arr6_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr6_2);
        povLeftGreen.writeArrayRight(arr6_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr6_3);
        povLeftGreen.writeArrayRight(arr6_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr6_4);
        povLeftGreen.writeArrayRight(arr6_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr6_5);
        povLeftGreen.writeArrayRight(arr6_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr6_1);
        povLeftBlue.writeArrayRight(arr6_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr6_2);
        povLeftBlue.writeArrayRight(arr6_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr6_3);
        povLeftBlue.writeArrayRight(arr6_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr6_4);
        povLeftBlue.writeArrayRight(arr6_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr6_5);
        povLeftBlue.writeArrayRight(arr6_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr6_1);
        povLeftBlue.writeArrayRight(arr6_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr6_2);
        povLeftBlue.writeArrayRight(arr6_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr6_3);
        povLeftRed.writeArrayRight(arr6_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr6_4);
        povLeftRed.writeArrayRight(arr6_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr6_5);
        povLeftBlue.writeArrayRight(arr6_5);
        wait_us(4000);
    }
    break;

case '7':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr7_1);
        povLeftRed.writeArrayRight(arr7_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr7_2);
        povLeftRed.writeArrayRight(arr7_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr7_3);
        povLeftRed.writeArrayRight(arr7_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr7_4);
        povLeftRed.writeArrayRight(arr7_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr7_5);
        povLeftRed.writeArrayRight(arr7_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr7_1);
        povLeftGreen.writeArrayRight(arr7_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr7_2);
        povLeftGreen.writeArrayRight(arr7_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr7_3);
        povLeftGreen.writeArrayRight(arr7_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr7_4);
        povLeftGreen.writeArrayRight(arr7_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr7_5);
        povLeftGreen.writeArrayRight(arr7_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr7_1);
        povLeftBlue.writeArrayRight(arr7_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr7_2);
        povLeftBlue.writeArrayRight(arr7_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr7_3);
        povLeftBlue.writeArrayRight(arr7_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr7_4);
        povLeftBlue.writeArrayRight(arr7_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr7_5);
        povLeftBlue.writeArrayRight(arr7_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr7_1);
        povLeftBlue.writeArrayRight(arr7_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr7_2);
        povLeftBlue.writeArrayRight(arr7_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr7_3);
        povLeftRed.writeArrayRight(arr7_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr7_4);
        povLeftRed.writeArrayRight(arr7_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr7_5);
        povLeftBlue.writeArrayRight(arr7_5);
        wait_us(4000);
    }
    break;

case '8':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr8_1);
        povLeftRed.writeArrayRight(arr8_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr8_2);
        povLeftRed.writeArrayRight(arr8_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr8_3);
        povLeftRed.writeArrayRight(arr8_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr8_4);
        povLeftRed.writeArrayRight(arr8_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr8_5);
        povLeftRed.writeArrayRight(arr8_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr8_1);
        povLeftGreen.writeArrayRight(arr8_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr8_2);
        povLeftGreen.writeArrayRight(arr8_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr8_3);
        povLeftGreen.writeArrayRight(arr8_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr8_4);
        povLeftGreen.writeArrayRight(arr8_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr8_5);
        povLeftGreen.writeArrayRight(arr8_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr8_1);
        povLeftBlue.writeArrayRight(arr8_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr8_2);
        povLeftBlue.writeArrayRight(arr8_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr8_3);
        povLeftBlue.writeArrayRight(arr8_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr8_4);
        povLeftBlue.writeArrayRight(arr8_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr8_5);
        povLeftBlue.writeArrayRight(arr8_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr8_1);
        povLeftBlue.writeArrayRight(arr8_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr8_2);
        povLeftBlue.writeArrayRight(arr8_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr8_3);
        povLeftRed.writeArrayRight(arr8_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr8_4);
        povLeftRed.writeArrayRight(arr8_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr8_5);
        povLeftBlue.writeArrayRight(arr8_5);
        wait_us(4000);
    }
    break;

case '9':
    if (colour2 == 1) { // Red
        //povRightRed.writeArrayRight(arr9_1);
        povLeftRed.writeArrayRight(arr9_1);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr9_2);
        povLeftRed.writeArrayRight(arr9_2);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr9_3);
        povLeftRed.writeArrayRight(arr9_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr9_4);
        povLeftRed.writeArrayRight(arr9_4);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr9_5);
        povLeftRed.writeArrayRight(arr9_5);
        wait_us(4000);
    } else if (colour2 == 2) { // Green
        //povRightGreen.writeArrayRight(arr9_1);
        povLeftGreen.writeArrayRight(arr9_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr9_2);
        povLeftGreen.writeArrayRight(arr9_2);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr9_3);
        povLeftGreen.writeArrayRight(arr9_3);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr9_4);
        povLeftGreen.writeArrayRight(arr9_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr9_5);
        povLeftGreen.writeArrayRight(arr9_5);
        wait_us(4000);
    } else if (colour2 == 3) { // Blue
        //povRightBlue.writeArrayRight(arr9_1);
        povLeftBlue.writeArrayRight(arr9_1);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr9_2);
        povLeftBlue.writeArrayRight(arr9_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr9_3);
        povLeftBlue.writeArrayRight(arr9_3);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr9_4);
        povLeftBlue.writeArrayRight(arr9_4);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr9_5);
        povLeftBlue.writeArrayRight(arr9_5);
        wait_us(4000);
    } else { // Disco
        //povRightRed.writeArrayRight(arr9_1);
        povLeftBlue.writeArrayRight(arr9_1);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr9_2);
        povLeftBlue.writeArrayRight(arr9_2);
        wait_us(4000);
        //povRightBlue.writeArrayRight(arr9_3);
        povLeftRed.writeArrayRight(arr9_3);
        wait_us(4000);
        //povRightRed.writeArrayRight(arr9_4);
        povLeftRed.writeArrayRight(arr9_4);
        wait_us(4000);
        //povRightGreen.writeArrayRight(arr9_5);
        povLeftBlue.writeArrayRight(arr9_5);
        wait_us(4000);
    }
    break;
    

    default: {

         if (colour2 == 1) { // Red
        
        povLeftRed.writeArrayRight(space1);
       wait_us(4000);
    } else if (colour2 == 2) { // Green
        povLeftGreen.writeArrayRight(space1);
       wait_us(4000);
    } else if (colour2 == 3) { // Blue
         povLeftBlue.writeArrayRight(space1);
       wait_us(4000);
    } else { // Disco
        povLeftRed.writeArrayRight(space1);
       wait_us(4000);
        povLeftBlue.writeArrayRight(space1);
       wait_us(4000);
        povLeftGreen.writeArrayRight(space1);
       wait_us(4000);
    
    }
    
        
    }
        break;
    
}
}
}

// ***** User function definitions *****
bool startsWith(char inputStr[], char searchStr[]) { //tests if inputStr starts with searchStr
int i;
bool flag = true; //match flag ‐ assumes there is a match
if(strlen(inputStr) < strlen(searchStr)) //input string shorter than search string
return false; //no match flag
else {
for(i = 0; i<strlen(searchStr); i++) { //inspect each character
if(inputStr[i] != searchStr[i]) //characters mismatch
flag = false; //no match flag
}
return flag; //return status of flag
}
}


// ***** Main program *****
int main() {
//variables for UART communication
char instr[1]; //string to store received characters ‐ only going to receive one char at a time
int ret; //temporary integer variable
char tempMsg[100]; //string for temporarily storing parts of a new message

char msg[100]; //string for storing a complete received message
char str[100]; //string for transmitting messages
int index=0; //to indicate the current character position in tempMsg
bool newMsg = false; //flag to indicate that a new complete message was received
//variables for message handling
char cmd[100]; //dummy variable for reading command string
char cmd2[100];
char cmd3;
int par, par2; //variable that contains the parameter value from the received msg


blueTooth.set_blocking(false); //enable non‐blocking mode
printf("Waiting for a POV Display message...\n"); //debug terminal message
 char arrSpace[] = {1,0,0,0,0,0,0,0};
//while(newMsgFlag == false){
    for(int j = 0; j< 5;j++){
        for(int i =0; i < 8;i++){
            povRightBlue.writeBitRight(arrSpace[i]);// Default case for unsupported characters
            povLeftBlue.writeBitLeft(arrSpace[i]);// Default case for unsupported characters
            wait_us(50000);
            povRightRed.writeBitRight(arrSpace[i]);// Default case for unsupported characters
            povLeftRed.writeBitLeft(arrSpace[i]);// Default case for unsupported characters
            wait_us(50000);
            povRightGreen.writeBitRight(arrSpace[i]);// Default case for unsupported characters
            povLeftGreen.writeBitLeft(arrSpace[i]);// Default case for unsupported characters
            wait_us(50000);
            povRightRed.writeBitRight(arrSpace[i]);// Default case for unsupported characters
            povLeftRed.writeBitLeft(arrSpace[i]);// Default case for unsupported characters
            wait_us(50000);
            povRightBlue.writeBitRight(arrSpace[i]);// Default case for unsupported characters
            povLeftBlue.writeBitLeft(arrSpace[i]);// Default case for unsupported characters
            wait_us(50000);
             povRightGreen.writeBitRight(arrSpace[i]);// Default case for unsupported characters
            povLeftGreen.writeBitLeft(arrSpace[i]);// Default case for unsupported characters
            //wait_us(50000);
        }
    }
//}

while (1) {
//UART receiving task ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
ret = blueTooth.read(instr, 1); //check if there is one character available in RX buffer
if(ret > 0) { //if a character is available ‐ instr[0] is the character
if(instr[0] == '#') { //if the last character of message is received
tempMsg[index] = '\0'; //add the null character to convert to proper string
strcpy(msg, tempMsg); //transfer the temp message to msg
index = 0; //reset the character index to 0
newMsg = true; //set the flag to indicate new message was received
}
else if(instr[0] == '!') { //if the received character is the first character of the message
index = 0; //reset the character index to 0
}
else {
tempMsg[index] = instr[0]; //store the received character in the message string at the index position
index++; //increment the character index
}
}

//message handling task ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
if(newMsg == true) {    //check if a new complete message was received
            //general message format: !<command> <parameter1(optional)> <parameter2(optional)>#  
         
            printf("new message recieved\n");
            printf("%s\n", msg);
            if(startsWith(msg, (char*)"TEX") != NULL) { 
                sscanf(msg, "%s %s %s %d %d",&cmd2, &cmd, &cmd3, &par, &par2);    //get par1 and par2 from string

                colour = par;
                colour2 = par2;
                printf("%s\n",&cmd);
                sprintf(newString, "%s\n", &cmd); //send characters to a string
                printf("%c\n",newString[0]);
                printf("%s\n",&cmd3);
                sprintf(newString2, "%s\n", &cmd3); //send characters to a string
                printf("%c\n",newString2[0]);   
            }
        }
    //printf("CASE string");
     a0 = newString[0];
     a1 = newString[1];
     a2 = newString[2];
     a3 = newString[3];
     a4 = newString[4];
     a5 = newString[5];
     a6 = newString[6];
     a7 = newString[7];
     a8 = newString[8];
     a9 = newString[9];
     

     aa = newString2[0];
     ab = newString2[1];
     ac = newString2[2];
     ad = newString2[3];
     ae = newString2[4];
     af = newString2[5];
     ag = newString2[6];
     ah = newString2[7];
     ai = newString2[8];
     aj = newString2[9];
    


   // printf("Case Shift");
    //if(IrSensorFunction() == 0){
            newMsg = false;  //clear flag to indicate the message was responded to
char q;
char a;

    wait_us(3000);
    alphaR(a);
    alphaL(q);
    wait_us(1000);
    alphaR(a9);
    alphaL(aj);
    wait_us(1000);
    alphaR(a8);
    alphaL(ai);
    wait_us(1000);
    alphaR(a7);
    alphaL(ah);
    wait_us(1000);
    alphaR(a6);
    alphaL(ag);
    wait_us(1000);
    alphaR(a5);
    alphaL(af);
    wait_us(1000);
    alphaR(a4);
    alphaL(ae);
    wait_us(1000);
    alphaR(a3);
    alphaL(ad);
    wait_us(1000);
    alphaR(a2);
    alphaL(ac);
    wait_us(1000);
    alphaR(a1);
    alphaL(ab);
    wait_us(1000);
    alphaR(a0);
    alphaL(aa);
    wait_us(1000);
    alphaR(a);
    alphaL(q);
    wait_us(3000);
   

    
        
}
}