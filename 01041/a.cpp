#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdexcept>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define INF 1000001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
vector<pair<ll, ll> > cities[1000]; // {to, dist}
ll source, dest;
ll dist[1000];
ll pre[1000];
priority_queue<pll> toFinalise; // {dist, two}
stack<ll> path;

void dijkstra(ll source) {
    forn (i, N) {
        dist[i] = INF;
    }
    dist[source] = 0;
    toFinalise.push(make_pair(0, source));
    while (!toFinalise.empty()) {
        ll one = toFinalise.top().second;
        ll d = -toFinalise.top().first;
        toFinalise.pop();
        if (d == dist[one]) {
            for (pll t : cities[one]) {
                ll two = t.first;
                ll d = t.second;
                if (dist[one] + d < dist[two]) {
                    dist[two] = dist[one] + d;
                    pre[two] = one;
                    toFinalise.push(make_pair(-dist[two], two));
                }
            }
        }
    }
}


int main() {
    cin >> N;
    cin >> source >> dest;
    source--;
    dest--;
    ll a, b, d;
    cin >> a >> b >> d;
    while(a != 0 || b != 0 || d != 0) {
        a--;
        b--;
        cities[a].push_back(make_pair(b, d));
        cities[b].push_back(make_pair(a, d));
        cin >> a >> b >> d;
    }
    dijkstra(source);
    cout << dist[dest] << endl;;
    stack<ll> path;
    ll k = dest;
    while (k != source) {
        path.push(k);
        k = pre[k];
    }
    path.push(source);
    while (!path.empty()) {
        cout << path.top() + 1 << " ";
        path.pop();
    }
    cout << endl;
}