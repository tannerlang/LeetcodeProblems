//Search in a Binary Tree
/*You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null*/
 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//bfs

#include<queue>
using namespace std;
class Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) 
        {
            queue<TreeNode*> q;
            q.push(root);
            int check = val;

            if (!root)
            {
                return nullptr;
            }
            
            
            while (!q.empty())
            {
                TreeNode* curr = q.front();
                q.pop();

                
                if (curr->val == check)
                {
                    return curr;
                }
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            //if we never find it
            return nullptr;
     
        }
    };