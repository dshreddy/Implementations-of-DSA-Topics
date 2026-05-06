#include<iostream>
using namespace std;

class HashSet{
private:

    static const int num_buckets = 913;

    vector<int> buckets[num_buckets];

    int hash(int key) {
        if(key < 0) key = -key;
        return key % num_buckets;
    }

public:

    // O(1)
    void insert(int n) {
        int index = hash(n);
        for(int x: buckets[index]) if(x == n) return;
        buckets[index].push_back(n);
    }

    // O(1)
    bool find(int n) {
        int index = hash(n);
        for(int x: buckets[index]) if(x == n) return true;
        return false;
    }

    // O(1)
    void remove(int n) {
        int index = hash(n);
        auto& bucket = buckets[index];

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] == n) {
                swap(bucket[i], bucket.back());
                bucket.pop_back();
                return;
            }
        }
    }
};

int main() {
    HashSet s;
    s.insert(10);
    s.insert(923);   // collision likely

    cout << s.find(10) << endl;  // 1
    cout << s.find(5) << endl;   // 0

    s.remove(10);
    cout << s.find(10) << endl;  // 0
}

