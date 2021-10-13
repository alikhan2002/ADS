#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int n; 
    cin >> n;
    vector<int> a(n);
    int maxi = -5645;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(maxi < a[i]) maxi = a[i];
    }
    sort(a.begin(), a.end());
    int j = a.size() - 1;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] != a[j]){
            cout << a[i];
            break;
        }
    }


}