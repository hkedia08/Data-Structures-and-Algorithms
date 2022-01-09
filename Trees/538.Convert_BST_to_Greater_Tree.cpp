//https://leetcode.com/problems/convert-bst-to-greater-tree/
//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

class Solution
{
    // inorder traversal to get all the elements of the tree
    void intraversal(vector<int> &inorder, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        intraversal(inorder, root->left);
        inorder.push_back(root->val);
        intraversal(inorder, root->right);
    }
    // traveesal is same just change root values
    void findtraversal(vector<int> &inorder, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        findtraversal(inorder, root->left);
        int sum = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] >= root->val)
            {
                sum += inorder[i];
            }
        }
        root->val = sum;
        findtraversal(inorder, root->right);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        vector<int> inorder;
        intraversal(inorder, root);
        findtraversal(inorder, root);
        return root;
    }
};