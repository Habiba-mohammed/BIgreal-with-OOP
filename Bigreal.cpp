#include "Bigreal.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string Bigreal :: addition(string s1, string s2)  {
    string newres;
    int carry = 0;
    // incase no decimal point :D
    int point1=s1.find('.');
    if(point1==-1) { s1.insert(s1.begin(),'.');  point1=s1.size()-2; }
    int point2=s2.find('.');
    if(point2==-1) { s2.insert(s2.begin(),'.');  point2=s2.size()-2; }
    // we start adding from the rightmost digit and calculating the carry
    int i = s1.size() - 1;  int size1=s1.size();
    int j = s2.size() - 1;  int size2=s2.size();

    int newsize1=(size1-1)-point1;//after point for string1
    int newsize2=(size2-1)-point2;//after point for string2

    int sum=0;
    //fraction part only <3 :D
    while (newsize1 > 0 || newsize2 > 0) {
        if(newsize1==newsize2)
        {
            sum= s1[i]-'0' + s2[j]-'0' +carry;
            carry=0;
            if(sum>=10) {sum-=10,carry++;}
            newres=char(sum+'0')+(newres);
            newsize1--,newsize2--;
            i--,j--;
        }
        else if(newsize2>newsize1) // the second one has more elements in the fraction
        {
            newres= s2[j] + (newres); //push front
            newsize2--;
            j--;
        }
        else
        {
            newres=s1[i]+(newres);
            newsize1--;
            i--;
        }
    }
    // before the point <3
    newres="."+newres; i=point1-1; j=point2-1;
    while(point1>0 ||point2>0 )
    {
        if(point1>0 && point2>0)
        {
            int value= s1[i]-'0' + s2[j]-'0' + carry;
            carry=0;
            if(value>=10) value-=10,carry++;
            newres=char(value+'0')+newres;
            i--,j--,point1--,point2--;
        }
        else if(point1>0)
        {
            int value= s1[i]-'0' + carry;
            carry=0;
            if(value>=10) {value-=10;carry++;}
            newres= char(value+'0') + newres;
            point1--;
            i--;
        }
        else
        {
            int value= s2[j]-'0' + carry;
            carry=0;
            if(value>=10){value-=10; carry++;}
            newres=char(value+'0')+newres;
            point2--;
            j--;
        }
    }
    if(carry) newres='1'+newres;
    return removeTrailingZeroes(newres);
}
//============================================================================
string Bigreal:: subtraction( string large,  string small) {
    string result="";
    int carry = 0;
    // incase no decimal point :D
    int point1=large.find('.');
    if(point1==-1) { large.insert(large.begin(),'.');  point1=large.size()-2; }
    int point2=small.find('.');
    if(point2==-1) { small.insert(small.begin(),'.');  point2=small.size()-2; }

// we start subtracting from the rightmost digit and calculating the carry
    int i = large.size() - 1;   int size1=i;
    int j = small.size() - 1;   int size2=j;

    // 0.123 +0.1 == 0.2(23)
    while(size1-point1<size2-point2){
        large+='0';
        i++;
        size1++;
    }
    while(size1-point1>size2-point2){
        small+='0';
        j++;
        size2++;
    }

    while (i >= 0 || j >= 0 || carry) {
        int num1 = (i >= 0) ? large[i] - '0' : 0;
        int num2 = (j >= 0) ? small[j] - '0' : 0;
        if( (i>=0 || j>=0) && large[i]=='.'){
            result.insert(result.begin(),'.');
            i--;
            j--;
            continue;
        }
        i--; j--;
        int diff = num1 - num2 - carry;
        carry=0;

        if (diff<0 ) {
            carry++;
            diff += 10;
        }


        result.insert(result.begin(), diff + '0');

    }


    return removeTrailingZeroes(result);

}
//============================================================================
string Bigreal:: removeTrailingZeroes(string num){
    for(int i{0};i<num.size() ;i++){
        if(num[i]!='0') break;
        else {
            num.erase(i,1);
            i--;
        }
    }
    if(num[0]=='.'){
        num.insert(num.begin(),'0');
    }
    int point = num.find('.');
    int size=num.size() - 1;
    for(int i{size}; i>(point+1) && point!=-1;i--){
        if(num[i]!='0') break;

        else{
            num.erase(i,1);
        }
    }
    return num;
}
//============================================================================
void Bigreal::equality(Bigreal& ob2) // make fractions of the same size(in the fraction part only )
{
    int point1 = number.find('.');
    if (point1 == -1)
    {
        number += '.';
        point1 = number.size() - 1;
    }

    int point2 = ob2.number.find('.');
    if (point2 == -1)
    {
        ob2.number += '.';
        point2 = ob2.number.size() - 1;
    }
////////////////////////////////////////////////////////////
    int newsize1 = number.size() - 1 - point1;
    int newsize2 = ob2.number.size() - 1 - point2;

// not correct to add 0's in the beginning <3
//    if (point1 > point2)
//    {
//        for (int x = 0; x < (point1 - point2); x++)
//            ob2.number = "0" + ob2.number;
//    }
//    else if (point1 < point2)
//    {
//        for (int x = 0; x < (point2 - point1); x++)
//            number = "0" + number;
//    }

    if (newsize1 > newsize2)
    {
        for (int x = 0; x < (newsize1 - newsize2); x++)
            ob2.number += "0";
    }
    else if (newsize1 < newsize2)
    {
        for (int x = 0; x < (newsize2 - newsize1); x++)
            number += "0";
    }
}
//============================================================================

