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
    void back(){
        if(top == -1){
            cout<<"error"<<'\n';
        }else{
            cout<<a[top]<<'\n';
        }
    }
    void pop(){
        if(top == -1){
            cout<<"error"<<'\n';
        }else if(top != -1){
            cout<<a[top]<<'\n';
            top--;
        }
    }
    int size(){
        if(top == -1) return 0;
        return top + 1;
    }
    int clear(){
        return top = -1;
    }
};
int main(){
    st ss;
    string s;
    while( cin>>s ){
        if(s == "size"){
            cout<<ss.size()<<'\n';
        }
        if(s == "push"){
            int n;
            cin>>n;
            ss.push(n);
            cout<<"ok"<<'\n';
        }
        if(s == "back"){
            ss.back();
        }
        
        if(s == "pop"){
            ss.pop();
        }
        if(s == "clear"){
            ss.clear();
            cout<<"ok"<<'\n';
        }

        if(s == "exit"){
            cout<<"bye";
            break;
        }
    }
}