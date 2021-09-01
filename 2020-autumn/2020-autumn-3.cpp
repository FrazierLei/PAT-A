#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Node{
    gg val;
    Node *left, *right;
};

Node* build(vector<gg> in, vector<gg> pre, gg r, gg left, gg right){
    if (left > right)
        return nullptr;
    Node* root = new Node;
    gg i = find(in.begin(), in.end(), pre[r]) - in.begin();
    root->val = pre[r];
    root->left = build(in, pre, r + 1, left, i - 1);
    root->right = build(in, pre, r + i - left + 1, i + 1, right);
    return root;
}
void levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    bool space = false;
    while (not q.empty()){
        gg s = q.size();
        for (gg i = 0; i < s; ++i){
            auto t = q.front();
            q.pop();
            if (i == 0){
                cout << (space ? " " : "") << t->val;
                space = true;
            }
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n;
    cin >> n;
    vector<gg> in(n), pre(n);
    for (gg &i : in)
        cin >> i;
    for (gg &i : pre)
        cin >> i;
    auto root = build(in, pre, 0, 0, n - 1);
    levelOrder(root);
    return 0;
}