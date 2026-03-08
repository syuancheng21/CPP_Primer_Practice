#include "ex13_28.h"

/*
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
*/

TreeNode &TreeNode::operator=(const TreeNode &r_node)
{
    ++*r_node.count;
    if (--*count == 0)
    {
        delete left;
        delete right;
        delete count;
    }

    value = r_node.value;
    count = r_node.count;
    left = r_node.left;
    right = r_node.right;

    return *this;
}

BinStrTree &BinStrTree::operator=(const BinStrTree &bst)
{
    TreeNode *new_root = new TreeNode(*bst.root);
    delete root;

    root = new_root;
    return *this;
}


int main() {
    TreeNode m("init");

    TreeNode l("left");

    TreeNode r("right");

    

    return 0;
}