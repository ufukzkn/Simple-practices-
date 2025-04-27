#include <iostream>
using namespace std;

//Exercise 1
class Node {
private:
    int value;
    Node* left;
    Node* right; 
    Node* parent;
public:
    Node(int v, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) 
        : value(v), left(left), right(right), parent(parent) {}
    int getV() { return value; }//hebele bura point
    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    Node* getParent() { return parent; }
    void setV(int v) { this->value = v; }
    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }
    void setParent(Node* p) { parent = p; }
};

class BST {
private:
    Node* root;
public:
    BST() { root = nullptr; }
    
    bool empty(Node* p) {
        return p == nullptr;
    }
    
    Node* getRoot() { return root; }
    
    void insert(int x) {
        Node* newNode = new Node(x);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        Node* current = root;
        Node* parent = nullptr;
        
        while (current != nullptr) {
            parent = current;
            if (x < current->getV())
                current = current->getLeft();
            else
                current = current->getRight();
        }
        
        newNode->setParent(parent);
        if (x < parent->getV())
            parent->setLeft(newNode);
        else
            parent->setRight(newNode);
    }
    
    Node* search(int x) {
        Node* current = root;
        while (current != nullptr && current->getV() != x) {
            if (x < current->getV())
                current = current->getLeft();
            else
                current = current->getRight();
        }
        return current;
    }
    
    void inorder(Node* n) {
        if (n != nullptr) {
            inorder(n->getLeft());
            cout << n->getV() << " ";
            inorder(n->getRight());
        }
    }
};

int main(int argc, char** argv) {
    //Exercise 1 - tests
    cout << endl << "Exercise 1 - tests" << endl;
    BST *bt = new BST();
    
    cout << endl << "bt->insert(15): 15 - ";
    bt->insert(15);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(7): 7 15 - ";
    bt->insert(7);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(4): 4 7 15 - ";
    bt->insert(4);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(19): 4 7 15 19 - ";
    bt->insert(19);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(9): 4 7 9 15 19 - ";
    bt->insert(9);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(16): 4 7 9 15 16 19 - ";
    bt->insert(16);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(17): 4 7 9 15 16 17 19 - ";
    bt->insert(17);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(2): 2 4 7 9 15 16 17 19 - ";
    bt->insert(2);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(11): 2 4 7 9 11 15 16 17 19 - ";
    bt->insert(11);
    bt->inorder(bt->getRoot());
    
    cout << endl << "bt->insert(10): 2 4 7 9 10 11 15 16 17 19 - ";
    bt->insert(10);
    bt->inorder(bt->getRoot());
    cout << endl;
    
    return 0;
}
