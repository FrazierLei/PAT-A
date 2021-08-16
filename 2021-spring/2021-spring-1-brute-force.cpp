#include <bits/stdc++.h>
using namespace std;
using gg = long long;

bool isPrime(gg n){
    if (n <= 1)
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
    gg n, p, start = -1, diff = -1;
    cin >> n >> p;
    if (n > 1){
        for (gg i = 2; i < p; ++i){
            for (gg j = 1; i + (n - 1) * j <= p; ++j){
                bool flag = true;
                for (gg k = 0; k < n; ++k)
                    if (not isPrime(i + k * j)){
                        flag = false;
                        break;
                    }
                if (flag and j >= diff){
                    start = i;
                    diff = j;
                }
            }
        }
        if (start > 0){
            for (gg k = 0; k < n; ++k)
                cout << (k == 0 ? "" : " ") << (start + k * diff);
            return 0;
        }
    }
    // n为1或者没有找到长度为n的等差素数序列
    for (gg i = p; i > 1; --i){
        if (isPrime(i)){
            cout << i;
            return 0;
        }
    }
}
