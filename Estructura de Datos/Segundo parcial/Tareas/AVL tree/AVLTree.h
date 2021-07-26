#include <iostream>
#include <queue>
#include <unordered_map>
#include "Node.h"
#pragma once
using namespace std;

class AVL
{
private:
    Node *root;

public:
    AVL()
    {
        this->root = NULL;
    }

    int calheight(Node *p);
    int bf(Node *n);
    Node *llrotation(Node *n);
    Node *rrrotation(Node *n);
    Node *rlrotation(Node *n);
    Node *lrrotation(Node *n);
    Node *insert(Node *r, int data);
    void levelorder_newline();
    void levelorder_newline(Node *v);
    Node *deleteNode(Node *p, int data);
    Node *inpre(Node *p);
    Node *insuc(Node *p);
    void setRoot(Node *_root){root=_root;}
    Node *getRoot(){return root;}
    ~AVL()
    {
    }
};