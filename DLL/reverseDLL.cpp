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
Node* reverseDLL(Node* head){
    Node* current = head;
    Node* newhead = nullptr;
    while(current!=nullptr){
        swap(current->prev, current->next);
        newhead = current;
        current = current->prev;
    }
    return newhead;
}
void printListForward(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
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

    
    head = reverseDLL(head);
    printListForward(head);
    

    return 0;    
}
    
