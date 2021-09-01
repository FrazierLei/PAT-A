#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, m, ans = 0;
    cin >> n >> m;
    vector<gg> v(n + 1);
    for (gg i = 1; i <= n; ++i)
        cin >> v[i];
    partial_sum(v.begin(), v.end(), v.begin());
    for (gg i = 0; i < n; ++i)
        for (gg j = i + 1; j <= n; ++j)
            if (v[j] - v[i] <= m)
                ++ans;
    cout << ans;
    return 0;
}