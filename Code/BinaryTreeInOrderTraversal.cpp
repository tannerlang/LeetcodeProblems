

//Given the root of a binary tree, return the inorder traversal of its nodes' values.
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
 

     #include<vector>
     using namespace std;
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) 
        {
            vector<int> result;
            if(root == nullptr)
            {
                return result;
            }
    
            vector<int> leftSubtree = inorderTraversal(root->left);
            vector<int> rightSubtree = inorderTraversal(root->right);
    
    
    
    
          
    
    
            result.insert(result.end(), leftSubtree.begin(), leftSubtree.end());
            result.push_back(root->val);
            result.insert(result.end(), rightSubtree.begin(), rightSubtree.end());
    
    
            return result;
    
        }
    };