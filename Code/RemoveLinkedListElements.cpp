//Remove Linked List Elements

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
        ListNode* removeElements(ListNode* head, int val) 
        {
          ListNode* dummy = new ListNode();
          dummy->next = head;
          ListNode* curr = head;
          ListNode* slow = dummy;
    
          while (curr)
          {
            if (curr->val == val)
            {
                ListNode* temp = curr;
                curr = curr->next;
                slow->next = slow->next->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
                slow = slow->next;
            }
          }
    
          return dummy->next;
        }
    };