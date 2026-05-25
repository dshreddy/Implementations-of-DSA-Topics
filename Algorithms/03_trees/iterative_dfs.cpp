#include<iostream>
#include <unordered_set>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void iterative_preorder(TreeNode *root) {

    stack<TreeNode*> stack;
    TreeNode * curr = root;

    while(curr || !stack.empty()) {
        if(curr) {
            cout << curr->val << "\t";
            if(curr->right) stack.push(curr->right);
            curr = curr->left;
        } else {
            curr = stack.top();
            stack.pop();
        }
    }
}

void iterative_inorder(TreeNode *root) {

    stack<TreeNode*> stack;
    TreeNode * curr = root;

    while(curr || !stack.empty()) {
        if(curr) {
            stack.push(curr);
            curr = curr->left;
        } else {
            curr = stack.top();
            stack.pop();
            cout<<curr->val<<"\t";
            curr = curr->right;
        }
    }
}

void iterative_postorder(TreeNode *root) {

    stack<TreeNode*> stack;
    stack<bool> visited;

    stack.push(root);
    visited.push(false);

    while(!stack.empty()) {
        TreeNode *curr = stack.top();
        bool isVisited = visited.top();
        stack.pop();
        visited.pop();
        if(curr) {
            if(isVisited) {
                cout << curr->val << "\t";
            } else {
                stack.push(curr);
                visited.push(true);
                stack.push(curr->right);
                visited.push(false);
                stack.push(curr->left);
                visited.push(false);
            }
        }
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Iterative Preorder Traversal: ";
    iterative_preorder(root);
    cout<<"\n";

    cout << "Iterative Inorder Traversal: ";
    iterative_inorder(root);
    cout<<"\n";

    cout << "Iterative Postorder Traversal: ";
    iterative_postorder(root);
    cout<<"\n";

    return 0;
}