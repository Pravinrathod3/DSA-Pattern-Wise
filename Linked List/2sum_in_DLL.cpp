#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        Node* first = head;
        Node* last = head;
        
        vector<pair<int, int>> res;
        
        while(last->next != NULL){
            last = last->next;
        }
        
        while(first->data < last->data){
            int start = first->data;
            int end = last->data;
            
            if((start + end) == target){
                res.push_back({start, end});
                
                first = first->next;
                last = last->prev;
            }
            else if((start + end) > target){
                last = last->prev;
            }
            else{
                first = first->next;
            }
        }
        
        return res;
        
        
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->prev = head->next->next->next;
    
    int target = 7;
    
    Solution obj;
    vector<pair<int, int>> res = obj.findPairsWithGivenSum(head, target);
    
    for(auto p : res){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    
    return 0;
}


