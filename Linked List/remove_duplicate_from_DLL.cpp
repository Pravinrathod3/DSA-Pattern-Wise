#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};


class Solution {
  public:
  
   void deletenode(Node* temp){
       if(temp->prev != NULL){
          temp->prev->next = temp->next;
       }
       if(temp->next != NULL){
          temp->next->prev = temp->prev;
       }
       temp->prev = NULL;
       temp->next = NULL;
       delete(temp);
   }

    Node *removeDuplicates(struct Node *head) {
        if(head == NULL || head->next == NULL) return head;
        
        Node* temp = head->next;
        
        while(temp != NULL){
            Node* nextnode = temp->next;
            if(temp->data == temp->prev->data){
                deletenode(temp);
            }
            temp = nextnode;
            
        }
        
        return head;
    }
};

int main(){
    Solution obj;
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head = obj.removeDuplicates(head);
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
} 