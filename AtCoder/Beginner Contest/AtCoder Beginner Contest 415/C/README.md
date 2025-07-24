# C - Mixture

[링크](https://atcoder.jp/contests/abc415/tasks/abc415_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

문자열 S의 길이는 2^N - 1로 고정이다.

BFS를 이용해 가능한 모든 조합을 탐색한다.

이에 O(2^N \* N)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS에 O(2^N)의 공간 복잡도를 사용한다.

### 완전 탐색 (BFS)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     108      | O(2^N \* N) |   O(2^N)    |

각 상태는 2가지가 존재한다.

- 현재 혼합된 화합물질
- 현재 사용할 수 있는 화합물질

각 상태마다 혼합된 화합물질의 상태가 위험한 화합물질인지 확인하며 탐색을 진행한다.

이를 BFS를 이용해 완전 탐색 후 정답에 도달 가능한지 판단한다.

이 때 이미 방문한 상태는 방문하지 않도록 해 중복 탐색을 방지한다.

```cpp
struct Status {
  int mixed = 0;
  int canUse = 0;
};

bool solution(int n, string &s) {
  bool answer = false;

  unordered_set<int> dangerous;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      dangerous.insert(i + 1);
    }
  }

  vector<int> chemicals;
  for (int i = 1; i <= n; i++) {
    chemicals.push_back(i);
  }

  queue<Status> q;
  q.push({0, (1 << n) - 1});

  unordered_set<long long> visited;
  visited.insert(0);

  while (!q.empty() && !answer) {
    Status cur = q.front();
    q.pop();

    for (int &chem : chemicals) {
      if (cur.canUse & (1 << (chem - 1)) == 0) continue;
      if (cur.mixed & (1 << (chem - 1))) continue;

      Status next = cur;
      next.canUse -= (1 << (chem - 1));
      next.mixed += (1 << (chem - 1));

      if (visited.count(next.mixed) > 0) continue;
      visited.insert(next.mixed);

      if (dangerous.count(next.mixed)) continue;
      if (next.canUse == 0) {
        answer = true;
        break;
      }
      q.push(next);
    }
  }

  return answer;
}
```

## 고생한 점
