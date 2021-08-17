#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, m;
    string s;
    cin >> n;
    unordered_set<string> alumnus;
    vector<string> g, ag;
    for (gg i = 0; i < n; ++i){
        cin >> s;
        alumnus.insert(s);
    }
    cin >> m;
    for (gg i = 0; i < m; ++i){
        cin >> s;
        g.push_back(s);
        if (alumnus.count(s))
            ag.push_back(s);
    }
    cout << ag.size() << "\n";
    if (not ag.empty()){ // 有校友
        sort(ag.begin(), ag.end(), [](const string &s1, const string &s2){
            string y1 = s1.substr(6, 2), m1 = s1.substr(8, 2), d1 = s1.substr(10, 2);
            string y2 = s2.substr(6, 2), m2 = s2.substr(8, 2), d2 = s2.substr(10, 2);
            return tie(y1, m1, d1) < tie(y2, m2, d2);
        });
        cout << ag.front();
    } else {
        sort(g.begin(), g.end(), [](const string &s1, const string &s2){
            string y1 = s1.substr(6, 2), m1 = s1.substr(8, 2), d1 = s1.substr(10, 2);
            string y2 = s2.substr(6, 2), m2 = s2.substr(8, 2), d2 = s2.substr(10, 2);
            return tie(y1, m1, d1) < tie(y2, m2, d2);
        });
        cout << g.front();
    }
    return 0;
}