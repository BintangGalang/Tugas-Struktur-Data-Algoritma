#include <iostream>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int key;
    
    Node() {
        left = right = NULL;
    }
};

class BST {
public:
    Node *root;
    
    BST() {
        root = NULL;
    }
    
    Node *insertRecursive(int inputKey, Node *currentRoot) {
        if (currentRoot == NULL) {
            Node *newNode = new Node();
            newNode->key = inputKey;
            return newNode;
        }
        
        if (inputKey < currentRoot->key) {
            currentRoot->left = insertRecursive(inputKey, currentRoot->left);
        } else if (inputKey > currentRoot->key) {
            currentRoot->right = insertRecursive(inputKey, currentRoot->right);
        }
        
        return currentRoot;
    }
    
    void insert(int inputKey) {
        root = insertRecursive(inputKey, root);
    }
    
    Node *searchRecursive(int targetKey, Node *currentNode) {
        if (currentNode == NULL || currentNode->key == targetKey) {
            return currentNode;
        }
        
        if (targetKey < currentNode->key) {
            return searchRecursive(targetKey, currentNode->left);
        } else {
            return searchRecursive(targetKey, currentNode->right);
        }
    }
    
    Node *search(int targetKey) {
        return searchRecursive(targetKey, root);
    }
    
    Node *findMinNode(Node *currentNode) {
        while (currentNode->left != NULL) {
            currentNode = currentNode->left;
        }
        return currentNode;
    }
    
    Node *deleteNode(Node *currentNode, int keyToDelete) {
        if (currentNode == NULL) {
            return currentNode;
        }
        
        if (keyToDelete < currentNode->key) {
            currentNode->left = deleteNode(currentNode->left, keyToDelete);
        } else if (keyToDelete > currentNode->key) {
            currentNode->right = deleteNode(currentNode->right, keyToDelete);
        } else {
            if (currentNode->left == NULL) {
                Node *temp = currentNode->right;
                delete currentNode;
                return temp;
            } else if (currentNode->right == NULL) {
                Node *temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            
            Node *minRight = findMinNode(currentNode->right);
            currentNode->key = minRight->key;
            currentNode->right = deleteNode(currentNode->right, minRight->key);
        }
        
        return currentNode;
    }
    
    void preOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            cout << currentNode->key << " ";
            preOrderTraversal(currentNode->left);
            preOrderTraversal(currentNode->right);
        }
    }
    
    void inOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            inOrderTraversal(currentNode->left);
            cout << currentNode->key << " ";
            inOrderTraversal(currentNode->right);
        }
    }
    
    void postOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            postOrderTraversal(currentNode->left);
            postOrderTraversal(currentNode->right);
            cout << currentNode->key << " ";
        }
    }
    
    void preOrder() {
        cout << "Pre Order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }
    
    void inOrder() {
        cout << "In Order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
    
    void postOrder() {
        cout << "Post Order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }
};

int main(int argc, char** argv) {
    BST *bin1 = new BST();
    
    bin1->insert(6);
    bin1->insert(7);
    bin1->insert(4);
    bin1->insert(8);
    bin1->insert(5);
    bin1->insert(3);
    
    bin1->preOrder();
    bin1->postOrder();
    bin1->inOrder();
    
    int keyToSearch = 5;
    Node *searchResult = bin1->search(keyToSearch);
    if (searchResult != NULL) {
        cout << "Found: " << searchResult->key << endl;
    } else {
        cout << "Not Found" << endl;
    }
    
    int keyToDelete = 4;
    bin1->deleteNode(bin1->root, keyToDelete);
    
    bin1->preOrder();
    bin1->postOrder();
    bin1->inOrder();
    
    return 0;
}




