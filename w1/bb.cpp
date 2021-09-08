#include <iostream>
using namespace std;

struct st{
    int a[100000];
    int top;
    int front;
    st(){
        top = -1;
        front = 0;
    }
    void push(int x){
        top++;
        a[top] = x;
    }
    void front1(){
        cout<<a[front]<<'\n';
    }
    void pop(){
        int n = a[front];
        front++;
    }
    int size(){
        return top + 1 - front;
    }
    void clear(){
        top = -1;
        front = 0;
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
        if(s == "front"){
            if(ss.size() == 0){
                cout<<"error"<<'\n';
            }else{
                ss.front1();
            }
        }
        
        if(s == "pop"){
            if(ss.size() == 0){
                cout<<"error"<<'\n';
            }else{
                ss.pop();
            }
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