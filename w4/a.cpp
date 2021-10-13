#include <iostream>
#include <vector>

using namespace std; 

class Node{
    public:
    int data;
    Node *left, *right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public:
    Node *root;
    int size;
    BST(){
        root = NULL;
    }

    Node *insert(Node *node, int data){
        if(node == NULL){
            node = new Node(data);
            return node;
        }
        if(node->data == data) return node;
        if(data <= node-> data){
            node -> left = insert(node->left, data);
        }else{
            node -> right = insert(node -> right, data);
        }
        return node;
    }
    int tree_height(Node* root) {
        if (root == NULL) 
            return 0;
        else {
            int left_height = tree_height(root->left);
            int right_height = tree_height(root->right);
            
            return max(left_height, right_height) + 1;
        }
    }
};
void print( Node* root){
    if (root != NULL){
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}


int main(){
    BST*tree = new BST();
    int n;
    while(cin >> n){
        if(n == 0) break;
        tree ->root = tree->insert(tree -> root, n);
    }
    print(tree->root);
    
    return 0;
}