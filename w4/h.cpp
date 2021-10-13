#include <iostream>

using namespace std;

bool balance = true;
class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
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
        if(node -> data == data ) return node;
        
        if(data <= node -> data){
            node -> left = insert(node -> left, data);
        }else{
            node -> right = insert(node-> right, data);
        }
        return node;
    }
    void check_left(Node *root){
        while(root ->left != NULL){
            root = root -> left;
            int right_height = tree_height(root->right);
            int left_height = tree_height(root->left);
            if(abs(right_height - left_height) > 1){
                balance = false;
                break;
            }
        }

    }
    void check_right(Node *root){
        while(root ->right != NULL){
            root = root -> right;
            int right_height = tree_height(root->right);
            int left_height = tree_height(root->left);
            if(abs(right_height - left_height) > 1){
                balance = false;
                break;
            }
        }

    }

    int tree_height(Node *root){
        if(root == NULL){
            return 0;
        }else{
            int left_root = tree_height(root->left);
            int right_root = tree_height(root->right);
            // cout << root->data<< " ";
            return max(right_root, left_root) + 1;
        }
    }
};

int main(){

    int n;
    BST *tree = new BST();
    while(cin >> n){
        if(n == 0) break;
        tree->root = tree->insert(tree->root,n);
    }
    tree->check_left(tree->root);
    tree->check_right(tree->root);
    int right_height = tree->tree_height(tree->root->right);
    int left_height = tree->tree_height(tree->root->left);
    if(abs(right_height - left_height) <= 1 and balance){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}