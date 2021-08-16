#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, m, x, y;
    cin >> n >> m;
    vector<gg> v(n);
    for (gg &i : v)
        cin >> i;
    for (auto it = v.begin(); it != v.end() + 1; ++it)
        push_heap(v.begin(), it);

    cin.get();
    string s;
    while (m--){
        vector<string> words;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s)
            words.push_back(s);
        if (words[3] == "root"){
            x = stoll(words[0]);
            cout << (x == v[0] ? "1" : "0");
        } else if (words[3] == "are"){
            x = stoll(words[0]);
            y = stoll(words[2]);
            gg xx = find(v.begin(), v.end(), x) - v.begin();
            gg yy = find(v.begin(), v.end(), y) - v.begin();
            cout << ((xx - 1) / 2 == (yy - 1) / 2 ? "1" : "0");
        } else if (words[3] == "parent"){
            x = stoll(words[0]);
            y = stoll(words[5]);
            gg xx = find(v.begin(), v.end(), x) - v.begin();
            gg yy = find(v.begin(), v.end(), y) - v.begin();
            cout << (xx == (yy - 1) / 2 ? "1" : "0");
        } else if (words[3] == "left"){
            x = stoll(words[0]);
            y = stoll(words[6]);
            gg xx = find(v.begin(), v.end(), x) - v.begin();
            gg yy = find(v.begin(), v.end(), y) - v.begin();
            cout << (xx == 2 * yy + 1 ? "1" : "0");
        } else if (words[3] == "right"){
            x = stoll(words[0]);
            y = stoll(words[6]);
            gg xx = find(v.begin(), v.end(), x) - v.begin();
            gg yy = find(v.begin(), v.end(), y) - v.begin();
            cout << (xx == 2 * yy + 2 ? "1" : "0");
        }
    }

    return 0;
}
