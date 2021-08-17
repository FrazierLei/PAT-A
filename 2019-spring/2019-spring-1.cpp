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
    gg n;
    cin >> n;
    if (is_prime(n) and is_prime(n - 6))
        cout << "Yes\n" << (n - 6);
    else if (is_prime(n) and is_prime(n + 6))
        cout << "Yes\n" << (n + 6);
    else {
        cout << "No\n";
        for (gg i = n + 1; ;++i){
            if (is_prime(i) and (is_prime(i - 6) or is_prime(i + 6))){
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}
