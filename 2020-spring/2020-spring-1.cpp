#include <bits/stdc++.h>
using namespace std;
using gg = long long;

bool is_prime(gg n){
    if (n < 2)
        return false;
    for (gg i = 2; i <= (gg)sqrt(n); ++i){
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    bool flag = true;
    for (gg i = 0; i < s.size(); ++i){
        string a = s.substr(i);
        gg n = stoll(a);
        if (is_prime(n))
            cout << a << " Yes\n";
        else {
            cout << a << " No\n";
            flag = false;
        }
    }
    if (flag)
        cout << "All Prime!";
    return 0;
}
