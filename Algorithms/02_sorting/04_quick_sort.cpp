#include<iostream>
using namespace std;

// Tita(n*logn) [avg case time complexity]
void quick_sort(vector<int> &v, int start, int end) {
    if(start < end) {
        int pivot = end, ptr = start;
        for(int i = start; i < pivot; i++) if(v[i] < v[pivot]) swap(v[ptr++], v[i]);
        swap(v[ptr], v[pivot]);
        quick_sort(v, start, ptr-1);
        quick_sort(v, ptr+1, end);
    }
}

int main() {
    vector<int> v = {0, 3, -1, 2};
    quick_sort(v, 0, v.size()-1);
    for(int i: v) cout<<i<<"\t";
    cout<<"\n";
}