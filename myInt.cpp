#define DUMPING
#include "myInt.h"

#ifdef DUMPING
FILE *logFile = fopen("dump.txt", "w");
FILE *dotFile = fopen("grvz.dot", "w");
int operators = 0;
#endif

myInt::myInt(int value):
          value (value)
{
    #ifdef DUMPING
    fprintf(dotFile, "  v%d[shape = Mrecord, style = filled, fillcolor = pink, label = \"tmp_obj | id : %d | value : %d \"];\n", id, id, value); 
    // fprintf(dotFile, "  v%d;\n", id); 
    fprintf(logFile, "myInt:%d constructed, value:%d\n", id, value);
    #endif
}

myInt::myInt(const myInt& x):
value (x.value)
{
    #ifdef DUMPING
    fprintf(dotFile, "  v%d[shape = Mrecord, style = filled, fillcolor = pink, label = \"tmp_obj(copied) | id : %d | value : %d \"];\n", id, id, value); 
    fprintf(dotFile, "  v%d -> v%d[color = red, label = \"copying\"];\n", x.id, id); 
    fprintf(logFile, "myInt:%d constructed from %d, value:%d\n", id, x.id, value);
    #endif
}

myInt::myInt(myInt&& x):
value (x.value)
{
    #ifdef DUMPING
    fprintf(dotFile, "  v%d[shape = Mrecord, style = filled, fillcolor = yellow, label = \"tmp_obj(not copied) | id : %d | value : %d \"];\n", id, id, value); 
    fprintf(dotFile, "  v%d -> v%d[color = green, label = \"transfering\"];\n", x.id, id); 
    fprintf(logFile, "myInt:%d constructed from %d, value:%d\n", id, x.id, value);
    #endif
}

myInt::myInt(const int value, bool flag):
value (value)
{
    #ifdef DUMPING
    fprintf(dotFile, "  v%d[shape = Mrecord, style = filled, fillcolor = lightgreen, label = \"id : %d | value : %d \"];\n", id, id, value); 
    // fprintf(dotFile, "  v%d;\n", id); 
    fprintf(logFile, "myInt:%d constructed from value, value:%d\n", id, value);
    #endif
}

myInt::myInt(const myInt& x, bool flag):
value (x.value)
{
    #ifdef DUMPING
    fprintf(dotFile, "  v%d[shape = Mrecord, style = filled, fillcolor = lightgreen, label = \"id : %d | value : %d \"];\n", id, id, value); 
    // fprintf(dotFile, "  v%d;\n", id); 
    fprintf(logFile, "myInt:%d constructed from %d, value:%d\n", id, x.id, value);
    #endif
}

myInt& myInt:: operator  = (myInt &&other) {
    value = other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n ", this->id, operators, other.id, operators); 
    fprintf(logFile, "operator = was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt:: operator  = (const int &value) {
    this->value = value;

    #ifdef DUMPING
    operators++;
    fprintf(logFile, "operator = was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt:: operator += (const myInt &other) {
    value += other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"+=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d; op%d->v%d[fillcolor = blue];\n", this->id, operators, other.id, operators, operators, this->id); 
    fprintf(logFile, "operator += was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt:: operator -= (const myInt &other) {
    value -= other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"-=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d; op%d->v%d[fillcolor = blue];\n", this->id, operators, other.id, operators, operators, this->id);  
    fprintf(logFile, "operator -= was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt:: operator *= (const myInt &other) {
    value *= other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"*=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d; op%d->v%d[fillcolor = blue];\n", this->id, operators, other.id, operators, operators, this->id); 
    fprintf(logFile, "operator *= was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt::operator /= (const myInt &other) {
    value /= other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"/=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d; op%d->v%d[fillcolor = blue];\n", this->id, operators, other.id, operators, operators, this->id); 
    fprintf(logFile, "operator /= was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt::operator %= (const myInt &other) {
    value %= other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"%=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d; op%d->v%d[fillcolor = blue];\n", this->id, operators, other.id, operators, operators, this->id); 
    fprintf(logFile, "operator /= was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt::operator &= (const myInt &other) {
    value &= other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"&=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d; op%d->v%d[fillcolor = blue];\n", this->id, operators, other.id, operators, operators, this->id); 
    fprintf(logFile, "operator /= was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt::operator |= (const myInt &other) {
    value |= other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"|=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d; op%d->v%d[fillcolor = blue];\n", this->id, operators, other.id, operators, operators, this->id); 
    fprintf(logFile, "operator /= was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt& myInt::operator ^= (const myInt &other) {
    value ^= other.value;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"^=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d; op%d->v%d[fillcolor = blue];\n", this->id, operators, other.id, operators, operators, this->id); 
    fprintf(logFile, "operator /= was called, %d:current value is %d\n", id, value);
    #endif

    return *this;
}

myInt operator , (const myInt &a, const myInt &b) {
    int i = 1;
    for (i = 1; b.value / i; i *= 10);

    myInt res = a.value + b.value * i;

    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \",\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n  op%d->v%d;\n", a.id, operators, b.id, operators, operators, res.id); 
    fprintf(logFile, "operator + was called, %d:current value is %d\n", res.id, res.value);
    #endif

    return res;
}

