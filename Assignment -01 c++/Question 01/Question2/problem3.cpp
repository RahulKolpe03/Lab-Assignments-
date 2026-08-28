#include <iostream>
using namespace std;

int main()
{
    int statusReg  = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg    = 0b11001010;

    // ------------------------------------------------
    // REGPTR1 : Pointer to const integer
    // ------------------------------------------------

    const int* regPtr1 = &statusReg;

    cout << "Status Register : " << *regPtr1 << endl;

    // *regPtr1 = 10;
    // ERROR: Cannot modify the value through a pointer-to-const.

    // regPtr1 = &controlReg;
    // This is allowed because regPtr1 itself is NOT const.
    // Pointer can point to another address.


    // ------------------------------------------------
    // REGPTR2 : Constant pointer to integer
    // ------------------------------------------------

    int* const regPtr2 = &controlReg;

    cout << "Control Register : " << *regPtr2 << endl;

    *regPtr2 = 25;

    cout << "New Control Register : " << controlReg << endl;

    // regPtr2 = &dataReg;
    // ERROR: regPtr2 is a constant pointer.
    // It cannot point to another address.


    // ------------------------------------------------
    // REGPTR3 : Constant pointer to constant integer
    // ------------------------------------------------

    const int* const regPtr3 = &statusReg;

    cout << "Status Register using regPtr3 : "
         << *regPtr3 << endl;

    // *regPtr3 = 20;
    // ERROR: Cannot modify the value because the pointed value is const.

    // regPtr3 = &dataReg;
    // ERROR: Cannot change the address because the pointer is const.


    return 0;
}