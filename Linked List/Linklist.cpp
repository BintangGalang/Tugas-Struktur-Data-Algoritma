#include <iostream>
using namespace std;

class Node{
	public:
		char id;
		Node *next;
	
	Node(){
		next = NULL;
	}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
	LinkedList(){
		head = tail = NULL;
	}
	
	void insertToHead(char data){
		Node *node = new Node;
		node->id = data;
		
		Node *tmp = head;
		head = node;
		node->next = tmp;
	}
	
	void insertToTail(char data){
		Node *node = new Node;
		node->id = data;
		
		if(head == NULL){
			head = tail = NULL;
		} else{
			tail->next = node;
			tail = node;
		}
	}
	
	void insertNodeAfter(char data, char after){
		
		if(head == NULL){
			head = tail = NULL;
		} else if(tail->id == data){
			insertToTail(data);
		} else{
			Node *node = new Node;
			node->id = data;
			
			Node *tmp = head;
			while(tmp->id != after && tmp != NULL){
				tmp = tmp->next;
			}
			
			if(tmp == NULL){
				cout << "Node is not found" << endl;
			} else{
				node->next = tmp->next;
				tmp->next = node;
			}
		}
	}
	
	void insertNodeBefore(char data, char before){
		
		Node *node = new Node;
		node->id = data;
		
		
		if(head == NULL || head->id == before){
			insertToHead(data);
		} else{
			Node *sebelumnya = NULL;
			Node *sekarang = head;
			
			while(sekarang != NULL && sekarang->id != before){
				sebelumnya = sekarang;
				sekarang = sekarang->next;
			}
			
			if(sekarang == NULL){
				cout << "Node is not found" << endl;
			} else{
				sebelumnya->next = node;
				node->next = sekarang;
			}
		}
	}
	
	
	void removeNodeAfter(char data, char after){
		if(head != NULL){
			Node *tmp = head;
			while (tmp != NULL && tmp->id != after){
				tmp = tmp->next;
			}
			if (tmp == NULL || tmp->next ==NULL){
				cout << "Error : Data Tidak Ditemukan.";
			} else{
				Node *hapus = tmp->next;
				tmp->next = tmp->next->next;
				delete hapus;
			}
		} else{
			cout << "Error : Linkedlist Kosong.";
		}
	}
	
	void removeNodeBefore(char data, char before){
		
		Node *node = new Node;
		node->id = data;
	
		if(head == NULL || head->id == before){
			cout << "Error: no code was found before this" << endl;
		} else{
			Node *sebelumnya = NULL;
			Node *sekarang = head;
			
			while(sekarang != NULL && sekarang->next != NULL && sekarang->next->id != before){
				sebelumnya = sekarang;
				sekarang = sekarang->next;
			}
			
			if(sekarang == NULL || sekarang->next == NULL){
				cout << "Error: no code was found before this" << endl;
			} else{
				if(sebelumnya == NULL){
					head = sekarang->next;
				} else{
					sebelumnya->next = sekarang->next;
				}
				delete sekarang;
			}
		}
	}
	
	
	void removeHead(){
		if(head == tail){
			head = tail = NULL;
			delete head;
		} else if(head != NULL){
			Node *hapus = head;
			head = head->next;
			delete hapus;
		} else{
			cout << "Error: LinkedList is empty!" << endl;
		}
	}
	
	void removeTail(){
		if(head != NULL){
			if(head == tail){
				delete tail;
				head = tail = NULL;
			} else{
				Node *tmp = head;
				while(tmp->next != tail){
					tmp = tmp->next;
				}
				delete tail;
				tail = tmp;
				tail->next = NULL;
			}
		} else{
			cout << "Error: LinkedList empty!" << endl;
		}
	}
	
	void printALL(){
		if(head != NULL){
			Node *tmp = head;
			
			do{
				cout << tmp->id << "->";
				tmp = tmp->next;
			} while(tmp != NULL);
		}
	}
};


int main(int argc, char** argv){
	LinkedList *link1 = new LinkedList;
	
	Node *node1 = new Node;
	node1->id = 'A';
	
	Node *node2 = new Node;
	node2->id = 'B';
	node1->next = node2;
	
	Node *node3 = new Node;
	node3->id = 'C';
	node2->next = node3;
	
	Node *node4 = new Node;
	node4->id = 'D';
	node3->next = node4;
	
	link1->head = node1;
	link1->tail = node4;
	
	cout << "Tampilan data awal: ";
	link1->printALL();
	cout << endl << endl;
	
	link1->insertToHead('P');
	/*Node *tmp1 = link1->head;
	link1->head = node1;
	node1->next = tmp1;
	*/
	cout << "Menambahkan data di Head: ";
	link1->printALL();
	cout << endl << endl;
	
	link1->insertToTail('M');
	cout << "Menambahkan data di Tail: ";
	link1->printALL();
	cout << endl << endl; 
	
	
	link1->insertNodeAfter('T', 'B');
	cout << "Menggunakan insertNodeAfter: ";
	link1->printALL();
	cout << endl << endl;
	
	link1->insertNodeBefore('U', 'B');
	cout << "Menggunakan insertNodeBefore: ";
	link1->printALL();
	cout << endl << endl;
	
	link1->removeNodeAfter('T', 'B');
	cout << "Menggunakan removeNodeAfter: ";
	link1->printALL();
	cout << endl << endl;
	
	link1->removeNodeBefore('U', 'B');
	cout << "Menggunakan removeNodeBefore: ";
	link1->printALL();
	cout << endl << endl;
	
	link1->removeHead();
	cout << "Menggunakan removeHead: ";
	link1->printALL();
	cout << endl << endl;
	
	link1->removeTail();
	cout << "Menggunakan removedTail: ";
	link1->printALL();
	cout << endl << endl;
	
	
	return 0;
}