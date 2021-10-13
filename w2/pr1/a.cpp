#include <bits/stdc++.h>
using namespace std;

struct node{
    string val; 
    
    node * next;

    node * prev;

    node(string x){
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
    
    void add(string x){
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

    node * find(string x){
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
    void dl(string x){
        node * temp = find(x);
        if(temp != NULL) dl(temp);
        else {
            check++;
        }
    }

};

int main(){
    ll * l = new ll();
    freopen("input.txt", "r", stdin);
    // associates standard output with output.txt
    // (this will create a new file called output.txt if none exists)
    
	freopen("output.txt", "w", stdout);
    // reads the input.txt file and stores in string x
    string c;
    long long n;
    while(cin >> c){
            l -> add(c);
        if(c[0] == ' ')
            break;
    }
    if( l -> empty()){
        cout<<"EMPTY";
    }else{
        while(!l -> empty()){
                cout << (l->head)->val<<" ";
                l -> dl(l -> head);
        }
    }
    // prlong longs string x in output.txt file
    fclose(stdout);
    return 0;
}