#include <bits/stdc++.h>

using namespace std;

int main(){

    int n; cin >> n;

    vector<int> v(n);
    vector<int> a;


    for(int i = 0; i < n; i++){
        cin >> v[i];
        a.push_back(v[i]);
    }
    
    for(int i = 0; i < n; i++){
        int res = 0;
        if(i < 2) {
            cout << "-1\n";
        }
        else{
            sort(a.begin(), a.begin() + i + 1);
            res = a[i] * a[i - 1] * a[i - 2];
            cout <<  res << "\n";
        }
    }
}