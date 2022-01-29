//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// RIGHT TO LEFT BFS

// This is O(N) space
class Solution
{
public:
    Node *connect(Node *root)
    {
        // right to left bfs
        if (root == NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *rightptr = NULL;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                Node *curr = q.front();
                q.pop();
                curr->next = rightptr;
                rightptr = curr;
                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
};

// using dfs

// dry run on paper to understand it more clearly
//  space is equal to height of binary tree O(Logn)
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL || root->left == NULL || root->right == NULL)
        {
            return root;
        }
        //1
        root->left->next = root->right;

        if (root->next != NULL)
        {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);
        return root;
    }
};

// go to left most node
// traverse it level by level
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        Node *curr = root;
        while (curr->left != NULL)
        {
            Node *temp = curr;
            // level order
            while (curr != NULL)
            {
                curr->left->next = curr->right;
                curr->right->next = curr->next == NULL ? NULL : curr->next->left;
                curr = curr->next;
            }
            curr = temp->left;
        }
        return root;
    }
};