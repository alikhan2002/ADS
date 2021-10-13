#include <iostream>
#include <cmath>
using namespace std; 

bool Isprime(int x){
    if(x == 0 || x == 1){
        return 0;
    }
    for (int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int main(){
    int n; 
    cin >> n;
    while(!Isprime(n)){
        n++;
    }
    cout<<n;

}