#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            if (st.count(temp->val)) {
                if(prev == NULL){
                    ListNode* del = temp;
                    head = temp->next;
                    temp = head;
                }
                else{
                    ListNode* del = temp;
                    prev->next = temp->next;
                    temp = prev->next;

                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};

int main(){
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    vector<int> nums = {2, 3};
    ListNode* modifiedHead = sol.modifiedList(nums, head);
    while(modifiedHead != NULL){
        cout << modifiedHead->val << " ";
        modifiedHead = modifiedHead->next;
    }
    return 0;
}
