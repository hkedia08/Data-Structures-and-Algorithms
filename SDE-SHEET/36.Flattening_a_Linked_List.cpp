// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

Node *merge(Node *a, Node *b)
{
    Node *temp = new Node(-1);
    Node *res = temp;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {

            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a != NULL)
        temp->bottom = a;
    if (b != NULL)
        temp->bottom = b;
    return res->bottom;
}
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    root->next = flatten(root->next);
    return merge(root, root->next);
}
