#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // we have parabola, and we must find extreme of this parabola on length from -10 to 10
    // y = 2x^2 + 4x - 15 ---- our parabola
    double a = 2, b = 4, c = -15;
    double exp = 1 / 1e6;
    double l = -10, r = 10 + exp;
    while (r - l > exp){
        double m1 = l + (r - l) / 3.;
        double m2 = l + (r - l) / 3. * 2.;
        if (a * m1 * m1 + b * m1 + c >= a * m2 * m2 + b * m2 + c){
            l = m1;
        } else {
            r = m2;
        }
    }
    cout << l;
    return 0;
}