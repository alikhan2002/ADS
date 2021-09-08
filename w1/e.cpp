#include <iostream>
using namespace std;
struct st{
    long long a[100000];
    long long b[100000];
    int top;
    int front;
    int front_1;
    int top_1;
    st(){
        top = -1;
        front = 0;
        top_1 = -1;
        front_1 = 0;
    }
    void push_1(int x){
        top++;
        a[top] = x;
    }
    void push_2(int x){
        top_1++;
        b[top_1] = x;
    }
    int front1(){
        return a[front];
    }
    int front2(){
        return b[front_1];
    }
    void pop(){
        front++;
    }
    void pop_1(){
        front_1++;
    }
    int size(){
        return top + 1 - front;    
    }
    int size_1(){
        return top_1 + 1 - front_1;
    }
};
int main(){
    st ss;
    int i = 0;
    int n, m;
    while( i < 5){
        cin>>n;
        ss.push_1(n);
        i++;
    }
    int j = 0;
    while( j < 5){
        cin >> m;
        ss.push_2(m);
        j++;
    }
    long long cnt = 0; 
    while(ss.size() != 0 and ss.size_1() != 0 ){
        int t1 = ss.front1();
        ss.pop();
        int t2 = ss.front2();
        ss.pop_1();
        if(t1 > t2){
            if(t1 == 9 && t2 == 0){
                ss.push_2(t1);
                ss.push_2(t2);
            }else{
                ss.push_1(t1);
                ss.push_1(t2);}
            }else if(t1 < t2 ){
                if(t1 == 0 && t2 == 9){
                    ss.push_1(t1);
                    ss.push_1(t2);
                }else{
                    ss.push_2(t1);
                    ss.push_2(t2);
                }
        }  
        
        cnt++;
        
    }
    if(ss.size() == 0){
            cout<<"second "<<cnt;
        }
        if(ss.size_1() == 0){
            cout<<"first "<<cnt;
        }
        if(cnt > 1000000){
            cout<<"botva";
        }
        

}