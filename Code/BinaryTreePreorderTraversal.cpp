//Binary Tree preorder Traversal

/*Given the root of a binary tree, return the preorder traversal of its nodes' values.*/


#include<vector>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 class Solution {
    public:
    
        void preorderHelper(TreeNode* root, vector<int>& result)
        {
            if (!root)
            {
                return;
            }

            result.push_back(root->val);
            preorderHelper(root->left, result);
            preorderHelper(root->right, result);
            
        }
    
        vector<int> preorderTraversal(TreeNode* root) 
        {
            vector<int> result;
            preorderHelper(root,result);

            return result;
            
        }
    };