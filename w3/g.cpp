#include <iostream>
 
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    long long a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
   
    while(k--){
        long long r = n - 1, l = 0;
        long long x;
        cin >> x;
        while( l <= r){
            long long mid = (r + l)/2;
            if(a[mid] == x){
                cout <<"YES\n";
                break;
            }else if( a[mid] > x){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }   
        if(l > r){
            cout << "NO\n";
        }
    }
}