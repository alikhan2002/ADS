#include <iostream>
using namespace std;

struct st{
    int a[1000];
    int top;
    st(){
        top = -1;
    }
    void push(int x){
        top++;
        a[top] = x;
    }
    int back(){
        return a[top];
    }
    void pop(){
        if(top != -1){
            top--;
        }
    }
};
int main(){
    st ss;
    int n;
    cin >> n;
    string s = "" ;
    bool res = true;
    for( int i = 0; i < n; i++){
        int m;
        cin>>m;
        int b[m];
        for( int j = 0; j < m; j++){
            int k;
            cin>>k;
            b[j] = k;
            ss.push(k);
            if(k > n){
                res = false;
            }
        }
        if(n == 2 && i == 0){
            for( int j = 1; j < m; j++){
                if(b[j - 1] > b[j]) res = false;
            }
        }
        if(n == 2 && i == 1){
            for( int j = 1; j < m; j++){
                if(b[j - 1] < b[j]) res = false;
            }
        }
        for( int j = 0; j < m; j++){
            if( i + 1 != ss.back()){
                s += to_string(i + 1) + " " + to_string(ss.back()) + '\n';
            }
            
            ss.pop();
        }
    }
    if(res) cout<<s;
    else{
        cout<<"0";
    }
}