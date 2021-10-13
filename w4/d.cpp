#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data){
        this -> data = data;
        this->left = this->right = NULL;
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
        if(node -> data == data) return node;
        
        if(data <= node -> data){
            node -> left= insert(node ->left, data);
        }else{
            node -> right = insert(node -> right, data);
        }
        return node;
    }
};
void print(Node *root){
    if(root != NULL){
        print(root -> left);
        cout << root -> data << "\n";
        print(root -> right);
    }
}

int main(){
    int n;
    BST *tree = new BST();
    while(cin >> n){
        if( n == 0) break;
        tree -> root = tree ->insert(tree->root, n);
    }
    print(tree->root);

    return 0;
}