#include "Bigreal.h"
#include "Bigreal.cpp"
#include <iostream>
using namespace std;
int main() {
     //Test Case 0: Default Constructor
    Bigreal num0;
    cout << "Test Case 0 (Default Constructor): " << num0 << endl;


    // Test Case 1: Positive Addition
    Bigreal num1("123.45");
    Bigreal num2("67.89");
    cout << "Test Case 1: " << num1 + num2 << endl;

    // Test Case 2: Negative Addition
    Bigreal num3("-123.45");
    Bigreal num4("-67.89");
    cout << "Test Case 2: " << num3 + num4 << endl;

    // Test Case 3: Mixed Sign Addition
    Bigreal num5("-123.45");
    Bigreal num6("67.89");
    cout << "Test Case 3: " << num5 + num6 << endl;


    // Test Case 4: Positive Subtraction
    Bigreal num7("1000.50");
    Bigreal num8("500.25");
    cout << "Test Case 4: " << num7 - num8 << endl;
    cout << "Test Case 4': " << num8 - num7 << endl;


    // Test Case 5: Negative Subtraction
    Bigreal num9("-1000.50");
    Bigreal num10("-500.25");
    cout << "Test Case 5: " << num9 - num10 << endl;
    cout << "Test Case 5': " << num10 - num9 << endl;


    // Test Case 6: Mixed Sign Subtraction
    Bigreal num11("-1000.50");
    Bigreal num12("500.25");
    cout << "Test Case 6: " << num11 - num12 << endl;
    cout << "Test Case 6': " << num12 - num11 << endl;


    // Test Case 7: Equality Check
    Bigreal num13("123.456");
    Bigreal num14("123.456");
    if (num13 == num14)
        cout << "Test Case 7: equal\n";

    // Test Case 8: Greater Than Check
    Bigreal num15("100.00");
    Bigreal num16("99.99");
    if (num15 > num16)
        cout << "Test Case 8: greater\n";

    // Test Case 9: Less Than Check
    Bigreal num17("99.99");
    Bigreal num18("100.00");
    if (num17 < num18)
        cout << "Test Case 9: lessthan\n";

    // Test Case 10: Less Than or Equal Check
    Bigreal num19("99.99");
    Bigreal num20("100.00");
    if (num19 <= num20)
        cout << "Test Case 10: lessthan or equal\n";

    // Test Case 11: Greater Than or Equal Check
    Bigreal num21("100.00");
    Bigreal num22("99.99");
    if (num21 >= num22)
        cout << "Test Case 11: Greaterthan or equal\n";

    // Test Case 12: Invalid Number Check ( automatic )
    cout<<"Test Case 12: ";
    Bigreal num23("g12.34.56");


//    // Additional Test Cases

    // Test Case 13: Large Positive Addition
    Bigreal num24("9999.999999999999999999999999999999999");
    Bigreal num25("0.000000000000000000000000000000001");
    cout << "Test Case 13: " << num24 + num25 << endl;
//
    // Test Case 14: Large Negative Subtraction
    Bigreal num26("-999999999999999999999999999999999.999999999999999999999999999999999");
    Bigreal num27("-0.000000000000000000000000000000001");
    cout << "Test Case 14: " << num26 - num27 << endl;

   // Test Case 15: Decimal Numbers Addition
    Bigreal num28("0.333333");
   Bigreal num29("-0.666666");
    cout << "Test Case 15: " << num28 + num29 << endl;

    // Test Case 16: Using Copy Constructor
    Bigreal num30(num28); // Copy Constructor is called
    cout << "Test Case 16 (Copy Constructor): " ;
     num30.sign();
    cout<<" "<<num30 << endl;

    // Test Case 17: Using Assignment Operator
    Bigreal num31("99.99");
    Bigreal num32("123.45");
    num31 = num32; // Assignment Operator is called
    cout << "Test Case 17 (Assignment Operator): " << num31 << endl;

    return 0;
}
