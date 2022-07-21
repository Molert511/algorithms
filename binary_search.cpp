#include<bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, n;
    cin >> x >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++){
        cin >> vec[i];
    }
    ll l = 0, r = n;
    while (l + 1 < r){
        ll m = (l + r) / 2;
        if (x < vec[m]){
            r = m;
        } else {
            l = m;
        }
    }
    if (vec[l] == x){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}