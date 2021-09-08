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

    void push_back(int x){
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
   

    st  * f = new st;
    st * second = new st;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        long m;
        char s;
        cin >> s;
        if(s == '+'){
            cin >> m;
            f->push_back(m);
            if(f->size() > second->size()){
                second->push_back(f->front1());
                f->pop_front();
            }
        } else if(s == '*'){
            cin >> m;
            f->push_front(m);
            if(f->size() > second->size()){
                second->push_back(f->front1());
                f->pop_front();
            }
        }else if(s == '-'){
                cout<<second->front1()<<'\n';
                second->pop_front();
                if(f->size() > second->size()){
                    second->push_back(f->front1());
                    f->pop_front();
                }
       }
    }
    return 0;
}