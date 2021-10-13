#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n; 
    cin>>n;
    stack <int> st[n];
    for(int i = 0; i < n; i++){
        for(int j =0 ; j < n; j++){
            int m;
            cin>>m;
            st[i].push(m);
        }
    }
    while(!st[0].empty()){
        cout<<st[0].top()<<" ";
        st[0].pop();
    }
    


}

