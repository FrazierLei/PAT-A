#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Node{
    string val;
    gg left = -1, right = -1;
};
vector<Node> tree(25);
void dfs(gg root){
    if (root == -1)
        return;
    if (tree[root].left == -1 or tree[root].right == -1){
        cout << "(" << tree[root].val;
        dfs(tree[root].left);
        dfs(tree[root].right);
        cout << ")";
    } else {
        cout << "(";
        dfs(tree[root].left);
        dfs(tree[root].right);
        cout << tree[root].val << ")";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n;
    cin >> n;
    vector<bool> f(n + 1, true);
    f[0] = false;
    for (gg i = 1; i <= n; ++i){
        string s;
        gg left, right;
        cin >> s >> left >> right;
        tree[i].val = s;
        tree[i].left = left;
        tree[i].right = right;
        if (left != -1)
            f[left] = false;
        if (right != -1)
            f[right] = false;
    }
    gg root = find(f.begin(), f.end(), true) - f.begin();
    dfs(root);
    return 0;
}