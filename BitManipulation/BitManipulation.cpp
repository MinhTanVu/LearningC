#include <iostream>

using namespace std;

int andOperator(int A, int B) {
    return A&B;
}

int orOperator(int A, int B) {
    return A|B;
}

int xorOperator(int A, int B) {
    return A^B;
}

int rightShift(int A, int position) {
    return A >> position;
}

int leftShift(int B, int position) {
    return B << position;
}

int enableABit(int A, int position) {
    return A | 1 << position; 
}

int main() {

    int A = 5; //101
    int B = 6; //110

    cout << andOperator(A,B) << endl; // 5&6 -> 101&110 -> 100 =  4 

    cout << orOperator(A,B) << endl; // 5|6 -> 101|110 -> 111 = 7
    
    cout << xorOperator(A,B) << endl; // 5^6 -> 101^110 -> 011 =  3 

    cout << rightShift(A , 2) << endl; // 5 >> 2 -> 101 >> 2 -> 001 = 1

    cout << leftShift(B, 1) << endl; // 6 << 1 -> 110 << 1 -> 1100 = 12

    cout << enableABit(A, 2) << endl; // 5|1<<2 -> 101|100 = 101 = 5 
 
    return 0;
}