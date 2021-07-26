#include <iostream>
#include "TreeNode.h"
#pragma once

class BTree
{
    TreeNode *root;
    int t;

public:
    BTree(int temp)
    {
        root = NULL;
        t = temp;
    }
    void traverse();
    TreeNode *search(int k);
    void insert(int k);
};