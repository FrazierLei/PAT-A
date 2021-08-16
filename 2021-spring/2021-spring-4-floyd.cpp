#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 205;

gg n, m;
vector<gg> path(1);
vector<vector<gg>> dis(MAX, vector<gg>(MAX, INT_MAX)); // 邻接矩阵
void floyd() {
    for (gg k = 0; k <= n; ++k) {
        for (gg i = 0; i <= n; ++i) {
            for (gg j = 0; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);  // 更新距离
            }
        }
    }
}

vector<bool> visit(MAX);
void dfs(gg v){
    visit[v] = true;
    for (gg i = 0; i <= n; ++i){
        if (not visit[i] and dis[v][i] < INT_MAX)
            dfs(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (gg i = 0; i < n; ++i)
        dis[i][i] = 0;
    while (m--){
        gg a, b, d;
        cin >> a >> b >> d;
        dis[a][b] = d;
        dis[b][a] = d;
    }
    dfs(0);
    vector<gg> cant_visit;
    for (gg i = 0; i < n + 1; ++i){
        if (not visit[i]){
            cant_visit.push_back(i);
            visit[i] = true;
        } else {
            visit[i] = false;
        }
    }
    floyd();
//    for (gg i = 0; i <= n; ++i){
//        for (gg j = 0; j <= n; ++j)
//            cout << dis[i][j] << " ";
//        cout << "\n";
//    }
    for (gg i = 0; i < n; ++i)
        dis[i][i] = INT_MAX;
    gg i = 0, d = 0;
    for (gg k = 0; k < n - cant_visit.size(); ++k){
        visit[i] = true;
        dis[i][i] = INT_MAX;
        auto it = min_element(dis[i].begin(), dis[i].end());
        while (visit[it - dis[i].begin()] and count(visit.begin(), visit.begin() + n + 1, false) > 0){
            *it = INT_MAX;
            it = min_element(dis[i].begin(), dis[i].end());
        }
        d += *it;
        i = it - dis[i].begin();
        path.push_back(i);
    }
    for (gg i = 0; i < path.size(); ++i)
        cout << (i == 0 ? "" : " ") << path[i];
    cout << "\n";
    if (not cant_visit.empty()){
        for (gg i = 0; i < cant_visit.size(); ++i)
            cout << (i == 0 ? "" : " ") << cant_visit[i];
    } else {
        cout << d << "\n";
    }

    return 0;
}
