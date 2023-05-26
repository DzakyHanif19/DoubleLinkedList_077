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


}

