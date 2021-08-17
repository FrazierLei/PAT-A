#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1005;
vector<vector<gg>> record(MAX, vector<gg>(MAX));
vector<gg> call(MAX), callback(MAX), suspects, ufs(MAX);

void init(){
    iota(ufs.begin(), ufs.end(), 0);
}

gg findRoot(gg x){
    return ufs[x] == x ? x : ufs[x] = findRoot(ufs[x]);
}

void unionSets(gg a, gg b){
    gg ra = findRoot(a), rb = findRoot(b);
    if (ra < rb)
        ufs[rb] = ra;
    else
        ufs[ra] = rb;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg k, n, m;
    cin >> k >> n >> m;
    for (gg i = 0; i < m; ++i){
        gg c, r, d;
        cin >> c >> r >> d;
        record[c][r] += d;
    }
    for (gg i = 1; i <= n; ++i){
        for (gg j = 1; j <= n; ++j){
            if (record[i][j] > 0 and record[i][j] <= 5){
                ++call[i];
                if (record[j][i] != 0)
                    ++callback[i];
            }
        }
        if (call[i] > k and callback[i] * 5 <= call[i])
            suspects.push_back(i);
    }
    if (suspects.empty()){
        cout << "None";
        return 0;
    }
    init();
    for (gg i : suspects)
        for (gg j : suspects)
            if (record[i][j] > 0 and record[j][i] > 0)
                unionSets(i, j);
    vector<gg> roots;
    for (gg i : suspects)
        if (ufs[i] == i)
            roots.push_back(i);
    for (gg r : roots){
        bool space = false;
        for (gg i : suspects){
            if (ufs[i] == r){
                cout << (space ? " " : "") << i;
                space = true;
            }
        }
        cout << "\n";
    }
    return 0;
}
