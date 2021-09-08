#include <iostream>
using namespace std;

struct st{
    long * a;
    long top;
    long front;
    st(long n){
        top = -1;
        front = 0;
        a = new long[n];
    }
    void push(long x){
        top++;
        a[top] = x;
    }
    
    // void middle(long n){
    //     a[top + 1] = a[top];
    //     a[top] = n;
    //     top++;
    // }
    void front1(){
        cout<<a[front]<<'\n';
        front++;
    }
    int size(){
        return top + 1 - front;
    }
};
int main(){
    long  n;
    long i = 0; 
    cin >> n;
    st q(n);
    st qq(n);
    for(int i = 0; i < n; i++){
        long m;
        char s;
        cin >> s;
        if(s == '+'){
            cin >> m;
            q.push(m);
        } else if(s == '*'){
            cin >> m;
            q.middle(m);
        }else if(s == '-'){
            q.front1();
       }
    }
}

