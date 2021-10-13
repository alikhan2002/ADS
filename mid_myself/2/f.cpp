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
    void push(Node *root, vector<int> &v){
        if(root != NULL){
            push(root -> left, v);
            v.push_back(root->data);
            push(root-> right, v);
        }
    }
    Node* balance(vector<int> &a, int l, int r){
        int m = l + (r - l) / 2;
        Node *node = new Node(a[m]);
        if(l > r) return NULL;
        node ->left = balance(a, l, m - 1);
        node -> right = balance(a, m + 1, r);
        return root;
    }
    vector<int> v;
    Node* balanceBST(Node *root){
        push(root, v);
        return balance(v, 0, v.size() - 1);
    }


};


int main(){

    BST *tree = new BST();
    vector<int> v;
    int n; cin >> n;
    for(int i = 0; i < pow(2, n) - 1; i++){
        int x;
        cin >> x;
        tree->root= tree -> insert(tree->root, x);
        v.push_back(x);
    }
    tree->balanceBST(tree->root);

    return 0;
}