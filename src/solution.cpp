#include "solution.h"
#include <iostream>

bool isContains(Node* node, int key) {

    if(!node)return false;
    if(key< node->key) return isContains(node->left,key);
    if(key>node->key) return isContains(node->right,key);

    return true;
}

Node* insert(Node* node, int value) {

    if(!node) return new Node(value);

    (value < node->key) ? (node->left = insert(node->left, value)) : (node->right= insert(node->right,value));
    
    return node;
}

Node* getMax(Node* node) {
    if(!node) return nullptr;
    if(!node->right) return node;
    return getMax(node->right);
    return nullptr;
}

Node* getMin(Node* node) {
    if(!node) return nullptr;
    if(!node->left) return node;
    return getMin(node->left);
    return nullptr;
}

Node* remove(Node* node, int key) {

    if(!node) return nullptr;//does not exist
    if(key == node->key && !node->left && node->right) //leaf
    {
        delete node;
        return nullptr;
    }

    if(key == node->key)//one child
    {
        Node* temp;
        if (!node->left)
        {
            temp = node->right;
            delete node;
        }
        else if(!node->right)
        {
            temp = node->left;
            delete node;
        }
        else //2 children
        {
            temp = getMin(node->right);

            Node* newNode = new Node (temp->key);
            newNode->left= node->left;
            newNode->right= node->right;
            delete node;
            newNode->right= remove(newNode->right,temp->key);
            return newNode;
        }
        return temp;
    }



    if (key < node->key) node->left = remove(node->left, key);
    if (key > node->key) node->right= remove(node->right,key);
  
    return node;
    //A tree is called a balanced tree <=> |H left - H right| = 0   (H = height)
}
int getHeight (Node *tree)
{
    if(!tree) return 0;
    return 1 + std:: max(getHeight(tree->left),getHeight(tree->right));
}
bool isBalanced(Node* tree)
{
    if(!tree) return true;

    if(std:: abs(getHeight(tree->left)-getHeight(tree->right)) > 1) return false;

    return isBalanced(tree->left) && isBalanced(tree->right); 

}
Node* section(const Node* l, const Node* r) {
    return nullptr;
}

bool areCousins(const Node*, int key1, int key2) {
    return false;
}

int LCA(const Node* root, int key1, int key2) {
    if (!root || root->key == key1 || root->key == key2) return root->key;
    Node* left; left->key = LCA(root->left, key1, key2);
    Node* right; right->key = LCA(root->right, key1, key2);
    return !left->key ? right->key : !right->key ? left->key : root->key;
}