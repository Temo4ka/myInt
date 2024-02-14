#include <stdio.h>
#include <stdlib.h>

struct myInt {
    int value;
    int id = rand();

    myInt(int value);
    myInt(int value, bool flag);
    myInt(const myInt& x, bool flag);
    myInt(const myInt& x);
    myInt(myInt&& x);


    myInt& operator  = (myInt &&other);
    myInt& operator  = (const int &value);
    myInt& operator += (const myInt &other);
    myInt& operator -= (const myInt &other);
    myInt& operator *= (const myInt &other);
    myInt& operator /= (const myInt &other);
    myInt& operator %= (const myInt &other);
    myInt& operator &= (const myInt &other);
    myInt& operator |= (const myInt &other);
    myInt& operator ^= (const myInt &other);

};

myInt operator + (const myInt &a, const myInt &b);
myInt operator - (const myInt &a, const myInt &b);
myInt operator / (const myInt &a, const myInt &b);
myInt operator * (const myInt &a, const myInt &b);
myInt operator % (const myInt &a, const myInt &b);
myInt operator , (const myInt &a, const myInt &b);

bool  operator >  (const myInt &a, const myInt &b);
bool  operator <  (const myInt &a, const myInt &b);
bool  operator >= (const myInt &a, const myInt &b);
bool  operator <= (const myInt &a, const myInt &b);
bool  operator == (const myInt &a, const myInt &b);
bool  operator != (const myInt &a, const myInt &b);

myInt max(myInt, myInt);

void startGraph();
void endGraph();
