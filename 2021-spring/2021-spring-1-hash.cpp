#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1e5 + 5;
vector<gg> primes;
vector<bool> is_prime(MAX);
void get_prime(gg n){
    vector<bool> f(n);
    for (gg i = 2; i < n; ++i){
        if (not f[i]){
            primes.push_back(i);
            is_prime[i] = true;
            for (gg j = i + i; j < n; j += i)
                f[j] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n, p, start = -1, diff = -1;;
    cin >> n >> p;
    get_prime(MAX);
    if (n > 1){
        for (gg i = 0; primes[i] < p; ++i){
            gg s = primes[i];
            for (gg j = (p - s) / (n - 1); j > 1; --j){
                for (gg k = 1; k < n; ++k)
                    if (not is_prime[s + k * j])
                        goto loop; // 跳出最里层循环，寻找新的公差
                if (j >= diff){ // 这里不能是严格大于，因为可能出现公差相同但是首项更大的情况
                    start = s;
                    diff = j;
                }
                loop:;
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
        if (is_prime[i]){
            cout << i;
            return 0;
        }
    }
}
