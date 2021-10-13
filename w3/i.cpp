#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, b;
    cin >> n >> b;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < b; i++){
        int x; 
        long long l = 0, r = n - 1;
        int res_right = -1, res_left = -1;
        cin >> x;
        while( l <= r){
            int m = (r + l)/2;
            if(v[m] >= x){
                r = m - 1; 
                res_left = m;
            }else{
                l = m + 1;
            }
        }
        l = 0, r = n - 1;
        while( l <= r){
            int m = l + (r - l) / 2;
            if(v[m] <= x){
                l = m + 1; 
                res_right = m;
            }else{
                r = m - 1;
            }
        }
        if(res_left != -1 and v[res_left] == x and v[res_right] == x){
            cout << res_left + 1 << " ";
            cout << res_right + 1 << "\n";
        }else{
            cout <<"0\n";
        }
    }
    
}