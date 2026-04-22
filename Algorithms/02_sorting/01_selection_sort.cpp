#include<iostream>
using namespace std;


// O(n^2)
void selection_sort(vector<int> &v) {
    int n = v.size(), min, min_idx;
    for(int i = 0; i < n; i++) {
        min = v[i];
        min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(v[j] < min) {
                min = v[j];
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);
    }
}

int main() {
    vector<int> v = {0, 3, -1, 2};
    selection_sort(v);
    for(int i: v) cout<<i<<"\t";
    cout<<"\n";
}