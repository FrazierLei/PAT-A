#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<array<gg, 2>> edges;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, r, k, m, a, b;
    cin >> n >> r >> k;
    while (r--){
        cin >> a >> b;
        edges.push_back({a, b});
    }
    cin >> m;
    while (m--){
        vector<gg> v;
        for (gg i = 0; i < n; ++i){
            cin >> a;
            v.push_back(a);
        }
        unordered_set<gg> us(v.begin(), v.end());
        if (us.size() > k)
            cout << "Error: Too many species.\n";
        else if (us.size() < k)
            cout << "Error: Too few species.\n";
        else {
            for (auto e : edges){
                if (v[e[0] - 1] == v[e[1] - 1]){
                    cout << "No\n";
                    goto loop;
                }
            }
            cout << "Yes\n";
        }
        loop:;
    }
    return 0;
}
