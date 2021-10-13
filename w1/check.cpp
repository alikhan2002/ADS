#include <iostream>
using namespace std;

struct st{
    int a[100000];
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
    bool empty(){
        if(top != -1){
            return 0;
        }
        return 1;
    }
};
int main(){
    st ss[1000];
    string s;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j =0 ; j < n; j++){
            int m;
            cin>>m;
            ss[i].push(m);
        }
    }
    while(!ss[0].empty()){
        cout<<ss[0].back()<<" ";
        ss[0].pop();
    }
}