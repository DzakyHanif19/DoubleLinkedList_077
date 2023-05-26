#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class doublelinkedlist {
private:
	node* START = NULL;
public:
	void addnode();
	bool search(int rollNo, node** previous, node** current);
	bool deletenode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();

};

void doublelinkedlist::addnode(){
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student:";
	cin >> nim;
	cout << "\nEnter the name of the student:";
	cin >> nm;

	node* newNode = new node(); //step1
	newNode->noMhs = nim; //step 2
	newNode->name = nm; //step3

	/*insert a node in the begining of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) { //check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step3
		if (START != NULL)
			START->prev = newNode; //step4
		newNode->next = NULL;
		START = newNode; //step5
		return;
	}

	/*inserting a node between two nodes in the list*/
	node* current = START;
	node* previous = NULL;
	while (current->next != NULL && current->next->noMhs < nim)
	{
		previous = current;
		current = current->next;
	}
	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}
	newNode->next = current->next;
	newNode->prev = current;
	if (current->next != NULL)
		current->next->prev = newNode;
	current->next = newNode;
}

