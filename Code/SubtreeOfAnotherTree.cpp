//Subtree of Another Tree

/*Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.*/

using namespace std;
#include<queue>

  //Definition for a binary tree node.
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 class Solution 
{
public:

    //BFS approach
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty())
        {
            TreeNode* curr = q.front();     //current node being processed
            q.pop();

            //if current node matches subroots value and the trees are identical.
            if (curr->val == subRoot->val && areTreesIdentical(curr, subRoot))
            {
                return true;
            }


            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            } 
        }
        return false;   //no match found while proccessing tree with queue.
        
    }

    //checks if the trees are matching
    bool areTreesIdentical(TreeNode* root, TreeNode* subRoot)
    {
        //if both trees are empty return true
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        
        //if one is, return false
        if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }
        

        //all three conditions must be true for the trees to be matching.
        return (root->val == subRoot->val) && areTreesIdentical(root->left, subRoot->left) && areTreesIdentical(root->right,subRoot->right);
        
    }
};