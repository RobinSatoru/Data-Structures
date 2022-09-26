//Robin Singh 21105077
// Q1) While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element?

//Ans.1
//Let's create a basic circular linked list
#include <iostream>
using namespace std;

class Node{
    //Creating class objects
    public:
    int data;
    Node*next;
    //Calling Node constructor
    Node(int data){
        this->data = data;
        next=NULL;
    }
};
//to add a node at end on linked list
void append(Node* &head, int data) {
    Node*temp = head;
    Node*newNode = new Node(data);
    if(temp == NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    while(temp->next!=head){
        temp = temp->next;
    }   //This condition establishes that the traversing element(temp) has reached the first element
    temp->next = new_node;
    newNode->next = head;
}
//to print elements of linked list from head to the last node.
void print(Node* &head){
    Node*temp = head;
    do{
      cout<<temp->data<<"->";
      temp = temp->next;
    }while(temp!=head);
}

int main(){
    Node*head = NULL;
    append(head,1);
    append(head,2);
    append(head,3);
    print(head);
}
/*
With reference to above example of circular linked list.

Line 29 i.e. while(temp->next!=head){temp=temp->next;} establishes that the traversing element/variable has reached the first element.

We Know that in circular linked list last node of linked list points to head of that linked list, hence we can check if any node points to head of linked list then that node is the end of circular linked list.
*/


/*Q2)  What are the practical applications of a circular linked list? (Try to find applications in your respective fields).

Practical applications of circular linked list are :

1)Multiplayer Games: All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.

2)Computing Resources: Circular Linked Lists is used to manage the computing resources of the computer.

3)Fibonacci Heap: Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.

4)Computer Networking:Circular linked list is also used in computer networking for token scheduling.

5)Implementation of Data Structure: Data structures such as stacks and queues are implemented with the help of the circular linked lists.

*/
