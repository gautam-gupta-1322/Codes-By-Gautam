#include <iostream>
using namespace std;
struct node
{
    int data;
    int height;
    node *left;
    node *right;
} *root = 0;
class avl
{
    node *head;
    node *ptr;
    node *temp;

public:
    avl(void)
    {
        head = ptr = temp = 0;
    }
    node *make(int x)
    {
        node *nw = new node[1];
        nw->data = x;
        nw->left = 0;
        nw->right = 0;
        nw->height = 1;
        if (head == 0)
        {
            head = root = nw;
        }
        return nw;
    }
    int heights(struct node *yes)
    {
        int l, r;
        l = (yes && yes->left) ? yes->left->height : 0;
        r = (yes && yes->right) ? yes->right->height : 0;

        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
    node *llrotation(struct node *yes)
    {
        ptr = yes->left;
        yes->left = yes->left->right;
        ptr->right = yes;
        ptr->height = heights(ptr);
        yes->height = heights(yes);
        if (root == yes)
        {
            root = ptr;
        }
        return ptr;
    }
    node *rrrotation(struct node *yes)
    {
        ptr = yes->right;
        yes->right = yes->right->left;
        ptr->left = yes;
        ptr->height = heights(ptr);
        yes->height = heights(yes);
        if (root == yes)
        {
            root = ptr;
        }
        return ptr;
    }
    node *lrrotation(struct node *yes)
    {
        yes->left = rrrotation(yes->left);
        return llrotation(yes);
    }
    node *rlrotation(struct node *yes)
    {
        yes->right = llrotation(yes->right);
        return rrrotation(yes);
    }
    int bb(node *yes)
    {
        int l, r;
        l = (yes && yes->left) ? yes->left->height : 0;
        r = (yes && yes->right) ? yes->right->height : 0;
        return l - r;
    }
    node *create(int x, node *yes = root)
    {
        if (x == -1)
        {
            cout << "AVL tree created!!!" << endl;
            return 0;
        }
        if (yes == 0)
        {
            yes = make(x);
            return yes;
        }
        else if (x < yes->data)
        {
            yes->left = create(x, yes->left);
        }
        else if (x > yes->data)
        {
            yes->right = create(x, yes->right);
        }
        if (bb(yes) == 2)
        {
            if (bb(yes->left) == 1)
                return llrotation(yes);
            else if (bb(yes->left) == -1)
                return lrrotation(yes);
        }
        else if (bb(yes) == -2)
        {
            if (bb(yes->right) == -1)
                return rrrotation(yes);
            else if (bb(yes->right) == 1)
                return rlrotation(yes);
        }
        yes->height = heights(yes);
        return yes;
    }
    void inorder(node *yes)
    {
        if (yes)
        {
            inorder(yes->left);
            cout << "--> " << yes->data << " Of height ->" << heights(yes) << endl;
            inorder(yes->right);
        }
    }
    int search(int x, node *yes = root)
    {
        if (yes == 0)
        {
            cout << "element not found !!!";
            return 0;
        }
        if (yes->data == x)
        {
            cout << "Element found";
            return 1;
        }
        else if (x < yes->data)
        {
            return search(x, yes->left);
        }
        else //if (x > yes->data)
        {
            return search(x, yes->right);
        }
    }
    node *inpre(struct node *yes)
    {
        while (yes->right != 0)
        {
            yes = yes->right;
        }
        return yes;
    }
    node *insuc(struct node *yes)
    {
        while (yes->left != 0)
        {
            yes = yes->left;
        }
        return yes;
    }
    struct node *deleted(int x, node *yes)
    {
        if (yes == 0)
            return 0;
        if (yes->left == 0 && yes->right == 0)
        {
            if (yes == root)
            {
                root = head = 0;
            }
            free(yes);
            return 0;
        }
        if (x < yes->data)
        {
            yes->left = deleted(x, yes->left);
        }
        else if (x > yes->data)
        {
            yes->right = deleted(x, yes->right);
        }
        else
        {
            if (heights(yes->left) > heights(yes->right))
            {
                ptr = inpre(yes->left);
                yes->data = ptr->data;
                yes->left = deleted(ptr->data, yes->left);
            }
            else
            {
                ptr = insuc(yes->right);
                yes->data = ptr->data;
                yes->right = deleted(ptr->data, yes->right);
            }
        }
        if (bb(yes) == 2)
        {
            if (bb(yes->left) == 1)
                return llrotation(yes);
            else
                return lrrotation(yes);
        }
        else if (bb(yes) == -2)
        {
            if (bb(yes->right) == -1)
                return rrrotation(yes);
            else
                return rlrotation(yes);
        }
        yes->height = heights(yes);

        return yes;
    }
};
int main()
{
    avl tr;
    int x = 0;
    cout << "Creating BST !!! Enter elements you want ...(enter -1 to stop) " << endl;
    while (x != -1)
    {
        cin >> x;
        tr.create(x, root);
    }
    cout << "Displaying your BST --> " << endl;
    tr.inorder(root);
    x = 1;
    while (x != -1)
    {
        cout << "enter node you want to delete(enter -1 to stop) --> " << endl;
        cin >> x;
        if (tr.search(x))
        {
            tr.deleted(x, root);
        }
        else
        {
            cout << "Element not found !!!" << endl;
        }
        cout << "Your tree after deletion -> " << endl;
        tr.inorder(root);
    }
}