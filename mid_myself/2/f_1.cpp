#include <bits/stdc++.h>

using namespace std;

class Node{
    public: 
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->right = this->left = NULL;
    }
};
vector<Node*> v;
class BST{
    public: 
    Node *root;
    BST(){
        root = NULL;
    }

    Node *insert(Node *node, int data){
        if(node == NULL){
            node = new Node(data);
            return node;
        }
        if(data <= node ->data){
            node ->left = insert(node->left, data);
        }else{
            node ->right = insert(node->right, data);
        }
        return node;   
    }
    void push(Node *root){
        if(root != NULL){
            cout << root ->data << " ";
            push(root -> left);
            v.push_back(root);
            push(root-> right);
        }
    }
    Node* balance(vector<Node*> &a, int l, int r){
        int m = l + (r - l) / 2;
        Node *node = a[m];
        if(l > r) return NULL;
        node ->left = balance(a, l, m - 1);
        node -> right = balance(a, m + 1, r);
        return v[m];
    }


};


int main(){

    BST *tree = new BST();
    int n; cin >> n;
    for(int i = 0; i < pow(2, n) - 1; i++){
        int x;
        cin >> x;
        tree->root= tree -> insert(tree->root, x);
    }
    tree ->balance(v, 0, v.size() - 1);
    tree->push(tree -> root);

    return 0;
}