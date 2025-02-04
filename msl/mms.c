//
// Created by Slave on / Tuesday / 05-Nov-24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void read_hundred(char** m);
void* (*functionPointer)(int);
void foo(int);

int main(void) {

//  binary to hex (to dec)
    char *bin="01010011";
    char *a = bin;
    int num = 0;
    do {
        int b = *a=='1'?1:0;
        num = (num<<1)|b;
        a++;
    } while (*a);
    printf("%X\n", num);

//  array of pointers
    int * arr[10];
    for(size_t i = 0; i < 10; i++) {
        printf("arr[%d]\t(%p)\n", i, &arr[i]);
    }

//  two-dimentional array of pointers
    const char* e[1][2];
    for(size_t r = 0; r < 1; r++) {
        for(size_t c = 0; c < 2; c++) {
            printf("e[%d][%d]\t%p\n", r, c, &e[r][c]);
        }
    }

//  matrix
    srand(time(NULL));
    char matrix[10][10];
    for(size_t r= 0; r < 10; r++) {
        for(size_t c = 0; c < 10; c++) {
            matrix[r][c] = rand() % 50 + 1;
        }
    }
    read_hundred(matrix);




//  function pointer
    functionPointer = &foo;
    functionPointer(4);


    return 0;
}
void foo(int x) {
    printf("Printed: %d", x);
}

void read_hundred(char** m) {
    int i=0;
    int j=0;
    while(i < 10) {
        while(j < 10) {
            printf("%d ", m[i][j]);
            j++;
        }
        printf("\n");
        j=0;
        i++;
    }
}