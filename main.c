#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdbool.h>
#include <assert.h>



#define NEWLINE printf("\n");


void printArray(int* a, const int size) {
    printf("PRINT FUNCTION:\t%p\n", a);
    for(int i = 0 ; i < size; i++) {
       printf("%d ", a[i]);
    }
    NEWLINE;
}


struct asdf {
    int a;
    double dbl;
    char e;
};

typedef struct ProperAsdf{ // size is the sum of int double and char (without compiler optimisations)
    int _a;             // 4 bytes
    double _dbl;        // 8 bytes
    char _e;            // 1 byte
}proper_asdf;           // 24 bytes XD


union asedf {
    char a;
    int b;
    // union asedf* e;
    /*
     *  "aesdf is necessary here becase how are you going
     *  to make a pointer of the same object if it is annnonymous?"
     *  */
}mbmr; // this is just an object of the type "asedf", it can be also declared in main
// main.. -> union asedf mbmr;
// if we have "typedef" infront we can skip typing the keyword "union"
// it becomes: asedf mbmr;
// the union or struct itself can be annonymous


union {
    char a;
    int b;
    // union <???>* element;
    // you cannot make pointer of a annonymous structure
}annonymous_union;

struct {
    int x;
    double y;
    char z;
}annonymous_structure;






int main(int argc, char** argv) {

    mbmr.a = 77;
    mbmr.b = 77;


    printf("%c\t[%p]\t%d bytes (char)\n"
                "%i\t[%p]\t%d bytes (int)\n"
                "mbmr\t[%p]\t%llu bytes\n",
                mbmr.a, mbmr.a, sizeof(mbmr.a),
                mbmr.b, mbmr.b, sizeof(mbmr.b), mbmr, sizeof(mbmr));

    printf("%llu bytes\n", sizeof(struct ProperAsdf));
    system("pause");




    printf("Hello, World!\n");

    for(int i = 0; i < argc; i++) {
        printf("%s", argv[i]);
    }
    NEWLINE;



    int arr1[] = {1, 2, 3, 4, 145, 12};
    printf("MAIN:\t\t%x\n", arr1);
    printArray(arr1, sizeof(arr1) * 6);
    system("pause");
    int arr2[] = {1, 3, 5, 8, 6,4, 212, 154};

    int arr1_size = sizeof(arr1) / sizeof(int);
    int arr2_size = sizeof(arr2) / sizeof(int);

    int result;
    if(arr1_size < arr2_size)
        result = memcmp(arr1, arr2, arr1_size * sizeof(int));
    else
        result = memcmp(arr1, arr2, arr2_size * sizeof(int));

    const char* message;
    switch (result) {
        case -1: message = "first array is different"; break;
        case 0: message = "equal"; break;
        case 1: message = "second array is different"; break;
        default: break;
    }
    printf("message size: %d\n",strlen(message));
    printf("Are they equal?\t[%s] (%d)\n", message, result);

    printArray(arr1, arr1_size);
    printArray(arr2, arr2_size);

    //      to,  from       size of (to)
    // always choose        the lower size
    memcpy(arr1, arr2, arr1_size * sizeof(int));
    printArray(arr1, arr1_size);
    printArray(arr2, arr2_size);

    system("pause");
    memset(arr1, 9, arr1_size * sizeof(int));
    printArray(arr1, arr1_size);
    printArray(arr2, arr2_size);

    system("pause");

    struct asdf asdf = {1, 23.4, 'd'}; // no "typedef"
    printf("%d, %f, %c\n", asdf.a, asdf.dbl, asdf.e);

    proper_asdf p = {2, 50.673, 'T'}; // with "typedef"
    printf("%d, %f, %c\n", p._a, p._dbl, p._e);


    assert(p._a == 2); // if is true, it continues. make it false to break the program

    printf("p._dbl = %.1f [formatted]\n", p._dbl);

    double x;
    char* str[10];
    scanf("%d", &x);

    scanf("%s", str);
    printf("ANANQNQN: %3f, \"%s\"", x, str);




    return 0;
}
