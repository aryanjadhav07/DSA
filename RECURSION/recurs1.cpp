#include<bits/stdc++.h>
using namespace std;

int c = 1;

void print(){

    if (c == 100){
        return;
    }
    c++;
    cout << c << endl;
    print();
}

int main(){

    print();

    return 0;
}