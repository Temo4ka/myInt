#include "myInt.h"

int main() {
    startGraph();

    myInt a(3, 1);
    myInt b(-6, 1);
    myInt c = a * b + b * b;

    endGraph();

    return 0;
}