//Reorder List

/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.*/


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
        void reorderList(ListNode* head) 
        {
            //find the middle
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            //reverse 2nd half
            ListNode* curr = slow->next;
            ListNode* prev = nullptr;
            slow->next = nullptr;

            while (curr)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            //merge lists
            ListNode* first = head;
            ListNode* second = prev;
            while(second)
            {
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;

                first->next = second;
                second->next = temp1;

                first = temp1;
                second = temp2;
            }
        }
    };