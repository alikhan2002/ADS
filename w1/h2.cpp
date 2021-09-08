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
    int front1(){
        return a[front];
    }
    void pop(){
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

            if(q.size() > qq.size()){
                
                qq.push(q.front1());

                q.pop();
            }
        } else if(s == '*'){
            cin >> m;

            q.push(m);

            if(q.size() > qq.size()){

                qq.push(q.front1());

                q.pop();
            }

        }else if(s == '-'){
            cout << qq.front1() << "\n";
            
            qq.pop();
            
            if(q.size() > qq.size()){
                
                qq.push(q.front1());
                
                q.pop();
             }
        }
    }
}

