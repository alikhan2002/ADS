#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    double l = 0, r = 1e8;
    for(int j = 0; j < 100; j++){
        double m = (l + r) / 2;
        int len = 0;
        for(int i = 0; i < n; i++){
            len += (int)v[i]/m;
        }
        if(len >= k){
            l = m;
        }else{
            r = m;
        }
    }

    cout <<setprecision(20) << l;
}