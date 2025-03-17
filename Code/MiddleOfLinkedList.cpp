


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    public:
        ListNode* middleNode(ListNode* head) 
        {
            ListNode* dummy = new ListNode();
            dummy->next = head;
            ListNode* fast = head;
            ListNode* slow = dummy;
    
            int node_Count = 0;
            while(fast)
            {
                fast = fast->next;
                node_Count++;
            }
    
            node_Count = (node_Count / 2);
    
            for(int i = 0; i<node_Count; i++)
            {
                slow = slow->next;
            }
    
            return slow->next;
        }
    };