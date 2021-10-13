#include <bits/stdc++.h>
using namespace std;

struct node{
    long long val; 
    
    node * next;

    node * prev;

    node(long long x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct ll{
    node * head;
    node * tail;
    long long size, check;
    
    ll(){
        head = NULL;
        tail = NULL;
        size = check = 0;
    }
    
    void add(long long x){
        node * newNode = new node(x);
        size++;
        check++;
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    node * find(long long x){
        node * temp = head;
        node * result = NULL;
        while(temp != NULL){
            if(temp->val == x){
                result = temp;
                break;
            }
            temp = temp->next;
        }   
        return result;
    }

     void dl(node * n){
        if(n != NULL){
            size--;
            check--;
            if(n->prev == NULL && n->next == NULL){
                head = tail = NULL;
            }else if(n->prev != NULL && n->next != NULL){
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }else if(n->prev == NULL && n->next != NULL){
                head = n->next;
                n->next->prev = NULL;
            }else if(n->next == NULL && n->prev != NULL){
                tail = n->prev;
                n->prev->next = NULL;  
            }
            delete n;
        }
    }
    bool empty(){
        return size == 0;
    }
    bool check_empty(){
        return check == 0;
    }
    void dl(long long x){
        node * temp = find(x);
        if(temp != NULL) dl(temp);
        else {
            check++;
        }
    }
    bool dl_1(long long x){
        node * temp = find(x);
        if(temp != NULL) return 1;
        else {
            return 0;
        }
    }

};

int main(){
    ll * l = new ll();
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    char c;
    long long n;
    while(cin >> c){
        if(!(cin >> n)) break;
        if(c == '+'){
            l->add(n);
        }
        if(c == '-'){
            if(l->find(n) != NULL){
                l -> dl(n);
            }else{
               l -> add(-1);
            }
        }
        if(cin.get() == -1)
            break;
    }
    if( l -> empty()){
        cout<<"EMPTY";
    }else{
        while(!l -> empty()){
            if((l->head)->val != -1){
                cout << (l->head)->val<<" ";
                l -> dl(l -> head);
            }else{
                freopen("output.txt", "w", stdout);
                cout<< "ERROR ";
                break;
            }
        }
    }
    // prlong longs string x in output.txt file
    fclose(stdout);
    return 0;
}