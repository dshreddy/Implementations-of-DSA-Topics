#include<iostream>
using namespace std;

class HashMap{
private:

    static const int num_buckets = 913;

    vector<pair<int, int>> buckets[num_buckets];

    int hash(int key) {
        if(key < 0) key = -key;
        return key % num_buckets;
    }

public:

    // O(1)
    void insert(pair<int, int> p) {
        int index = hash(p.first);
        for(auto& x: buckets[index]) if(x.first == p.first) {
            x.second = p.second;
            return;
        }
        buckets[index].push_back(p);
    }

    // O(1)
    pair<int, int> find(int key) {
        int index = hash(key);
        for(const auto& x: buckets[index]) if(x.first == key) return x;
        return {-1, -1};
    }

    // O(1)
    void remove(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i].first == key) {
                swap(bucket[i], bucket.back());
                bucket.pop_back();
                return;
            }
        }
    }
};

int main() {
    HashMap m;
    m.insert({10, 100});
    m.insert({923, 9230});   // collision likely

    auto result = m.find(10);
    cout << result.second << endl;  // 100

    result = m.find(923);
    cout << result.second << endl;  // 9230

    m.insert({10, 101});
    result = m.find(10);
    cout << result.second << endl;  // 101

    m.remove(10);
    result = m.find(10);
    cout << result.second << endl;  // -1
}

