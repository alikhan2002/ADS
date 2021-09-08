#include <iostream>
#include <fstream>
using namespace std;
struct st{
    string b[10000];
    int a[10000];
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
    void push_st(string x){
        top++;
        b[top] = x;
    }
    int front1(){
        return a[front];
    }
    string front2(){
        return b[front];
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
    st clas; 
    st name;
    st cl, na;
    st cl_11, na_11;
    string s;
    ifstream file("input.txt");
    int count = 0;
    while(getline(file, s)){
        count++;
        string c = "";
        int x;
        for(int i = 0; i < 1; i++){
            if(s[i] >= 48 and s[i] <= 57){
                if(s[i + 1] >= 48 and s[i + 1] <= 57){
                    c += s[i];
                    c += s[i + 1];
                    x = stoi(c); 
                }else{  
                    x = s[i] - '0'; 

                }
                if()
            }

        }
        string d = "";
        for(int i = 3; i < s.size(); i++){
            d += s[i];

        }
        name.push_st(d);
    }
    int cnt = 9;
    while(clas.size() != 0){
        for(int i = 0; i < count; i++){
            if(clas.front1() == cnt){
                cl.push(cnt);
                na.push_st(name.front2());
                name.pop();
                clas.pop();
        }
        cnt++;        
    }
    while(cl.size() != 0){
        cout<<cl.front1()<<" "<<na.front2()<<endl;
        cl.pop();
        na.pop();

    }
    file.close(); 

    return 0;

}