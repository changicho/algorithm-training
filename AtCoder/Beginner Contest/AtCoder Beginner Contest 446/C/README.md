# C - Omelette Restaurant

[링크](https://atcoder.jp/contests/abc446/tasks/abc446_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

각 배열의 크기를 N, 유통기한 날짜를 D라 하자.

각 날짜마다 폐기하는 계란과 구매하는 계란, 사용하는 계란의 수를 시뮬레이션한다.

이를 위해 deque를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

deque에 O(D)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     104      |    O(N)     |    O(D)     |

각 날짜별로 계란을 구매하고, 계란을 사용하고, 계란을 폐기하는 과정을 시뮬레이션한다.

이 때 D일 이상 지난 계란을 관리하기 위해 deque를 사용한다.

```cpp
long long solution(int n, int d, vector<long long>& a, vector<long long>& b) {
  long long answer = 0;

  deque<pair<int, long long>> q;

  for (int i = 0; i < n; i++) {
    q.push_back({i, a[i]});

    int need = b[i];
    while (!q.empty() && need > 0) {
      auto [before, count] = q.front();
      q.pop_front();
      if (count <= need) {
        need -= count;
      } else {
        q.push_front({before, count - need});
        need = 0;
      }
    }

    while (!q.empty() && q.front().first + d <= i) {
      q.pop_front();
    }
  }

  while (!q.empty()) {
    auto [before, count] = q.front();
    q.pop_front();
    answer += count;
  }

  return answer;
}
```

## 고생한 점
