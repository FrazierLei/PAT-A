#include <bits/stdc++.h>
using namespace std;
using gg = long long;
bool isPrime(gg n){
    if (n <= 2)
        return false;
    for (gg i = 2; i <= sqrt(n); ++i){
        if (n % i == 0)
            return false;
    }
    return true;
}

gg gcd(gg a, gg b){
    return (b == 0 ? a : gcd(b, a % b));
}

gg digitSum(gg n){
    gg ans = 0;
    while (n != 0){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

gg lowerBound(gg k, gg t){ // k为数的位数，t为末尾9的个数，
    gg ans = pow(10, k - 1);
    for (gg i = 0; i < t; ++i)
        ans += 9 * pow(10, i);
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg N, m, k;
    cin >> N;
    for (gg i = 1; i <= N; ++i){
        cout << "Case " << i << "\n";
        cin >> k >> m;
        bool flag = true;
        if (m <= 9 * k){
            for (gg n = 3; n < m; ++n){
                if (isPrime(gcd(n, m)) and ((m - n + 1) % 9 == 0)){
                    gg t = (m - n + 1) / 9, lb = lowerBound(k, t), ub = pow(10, k);
                    for (gg a = lb; a < ub; a += pow(10, t)){
                        if (digitSum(a) == m and digitSum(a + 1) == n){
                            flag = false;
                            cout << n << " " << a << "\n";
                        }
                    }
                }
            }
        }
        if (flag)
            cout << "No Solution\n";
    }
    return 0;
}
