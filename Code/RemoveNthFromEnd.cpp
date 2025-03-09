//Remove Nth Node From End of List
/*Given the head of a linked list, remove the nth node from the end of the list and return its head.*/



//use two pointer approach

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution 
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {   
        ListNode* dummy = new ListNode(0,head);     //make a dummy pointing to head
        ListNode* fast = head;
        ListNode* beforeN = dummy;
        

        if (head->next == nullptr && n == 1) //if head only has one node and n = 1 return immedietely.
        {
            return nullptr;
        }
        
        //move fast n steps ahead
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        //then move fast to the end of the list and incremen beforeN with it, resulting in beforeN being the node before n.
        while (fast != nullptr)     //executes until fast is at the end of the list.
        {
            fast = fast->next;  
            beforeN = beforeN->next;
        }
        

     
        ListNode* temp = beforeN->next;
        beforeN->next = beforeN->next->next;    //removes nth node
        delete temp;
       

        return dummy->next;
        
    }
};