//Intersection of Two Linked Lists
/*Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#include<unordered_set>;
using namespace std;

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
        {
            ListNode* curr = headA;
            unordered_set<ListNode*> seen;

            while (curr)
            {
                seen.insert(curr);
                curr = curr->next;
            }
            
            curr = headB;
            while (curr)
            {
                if (seen.count(curr))
                {
                    return curr;
                }
              
                curr = curr->next;
            }
            
            return nullptr;
        }
    };