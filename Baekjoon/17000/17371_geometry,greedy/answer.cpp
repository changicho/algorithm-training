#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

long long getLength(Axis a, Axis b) {
  return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

void solution() {
  int N;
  cin >> N;

  vector<Axis> points(N);
  for (int i = 0; i < N; i++) {
    cin >> points[i].x >> points[i].y;
  }

  long long distance = 1e10;
  long long answerIndex = 0;

  // 가장 가까운 편의시설까지의 거리와 가장 먼 편의시설까지의 거리의 평균이 최소가 되는 좌표로 이사
  for (int from = 0; from < N; from++) {
    long long longest = -1;
    long long longestIndex = from;

    for (int to = 0; to < N; to++) {
      if (to == from) {
        continue;
      }

      long long currentLength = getLength(points[from], points[to]);
      if (longest < currentLength) {
        longest = currentLength;
        longestIndex = from;
      }
    }

    if (distance > longest) {
      distance = longest;
      answerIndex = longestIndex;
    }
  }

  cout << points[answerIndex].x << " " << points[answerIndex].y << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}