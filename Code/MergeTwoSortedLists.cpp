//Merge Two Sorted Lists
/*You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/

//Will attempt to solve recursively


using namespace std;



// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* sortedList;       //inits sortedList


        if (list1 == nullptr)
        {
            return list2;           //return list2 because list1 doesnt exist and list2 is already sorted, therefore returning list2 would suffice
        }
        if (list2 == nullptr)
        {
            return list1;           //return list1 because list2 doesnt exist and list` is already sorted, therefore returning list` would suffice
        }
        if (list1->val <= list2->val)
        {
            sortedList = list1; //set sortedList to list1 since it has the smaller val
            sortedList->next = mergeTwoLists(list1->next, list2);  //sets sorteList->next to to the smaller of list1-next and list2
        }
        else
        {
            sortedList = list2; //sortedList to list2 since it is smaller
            sortedList->next = mergeTwoLists(list1, list2->next);  //sets sorteList->next to to the smaller of list1 and list2->next
        }

        return sortedList;
    }
};