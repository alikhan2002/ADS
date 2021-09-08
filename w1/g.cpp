#include <iostream>
using namespace std;
struct st{
    long long a[100000];
    int top;
    st(){
        top = -1;
    }
    void push(int x){
        top++;
        a[top] = x;
    }
    int back(){
        if(top != -1){
            return a[top];
        }
    }
    void pop(){
        if(top != -1){
            top--;
        }
    }
    int size(){
        if(top == -1) return 0;
        return top + 1;
    }
};
int main(){
    st stack;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++){        
        if( s[i] >= 48 and s[i] <= 57){
            int x = s[i] - '0';
            stack.push(x);
        }
        if(s[i] != ' '){
            if( s[i] >= 42 and s[i] <= 45){
                if(s[i] == '+'){
                    int b = stack.back();
                    stack.pop();
                    int a = stack.back();
                    stack.pop();
                    int z = a + b;
                    stack.push(z);
                }else if(s[i] == '*'){
                    int b = stack.back();
                    stack.pop();
                    int a = stack.back();
                    stack.pop();
                    int z = a * b;
                    stack.push(z);
                }else if(s[i] == '-'){
                    int b = stack.back();
                    stack.pop();
                    int a = stack.back();
                    stack.pop();
                    int z = a - b;
                    stack.push(z);
                }
            }
        }
    }cout<<stack.back();

}