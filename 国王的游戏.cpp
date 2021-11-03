#include<bits/stdc++.h>
using namespace std;
long long mod;
long long q,n;
long long Fastpow(long long a, long long b){
    long long x = 1;
    while (b > 0) {
        if (b % 2 != 0) {
            x = x * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return x;
}
long long Fastgeometric(long long n){
    if (n == 0)
        return 0;
    if (n == 1)
        return q;
    if (n % 2 == 0) {
        return (Fastpow(q, n / 2) + 1) % mod * Fastgeometric(n / 2) % mod;
    } else {
        return (Fastpow(q, n) + Fastgeometric(n - 1)) % mod;
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &q, &n);
        --n;
        mod = 100000007;
        q %= mod;
        printf("%lld\n", Fastgeometric(n) + 1);
    }
    return 0;
}
