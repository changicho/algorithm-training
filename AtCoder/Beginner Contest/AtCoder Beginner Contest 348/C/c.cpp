#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Bean {
  int a, c;
};

int solution(int size, vector<Bean> &beans) {
  unordered_map<int, int> color2minA;

  for (Bean &bean : beans) {
    if (color2minA.find(bean.c) == color2minA.end()) {
      color2minA[bean.c] = bean.a;
    } else {
      color2minA[bean.c] = min(color2minA[bean.c], bean.a);
    }
  }

  int answer = -1;

  for (auto &it : color2minA) {
    answer = max(answer, it.second);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<Bean> beans(N);

  for (int i = 0; i < N; i++) {
    cin >> beans[i].a >> beans[i].c;
  }

  int answer = solution(N, beans);

  cout << answer << endl;

  return 0;
}