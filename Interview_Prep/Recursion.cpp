// #include <stdio.h>

// void f(int i, int n){
//     if (i > n)
//         return;
//     printf("Aryan\n");
//         f(i + 1, n);
// }

// int main() {
//     int n = 5;
//     f(1,n);
// }

// #include <iostream>
// using namespace std;

// void f(int i, int n){
//     if (i < n)
//         return;
//     cout << i << endl;
//     f(i - 1, n);
// }

// int main() {
//     int n = 1;
//     f(5,n);
// }


// this is using backtracking...
#include <iostream>
using namespace std;

void f(int i, int n){
    if (i > 3)
        return;
    f(i + 1, n);
    cout << i << endl;

}

int main() {
    int n = 3;
    f(1,n);
}

