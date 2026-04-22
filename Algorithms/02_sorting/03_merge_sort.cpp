#include<iostream>
using namespace std;

// O(n)
void merge(vector<int> &v, int start, int mid, int end) {

    vector<int> temp(end-start+1);

    int i = start, j = mid+1, k = 0;

    while(i <= mid && j <= end) {
        if(v[i] < v[j]) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }
    while(i <= mid) temp[k++] = v[i++];
    while(j <= end) temp[k++] = v[j++];

    for(int x = start; x <= end; x++) v[x] = temp[x-start];
}

// O(n*logn)
void merge_sort(vector<int> &v, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        merge_sort(v, start, mid);
        merge_sort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}

int main() {
    vector<int> v = {0, 3, -1, 2};
    merge_sort(v, 0, v.size()-1);
    for(int i: v) cout<<i<<"\t";
    cout<<"\n";
}