#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, m, t;
    cin >> n >> m;
    queue<gg> q;
    for (gg i = 0; i < n; ++i){
        cin >> t;
        q.push(t);
    }
    vector<gg> temp;
    for (gg i = 0; i < m; ++i){
        t = q.front();
        q.pop();
        temp.push_back(t);
    }
    sort(temp.begin(), temp.end());
    vector<gg> run;
    while (not q.empty()){
        while (run.empty() or temp.back() > run.back()){
            auto it = temp.begin();
            if (not run.empty())
                it = upper_bound(temp.begin(), temp.end(), run.back()); // temp中第一个大于run中最大元素的元素
            run.push_back(*it); // 把这个元素添加到run后面
            temp.erase(it); // 删除temp中这个元素
            if (not q.empty()){
                t = q.front(); // temp有了位置，q弹出一个元素加进来
                q.pop();
                it = upper_bound(temp.begin(), temp.end(), t); // temp中第一个大于新元素的位置
                temp.insert(it, t); // 插入到这个位置的前面
            }
        }
        // 打印 run，然后清空
        if (not run.empty()){
            for (gg i = 0; i < run.size(); ++i)
                cout << (i == 0 ? "" : " ") << run[i];
            cout << "\n";
            run.clear();
        }
    }
    if (not temp.empty())
        for (gg i = 0; i < temp.size(); ++i)
            cout << (i == 0 ? "" : " ") << temp[i];

    return 0;
}
