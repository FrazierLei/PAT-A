#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n;
    cin >> n;
    vector<gg> v(n), ans(n, 200);
    for (gg &i : v)
        cin >> i;
    for (gg i = 1; i < n; ++i){
        if (v[i] > v[i - 1])
            ans[i] = ans[i - 1] + 100;
        else if (v[i] == v[i - 1])
            ans[i] = ans[i - 1];
        
    }
    for (gg i = n - 2; i >= 0; --i){
        if (v[i] > v[i + 1])
            ans[i] = max(ans[i], ans[i + 1] + 100);
        else if (v[i] == v[i + 1])
            ans[i] = max(ans[i], ans[i + 1]);
    }

    gg sum = accumulate(ans.begin(), ans.end(), 0);
    cout << sum;
    return 0;
}