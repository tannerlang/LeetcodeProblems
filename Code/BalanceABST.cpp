//Balance A Binary Search Tree
/*Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.*/


#include<vector>
using namespace std;
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
        TreeNode* balanceBST(TreeNode* root) 
        {
            vector<int> nodes;
            inorderTraversal(root, nodes);
            return arrayToBST(nodes, 0, nodes.size() - 1);
        }

        void inorderTraversal(TreeNode* root, vector<int>& nodes)
        {
            if (!root)
            {
                return;
            }

            inorderTraversal(root->left, nodes);
            nodes.push_back(root->val);
            inorderTraversal(root->right, nodes);
        }

        TreeNode* arrayToBST(vector<int>& nodes, int left, int right)
        {
            if (left > right)
            {
                return nullptr; //base case
            }

            int mid = (left + right) / 2;

            TreeNode* root = new TreeNode(nodes[mid]);

            root->left = arrayToBST(nodes, left, mid - 1);
            root->right = arrayToBST(nodes, mid + 1, right);

            return root;
        }
    };