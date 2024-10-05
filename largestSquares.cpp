#include <bits/stdc++.h>
 
 
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int ub = 1e9 + 1;



bool checkEdges(int left, int right, int top, int bottom, char target, vector<vector<char>> rec) {
    // Left
    for (int i = top, j = left; i <= bottom; i++) 
        if (rec[i][j] != target) 
            return false;
    // Right
    for (int i = top, j = right; i <= bottom; i++) 
        if (rec[i][j] != target)
            return false;
    // Top
    for (int i = top, j = left; j <= right; j++) 
        if (rec[i][j] != target)
            return false;
    // Bottom
    for (int i = bottom, j = left; j <= right; j++) 
        if (rec[i][j] != target) 
            return false;
    return true;
}
 
void solve() { 
    int m, n, q;
    cin >> m >> n >> q;
    cout << m << ' ' << n << ' ' << q << '\n';
    vector<vector<char>> rec(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rec[i][j];
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x >= m || y >= n) {
            cout << 0 << '\n';
            continue;
        }

        int res = 1;
        int left = y - 1;
        int right = y + 1;
        int top = x - 1;
        int bottom = x + 1;
        while (true) {
            if (left < 0 || right >= n || top < 0 || bottom >= m) break;
            if (checkEdges(left, right, top, bottom, rec[x][y], rec) == false) break;
            left--;
            right++;
            top--;
            bottom++;
            res += 2;
        }
        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--)
        solve();

    return 0;
}
