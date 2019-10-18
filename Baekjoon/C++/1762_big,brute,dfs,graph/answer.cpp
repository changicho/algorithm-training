#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> map[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> n >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        sort(map[i].begin(), map[i].end());
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (auto nxt : map[i]) {
            if (nxt < i) continue;
            int v1 = nxt;
            int v2 = i;
            
            if (map[v1].size() > map[v2].size()) {
                swap(v1, v2);
            }

            for (auto k : map[v1]) {
                cnt += binary_search(map[v2].begin(), map[v2].end(), k);
            }
        }
    }

    cout << cnt / 3;
}