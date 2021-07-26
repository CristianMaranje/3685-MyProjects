#include <iostream>
#pragma once

class Node
{
private:
    Node *left;
    int data;
    int height;
    Node *right;

public:
void setNodeLeft(Node *_left){left=_left; }
Node *getNodeLeft(){return left;}
void setData(int _data){data=_data;}
int getData(){return data;}
void setHeight(int _height){height=_height;}
int getHeight(){return height;}
void setNodeRight(Node *_right){right=_right;}
Node *getNodeRight(){return right;}
};