#include <bits/stdc++.h>


using namespace std;

#define ll long long

ll const INF = 1e9;

ll solve(vector<ll> &inp, ll is_sum, vector<ll> &means){
    if (is_sum < 0){
        return INF;
    }
    if (is_sum == 0){
        means[0] = 0;
        return 0;
    }
    if (means[is_sum] != INF){
        return means[is_sum];
    }
    ll best = INF;
    for (auto elem: inp){
        best = min(best, solve(inp, is_sum - elem, means) + 1);
    }
    means[is_sum] = best;
    return best;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, is_sum;
    cin >> n >> is_sum;
    vector<ll> inp(n);
    for (ll i = 0; i < n; i++){
        cin >> inp[i];
    }
    vector<ll> dp(is_sum + 1, INF);
    dp[0] = 0;
    for (ll i = 1; i <= is_sum; i++){
        ll best = INF;
        for (auto elem: inp){
            if (i - elem >= 0) {
                best = min(best, dp[i - elem] + 1);
            }
        }
        dp[i] = best;
    }
    cout << dp[is_sum];
    return 0;
}
