#include <iostream>
using namespace std;

struct st{
    int a[100000];
    int top;
    st(){
        top = -1;
    }
    void push(int x){
        top++;
        a[top] = x;
    }
    int back(){
        return a[top];
    }
    void pop(){
        if(top != -1){
            top--;
        }
    }
    bool empty(){
        if(top != -1){
            return 0;
        }
        return 1;
    }
};
int main(){
    int n;
    cin >> n;
    string s = "" ;
    st ss, c, check;
    bool res = true;
    if(n == 0){
        return 0;
    }
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        for( int j = 0; j < m; j++){
            int k;
            cin >> k;
            if(k > n){
                res = false;
            }
            if(i == 0){
                ss.push(k);
            }else{
                c.push(k);
                check.push(k);
            }
        if( n > 2){
            if(i > 0){
                while(!c.empty()){
                    ss.push(c.back());
                    c.pop();
                    s += to_string(i + 1) + " 1" + '\n';
                    }
                }
            }
        }
    }
    if(n == 2){
        while( ss.back() == 2 and !ss.empty()){
            s += "1 2\n";
            ss.pop();
        }
        while( ss.back() == 1){
            ss.pop();
        }
        while( c.back() == 1){
            c.pop();
            s += "2 1\n";
        }
        while( c.back() == 2){
            if(c.empty()) break;
            c.pop();
        }
    }  
    if(n == 2){
        if( ss.empty() and c.empty()){
            cout<<s;
            return 0;
        } else{
            cout<<"0";
            return 0;
        }
    }
    //*********************

    // if(n == 2 and !c.empty() and !ss.empty()){
    //     while(ss.back()!= 1){
    //         if(ss.back() == 2){
    //             s += "1 2\n";
    //             ss.pop();
    //         }else{
                
    //         }
    // }
    // if(c.empty()){
    //     while(!ss.empty()){
    //         if(ss.back() != 1){
    //             s += "1 " + to_string(ss.back()) + '\n';
    //         }
    //         ss.pop();
    //     }
    // }
    // while(!ss.empty()){
    //     cout<<ss.back()<<" ";
    //     ss.pop();
    // }
    if( check.empty()){
        while(!ss.empty()){
            if(ss.back() != 1){
                s += "1 " + to_string(ss.back()) + '\n';
            }
            ss.pop();
        }
    }else{
        while(!ss.empty()){
            if(ss.back() > 2){
                s += "1 " + to_string(ss.back()) + '\n';
                ss.pop();
            }else{
                s += "1 2\n";
                c.push(ss.back());
                ss.pop();
            }
        }
        while(!c.empty()){
            if(c.back() == 1){
                s +=  "2 1\n"; 
                c.pop();
            }else{
                s += "2 3\n";
                ss.push(c.back());
                c.pop();
            }
        }
    }
    
    while(!ss.empty()){
        s += "3 " + to_string(ss.back())+ '\n';
        ss.pop();
        }
    if(res) {
        cout<<s;
    }
    else cout<<"0";
    return 0;
}