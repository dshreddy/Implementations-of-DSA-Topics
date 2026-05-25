#include<iostream>
using namespace std;

class SegmentTreeNode {
public:
    int lower_bound, upper_bound, sum;
    SegmentTreeNode *left, *right;

    SegmentTreeNode(int l, int r, int s) : lower_bound(l), upper_bound(r), sum(s) {}
};

class SegmentTree {
private:

    SegmentTreeNode *root = nullptr;
    int n;

    SegmentTreeNode* _build(vector<int> &v, int lower, int upper) {
        if(lower > upper) return nullptr;
        if(lower == upper) return new SegmentTreeNode(lower, lower, v[lower]);

        int middle = (lower + upper) / 2;
        SegmentTreeNode *newN = new SegmentTreeNode(lower, upper, 0);
        newN->left = _build(v, lower, middle);
        newN->right = _build(v, middle+1, upper);
        newN->sum = newN->left->sum + newN->right->sum;

        return newN;
    }

    void _update(SegmentTreeNode *rt, int index, int value) {
        int lower = rt->lower_bound, upper = rt->upper_bound;
        int middle = (lower+upper)/2;
        
        if(lower == upper) {
            rt->sum = value;
            return;
        }

        if(index >= lower && index <= middle) _update(rt->left, index, value);
        else _update(rt->right, index, value);

        rt->sum = rt->left->sum + rt->right->sum;
    }

    int _query(SegmentTreeNode *rt, int l, int r) {
        int lower = rt->lower_bound, upper = rt->upper_bound;
        int middle = (lower+upper)/2;

        if(l == lower && r == upper) return rt->sum;
        else if(r <= middle) return _query(rt->left, l, r);
        else if(l > middle) return _query(rt->right, l, r);
        else return _query(rt->left, l, middle) + _query(rt->right, middle+1, r);
    }

public:

    SegmentTree(vector<int> &v) {
        n = v.size();
        root = _build(v, 0, n-1);
    }

    void update(int index, int value) {
        if(index < 0 || index >= n) return;
        _update(root, index, value);
    }

    int query(int l, int r) {
        if(l < 0 || r >= n || l > r) return 0;
        return _query(root, l, r);
    }
}

int main() {

}