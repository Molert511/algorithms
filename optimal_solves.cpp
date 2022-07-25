#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool valid(ll t, vector<ll> &vec, ll k){
    ll is_sum = 0;
    for (auto elem: vec){
        is_sum += t / elem;
    }
    if (k <= is_sum) {
        return true;
    } else {
        return false;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k, n;
    cin >> k >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++){
        cin >> vec[i];
    }
    ll l = 0, r = vec[0] * k;
    while (l + 1 < r){
        ll m = (l + r) / 2;
        if (valid(m, vec, k)){
            r = m;
        } else {
            l = m;
        }
    }
    cout << l + 1;
    return 0;
}