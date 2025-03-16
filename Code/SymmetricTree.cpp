//Symmetric Tree
/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center)*/

//
#include<vector>
#include<queue>
using namespace std;
 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  //BFS
class Solution 
{
    public:
        bool isSymmetric(TreeNode* root) 
        {
            
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty())
            {
                    int levelsize = q.size();
                    vector<int> nodeVals;

                    //process each node in the level, add them to vector to check if values are symmetric.
                    for (int i = 0; i < levelsize; i++)
                    {
                        TreeNode* curr = q.front();
                        q.pop();

                        //if node exists, add its val to the vecto
                        if (curr)
                        {
                            nodeVals.push_back(curr->val);
                            q.push(curr->left);
                            q.push(curr->right);
                        }
                        //if it doesnt exist, use an arbitrary val to use not lose the positions of nodes in the level for later
                        else
                        {
                            nodeVals.push_back(-10001);
                        }
                    }
                    int left = 0;
                    int right = nodeVals.size()-1;
                    while (left < right)
                    {
                        if (nodeVals[left] != nodeVals[right])
                        {
                            return false;
                        }
                        left++;
                        right--;
                    }
            }
            
            return true;
        }
};

//Recursion
class Solution 
{
    public:
    bool isSymmetric(TreeNode* root)
    {
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        if (!root1 || !root2)
        {
            return false;
        }

        return root1->val == root2->val && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
     
    }
};