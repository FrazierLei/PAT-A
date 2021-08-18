#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<array<gg, 2>> data(1e5+5);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg start, n, k;
    cin >> start >> n >> k;
    for (gg i = 0; i < n; ++i){
        gg addr, val, next;
        cin >> addr >> val >> next;
        data[addr][0] = val;
        data[addr][1] = next;
    }
    vector<gg> lst;
    while (start != -1){
        lst.push_back(start);
        start = data[start][1];
    }
    gg i = 0;
    while (i + k <= lst.size()){
        reverse(lst.begin() + i, lst.begin() + i + k);
        i += k;
    }
    if (n % k != 0) // 多出来的部分
        reverse(lst.begin() + i, lst.end());
    reverse(lst.begin(), lst.end());

    cout << setfill('0');
    for (gg i = 0; i < lst.size() - 1; ++i)
        cout << setw(5) << lst[i] << " " << data[lst[i]][0] << " " << setw(5) << lst[i + 1] << "\n";
    cout << setw(5) << lst.back() << " " << data[lst.back()][0] << " " << "-1";
    return 0;
}
