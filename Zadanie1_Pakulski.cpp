#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <vector>
#include <numeric>

// Piotr Pakulski nr ind. 146936 gr. D2 sem.2 Podstawy Programowania CW. 4 Zadanie 1
using namespace std;

void fillWithRandom(int *some_array, int array_size, int range_min, int range_max) {
    int rand_no = (range_max - range_min) + 1;

    for (int i{0}; i <= array_size; i++) {
        some_array[i] = rand() % rand_no + range_min;
    }
}

bool comp(int a, int b) {
    return (a < b);
}

int getArrayMaxVal(int *some_array, int array_size) {
    int* max_val;
    max_val = std::max_element(some_array, some_array + array_size, comp);
    return *max_val;
}

void printElement(string t) {
    cout << left << " " << setw(5) << t;
}

void printTable(int *some_array, int array_size) {
    string pre;
    cout << endl << "---------------------------------------" << endl;
    for (int i{0}; i <= array_size; i++) {
            if (i>0 && i%6 == 0) {
            cout << endl;
        }
        if (some_array[i] > 0) {
            pre = "+";
        }
        else {
            pre = "";
        }
        printElement(pre + to_string(some_array[i]));
    }
}

int avarageAndCount(int *some_array, int array_size, float *avg) {
    int elem_count{0};
    float inner_avg;

    float sum = accumulate(some_array, some_array + array_size + 1, 0);
    *avg = sum / array_size;

    for (int i{0}; i <= array_size; i++) {
        if (some_array[i] > *avg) {
            elem_count++;
        }
    }

    return elem_count;
}

int main() {
    int X[49], Y[49], Z[49], Q[2], elem_count, j{0};
    float avg;


    fillWithRandom(X, *(&X + 1) - X, -500, 500);
    fillWithRandom(Y, *(&Y + 1) - Y, -500, 500);
    fillWithRandom(Z, *(&Z + 1) - Z, -500, 500);

    printTable(X, *(&X + 1) - X);
    printTable(Y, *(&Y + 1) - Y);
    printTable(Z, *(&Z + 1) - Z);

    Q[0] = getArrayMaxVal(X, *(&X + 1) - X);
    Q[1] = getArrayMaxVal(Y, *(&Y + 1) - Y);
    Q[2] = getArrayMaxVal(Z, *(&Z + 1) - Z);

    cout << endl << endl << "The max values for the arrays are: ";
    printTable(Q, *(&Q + 1) - Q);

    elem_count = avarageAndCount(X, *(&X + 1) - X, &avg);
    cout << endl << endl << "AVG for X is: " << avg << " and the elements count grather that avg is: " << elem_count << endl;

    int * XD;
    XD = new int[elem_count - 1];
    for (int i{0}; i <= 49; i++) {
        if (X[i] > avg) {
            XD[j] = X[i];
            j++;
        }
    }
    cout << endl << endl << "The grather XD values are: ";
    printTable(XD, elem_count - 1);

    delete [] XD;

    return 0;
}
