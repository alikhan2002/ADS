#include <iostream>
using namespace std;
int main(){
    long long n, m;
    cin>>n;
    cin>>m;
    long long a, b;
    a = n; 
    b = m;
    while( n != 0 and m != 0){
        if(n > m){
            n = n % m;
        }else{
            m = m % n;
        }
    }
    cout<< (a * b) / (n + m);
}