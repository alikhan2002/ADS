#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            v.push_back(i + 1); 
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}