Bigreal::Bigreal(const string& num) : number(num) {
    neg = (number[0]=='-')? true: false;
    if( !neg ) pos=true;

    if(!isvalid())
        cout<<"invalid number\n";
    if(neg) number.erase(0,1);
    else
    if(number[0]=='+') number.erase(0,1);

    if(number[0]=='.') number='0'+number;



}
//============================================================================
Bigreal::Bigreal(){
    number="0";
}
//============================================================================
void Bigreal::setNum(string s) {
    if (Bigreal(s).isvalid()) {
        number = move(s);
    } else {
        cout << "invalid number\n";
    }
}

Bigreal& Bigreal::operator=(Bigreal& other){//assigment operator
    number = other.number;
    pos = other.pos;
    neg = other.neg;
    return *this;
}
//============================================================================
Bigreal::Bigreal(const Bigreal& other){//copy contructor
    number = other.number;
    pos = other.pos;
    neg = other.neg;
}
//============================================================================
void Bigreal::sign(){
    if(pos)
        cout<<"positive";
    else
        cout<<"negative";
}
//============================================================================
int  Bigreal::size(const string& s){
    return s.size();
}
//============================================================================
string Bigreal::getNum() const {
    return number;
}
//============================================================================
ostream& operator<<(ostream& cout, const Bigreal& num) {
    cout << num.number;
    return cout;
}
//============================================================================
string Bigreal::operator+( const Bigreal& other) {
    if (pos && other.pos){
        return addition(number, other.getNum());
    }

    else if(neg && other.neg ){
        string result= addition(number,other.number);
        result='-'+result;
        return result;
    }

    else if( neg && other.pos ){ // -2 +3
        if( (*this <= other) ) { //2 < 3
            return subtraction(other.number,number); // 3 - 2 --> positive value

        }
        else { // -5 + 3 == -1 * (5-3)
            string result= subtraction(number,other.number);
            result='-'+result;
            return result;
        }
    }
    else if( pos && other.neg ){ // 2+ -3
        if( (*this <= other) ) { // 2 < 3
            string result= subtraction(other.number,number);
            result='-'+result;
            return result; // 3 - 2 --> negative value
        }
        else { // 5+  -3 == -1 * (5-3)
            return subtraction(number,other.number);

        }
    }
    // will never come here eitherway
    return "";

}
//============================================================================
string Bigreal::operator-( const Bigreal & other) {
    if(pos && other.pos){
        if(*this>=other){ // 5 - 3
            string result= subtraction(number,other.number);
            return result;
        }
        else{ // 3 - 5
            string result= subtraction(other.number,number);
            result='-'+result;
            return result;
        }
    }
    else if(pos && other.neg) return addition(number,other.number);
    else if(neg && other.pos){//-40 1.00
        string result= addition(number,other.number);
        result='-'+result;
        return result;
    }
    else if(neg && other.neg){
        string result;
        if(*this>=other){ // -5 - -3 --> -1 * (5-3)
            result= subtraction(number,other.number);
            result='-'+result;
            return result;
        }
        else{ // -3 - -5 --> -1 * (3-5) == 5-3
            result= subtraction(other.number,number);
            return result;
        }
    }
    // will never come here eitherway
    return "";
}
//============================================================================
bool Bigreal::operator< (Bigreal other) { // number < other.number
    equality(other); // add zeroes to the fraction part to make them equal
    // now there's a point 100%
    int point1=number.find('.');
    int point2=other.number.find('.');


    if(point1==point2){ // we will go through each digit to check
        for(int i{0};i<number.size();i++){
            if(number[i] >= other.number[i] ){
                return false;
            }
        }
        return true;
    }
    else if(point1<point2){ //
        return true;
    }
    else{
        return false;
    }
}
//============================================================================
bool Bigreal::operator> (Bigreal other) {// number > other.number
    equality(other); // add zeroes to the fraction part to make them equal
    // now there's a point 100%
    int point1=number.find('.');
    int point2=other.number.find('.');

    if(point1==point2){ // we will go through each digit to check
        for(int i{0};i<number.size();i++){
            if(number[i] <= other.number[i] ){
                return false;
            }
        }
        return true;
    }
    else if(point1>point2){ //
        return true;
    }
    else{
        return false;
    }
}
//============================================================================
bool Bigreal::operator >= (Bigreal other) {// number >= other.number
    equality(other); // add zeroes to the fraction part to make them equal
    // now there's a point 100%
    int point1=number.find('.');
    int point2=other.number.find('.');

    if(point1==point2){ // we will go through each digit to check
        for(int i{0};i<number.size();i++){
            if(number[i] < other.number[i] ){
                return false;
            }
        }
        return true;
    }
    else if(point1>=point2){ //
        return true;
    }
    else{
        return false;
    }

}
//============================================================================
bool Bigreal::operator <= (Bigreal other) { // number <= other.number
    equality(other); // add zeroes to the fraction part to make them equal
    // now there's a point 100%
    int point1=number.find('.');
    int point2=other.number.find('.');

    if(point1==point2){ // we will go through each digit to check
        for(int i{0};i<number.size();i++){
            if(number[i] > other.number[i] ){
                return false;
            }
        }
        return true;
    }
    else if(point1<=point2){ //
        return true;
    }
    else{
        return false;
    }

}
//============================================================================
bool Bigreal::operator==(Bigreal other) {
    equality(other); // add zeroes to the fraction part to make them equal

    // now there's a point 100%
    int point1=number.find('.');
    int point2=other.number.find('.');

    if(point1!=point2) return false;
    else{
        for(int i{0};i<number.size();i++){
            if(number[i]!= other.number[i]){
                return false;
            }
        }
        return true;
    }
}
//============================================================================
bool Bigreal::isvalid(){
    string x=number;
    long long size=x.size();
    bool p=1;
    for(int i=0;i<size;i++){
        if(((x[i]=='.')||(x[i]=='-')||(x[i]=='+'))||((int(x[i])>47)&&(int(x[i])<58))){
            continue;
        }
        else{
            p=0;
        }
    }
    if(!p) return 0;
    if((count(x.begin(),x.end(),'.')<=1)&&(pos+count(x.begin(),x.end(),'-')<=1)&&(neg+count(x.begin(),x.end(),'+')<=1)) {
        return 1;
    }
    else{
        return 0;
    }
}
