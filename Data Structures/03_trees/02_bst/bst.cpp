
#include <iostream>
using namespace std;

struct TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode *root = nullptr;

    // O(log n)
    TreeNode * _insert(TreeNode *curr, int n) {
        if(!curr) return new TreeNode(n);

        if(n > curr->val) curr->right = _insert(curr->right, n);
        else if(n < curr->val) curr->left = _insert(curr->left, n);
        
        return curr;
    }

    // O(log n)
    TreeNode * _search(TreeNode *curr, int n) {
        if(!curr) return nullptr;

        if(n > curr->val) return _search(curr->right, n);
        else if(n < curr->val) return _search(curr->left, n);
        else return curr;
    }

    TreeNode * _min(TreeNode *curr) {
        while(curr && curr->left) curr = curr->left;
        return curr;
    }

    /**
     * O(log n)
     * Find minimum in right sub tree
     * This will have the following properties
     *  - Every value on left sub tree is less than this (since this is in right sub tree)
     *  - Every other value on right sub tree is more than this (since this is minimum)
     * So this value is eligible to become the root
     */
    TreeNode * _remove(TreeNode *curr, int n) {
        if(!curr) return curr;

        if(n > curr->val) curr->right = _remove(curr->right, n);
        else if(n < curr->val) curr->left = _remove(curr->left, n);
        else {
            // Case 1: no left child
            if(!curr->left) {
                TreeNode* temp = curr->right;
                delete curr;
                return temp;
            }

            // Case 2: no right child
            if(!curr->right) {
                TreeNode* temp = curr->left;
                delete curr;
                return temp;
            }

            // Case 3: two children
            TreeNode *minNode = _min(curr->right);
            curr->val = minNode->val;
            curr->right = _remove(curr->right, minNode->val);
        }
        return curr;
    }

    // O(n)
    // Also known as level order traversal
    void _bfs(TreeNode *curr) {
        if(!curr) return;

        queue<TreeNode*> q;
        q.push(curr);

        while(!q.empty()) {

            int l = q.size();

            for(int i = 0; i < l; i++) {

                TreeNode *curr = q.front();
                q.pop();

                cout<<curr->val<<"\t";
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            cout<<"\n";
        }
    }
public:

    void insert(int n) {
        root = _insert(root, n);
    }

    bool search(int n) {
        return _search(root, n);
    }

    void remove(int n) {
        root = _remove(root, n);
    }

    void print_level_order() {
        _bfs(root);
        cout<<"\n\n";
    }
};

int main()
{
    BST bst;
    bst.insert(0);
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(-1);
    bst.insert(-2);
    bst.insert(-3);
    bst.print_level_order();
    /*
           0
        -1   1   
       -2      2
      -3        3
    */
    bst.remove(-3);
    bst.print_level_order();
    bst.remove(-1);
    bst.print_level_order();
    bst.remove(0);
    bst.print_level_order();
}
