#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, m, a, b; // n persons， m round
    cin >> a >> b >> n >> m;
    unordered_set<gg> us = {a, b}, diff = {abs(a - b)};
    vector<vector<gg>> data(n, vector<gg>(m));
    vector<bool> out(n + 1);
    for (gg i = 0; i < n; ++i)
        for (gg j = 0; j < m; ++j)
            cin >> data[i][j];
    for (gg i = 0; i < m; ++i){
        for (gg j = 0; j < n; ++j){
            if (not out[j + 1]){
                gg num = data[j][i];
                if (us.count(num) or not diff.count(num)){
                    out[j + 1] = true;
                    cout << "Round #" << (i + 1) << ": " << (j + 1) << " is out.\n";
                } else {
                    us.insert(num);
                    for (gg c : us)
                        diff.insert(abs(num - c));
                }
            }
        }
    }
    if (count(out.begin() + 1, out.end(), false) == 0)
        cout << "No winner.";
    else {
        cout << "Winner(s):";
        for (gg i = 1; i <= n; ++i)
            if (not out[i])
                cout << " " << i;
    }
    return 0;
}
