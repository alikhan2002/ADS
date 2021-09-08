#include <iostream>
using namespace std;
int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    while(n != 0 and m != 0){
        if(n > m){
            n = n % m;
        }else{
            m = m % n;
        }
    }
    cout<<n + m;

}