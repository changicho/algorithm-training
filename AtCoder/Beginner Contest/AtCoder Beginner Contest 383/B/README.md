# B - ARC Division

[링크](https://atcoder.jp/contests/abc384/tasks/abc384_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 배열 arcs의 크기를 N이라 하자.

시뮬레이션을 수행할 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 경우마다 레이팅을 변화시켜야 하므로 O(1)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

각 arc별로 순회하며 레이팅을 변화시킨다.

```cpp
struct ARC {
  int div, performance;
};

// In ARC Div. 1, 1600 and 2799
// In ARC Div. 2, 1200 and 2399
int solution(int n, int rating, vector<ARC> &arcs) {
  int answer = rating;

  vector<pair<int, int>> divs = {{1600, 2799}, {1200, 2399}};

  for (ARC &arc : arcs) {
    int left = divs[arc.div - 1].first, right = divs[arc.div - 1].second;

    if (left <= answer && answer <= right) {
      answer += arc.performance;
    }
  }

  return answer;
}
```

## 고생한 점
