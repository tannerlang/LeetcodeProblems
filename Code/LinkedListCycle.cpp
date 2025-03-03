/*Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 

Internally, 'pos' is used to denote the index of the node that tail's next pointer is connected to. Note that 'pos' is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false. */


//Thought Process
//two pointer fast and slow approach
    //iterate slow pointer one step at a time.
    //iterate fast pointer one step at a time.
    //if fast == slow at any time, the link list has a cycle, return true
    //if fast == nullptr, the link list does not have a cycle, return false

using namespace std;


//Definition for singly-linked list.
 struct ListNode 
 {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution 
{
    public:
        bool hasCycle(ListNode *head) 
        {
            ListNode* fast = head;     //will move two steps at a time.
            ListNode* slow = head;     //will move one step at a time.

            while (fast != nullptr && fast->next != nullptr)       
            {
                fast = fast->next->next;    //increements two nodes
                slow = slow->next;          //increments one node
                if (fast == slow)
                {
                    return true;            //there is a cycle
                }

            }
            
            return false;                   //loop broke, meaning fast -> next doesnt exist

        }
};