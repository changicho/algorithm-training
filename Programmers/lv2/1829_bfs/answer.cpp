#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

struct Color {
  int color, count;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool compare(Color a, Color b) {
  return a.count > b.count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
  vector<Color> colors;
  bool visited[100][100] = {
      0,
  };

  queue<Axis> q;

  for (int y = 0; y < m; y++) {
    for (int x = 0; x < n; x++) {
      if (picture[y][x] == 0 || visited[y][x]) {
        continue;
      }
      int color = picture[y][x];
      int count = 0;
      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        if (picture[cur.y][cur.x] != color) continue;

        visited[cur.y][cur.x] = true;
        count += 1;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) {
            continue;
          }
          q.push(next);
        }
      }

      colors.push_back({color, count});
    }
  }

  sort(colors.begin(), colors.end(), compare);

  int number_of_area = colors.size();
  int max_size_of_one_area = 0;

  if (colors.size() > 0) {
    max_size_of_one_area = colors[0].count;
  }

  vector<int> answer(2);

  answer[0] = number_of_area;
  answer[1] = max_size_of_one_area;
  return answer;
}

struct TestCase {
  int m, n;
  vector<vector<int>> picture;
  vector<int> answer;
};

int main() {
  vector<TestCase> tcs = {{6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}}, {4, 5}}};

  for (TestCase tc : tcs) {
    vector<int> answer = solution(tc.m, tc.n, tc.picture);

    cout << "my answer : ";
    for (int i : answer) {
      cout << i << " ";
    }
    cout << ", real answer : ";

    for (int i : tc.answer) {
      cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}
