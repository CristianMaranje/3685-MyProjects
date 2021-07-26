#include "AVLTree.h"

//returns the height of the highest brother node
int AVL::calheight(Node *p)
{
    Node *left = p->getNodeLeft();
    Node *right = p->getNodeRight();

    if (left && right)
    {
        if (left->getHeight() < right->getHeight())
        {
            return right->getHeight() + 1;
        }
        else
        {
            return left->getHeight() + 1;
        }
    }
    else if (left && right == NULL)
    {
        return left->getHeight() + 1;
    }
    else if (left == NULL && right)
    {
        return right->getHeight() + 1;
    }
    return 0;
}

//returns balance factor(int) of the node
int AVL::bf(Node *n)
{
    Node *left = n->getNodeLeft();
    Node *right = n->getNodeRight();

    if (left && right)
    {
        return left->getHeight() - right->getHeight();
    }
    else if (left && right == NULL)
    {
        return left->getHeight();
    }
    else if (left == NULL && right)
    {
        return -right->getHeight();
    }
}

//left simple rotation rotation
Node *AVL::llrotation(Node *n)
{
    Node *p;
    Node *tp;

    p = n;
    tp = p->getNodeLeft();

    p->setNodeLeft(tp->getNodeRight());
    tp->setNodeRight(p);

    return tp;
}

//right simple rotation
Node *AVL::rrrotation(Node *n)
{
    Node *p;
    Node *tp;

    p = n;
    tp = p->getNodeRight();

    p->setNodeRight(tp->getNodeLeft());
    tp->setNodeLeft(p);

    return tp;
}

//right left double rotation
Node *AVL::rlrotation(Node *n)
{
    Node *p;
    Node *tp;
    Node *tp2;
    p = n;
    tp = p->getNodeRight();
    tp2 = tp->getNodeLeft();

    p->setNodeRight(tp2->getNodeLeft());
    tp->setNodeLeft(tp2->getNodeRight());
    tp2->setNodeLeft(p);
    tp2->setNodeRight(tp);

    return tp2;
}

//left right doulbe rotation
Node *AVL::lrrotation(Node *n)
{
    Node *p;
    Node *tp;
    Node *tp2;
    p = n;
    tp = p->getNodeLeft();
    tp2 = tp->getNodeRight();

    p->setNodeLeft(tp2->getNodeRight());
    tp->setNodeRight(tp2->getNodeLeft());
    tp2->setNodeRight(p);
    tp2->setNodeLeft(tp);

    return tp2;
}

Node *AVL::insert(Node *r, int data)
{

    if (r == NULL)
    {
        Node *n;
        n = new Node;
        n->setData(data);
        r = n;
        r->setNodeLeft(nullptr);
        r->setNodeRight(nullptr);
        r->setHeight(1);
        return r;
    }
    else
    {
        if (data < r->getData())
            r->setNodeLeft(insert(r->getNodeLeft(), data));
        else
            r->setNodeRight(insert(r->getNodeRight(), data));
    }

    r->setHeight(calheight(r));

    if (bf(r) == 2 && bf(r->getNodeLeft()) == 1)
    {
        r = llrotation(r);
    }
    else if (bf(r) == -2 && bf(r->getNodeRight()) == -1)
    {
        r = rrrotation(r);
    }
    else if (bf(r) == -2 && bf(r->getNodeRight()) == 1)
    {
        r = rlrotation(r);
    }
    else if (bf(r) == 2 && bf(r->getNodeLeft()) == -1)
    {
        r = lrrotation(r);
    }
    cout<<"here";
    return r;
}

void AVL::levelorder_newline()
{
    if (this->root == NULL)
    {
        cout << "\n"
             << "Empty tree"
             << "\n";
        return;
    }
    levelorder_newline(this->root);
}

void AVL::levelorder_newline(Node *v)
{
    queue<Node *> q;
    Node *cur;
    q.push(v);
    q.push(NULL);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == NULL && q.size() != 0)
        {
            cout << "\n";

            q.push(NULL);
            continue;
        }
        if (cur != NULL)
        {
            cout << " " << cur->getData();

            if (cur->getNodeLeft() != NULL)
            {
                q.push(cur->getNodeLeft());
            }
            if (cur->getNodeRight() != NULL)
            {
                q.push(cur->getNodeRight());
            }
        }
    }
}

Node *AVL::deleteNode(Node *p, int data)
{

    if (p->getNodeLeft() == NULL && p->getNodeRight() == NULL)
    {
        if (p == this->root)
            this->root = NULL;
        delete p;
        return NULL;
    }

    Node *t;
    Node *q;
    if (p->getData() < data)
    {
        p->setNodeRight(deleteNode(p->getNodeRight(), data));
    }
    else if (p->getData() > data)
    {
        p->setNodeLeft(deleteNode(p->getNodeLeft(), data));
    }
    else
    {
        if (p->getNodeLeft() != NULL)
        {
            q = inpre(p->getNodeLeft());
            p->setData(q->getData());
            p->setNodeLeft(deleteNode(p->getNodeLeft(), q->getData()));
        }
        else
        {
            q = insuc(p->getNodeRight());
            p->setData(q->getData());
            p->setNodeRight(deleteNode(p->getNodeRight(), q->getData()));
        }
    }

    if (bf(p) == 2 && bf(p->getNodeLeft()) == 1)
    {
        p = llrotation(p);
    }
    else if (bf(p) == 2 && bf(p->getNodeLeft()) == -1)
    {
        p = lrrotation(p);
    }
    else if (bf(p) == 2 && bf(p->getNodeLeft()) == 0)
    {
        p = llrotation(p);
    }
    else if (bf(p) == -2 && bf(p->getNodeRight()) == -1)
    {
        p = rrrotation(p);
    }
    else if (bf(p) == -2 && bf(p->getNodeRight()) == 1)
    {
        p = rlrotation(p);
    }
    else if (bf(p) == -2 && bf(p->getNodeRight()) == 0)
    {
        p = llrotation(p);
    }

    return p;
}

Node *AVL::inpre(Node *p)
{
    while (p->getNodeRight() != NULL)
        p = p->getNodeRight();
    return p;
}

Node *AVL::insuc(Node *p)
{
    while (p->getNodeLeft() != NULL)
        p = p->getNodeLeft();
    return p;
}
