#ifndef __BINTREE__
#define __BINTREE__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode *root;
} BinaryTree;

#endif