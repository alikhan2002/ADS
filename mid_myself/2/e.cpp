#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
int triangle = 0;

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
    void preorder(Node *root){
        if(root != NULL){
            if(root ->left != NULL and root -> right != NULL){
                triangle++;
            }
            preorder(root->left);
            preorder(root->right);
        }
    }

};
int main(){
    int n; cin >> n;
    BST *tree = new BST();
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }
    tree->preorder(tree->root);
    cout << triangle;
}