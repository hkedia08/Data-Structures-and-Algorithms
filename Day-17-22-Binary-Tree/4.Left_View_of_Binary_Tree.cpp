// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

void help(vector<int> &result, Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == result.size())
        result.push_back(root->data);
    if (root->left != NULL)
        help(result, root->left, level + 1);
    if (root->right != NULL)
        help(result, root->right, level + 1);
}
vector<int> leftView(Node *root)
{
    // Your code here
    int level = 0;
    vector<int> result;
    help(result, root, level);
    return result;
}