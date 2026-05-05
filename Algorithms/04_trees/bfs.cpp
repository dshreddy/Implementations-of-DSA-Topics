#include <iostream>
using namespace std;

struct TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x) {}
};

void bfs(TreeNode *root)
{
    if (!root) return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int l = q.size();
        for (int i = 0; i < l; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            cout << node->val << "\t";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main()
{
    /*
                         0
                        /  \
                        1   2
                       / \ / \
                       3 4 5 6
    */
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    bfs(root);
}
