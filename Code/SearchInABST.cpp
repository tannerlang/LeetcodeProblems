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


using namespace std;
class Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) 
        {
         if (!root)
         {
            return nullptr;
         }

         if (val == root->val)
         {
            return root;
         }

         if (val < root->val)
         {
            return searchBST(root->left, val);
         }
         if (val > root->val)
         {
            return searchBST(root->right, val);
         }

         return nullptr;     
        }
    };