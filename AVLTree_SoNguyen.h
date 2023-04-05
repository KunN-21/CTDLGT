#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define LH -1
#define EH 0 
#define RH 1

typedef int ItemType;
struct AVLNode
{
    int BalFactor;
    ItemType Info;
    AVLNode *Left;
    AVLNode *Right;
};
struct AVLTree
{
    AVLNode *Root;
};
AVLNode *createAVLNode(ItemType x);
void initAVLTree(AVLTree &avl);
void RotateLL(AVLNode *&T);
void RotateRL(AVLNode *&T);
void RotateLR(AVLNode *&T);
void RotateRR(AVLNode *&T);
int BalanceLeft(AVLNode *&T);
int BalanceRight(AVLNode *&T);
int InsertAVLNode(AVLNode *&T, AVLNode *p);
int SearchStandFor(AVLNode *&T, AVLNode *&q);
int DeleteAVLNode(AVLNode *&T, ItemType x);
AVLNode *FindAVLNode(AVLNode *root, ItemType x);
int DeleteAVLTree(AVLNode *&root);
void ShowAVLTree(AVLNode *&T, int count, int &Flag);
void WriteAVLTree(FILE *filename, AVLNode *T);
#endif