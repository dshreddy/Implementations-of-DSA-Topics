#include<iostream>
using namespace std;

class SegTreeNode {
public:
    int val = 0, lower = 0, upper = 0;
    SegTreeNode *left = nullptr, *right = nullptr;
    SegTreeNode(int x, int l, int r): val(x), lower(l), upper(r) {}
};

class SegmentTree {
private:
    SegTreeNode *root = nullptr;
    int n;

    int operation(SegTreeNode *l, SegTreeNode *r) {
        int result = 0;
        if(l) result += l->val;
        if(r) result += r->val;
        return result;
    }

    SegTreeNode * build(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        else if(l == r) return new SegTreeNode(nums[l], l, r);
        else {
            int middle = (l+r)/2;

            SegTreeNode *newN = new SegTreeNode(0, l , r);
            newN->left = build(nums, l, middle);
            newN->right = build(nums, middle+1, r);
            newN->val = operation(newN->left, newN->right);
            return newN;
        }
    }

    void update(SegTreeNode * curr, int index, int val) {
        int l = curr->lower, r = curr->upper, middle = (l+r)/2;
        if(l == r) {
            curr->val = val;
            return;
        }
        if(index <= middle) update(curr->left, index, val);
        if(index > middle) update(curr->right, index, val);
        curr->val = operation(curr->left, curr->right);
    }

    int query(SegTreeNode *curr, int p, int q) {
        int l = curr->lower, r = curr->upper, middle = (l+r)/2;
        if(l == p && r == q) return curr->val;
        if(q <= middle) return query(curr->left, p, q);
        if(p > middle) return query(curr->right, p, q);
        return operation(query(curr->left, p, middle), query(curr->right, middle+1, q));
    }

    void print() {
        cout<<"==========================================\n";

        queue<SegTreeNode *> q;        
        if(root) q.push(root);

        while(!q.empty()) {

            int l = q.size();
            for(int i = 0; i < l; i++) {
                
                SegTreeNode * u = q.front();
                q.pop();

                cout<<"val: "<<u->val<<" lower: "<<u->lower<<" upper: "<<u->upper;
                if(i != l-1) cout<<"|--|";

                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            cout<<"\n\n";
        }
        cout<<"==========================================\n";
    }

public:

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        root = build(nums, 0, n-1);
    }
    
    // O(log(n))
    void update(int index, int val) {
        if(index < 0 || index >= n) return;
        update(root, index, val);
    }
    
    // O(log(n))
    int sumRange(int left, int right) {
        if(min(left, right) < 0 || max(left, right) >= n || left > right) return -1;
        return query(root, left, right);
    }
};

int main() {

}