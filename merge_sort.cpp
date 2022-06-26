#include <bits/stdc++.h>


using namespace std;

#define ll long long

void bubble_sort(vector<ll> &vec){
    for (ll i = 0; i < vec.size() - 1; i++){
        for (ll j = 0; j < vec.size() - i - 1; j++){
            if (vec[j] > vec[j + 1]){
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void merge(vector<ll> &vec, ll l, ll m, ll r) { // this function make from two parts of array sorted part
    vector<ll> vec_left, vec_right; // there we just do two vectors which include sorted part of vector
    // now we full these vectors
    for (ll i = l; i <= m; i++){
        vec_left.push_back(vec[i]);
    }
    for (ll i = m + 1; i <= r; i++){
        vec_right.push_back(vec[i]);
    }
    // in this cycle we with two pointers change elements in our vector (with queue we append elements from our two crated vectors)
    ll pointer_1 = 0, pointer_2 = 0;
    while(pointer_1 < m - l + 1 || pointer_2 < r - m){ // something creepy
        if (pointer_1 < m - l + 1 && pointer_2 < r - m){
            if (vec_left[pointer_1] < vec_right[pointer_2]){
                vec[l + pointer_1 + pointer_2] = vec_left[pointer_1];
                ++pointer_1;
            } else {
                vec[l + pointer_1 + pointer_2] = vec_right[pointer_2];
                ++pointer_2;
            }
        } else if (pointer_1 >= m - l + 1){
            vec[l + pointer_1 + pointer_2] = vec_right[pointer_2];
            ++pointer_2;
        } else {
            vec[l + pointer_1 + pointer_2] = vec_left[pointer_1];
            ++pointer_1;
        }
    }

}


void merge_sort(vector<ll> &vec, ll l, ll r) { // there we are just getting parts of array, and after this we will merge this parts recursively
    if (l < r) {
        ll m = (l + r) / 2; // finding middle element of array
        merge_sort(vec, l, m); // sorting left part of array
        merge_sort(vec, m + 1, r); // sorting right part of array
        merge(vec, l, m, r); // merging two parts with helping of indexes
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (ll n = 2; n <= 100; n++){ // stress-test
        for (ll k = 0; k < 1000; k++) {
            vector<ll> vec(n);
            for (ll i = 0; i < n; i++) {
                vec[i] = rand();
            }
            vector<ll> vec_2 = vec;
            bubble_sort(vec_2);
            merge_sort(vec, 0, n - 1);
            if (vec != vec_2) {
                cout << n << '\n';
            }
        }
    }
    return 0;
}