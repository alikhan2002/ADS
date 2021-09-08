#include <iostream>
using namespace std;

struct st{
    int a[1000000];
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
        cout<<n<<'\n';
    }
    int size(){
        if(top == -1) return 0;
        return top + 1 - front;
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
        if(s == "front"){
            if(ss.size() != 0){
                ss.front1();
            }else{
                cout<<"error"<<'\n';
            }
        }
        
        if(s == "pop"){
            if(ss.size() != 0){
                ss.pop();
            }else{
                cout<<"error"<<'\n';
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