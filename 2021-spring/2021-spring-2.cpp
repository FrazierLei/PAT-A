#include <bits/stdc++.h>
using namespace std;
using gg = long long;

struct request{
    gg in, out;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, h, m, s;
    cin >> n;
    vector<request> v(n);
    for (gg i = 0; i < n; ++i){
        string t;
        cin >> t;
        h = stoll(t.substr(0, 2));
        m = stoll(t.substr(3, 2));
        s = stoll(t.substr(6, 2));
        v[i].in = h * 3600 + m * 60 + s;
        cin >> t;
        h = stoll(t.substr(0, 2));
        m = stoll(t.substr(3, 2));
        s = stoll(t.substr(6, 2));
        v[i].out = h * 3600 + m * 60 + s;
    }
    sort(v.begin(), v.end(), [](const request &r1, const request &r2){
        return tie(r1.out, r2.in) < tie(r2.out, r1.in);
    });
//    for (auto i : v)
//        cout << i.in << " " << i.out << "\n";
    gg ans = 1, out = v[0].out;
    for (gg i = 0; i < n -1; ++i){
        if (v[i + 1].in >= out){
            out = v[i + 1].out;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
