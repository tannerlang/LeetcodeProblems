//Balanced Binary Tree
/*Given a binary Tree, determine if it is height-balanced*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



  #include<math.h>
  using namespace std;

  class Solution 
  {
    public:
    bool isBalanced(TreeNode* root) 
    {
      return checkHeight(root) != -1;
    }


    int checkHeight(TreeNode* root)
    {
      if (!root)
      {
        return 0;
      }

      int leftHeight = checkHeight(root->left);
      if (leftHeight == -1)
      {
        return -1;
      }

      int rightHeight = checkHeight(root->right);
      if  (rightHeight == -1)
      {
        return -1;
      }

      if (abs(leftHeight - rightHeight) > 1)
      {
        return -1;
      }

      return std::max(leftHeight,rightHeight) + 1;
    }
};

  