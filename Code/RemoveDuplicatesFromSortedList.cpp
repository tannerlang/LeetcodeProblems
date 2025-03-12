//Remove Duplicates from Sorted List

#include<unordered_set>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) 
        {
            unordered_set<int> listVals;
            ListNode* curr = head;
            ListNode* dummy = new ListNode();
            dummy->next = head;
            ListNode* left = dummy;
    
            while(curr)
            {
                if(listVals.count(curr->val))   //if the node value is already in the set
                {
                    ListNode* temp = curr;
                    left->next = left->next->next;
                    curr = left->next;
                    delete temp;
                }
                else //add curr-val to the set, incremement the pointers
                {
                    listVals.insert(curr->val);
                    curr = curr->next;
                    left = left->next;
    
                }
            }
            return dummy->next;
        }
    };