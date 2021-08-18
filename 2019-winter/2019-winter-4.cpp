#include <bits/stdc++.h>
using namespace std;
using gg = long long;

struct BTNode {
    gg val;
    BTNode *left, *right;
    BTNode(gg v, BTNode* l = nullptr, BTNode* r = nullptr) : val(v) {}
};

BTNode* buildFromIn(vector<gg> &in, gg l, gg r){
    if (l > r)
        return nullptr;
    auto it = min_element(in.begin() + l, in.begin() + r + 1);
    gg num = *it;
    gg idx = it - in.begin();
    BTNode *root = new BTNode(num);
    root->left = buildFromIn(in, l, idx - 1);
    root->right = buildFromIn(in, idx + 1, r);
    return root;
}
void levelOrder(BTNode* root) {
    queue<BTNode*> q;
    q.push(root);
    bool space = false;
    while (not q.empty()) {
        auto t = q.front();
        q.pop();
        cout << (space ? " " : "") << t->val;
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
        space = true;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n;
    cin >> n;
    vector<gg> in(n);
    for (gg i = 0; i < n; ++i)
        cin >> in[i];
    BTNode *root = buildFromIn(in, 0, n - 1);
    levelOrder(root);
    return 0;
}
