// C++ program to demonstrate the size occupied by a class
// by specifying the bits to member variables of the class
// using bit fields
#include <iostream>
using namespace std;

// Define a class with bit-fields for loan information
class Loan {
public:
    // Maximum principal of 1,048,575
    unsigned int principal : 20;
    // Maximum interest rate of 63
    unsigned int interestRate : 6;
    // Maximum period of 63 months
    unsigned int period : 6;
};

int main()
{
    Loan loan1;
    loan1.principal = 500000;
    loan1.interestRate = 15;
    loan1.period = 36;

    // Print the size of loan1
    // (20+6+6)/8 = 4 Bytes
    // 1 Byte = 8 Bits
    cout << sizeof(Loan) << " Bytes" << endl;

    return 0;
}
