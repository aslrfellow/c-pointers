#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pointer_basic();
void pointer_const();
void void_pointers();
void arrays();
void pointer_arrays();
void pointer_arithmetic();
void passByReference();
void squareIt2(int * const input);
void squareIt1(int * const input);
void passByReferencemalloc();
void mallocinput();

char* sayIt(char *input) {
    char *s = NULL;
    s = (char *)malloc(100);
    sprintf(s, "Name is %s, len is %d", input, strlen(input));
    free(s);
    return s;
}

int main() {

     //mallocinput();
    //hello();
    printf(sayIt("aaaaaa"));


    return 0;
}

void mallocinput() {
    int size;
    printf("\nEnter size of memory: ");
    scanf("%d", &size);

    char *text = NULL;
    text = (char *)malloc(size * sizeof(char));
    printf("\nEnter name: ");
    scanf("%s", text);
    printf("\nYou entered: %s ", text);
    free(text);
    text = NULL;


//    char input[10];
//    printf("Enter number: ");
//    scanf("%s",&input);
//    printf("The number is %s, number is %d\n", input, atoi(input));
//
//    char name[10];
//    printf("Enter name: ");
//    scanf("%s",&name);
//    printf("The name is %s\n", name);
//
//    char *pName = NULL;
//    pName =  (char *)malloc(10* sizeof(char));
//    strcpy(pName, name);
//    printf("Name in memory is %s", pName);

}
void dynamicmemory() {
    char *s = NULL;
    s = (char *)malloc(10);
    s = "ABC";
    printf("value %s, address = %p, ... = %u\n",s, s, s);

}
void squareIt1(int * const input) {
    int b;
    b = *input;
    b = b * b;
    *input = b;

}

void passByReferencemalloc() {
    int *num = (int *)malloc(sizeof(int));
    *num = 5;
    squareIt2(num); // no & here as it is pointer already
    printf("Value is %d\n", *num);
    free(num);
}


void squareIt2(int * const input) {
    *input = (*input) * (*input);
}

void passByReference() {
    int i = 6;
    squareIt1(&i);
    printf("Value is %d\n", i);
}
void mystrelnmain() {

    char intput[] = "My string input";
    int i = mystrlen3(intput);
    printf("len is %d", i);

}


int mystrlen1(const char *inputStr) {
    int i = 0;
    while(*inputStr) {
        *inputStr++;
        i++;
    }
    return i;
}

int mystrlen3(const char *inputStr) {

    const char *lastAddress = inputStr;
    printf("Beginning address is %p\n", &inputStr);
    while(*lastAddress)
        ++lastAddress;
    printf("lastAddress is %p\n", &lastAddress);
    int total = lastAddress - inputStr;
    printf("Total is %d\n", total);

    return 0;
}

int mystrlen2(const char *inputStr) {

    char *beginningAddress = inputStr;
    printf("Beginning address is %p\n", &beginningAddress);
    while(*inputStr)
        ++inputStr;
    char *endAddress = inputStr;
    printf("Ending address is %p\n", &endAddress);

    int total = endAddress - beginningAddress;
    printf("Total is %d\n", total);

    return 0;
}

void copyString1(char to[], char from[]) {
    int i;
    for(i = 0; from[i]!='\0'; ++i )
        to[i] = from[i];
    to[i] = '\0';
}

void copyString2(char *to, char *from) {
    for(; *from != '\0'; ++from, ++to )
        *to = *from;
    *to = '\0';
}

void copyString3(char *to, char *from) {
    while( *from) //the null will take it off
        *to++ = *from++;
    *to = '\0';
}

