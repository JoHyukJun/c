#include "bintree.h"


int print_bintree()
{
    printf("BINTREE\n");

    return (0);
}

BinaryTree *create_binary_tree()
{
    BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));

    if (tree == NULL)
    {
        perror("malloc");

        return NULL;
    }
    tree->root = NULL;
    
    return tree;
}

TreeNode *create_tree_node(data)
int data;
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));

    if (node == NULL)
    {
        perror("malloc");

        return NULL;
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_tree_node(tree, data)
BinaryTree *tree;
int data;
{
    TreeNode *node = create_tree_node(data);

    if (node == NULL) return;

    if (tree->root == NULL)
    {
        tree->root = node;

        return;
    }

    TreeNode *current = tree->root;
    TreeNode *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        } else
        {
            current = current->right;
        }
    }

    if (data < parent->data)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }
}

TreeNode* search_tree_node(tree, data)
BinaryTree *tree;
int data;
{
    TreeNode *current = tree->root;

    while (current != NULL)
    {
        if (data == current->data)
        {
            return current;
        }
        else if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return NULL;
}

void delete_tree(node)
TreeNode *node;
{
    if (node == NULL) return;

    delete_tree(node->left);
    delete_tree(node->right);
    free(node);
}
