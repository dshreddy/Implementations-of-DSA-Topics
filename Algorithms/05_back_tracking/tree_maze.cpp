#include<iostream>
using namespace std;

struct TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x) {}
};

// Important: We only explore one path at a time, so we can backtrack if the path doesn't exist (that's why we pop). This is a key aspect of backtracking algorithms.
// Time Complexity: O(n) - We visit each node at most once.
bool leafPath(TreeNode *root, vector<int>& path) {
    // Null & 0 check
    if(!root || root->val == 0) return false;

    path.push_back(root->val);
    // Leaf Node Case
    if(!root->left && !root->right) return true;
    // Non Leaf Node Case
    if(leafPath(root->left, path) || leafPath(root->right, path)) return true;
    // Path Doesn't exist, backtrack
    path.pop_back();
    return false;
}

int main() {
    // Determine if there is a path from the root node to leaf node of a B Tree without 0s
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    /*
        Tree Structure:
                1
               / \
              2   3
             / \ / \
            0  0 5  6

        Expected Output: Path exists: 1 3 5
    */

    vector<int> path;
    if(leafPath(root, path)) {
        cout << "Path exists: ";
        for(int i : path) cout << i << " ";
        cout << endl;
    } else {
        cout << "No path exists." << endl;
    }

    return 0;
}
