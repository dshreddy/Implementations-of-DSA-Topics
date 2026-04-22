#include<iostream>
using namespace std;

// Tita(n*logn) [avg case time complexity]
void quick_sort(vector<int> &v, int start, int end) {
    if(start < end) {
        int pivot = v[end], j = start;
        for(int i = start; i < end; i++) if(v[i] < pivot) swap(v[j++], v[i]);
        swap(v[j], v[end]);
        quick_sort(v, start, j-1);
        quick_sort(v, j+1, end);
    }
}

int main() {
    vector<int> v = {0, 3, -1, 2};
    quick_sort(v, 0, v.size()-1);
    for(int i: v) cout<<i<<"\t";
    cout<<"\n";
}