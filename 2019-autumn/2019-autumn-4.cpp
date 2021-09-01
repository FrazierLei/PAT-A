#include <bits/stdc++.h>
using namespace std;
using gg = long long;

gg n, m, k;
const gg MAX = 1e3 + 5;
gg dis[MAX][MAX], graph[MAX][MAX];

void floyd() {
    for (gg k = 1; k <= n; ++k) {
        for (gg i = 1; i <= n; ++i) {
            for (gg j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(graph[0], graph[0] + MAX * MAX, INT_MAX);
    for (gg i = 1; i <= n; ++i)
        graph[i][i] = 0;
    while (m--){
        gg a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    for (gg i = 1; i <= n; ++i){
        for (gg j = 1; j <= n; ++j)
            dis[i][j] = graph[i][j];
    }
    floyd();
    cin >> k;
    while (k--){
        gg s, t, d, old_d = 0;
        cin >> s;
        bool flag = true;
        for (gg i = 0; i < n - 1; ++i){
            cin >> t;
            d = dis[s][t];
            if (d < old_d){
                flag = false;
            }
            old_d = d;
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}
