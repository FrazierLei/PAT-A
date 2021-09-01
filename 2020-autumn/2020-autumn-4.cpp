#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1005;
using agg3 = array<gg, 3>;
gg n, m, k;
struct Edge{
    gg to, cost, reward;
    Edge(gg t, gg c, gg r) : to(t), cost(c), reward(r){}
};
vector<gg> top, degree(MAX), cost(MAX, INT_MAX), reward(MAX), pre(MAX, -1);
vector<vector<Edge>> graph(MAX);

bool acycle(){
    vector<gg> temp(degree.begin(), degree.begin() + n);
    queue<gg> q;
    for (gg i = 0; i < n; ++i){
        if (temp[i] == 0)
            q.push(i);
    }
    while (not q.empty()){
        gg p = q.front();
        q.pop();
        top.push_back(p);
        for (auto e : graph[p]){
            if (--temp[e.to] == 0)
                q.push(e.to);
        }
    }
    return top.size() == n;
}

void dijkstra(gg s) {
    priority_queue<agg3, vector<agg3>, greater<agg3>> pq;
    cost[s] = 0;
    reward[s] = 0;
    pq.push({0, 0, s});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (cost[p[2]] != p[0] or reward[p[2]] != p[1]) {
            continue;
        }
        for (auto& e : graph[p[2]]) {
            if (cost[e.to] > p[0] + e.cost){
                cost[e.to] = p[0] + e.cost;
                reward[e.to] = p[1] + e.reward;
                pre[e.to] = p[2];
                pq.push({cost[e.to], reward[e.to], e.to});
            } else if (cost[e.to] == p[0] + e.cost and reward[e.to] < p[1] + e.reward){
                reward[e.to] = p[1] + e.reward;
                pre[e.to] = p[2];
                pq.push({cost[e.to], reward[e.to], e.to});
            }
        }
    }
}

vector<gg> path;
void dfs(gg v){
    if (pre[v] == -1)
        return;
    dfs(pre[v]);
    path.push_back(v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (m--){
        gg a, b, c, r;
        cin >> a >> b >> c >> r;
        graph[a].push_back(Edge(b, c, r));
        ++degree[b]; // 入度 + 1
    }
    cin >> k;
    vector<gg> v(k);
    for (gg i = 0; i < k; ++i)
        cin >> v[i];

    if (not acycle()){
        cout << "Impossible.\n";
        for (gg i : v){
            if (degree[i] == 0)
                cout << "You may take test " << i << " derectly.\n";
            else
                cout << "Error.\n";
        }
    } else {
        cout << "Okay.\n";
        // 新建一个节点
        for (gg i = 0; i < n; ++i){
            if (degree[i] == 0)
                graph[n].push_back({i, 0, 0});
        }
        dijkstra(n);
        for (gg i : v){
            if (degree[i] == 0)
                cout << "You may take test " << i << " derectly.\n";
            else {
                path.clear(); // 清空 path
                dfs(i);
                for (gg j = 0; j < path.size(); ++j)
                    cout << path[j] << (j == path.size() - 1 ? "\n" : "->");
            }
        }
    }
    return 0;
}
