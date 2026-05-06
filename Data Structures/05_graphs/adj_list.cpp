#include<iostream>
using namespace std;

int main() {
    
    unordered_map<int, vector<int>> adj_list;
    /*
        0 - 1
        |   |
        2 - 3
        |
        4
    */
    adj_list[0] = {1, 2};
    adj_list[1] = {0, 2, 3};
    adj_list[2] = {0, 1, 3, 4};
    adj_list[3] = {1, 2};
    adj_list[4] = {2};
}
