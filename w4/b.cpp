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
        size = 0;
    }

    Node *insert(Node *node, int data){
        if(node == NULL){
            node = new Node(data);
            size++;
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
    void sz(){
        cout << size;
    }
};


int main(){
    BST *tree = new BST();
    int n;
    int size = 0;
    while(cin >> n){
        if(n == 0) break;
        tree ->root = tree->insert(tree -> root, n);
        
    }
    tree->sz();
    return 0;
}