void pointer_vs_array() {
    //different implementation of copystring, using array and using pointers
    char from[] = "ABC";
    char to[10];
    copyString3(to, from);
    printf("res %s\n", to);
}
void pointer_arithmetic() {
    //pointer arithmetic example. string is 1 byte, ptr is 8 bytes interval

    char groot[] = "I am GROOT";
    char *pGroot = groot;

    for(int i = 0; i < strlen(groot); i++) {
        printf("groot[%d] = %c, "
               "Address is %p, "
               "pGroot address is %p, "
               "pGroot pointed address is %p, "
               "pGroot pointed adress value is %c\n", i, groot[i], &groot[i], &pGroot+i, (pGroot+i), *(pGroot+i));
    }

    /*
    groot[0] = I, Address is 0x7ffee94c8b8d, pGroot address is 0x7ffee94c8b80, pGroot pointed address is 0x7ffee94c8b8d, pGroot pointed adress value is I
    groot[1] =  , Address is 0x7ffee94c8b8e, pGroot address is 0x7ffee94c8b88, pGroot pointed address is 0x7ffee94c8b8e, pGroot pointed adress value is
    groot[2] = a, Address is 0x7ffee94c8b8f, pGroot address is 0x7ffee94c8b90, pGroot pointed address is 0x7ffee94c8b8f, pGroot pointed adress value is a
    groot[3] = m, Address is 0x7ffee94c8b90, pGroot address is 0x7ffee94c8b98, pGroot pointed address is 0x7ffee94c8b90, pGroot pointed adress value is m
    groot[4] =  , Address is 0x7ffee94c8b91, pGroot address is 0x7ffee94c8ba0, pGroot pointed address is 0x7ffee94c8b91, pGroot pointed adress value is
    groot[5] = G, Address is 0x7ffee94c8b92, pGroot address is 0x7ffee94c8ba8, pGroot pointed address is 0x7ffee94c8b92, pGroot pointed adress value is G
    groot[6] = R, Address is 0x7ffee94c8b93, pGroot address is 0x7ffee94c8bb0, pGroot pointed address is 0x7ffee94c8b93, pGroot pointed adress value is R
    groot[7] = O, Address is 0x7ffee94c8b94, pGroot address is 0x7ffee94c8bb8, pGroot pointed address is 0x7ffee94c8b94, pGroot pointed adress value is O
    groot[8] = O, Address is 0x7ffee94c8b95, pGroot address is 0x7ffee94c8bc0, pGroot pointed address is 0x7ffee94c8b95, pGroot pointed adress value is O
    groot[9] = T, Address is 0x7ffee94c8b96, pGroot address is 0x7ffee94c8bc8, pGroot pointed address is 0x7ffee94c8b96, pGroot pointed adress value is T
    */

    //using long. 8 bytes
    long num[] = {9L, 10L, 11L, 12L, 13L, 15L, 25L};
    long *pNum = num;

    for(int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
        printf("num[%d] = %d, "
               "Address is %p, "
               "pNum address is %p, "
               "pNum pointed address is %p, "
               "pNum pointed address value is %d\n", i, num[i], &num[i], &pNum+i, (pNum+i), *(pNum+i));
    }
    printf("size of int is %d\n", (int)sizeof(int));
    printf("size of long is %d\n", (int)sizeof(long));
    printf("size of float is %d\n", (int)sizeof(float));
    printf("size of char is %d\n", (int)sizeof(char));

    /*
    num[0] = 9, Address is 0x7ffee52c5b50, pNum address is 0x7ffee52c5b30, pNum pointed address is 0x7ffee52c5b50, pNum pointed address value is 9
    num[1] = 10, Address is 0x7ffee52c5b58, pNum address is 0x7ffee52c5b38, pNum pointed address is 0x7ffee52c5b58, pNum pointed address value is 10
    num[2] = 11, Address is 0x7ffee52c5b60, pNum address is 0x7ffee52c5b40, pNum pointed address is 0x7ffee52c5b60, pNum pointed address value is 11
    num[3] = 12, Address is 0x7ffee52c5b68, pNum address is 0x7ffee52c5b48, pNum pointed address is 0x7ffee52c5b68, pNum pointed address value is 12
    num[4] = 13, Address is 0x7ffee52c5b70, pNum address is 0x7ffee52c5b50, pNum pointed address is 0x7ffee52c5b70, pNum pointed address value is 13
    num[5] = 15, Address is 0x7ffee52c5b78, pNum address is 0x7ffee52c5b58, pNum pointed address is 0x7ffee52c5b78, pNum pointed address value is 15
    num[6] = 25, Address is 0x7ffee52c5b80, pNum address is 0x7ffee52c5b60, pNum pointed address is 0x7ffee52c5b80, pNum pointed address value is 25
    size of int is 4
    size of long is 8
    size of float is 4
    size of char is 1
     */

}
void pointer_arrays() {
    //arrays are pointer, hence pNumbers = numbers; no & as it is already a pointer.
    //point that in your head.

    int numbers[5] = {9,8,7,6};
    int *pNumbers = NULL;
    pNumbers = numbers;
    printf("Address of numbers is %p\n", numbers);
    printf("Address of pNumbers is %p\n", &pNumbers);
    printf("Value of pNumbers is %p address\n", pNumbers);
    printf("Value of pNumbers is %d integer\n", *pNumbers);
    printf("Value of pNumbers is %d integer\n", pNumbers[0]);
    printf("Value of pNumbers is %d integer\n", pNumbers[1]);

    //set the value of the pointer to the first element of the array
    pNumbers = &numbers[0];
    printf("Pointer is pointing to address of first element of array ptr %p\n", &pNumbers);
    printf("Pointer is pointing to value of first element of array ptr %p\n", pNumbers);
    printf("Pointer is pointing to value of first element of array ptr %d\n", *pNumbers);
    printf("numbers address of first element is %p\n", &numbers[0]);
    printf("numbers address of first element is %d\n", numbers[0]);
    printf("Pointer is pointing to value of second element of array ptr %d\n", pNumbers[1]);

    //hence below will suffice as it points to same memory where number is located.
    //the indices can be used to go through all values in array.
    //easier to write. programmer preference
    pNumbers = numbers;

    //ar[i] and *(ar+i) are equivalent.
    printf("numbers[i] is %d\n", numbers[0]);
    printf("*(numbers + 0) is %d\n", *(numbers + 0));
    printf("*numbers is %d\n", *numbers);
    printf("*(numbers + 1) is %d\n", *(numbers + 1));
    printf("*(numbers + 2) is %d\n", *(numbers + 2));


    printf("pNumbers is %d\n", *pNumbers);
    pNumbers++;
    printf("pNumbers incremented is %d\n", *pNumbers);

}
void arrays() {

    int data[5];
    int i;
    for (i; i < 5; i++) {
        data[i] = i;
        printf("%d\n", data[i]);
    }

    int num[9] = {1,2,3};
    for (int b; b < 10; b++) {
        printf("%d\n", num[b]);
    }

    int numbers[2][2];

    int numbers2[2][2] = {
            {2,4},
            {6,8}
    };

    printf("multi dim array value %d\n", numbers2[1][1]);

    //variable length array c99
    //VLA - use mainly for fortran to c converter
    int m = 5;
    float a9[m]; //not allowed before C99, VLA

    //value should integer and > 0
    float a7[(int)2.5];
    //float a8[(2.5]; not allowed - only int.


}
void void_pointers() {

    float amount = 1.15f;
    int num = 10;
    char initial = 'A';

    void *pVal = NULL;

    pVal = &amount;
    printf("Amount is %.5f\n", *(float*)pVal);

    pVal = &num;
    printf("Number is %d\n", *(int*)pVal);

    pVal = &initial;
    printf("Initial is %c\n", *(char*)pVal);

}
void pointer_const() {

    long num = 1000L;

    //if const is defined, the value cannot be changed.
    const long *pNum = &num;

    //value can be changed here
    //long *pNum = &num;

    // this will error: read-only variable is not assignable
    //*pNum = 2000L;

    //you can change the address the pointer is pointing to but not the value.
    long num2 = 2000L;
    pNum = &num2;
    //*pNum = 3000L; this is wrong. it is not changeable due to const syntax

    printf("Using const %d\n", *pNum);

    //the previous one, the value the pointer is pointing cannot be change.
    //with below, the address cannot be changed. the const is moved.
    long *const pNum2 = &num;
    printf("Using long *const pNum2 %d\n", *pNum2);
    //pNum2 = &num; cannot assign to variable 'pNum2' with const-qualified type 'long *const'

    *pNum2 = 5000l; // this is valid. value can be changed but not the address
    printf("Using long *const pNum2 %d\n", *pNum2);

    //both value and address cannot be changed.
    const long *const pNum3 = &num;
    //*pNum3 = 6000L; error: read-only variable is not assignable
    //pNum3 = &num2; error: cannot assign to variable 'pNum3' with const-qualified type 'const long *const'
    printf("Using long *const pNum3 %d\n", *pNum3);

}

void pointer_basic() {

    int num = 5;
    int *pNum = NULL;
    pNum = &num;

    *pNum = 10;

    printf("Address of num %p\n", &num);
    printf("Address of pNum %p\n", &pNum);
    printf("Address of pNum, avoid warning %p\n", (void*)&pNum);

    printf("Value of num %d\n", num);
    printf("Value of pNum %p\n", pNum);
    printf("Value of pNum it is pointing to %d\n", *pNum);

    //check for NULL before using
    if(!pNum)
        printf("It is null\n");
    else
        printf("It has value\n");

    //check for NULL before using
    pNum = NULL;
    if(pNum == NULL)
        printf("It is null\n");
    else
        printf("It has value\n");


}