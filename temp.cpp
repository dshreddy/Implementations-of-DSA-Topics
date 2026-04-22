#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define debug(x) cout << #x << " = " << x << endl
#define debugp(p) cout << #p << " = " << p.first << " " << p.second << endl
#define debugv(v) cout << #v << " = "; for (auto &x : v) cout << x << " "; cout << endl;
#define debugm(m) cout << #m << " = "; for (auto &x : m) { cout << x.first << " " << x.second << " "; } cout << endl;
#define debugv2d(v) cout << #v << " = \n"; for (auto &x : v) { for (auto &y : x) cout << y << " "; cout << endl; }
using namespace std;
 
class Solution {
public:
    void solve() {
        int n; cin>>n;
        // 1 
        // 1 2 => Not possible
        // 1 3 2 => Not possible
        // 3 1 4 2
        // 5 3 1 4 2
        if(n == 1) cout<<"1\n";
        else if(n == 2 || n == 3) cout<<"NO SOLUTION\n";
        else {
            int odd_max, even_max;

            if(n%2 != 0) {
                odd_max = n;
                even_max = n-1;
            } else {
                odd_max = n-1;
                even_max = n;
            }

            while(odd_max > 0) {
                cout<<odd_max<<" ";
                odd_max -= 2;
            }

            while(even_max > 0) {
                cout<<even_max<<" ";
                even_max -= 2;
            }
        }

    }
};
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    Solution sol;
    // int t;
    // cin >> t;
    // while (t--)
    {
        sol.solve();
    }
    //cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
    return 0;
}