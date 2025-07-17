#include<iostream>
using namespace std;

int fac(int f){
    int fact = 1;
    for(int i = 1; i <= f; i++){
        fact *= i;
    }

    return fact;
}

int ncr(int n, int r){

int ncr = fac(n) / (fac(r) * fac(n-r));
    return ncr;

}

int main(){

   cout << ncr(8, 2);

}