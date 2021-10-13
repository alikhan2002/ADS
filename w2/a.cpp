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
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    void add_back(string x){
        size++;
        node * newNode = new node(x);
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
        while(temp){
            if(temp -> val == x){
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
    }

};

int main(){
    ll * l = new ll();
    ll * lk = new ll();
    ll * ls = new ll();
    ll * la = new ll();
    freopen("input.txt", "r", stdin);
    // associates standard output with output.txt
    // (this will create a new file called output.txt if none exists)
    
	freopen("output.txt", "w", stdout);
    // reads the input.txt file and stores in string x
    string c;
    while(cin >> c){
        l -> add_back(c);
        if(cin.get() == -1) break;
    }
    map<string, int> mp;
    // cout<<"a";
    while(!l -> empty()){
            // cout << (l -> head) -> val<<"\n";
            mp[(l -> head) -> val]++;
            l -> dl(l -> head);
    }
    map<string, int> :: iterator it;
    for(auto it = mp.begin(); it != mp.end(); it++){
        ls  -> add_back(it->first);
        la  -> add_back(to_string(it->second));
    }
    while(!ls -> empty()){
        cout<<(ls -> head) -> val << " " << (la -> head) -> val <<'\n';
        ls -> dl(ls -> head);
        la -> dl(la -> head);
    }

    // prlong longs string x in output.txt file
    fclose(stdout);
    return 0;
}