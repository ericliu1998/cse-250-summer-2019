#include <iostream>
int main() {
    // Try to change x = 0 to x = 1 and check the exit code.
    int x = 0;

    ++x;
    x++;

    bool b = !(x - 2) && (27);
  
    return b;
}
