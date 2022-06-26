#include <bits/stdc++.h>


using namespace std;

#define ll long long

void counting_sort(){
    ll c; // min number which bigger than max element in array
    cin >> c;
    ll n;
    cin >> n; // size of array
    vector<ll>vec(n);
    for (ll i = 0; i < n; i++){
        cin >> vec[i]; // fill the array
    }
    vector<ll> vec_info(c, 0); // array which indexes include amount of numbers in array
    for(auto elem: vec){ // fill means
        ++vec_info[elem];
    }
    for (ll i = 1; i < c; i++){ // all indexes`s means - their position in result array
        vec_info[i] += vec_info[i - 1];
    }
    vector<ll> vec_res(n);//                          ^^^
    for(ll i = 0; i < n; i++){ //                     |||
        vec_res[vec_info[vec[i]] - 1] = vec[i];
    }
    for (auto elem: vec_res){ //print
        cout << elem << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    counting_sort();
    return 0;
}