#include <iostream>
using namespace std;

class Node{
	public:
		Node *left;
		Node *right;
		
		int key;
		
		Node(){
			left = right = NULL;
		}
};

class BST{
	public:
		Node *root;
		
		BST(){
			root = NULL;
		}
		
		Node *insertRecursive(int inputKey, Node *currentRoot){
			
			if (currentRoot==NULL){
			Node *newNode = new Node();
			newNode->key = inputKey;
			return newNode;
			}

			
			if (inputKey < currentRoot->key){
				currentRoot->left = insertRecursive(inputKey, currentRoot->left);
				
			} else if (inputKey > currentRoot->key){
				currentRoot->right = insertRecursive(inputKey, currentRoot->right);
				
			}
			
			return currentRoot;
		}
		
		void insert(int inputKey){
			root = insertRecursive(inputKey, root);
		}
		
		void *preOrderTraversal(Node *currentNode){
			
			if (currentNode!=NULL){
				cout << currentNode->key << " ";
				preOrderTraversal(currentNode->left);
				preOrderTraversal(currentNode->right);
				
			}
		}
				
		void *postOrderTraversal(Node *currentNode){
			
			if (currentNode!=NULL){
			
				postOrderTraversal(currentNode->left);
				postOrderTraversal(currentNode->right);
				cout << currentNode->key << " ";
				
			}
		}
		
		void *inOrderTraversal(Node *currentNode){
			
			if (currentNode!=NULL){
			
				inOrderTraversal(currentNode->left);
				cout << currentNode->key << " ";
				inOrderTraversal(currentNode->right);
				
			}
		}
				
		void preOrder(){
			cout << "Pre Order Traversal: ";
			
			preOrderTraversal(root);
			
			cout << endl;
		}
		
        void postOrder(){
			cout << "Post Order Traversal: ";
			postOrderTraversal(root);
			cout << endl;
		}
		
		void inOrder(){
			cout << "In Order Traversal: ";
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
	

	return 0;
}





