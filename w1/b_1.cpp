#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
 
struct queue{
    int storage[100000];
    int start;
    int finish;
    queue(){
        start = 0;
        finish = 0;
    }
 
    void push(int n){
        storage[finish] = n;
        finish++;
    }
 
    int pop(){
        int a = storage[start];
        start++;
        return a;
    }
 
    int front(){
        return storage[start];
    }
 
    int size(){
        return finish - start;
    }
 
    string clear(){
        finish = 0;
        start = 0;
        return "ok";
    }
 
    string exit(){
        return "bye";
    }
};
 
int main() {
    string a;
    string n;
    queue x;
    string i = "";
    while(cin >> a){
        if(a == "push"){
            int n;
            cin >> n;
            x.push(n);
            i += "ok\n";
        }
        else if(a == "pop" && x.size()!=0){
            n = to_string(x.front());
            x.pop();
            i += n + "\n";
        }
        else if(a == "pop" && x.size()==0){
            i += "error\n";
        }
        if(a == "front" && x.size()!=0){
            n = to_string(x.front());
            i += n + "\n";
        }else if(a == "front" && x.size()==0){
            i += "error\n";
        }
        if(a == "size"){
            n = to_string(x.size());
            i += n + "\n";
        }
        else if(a == "clear"){
            x.clear();
            i += "ok\n";
        }
        else if(a == "exit"){
            i += "bye\n";
            break;
        }
 
    }
    cout << i;
    return 0;
}