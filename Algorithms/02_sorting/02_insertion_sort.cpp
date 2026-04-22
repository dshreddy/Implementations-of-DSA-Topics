#include<iostream>
using namespace std;

// O(n^2)
void insertion_sort(vector<int> &v) {
    int n = v.size(), j;
    for(int i = 0; i < n; i++) {
        j = i;
        while(j > 0 && v[j] < v[j-1]) {
            swap(v[j], v[j-1]);
            j--;
        }
    }
}

int main() {
    vector<int> v = {0, 3, -1, 2};
    insertion_sort(v);
    for(int i: v) cout<<i<<"\t";
    cout<<"\n";
}