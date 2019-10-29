#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct axis {
    int x;
    int y;
};

bool compare(axis a, axis b) {
    if (a.x < b.x) {
        return true;
    }

    if (a.x == b.x && a.y < b.y) {
        return true;
    }

    return false;
}

void solution() {
    int N;
    cin >> N;

    vector<axis> dots(N);

    for (int i = 0; i < N; i++) {
        cin >> dots[i].x >> dots[i].y;
    }

    sort(dots.begin(), dots.end(), compare);

    for (axis a : dots) {
        cout << a.x << " " << a.y << "\n";
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