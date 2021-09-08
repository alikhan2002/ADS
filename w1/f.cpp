#include <iostream>
using namespace std;
struct st{
    char a[100000];
    int top;
    st(){
        top = -1;
    }
    void push(char x){
        top++;
        a[top] = x;
    }
    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    char back(){
        if(top != -1){
            return a[top];
        }
    }
    void pop(){
        if(top != -1) top--;        
    }

};
int main(){
st ss;
string s;
cin>>s;
bool res=true;
bool res1=false;
for(int i=0; i<s.size(); i++){

    if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
      
        ss.push(s[i]);
    } 
    else if(s[i]==')' && !ss.empty() && ss.back()=='(' ){
    
        ss.pop();
    
    }else if(s[i]=='}' && !ss.empty() && ss.back()=='{' ){
    
        ss.pop();
    
    }else if(s[i]==']' && !ss.empty() && ss.back()=='[' ){
    
        ss.pop();
    
    }else if ((s[i] == '}' || s[i] == ')' || s[i]==']') && ss.empty()) {
    
                res=false;
    
                break;
    
        }else if (!ss.empty() || (s[i] == ')' && ss.back() == '(') || (s[i] == '}' && ss.back() == '{') || (s[i] == ']' && ss.back() == '[')) {
    
                res1=true;
    
                break;
 }
}
if(ss.empty() && (res || res1)) cout<<"yes";
else cout<<"no";
}