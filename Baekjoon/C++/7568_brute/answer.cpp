#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct person {
    int x;
    int y;
};

void solution() {
    int N;
    cin >> N;

    vector<struct person> people(N);
    vector<int> answer;
    for (int i = 0; i < N; i++) {
        cin >> people[i].x >> people[i].y;
    }

    for (person p : people) {
        int rank = 0;
        for (person t : people) {
            if (p.x < t.x && p.y < t.y) {
                rank++;
            }
        }
        answer.push_back(rank + 1);
    }

    for (int i : answer) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}