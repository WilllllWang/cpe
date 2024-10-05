#include <bits/stdc++.h>
 
 
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int ub = 1e9 + 1;
 
void solve() { 
    int i, j;
    while (cin >> i >> j) {
        unordered_map<int, int> mp;
        int res = 0;
        for (int num = min(i, j); num <= max(i, j); num++) {
            int temp = num, count = 1;
            while (temp > 1) {
                if (temp % 2 == 0) temp /= 2;
                else temp = temp * 3 + 1;
                if (mp[temp]) {
                    count += mp[temp];
                    break;
                } 
                count++;
            }
            mp[num] = count;
            res = max(res, count);
        }
        cout << i << ' ' << j << ' ' << res << '\n';
    }
}





 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}
 