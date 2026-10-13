#include <iostream>
using namespace std;
class Node{
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
    
};
Node* insertAtBegin(Node* head, int val){
    
    Node* newNode = new Node(val);
    if(head==nullptr){
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}
Node* insertAtEnd(Node* head, int val){
    if(head==nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp= temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
void printListForward(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}
void printListBackward(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp= temp->prev;
        
    }
    cout << endl;
}
int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    head = insertAtBegin(head, 5);
    head = insertAtEnd(head, 40);

    printListForward(head);
    // printListBackward(third);

    return 0;    
}
    
