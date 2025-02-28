//Reverse Linked List
/*Given the head of a singly linked list, 
reverse the list, and return the reversed list.*/

 class Solution 
{
    public:
     // Definition for singly-linked list.
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* reverseList(ListNode* head)
    {
        /*We want head to be the new 'end' node of the list.
         so to process the first node: we start at head; curr = head and prev is null since we havent started yet
         - iterate with a while loop (while)
            store curr->next in a temp, then reverse curr->next = prev
            to process the next node, set prev = curr and curr = temp
        - return prev, it will be the new head (previous tail) of the list
        
          */
        ListNode* prev = nullptr;
        ListNode* curr = head;

       while (curr)
       {
            ListNode* temp = curr->next;    //stores the next node in a temp        
            curr->next = prev;              //reverses pointers
            prev = curr;
            curr = temp;
       }
       
       return prev;
    
    }

};