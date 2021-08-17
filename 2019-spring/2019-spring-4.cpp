#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1005; // 虽然树中节点个数<=30，但是节点编号可以很大(<=1000)

struct BTNode {
    gg val;
    BTNode *left, *right;
    BTNode(gg v, BTNode* l = nullptr, BTNode* r = nullptr) : val(v) {}
};

BTNode* buildTree(vector<gg>& post, vector<gg>& in, gg r, gg left, gg right) {
    if (left > right)
        return nullptr;
    gg i = find(in.begin(), in.end(), post[r]) - in.begin();
    auto root = new BTNode(post[r]);
    root->left = buildTree(post, in, r - 1 - (right - i), left, i - 1);
    root->right = buildTree(post, in, r - 1, i + 1, right);
    return root;
}

vector<gg> l(MAX), r(MAX), father(MAX), level(MAX);
bool full = true;

void dfs(BTNode* root){
    if (root == nullptr)
        return;
    if ((root->left != nullptr and root->right == nullptr) or (root->left == nullptr and root->right != nullptr))
        full = false;
    if (root->left != nullptr){
        father[root->left->val] = root->val;
        l[root->val] = root->left->val;
        level[root->left->val] = level[root->val] + 1;
        dfs(root->left);
    }
    if (root->right != nullptr){
        father[root->right->val] = root->val;
        r[root->val] = root->right->val;
        level[root->right->val] = level[root->val] + 1;
        dfs(root->right);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, m;
    cin >> n;
    vector<gg> post(n), in(n);
    for (gg i = 0; i < n; ++i) {
        cin >> post[i];
    }
    for (gg i = 0; i < n; ++i) {
        cin >> in[i];
    }
    BTNode* root = buildTree(post, in, n - 1, 0, n - 1);
    level[root->val] = 0;
    dfs(root);
    cin >> m;
    string s;
    cin.get();
    while (m--){
        vector<string> words;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s)
            words.push_back(s);
        if (words[3] == "root")
            cout << (stoll(words.front()) == root->val ? "Yes\n" : "No\n");
        else if (words[3] == "parent")
            cout << (father[stoll(words.back())] == stoll(words.front()) ? "Yes\n" : "No\n");
        else if (words[3] == "left")
            cout << (l[stoll(words.back())] == stoll(words.front()) ? "Yes\n" : "No\n");
        else if (words[3] == "right")
            cout << (r[stoll(words.back())] == stoll(words.front()) ? "Yes\n" : "No\n");
        else if (words[3] == "full")
            cout << (full ? "Yes\n" : "No\n");
        else if (words[4] == "on")
            cout << (level[stoll(words.front())] == level[stoll(words[2])] ? "Yes\n" : "No\n");
        else
            cout << (father[stoll(words.front())] == father[stoll(words[2])] ? "Yes\n" : "No\n");
    }
    return 0;
}
