#include <iostream>
#include <fstream>
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
    int front1(){
        return a[front];
    }
    void pop(){
        front++;
    }
    int size(){
        if(top == -1) return 0;
        return top + 1 - front;
    }
};

int main(){
    string s;
    int n;
    
    while(cin >> n){

    } 
    return 0;

}