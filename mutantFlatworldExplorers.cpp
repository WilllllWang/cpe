#include <bits/stdc++.h>
 
 
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int ub = 1e9 + 1;


 
void solve() { 
    unordered_map<char, char> left{{'N', 'W'}, {'W', 'S'}, {'S', 'E'}, {'E', 'N'}};
    unordered_map<char, char> right{{'N', 'E'}, {'E', 'S'}, {'S', 'W'}, {'W', 'N'}};
    int xMax, yMax;
    cin >> xMax >> yMax; 
    int x, y;
    char direction;
    string op;
    set<pair<int, int>> last;
    while (cin >> x >> y >> direction >> op) {
        bool flag = true;
        for (char& o: op) {
            if (o == 'L') 
                direction = left[direction];
            else if (o == 'R') 
                direction = right[direction];
            else {
                if (direction == 'N') {
                    if (y == yMax) {
                        if (last.count({x, y}) == 1) continue;
                        else {
                            last.insert({x, y});
                            cout << x << ' ' << y << ' ' << direction << " LOST\n";
                            flag = false;
                            break;
                        }
                    }
                    y++;
                }
                if (direction == 'S') {
                    if (y == 0) {
                        if (last.count({x, y}) == 1) continue;
                        else {
                            last.insert({x, y});
                            cout << x << ' ' << y << ' ' << direction << " LOST\n";
                            flag = false;
                            break;
                        }
                    }
                    y--;
                }
                if (direction == 'E') {
                    if (x == xMax) {
                        if (last.count({x, y}) == 1) continue;
                        else {
                            last.insert({x, y});
                            cout << x << ' ' << y << ' ' << direction << " LOST\n";
                            flag = false;
                            break;
                        }
                    }
                    x++;
                }
                if (direction == 'W') {
                    if (x == 0) {
                        if (last.count({x, y}) == 1) continue;
                        else {
                            last.insert({x, y});
                            cout << x << ' ' << y << ' ' << direction << " LOST\n";
                            flag = false;
                            break;
                        }
                    }
                    x--;
                }
            }
        }
        if (flag) cout << x << ' ' << y << ' ' << direction << '\n';
    }
}





 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}
 