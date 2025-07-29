#include<iostream>
using namespace std;

void decimalTobinary(int n){
    while(n > 0){
        int ans = 0;
        int pow = 1;
        int rem = n  % 2;
        n /= 2;
        ans += rem * pow;
        pow *= 10;
        cout << ans ;
    }
}

void binaryTodecimal(int n){
    int ans = 0; int pow = 1;
    while(n > 0){
        int rem = n % 10;
        ans += rem * pow;
        pow *= 2;
        n /= 10;
    }
    cout << ans;
}

int main(){

binaryTodecimal(1010);
return 0;

}