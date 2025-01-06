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

int notOperator(int A) {
    return ~A;
}

int main() {

    uint8_t A = 5; //0000 0000 0000 0101
    uint8_t B = 6; //0000 0000 0000 0110
    uint8_t C = -6;

    cout << andOperator(A,B) << endl; // 5&6 -> 0000 0000 0000 0101&00000110 -> 00000100 =  4 

    cout << orOperator(A,B) << endl; // 5|6 -> 00000101|00000110 -> 111 = 7
    
    cout << xorOperator(A,B) << endl; // 5^6 -> 00000101^00000110 -> 011 =  3 

    cout << rightShift(A , 2) << endl; // 5 >> 2 -> 00000101 >> 2 -> 00000001 = 1

    cout << leftShift(B, 1) << endl; // 6 << 1 -> 00000110 << 1 -> 000001100 = 12

    cout << enableABit(A, 2) << endl; // 5|1<<2 -> 00000101|00000100 -> 101 = 5 
    
    cout << notOperator(A) << endl; // ~5 > ~0000 0000 0000 0101 -> 1111 1111 1111 1010 = -6
                                                                //                   -1
    cout << notOperator(C) << endl;

    std::cout << "Size of int: " << sizeof(uint8_t) * 8 << " bits\n";
    // 

    return 0;
}

// [4,1,2,1,2]
// [101, 001, 010, 001, 010]

// 000 ^ 101 = 101
// 101 ^ 001 = 100
// 100 ^ 010 = 110
// 110 ^ 001 = 111
// 111 ^ 010 = 101 = 4 
 // 001 ^ 001 = 0