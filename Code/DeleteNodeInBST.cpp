//Delete Node in a BST

/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.*/

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
        TreeNode* deleteNode(TreeNode* root, int key) 
        {
            if (root == nullptr)
            {
                return nullptr;
            }

            if (key < root->val)
            {
               root->left = deleteNode(root->left, key); 
            }
            
            else if (key > root->val)
            {
                /* Go Right*/
                root->right = deleteNode(root->right, key);
            }
            else
            {
                //node only has right child
                if (!root->left)
                {
                    return root->right;
                }

                //node only has left child
                if (!root->right)
                {
                    return root->left;
                }
                
                //node has two children
                TreeNode* minNode = findMin(root->right);  //find inorder successor
                root->val = minNode->val;   //set val to successors value
                root->right = deleteNode(root->right, minNode->val);


            }
            return root;
        }

        TreeNode* findMin(TreeNode* node)
        {
            while (node->left)
            {
                node = node->left;
            }
            return node;
        }
    };