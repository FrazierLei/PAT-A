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
    priority_queue<gg, vector<gg>, greater<>> temp; // 最小堆
    for (gg i = 0; i < m; ++i){
        t = q.front();
        q.pop();
        temp.push(t);
    }
    vector<gg> run, next_run;
    while (not q.empty()){
        t = temp.top(); // 从temp中取出最小的元素
        temp.pop();
        run.push_back(t); // 放入run中
        t = q.front(); // 从待排序的队列中弹出一个元素
        q.pop();
        if (t > run.back()) // 如果这个元素比run中最大的元素小，进入下一个run中
            temp.push(t);
        else
            next_run.push_back(t);
        if (temp.empty()){ // temp为空时当前run的填充结束，遍历打印
            for (gg i = 0; i < run.size(); ++i)
                cout << (i == 0 ? "" : " ") << run[i];
            cout << "\n";
            for (gg i : next_run) // 将next_run中的元素全部放入temp队列中，清空，开始新一轮循环
                temp.push(i);
            next_run.clear();
            run.clear();
        }
    }
    // 队列q清空以后temp和next_run中依然可能有待排序的数，依次输出
    if (not temp.empty()){
        while (not temp.empty()){
            t = temp.top();
            temp.pop();
            run.push_back(t);
        }
        for (gg i = 0; i < run.size(); ++i)
            cout << (i == 0 ? "" : " ") << run[i];
        cout << "\n";
    }
    if (not next_run.empty()){
        for (gg i : next_run)
            temp.push(i);
        bool space = false;
        while (not temp.empty()){
            t = temp.top();
            temp.pop();
            cout << (space ? " " : "") << t;
            space = true;
        }
    }
    return 0;
}
