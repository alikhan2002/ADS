#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long res = 0;
    sort(v.begin(),v.end());
    int i = 1;
    int k = v[v.size() - 1];
    int j = v.size() - 2;
    while(x >= 0){
        if(j >= 0){
            if(k <= v[j]){
                i++;
                j--;
            }
        }
        if(x - i < 0){
            while(true){
                if(x - i >= 0){
                    res += k * i;
                    cout << res;
                    break;
                }i--;
            }
            break;
        }
        x -= i;
        res += k * i;
        k--;
        
    }
}