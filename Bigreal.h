// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include <string>
using namespace std;
#ifndef UNTITLED1_BIGREAL_H
#define UNTITLED1_BIGREAL_H


class Bigreal {
private:

    string addition( string s1, string s2);
    string subtraction(string large, string small);
    string removeTrailingZeroes(string num);


public:
    bool pos=false;
    bool neg=false;
    string number;
    //====================================================================
    string operator+  (const Bigreal& other);
    string operator-  (const Bigreal & other);
    bool   operator<  (Bigreal other);
    bool   operator>  (Bigreal other);
    bool   operator<= (Bigreal other);
    bool   operator>= (Bigreal other);
    bool   operator== (Bigreal other);
    friend ostream& operator<<(ostream& cout, const Bigreal& num);
    //====================================================================
    bool isvalid();
    Bigreal();//Default constructor
    Bigreal(const string& num);//intilize from string
    void setNum(string s);
    int size(const string& s);
    void sign();
    Bigreal& operator=(Bigreal& other);//assignment operator
    Bigreal(const Bigreal& other);//copy constructor
    //====================================================================
    void equality(Bigreal&other); // make fractions of the same size(in the fraction part only ) <3
    string getNum() const ;
    //====================================================================


};
#endif //UNTITLED1_BIGREAL_H
//ostream& operator<<(ostream& cout, const Bigreal& num);