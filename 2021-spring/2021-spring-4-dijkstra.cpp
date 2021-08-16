#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 205;
using agg2 = array<gg, 2>;

struct Edge{
    gg to, cost;
    Edge(gg t, gg c) : to(t), cost(c){}
};
vector<vector<Edge>> graph(MAX); // 邻接表
vector<gg> dis(MAX), path(1);
vector<bool> visit(MAX);

void dijkstra(gg s){
    fill(dis.begin(), dis.end(), INT_MAX);
    priority_queue<agg2, vector<agg2>, greater<>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (not pq.empty()){
        auto p = pq.top();
        pq.pop();
        if (dis[p[1]] != p[0])
            continue;
        for (auto& e : graph[p[1]]){
            if (dis[e.to] > dis[p[1]] + e.cost){
                dis[e.to] = dis[p[1]] + e.cost;
                pq.push({dis[e.to], e.to});
            }
        }
    }

}
void dfs(gg v){
    visit[v] = true;
    for (auto e : graph[v]){
        if (not visit[e.to])
            dfs(e.to);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, m;
    cin >> n >> m;
    while (m--){
        gg a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back(Edge(b, d));
        graph[b].push_back(Edge(a, d));
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
//    for (gg i = 0; i < cant_visit.size(); ++i)
//        cout << cant_visit[i] << " ";
//    for (gg i = 0; i < n; ++i)
//        cout << visit[i] << " ";
//    cout << "\n";
    gg i = 0, d = 0;
    for (gg k = 0; k < n - cant_visit.size(); ++k){
        visit[i] = true;
        dijkstra(i);
        dis[i] = INT_MAX;
        auto it = min_element(dis.begin(), dis.end());
        while (visit[it - dis.begin()] and count(visit.begin(), visit.begin() + n + 1, false) > 0){
            *it = INT_MAX;
            it = min_element(dis.begin(), dis.end());
        }
        d += *it;
        i = it - dis.begin();
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
