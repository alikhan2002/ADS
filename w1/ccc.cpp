#include <iostream>

using namespace std;


struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct st{
    node * tail;
    node * front;
    int cnt;
    st(){
        tail = NULL;
        front = NULL;
        cnt = 0;
    }

    int top(){
        if(tail != NULL){
            return tail->val;
        }
        return -1;
    }
    int front1(){
        if(front != NULL){
            return front->val;
        }
        return -1;
    }

    void push(int x){
       node * item = new node(x);
       cnt++;
       if(tail == NULL){
           tail = item;
           front = tail;
       }else{
            tail->next = item;
            item->prev = tail;
            tail = item;
       }
    }
    void push_front(int x){
        cnt++;
        node * item = new node(x);
        if(front == NULL){
            front = item;
            tail = front;
        }else{
                item->next = front;
                front->prev = item;
                front = item;
        }
    }
    void pop(){
        cnt--;
        if(front != NULL){
            tail = tail->prev;
            if (tail == NULL){
                front = NULL;
            }else{
                tail -> next = NULL;
            }
        }
    }
    void pop_front(){
        cnt--;
        if(tail != NULL){
            front = front->next;
            if(front == NULL){
                tail = NULL;
            }else{
                front -> prev = NULL;
            }
        }
    }

    bool empty(){
        return cnt == 0;
    }
    void clear(){
        cnt = 0;
        tail = NULL;
        front = NULL;
    }
    int size(){
        return cnt;
    }

};
int main(){
   

    st  * ss = new st;

    string s;
    while( cin>>s ){
        if(s == "size"){
            cout<<ss->size()<<'\n';
        }
        if(s == "push_front"){
            int n;
            cin>>n;
            ss->push_front(n);
            cout<<"ok"<<'\n';
        }
        if(s == "push_back"){
            int n;
            cin>>n;
            ss->push(n);
            cout<<"ok"<<'\n';
        }
        if(s == "front"){
            if(ss->front1() == -1){
                cout<<"error"<<'\n';
            }else{
                cout<<ss->front1()<<'\n';
            }
        }
        if(s == "back"){
             if( ss->top() == -1 ){
                cout<<"error"<<'\n';
            }else{
                cout<<ss->top()<<'\n';
            }
        }
        if(s == "pop_back"){
            if( ss->empty() ){
                cout<<"error"<<'\n';
            }else{
                cout<<ss->top()<<'\n';
                ss->pop();
            }
        }
        if(s == "pop_front"){
            if( ss->empty() ){
                cout<<"error"<<'\n';
            }else{
                cout<<ss->front1()<<'\n';
                ss->pop_front();
            }
        }
        if(s == "clear"){
            ss->clear();
            cout<<"ok\n";
        }

        if(s == "exit"){
            cout<<"bye";
            break;
        }
    }

    return 0;
}