#include <iostream>
using namespace std;

struct st{
    int a[100000];
    int top;
    int front;
    int size_c;
    
    st(){
        top = 0;
        front = 0;
        size_c = 0;
    }
    void push_back(int x){
        top++;
        a[top] = x;
        size_c++;
    }
    void push_front(int x){
        int f = top + 1;
        size_c++;
        if(top > 0){
            while(f >= 0){
                a[f] = a[f - 1];
                f--;
            }
        }
        a[front] = x;
    }
    void front1(){
        cout<<a[front]<<'\n';
    }
    void back(){
        cout<<a[top]<<'\n';
    }
    void pop_front(){
        int n = a[front];
        front++;
        cout<<n<<'\n';
        size_c--;

    }
    void pop_back(){
        cout<<a[top]<<'\n';
        top--;
        size_c--;
    }
    int size(){
        return size_c;
    }
    void clear(){
        top = 0;
        front = 0;
        size_c = 0;
    }
};
int main(){
    st ss;
    string s;
    while( cin>>s ){
        if(s == "size"){
            cout<<ss.size()<<'\n';
        }
        if(s == "push_back"){
            int n;
            cin>>n;
            ss.push_back(n);
            cout<<"ok"<<'\n';
        }
        if(s == "push_front"){
            int n;
            cin>>n;
            ss.push_front(n);
            cout<<"ok"<<'\n';
        }
        if(s == "front"){
            if(ss.size() == 0){
                cout<<"error"<<'\n';
            }else{
                ss.front1();
            }
        }
        if(s == "back"){
            if(ss.size() == 0){
                cout<<"error"<<'\n';
            }else{
                ss.back();
            }
        }
        
        if(s == "pop_front"){
            if(ss.size() == 0){
                cout<<"error"<<'\n';
            }else{
                ss.pop_front();
            }
        }
        if(s == "pop_back"){
            if(ss.size() == 0){
                cout<<"error"<<'\n';
            }else{
                ss.pop_back();
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