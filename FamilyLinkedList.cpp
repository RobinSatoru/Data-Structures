#include <iostream>                   
using namespace std;         

class Node {
    public:
    string name;
    int age;
    Node*next; //pointer for next node
    Node*prev; //pointer for previous node
    
    Node(string name,int age){
        this->name = name;
        this->age = age;
        next = NULL;
        prev = NULL;
    }
};

//to add a Node at the end of the list
void append(Node* &head, string name, int age) {
  
    Node*temp = head; // temporary variable so that head is not disturbed while traversal
    //creating a new node and storing name and age in it
    Node*newNode = new Node(name,age);
    //inserting node in empty list
    if(temp == NULL){
        head=newNode;
    }
    //inserting node in non-empty list
    else{
        while(temp->next != NULL){
          temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

//to insert the new node at the start of a non empty list
void insertAtHead(Node* &head,string name,int age){
    //Creating a Node pointer and storing address of new node in it 
    Node*newNode=new Node(name,age);
    //Inserting new node at head
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void display(Node*head){
    Node*temp=head;
    while(temp!=NULL){
      cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->next;
    }
    cout<<endl;
}

//to delete any Node excluding last
void deleteNode(Node* &head, int i) {
    if(i == 0) {
        Node*temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }
    else{
        Node*temp = head;
        for(int j=0;j<i;j++) {
          temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

//to delete last Node
void deleteLast(Node* &head) {
    Node*temp = head;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

int main() {
    //Initialising an empty linked list
    Node*head = NULL;
	int noOfFamilyMem;
    //Taking no of family members as input
	cout<<"Enter Number Of Family Members:";cin>>noOfFamilyMem;
    //Inserting family members details in doubly linked list
	for(int i=1;i<=noOfFamilyMem;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";cin.ignore();getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";cin>>age;
        //appending data name and age in doubly linked list
		append(head,name,age);
	}
    cout<<endl;//For space
    //Displaying Family details
    cout<<"Doubly Linked list with my family members as elements is shown below:"<<endl;
    cout<<endl;
    display(head);
}


/*BONUS QUESTION

Q.Try to find a way to link the family members' doubly-linked list based on their relationship.

Ans.One way to link the family members doubly-linked list is by sorting the doubly linked list according to age in decending order.By doing so we will get a doubly linked list in which older generation people will be close to head in double linked list and new generation people will be close to tail in doubly linked list.

*/
