//https://leetcode.com/problems/maximum-depth-of-binary-tree/

// recursive code
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// can be solved using level order traversal also
