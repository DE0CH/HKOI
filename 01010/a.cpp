#include <iostream>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N;
ll diamonds[100000];
ll mdm[100000];
bool mdmb[100000];

ll md(ll v, ll depth) {
    if (depth == N) {
        return 0;
    } else {
        if (!mdmb[v]) {
            mdm[v] = max(diamonds[v], md(v-1, depth + 1) + diamonds[v]);
            mdmb[v] = true;
        } 
        return mdm[v];
    }

}

int main() {
    cin >> N;
    forn(i, N) {
        cin >> diamonds[i];
    }
    ll maxD = 0;
    forn(i, N) {
        if (md(i, 0) > maxD) {
            maxD = md(i, 0);
        }
    }
    cout << maxD << endl;
}