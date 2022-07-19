#include <bits/stdc++.h>


using namespace std;

#define ll long long

ll partition(vector<ll> &vec, ll st, ll fin) { // there we swap elements
    ll pivot = vec[st]; // first element
    ll is_count = 0;
    for (ll i = st + 1; i <= fin; i++) { // count of smaller elements
        if (vec[i] <= pivot) {
            is_count++;
        }
    }
    ll index_of_pivot = st + is_count;
    swap(vec[st], vec[index_of_pivot]);// swapping for giving place for smaller elements
    ll i = st, j = fin;
    while (i < index_of_pivot && j > index_of_pivot) { // just swap
        while (vec[i] <= vec[index_of_pivot]) {
            i++;
        }
        while (vec[j] > vec[index_of_pivot]) {
            j--;
        }
        if (i < index_of_pivot && j > index_of_pivot) {
            swap(vec[i++], vec[j--]);
        }
    }
    return index_of_pivot;
}

void quick_sort(vector<ll> &vec, ll st, ll fin) { // main part of sorting
    if (st >= fin) {
        return;
    }
    ll p = partition(vec, st, fin); // smaller elements left, bigger right
    quick_sort(vec, st, p - 1); // the same with left side
    quick_sort(vec, p + 1, fin); // the same with right side
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }
    quick_sort(vec, 0, n - 1);
    for (auto elem: vec) {
        cout << elem << ' ';
    }
    return 0;
}
//3 7 3 5 2 4 6 9 3