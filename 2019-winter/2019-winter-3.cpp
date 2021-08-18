#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<vector<gg>> graph(205, vector<gg>(205));

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, m, k, l, a, b;
    bool flag;
    cin >> n >> m;
    while (m--){
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    cin >> k;
    for (gg i = 1; i <= k; ++i){
        cin >> l;
        vector<gg> v;
        for (gg j = 0; j < l; ++j){
            cin >> a;
            v.push_back(a);
        }
        unordered_set<gg> us(v.begin(), v.end());
        for (a = 0; a < l; ++a)
            for (b = a + 1; b < l; ++b){
                if (graph[v[a]][v[b]] == 0){
                    cout << "Area " << i << " needs help.\n";
                    goto loop;
                }
            }

        for (a = 1; a <= n; ++a){
            if (not us.count(a)){
                flag = true;
                for (b = 0; b < l; ++b){
                    if (graph[a][v[b]] == 0){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    cout << "Area " << i << " may invite more people, such as " << a << ".\n";
                    goto loop;
                }
            }
        }
        cout << "Area " << i << " is OK.\n";
        loop:;
    }
    return 0;
}
