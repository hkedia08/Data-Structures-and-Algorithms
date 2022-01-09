//https://leetcode.com/problems/convert-bst-to-greater-tree/
//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// there is property in bst  and inorder always give us sorted elements
// so we traverse in reverse direction so as to maximum element first
class Solution
{
    void inorder(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return;
        inorder(root->right, sum);
        (root->val) += sum;
        sum = root->val;
        inorder(root->left, sum);
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        int sum = 0;
        inorder(root, sum);
        return root;
    }
};

// this the solution which I had coded in first view

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