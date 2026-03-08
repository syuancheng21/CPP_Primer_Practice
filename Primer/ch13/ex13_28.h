#ifndef SYUAN_EX13_28_H
#define SYUAN_EX13_28_H

//Tree

#include <string>

class TreeNode {
public:
    TreeNode(const std::string& s = std::string()): value(s), count(new int(1)), left(nullptr), right(nullptr){}
    TreeNode(const TreeNode& node): value(node.value), count(node.count), left(node.left), right(node.right){ ++*count; }
    ~TreeNode() {
        if (--*count == 0)
        {
            delete left;
            delete right;
            delete count;
        }
    }

    TreeNode& operator=(const TreeNode& r_node);

private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree(): root(new TreeNode()) {}
    BinStrTree(const BinStrTree& rhs): root(new TreeNode(*rhs.root)) {}
    BinStrTree& operator=(const BinStrTree &bst);
    ~BinStrTree() { delete root; }

private:
    TreeNode *root;
};

#endif // SYUAN_EX13_28_H