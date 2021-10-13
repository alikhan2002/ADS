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
    Node *find_second_max(Node *node){
        while(node -> right != NULL and node->right->right != NULL){
            node = node ->right;
        }
        Node *prev = node;
        if(node ->right != NULL){
            node = node ->right;
        }
        if(node ->left != NULL){
            node = node ->left;
            while(node -> right !=NULL){
                node = node ->right;
            }
            return node;
        }else{
            return prev;
        }
    }
};


int main(){
    BST *tree = new BST();
    int n;
    while(cin >> n){
        if(n == 0) break;
        tree ->root = tree->insert(tree -> root, n);
        
    }
    cout << tree->find_second_max(tree->root)->data;
    return 0;
}