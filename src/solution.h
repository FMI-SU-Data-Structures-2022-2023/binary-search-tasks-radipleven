#ifndef WEEK7_TREE_H

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
};

bool isContains(Node*, int);
Node* insert(Node*, int);
Node* getMax(Node*);
Node* getMin(Node*);
Node* remove(Node*, int);
Node* section(const Node*, const Node*);
bool areCousins(const Node*, int, int);
int LCA(const Node*, int, int);
#define WEEK7_TREE_H

#endif //WEEK7_TREE_H