myInt operator % (const myInt &a, const myInt &b) {
    myInt res = a;
    res %= b;

    #ifdef DUMPING
    // operators++;
    // fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"%\"];\n", operators); 
    // fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n  op%d->v%d;\n", a.id, operators, b.id, operators, operators, res.id); 
    fprintf(logFile, "operator + was called, %d:current value is %d\n", res.id, res.value);
    #endif

    return res;
}

myInt operator + (const myInt &a, const myInt &b) {
    myInt res = a;
    res += b;

    #ifdef DUMPING
    // operators++;
    // fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"+\"];\n", operators); 
    // fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n  op%d->v%d;\n", a.id, operators, b.id, operators, operators, res.id); 
    fprintf(logFile, "operator + was called, %d:current value is %d\n", res.id, res.value);
    #endif

    return res;
}

myInt operator * (const myInt &a, const myInt &b) {
    myInt res = a;
    res *= b;

    #ifdef DUMPING
    // operators++;
    // fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"*\"];\n", operators); 
    // fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n  op%d->v%d;\n", a.id, operators, b.id, operators, operators, res.id); 
    fprintf(logFile, "operator * was called, %d:current value is %d\n", res.id, res.value);
    #endif

    return res;
}

myInt operator - (const myInt &a, const myInt &b) {
    myInt res = a;
    res -= b;

    #ifdef DUMPING
    // operators++;
    // fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"-\"];\n", operators); 
    // fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n  op%d->v%d;\n", a.id, operators, b.id, operators, operators, res.id); 
    fprintf(logFile, "operator - was called, %d:current value is %d\n", res.id, res.value);
    #endif

    return res;
}

myInt operator / (const myInt &a, const myInt &b) {
    myInt res = a;
    res /= b;

    #ifdef DUMPING
    operators++;
    // fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"/\"];\n", operators); 
    // fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n  op%d->v%d;\n", a.id, operators, b.id, operators, operators, res.id); 
    fprintf(logFile, "operator / was called, %d:current value is %d\n", res.id, res.value);
    #endif

    return res;
}

bool operator > (const myInt &a, const myInt &b) {
    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \">\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n ", a.id, operators, b.id, operators); 
    fprintf(logFile, "operator %d > %d was called\n", a.id, b.id);
    #endif

    return (a.value > b.value);
}
bool operator < (const myInt &a, const myInt &b) {
    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"<\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n ", a.id, operators, b.id, operators); 
    fprintf(logFile, "operator %d < %d was called\n", a.id, b.id);
    #endif

    return (a.value < b.value);
}
bool operator >= (const myInt &a, const myInt &b) {
    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \">=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n ", a.id, operators, b.id, operators); 
    fprintf(logFile, "operator %d >= %d was called\n", a.id, b.id);
    #endif

    return (a.value >= b.value);
}
bool operator <= (const myInt &a, const myInt &b) {
    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"<=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n ", a.id, operators, b.id, operators); 
    fprintf(logFile, "operator %d <= %d was called\n", a.id, b.id);
    #endif

    return (a.value <= b.value);
}

bool operator == (const myInt &a, const myInt &b) {
    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"==\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n ", a.id, operators, b.id, operators); 
    fprintf(logFile, "operator %d == %d was called\n", a.id, b.id);
    #endif

    return (a.value == b.value);
}

bool operator != (const myInt &a, const myInt &b) {
    #ifdef DUMPING
    operators++;
    fprintf(dotFile, "  op%d[shape = circle, style = filled, fillcolor = orange, label = \"!=\"];\n", operators); 
    fprintf(dotFile, "  v%d->op%d;\n  v%d->op%d;\n ", a.id, operators, b.id, operators); 
    fprintf(logFile, "operator != was called\n", a.value, b.value);
    #endif

    return (a.value != b.value);
}

myInt max(myInt a, myInt b) {
    return (a > b? a: b);   
}

void startGraph() {
    fprintf(dotFile, "digraph Varriables {\n"
                     "  rankdir = TB\n");
}

void endGraph() {
    fprintf(dotFile, "}\n");
}