// example code that shows how to write binary tree using unique_ptrs instead of raw ptrs
// unique_ptr are nice because they avoid memory leaks, programmer doesn't have to keep track of allocated memory no longer
#include <memory>
#include <algorithm>
#include <iostream>

using namespace std;

// binary tree node
struct TreeNode {
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;
    int data;
    TreeNode(int d):data(d){}
};

void insert(unique_ptr<TreeNode> &tree, int value) {
    if (tree == nullptr) {
        tree = make_unique<TreeNode>(value);
    }
    if (value > tree->data) {
        insert(tree->right, value);
    } else if (value < tree->data) {
        insert(tree->left, value);
    }
}

void inorder(unique_ptr<TreeNode> &tree) {
    if (tree->left) {
        inorder(tree->left);
    }
    cout << tree->data << endl;
    if (tree->right) {
        inorder(tree->right);
    }
}

int main() {
    srand(time(0));
    int N = 50;
    unique_ptr<TreeNode> root;
    for (int i = 0; i < N; ++i) {
        int value = rand() % N;
        insert(root, value);
    }
    inorder(root);
    return 0;
}
