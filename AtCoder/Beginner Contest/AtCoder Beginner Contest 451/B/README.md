# B - Personnel Change

[링크](https://atcoder.jp/contests/abc451/tasks/abc451_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

사람의 수를 N, 부서의 수를 M이라 하자.

각 부서마다 이전, 이후 인원 수를 계산하는데 O(N)의 시간 복잡도를 사용한다.

이후 부서를 순회하며 인원 수 차이를 계산하는데 O(M)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

각 부서를 위한 배열을 하나씩 만들어 O(M)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |  O(N + M)   |    O(M)     |

각 인원마다 이전, 이후 이동 부서에 숫자를 증가시킨다.

이후 각 부서를 순회하며 차이를 구한다.

```cpp
vector<int> solution(int n, int m, vector<pair<int, int>>& ab) {
  vector<int> answer;

  vector<int> first(m);
  vector<int> second(m);
  for (int i = 0; i < n; i++) {
    first[ab[i].first - 1]++;
    second[ab[i].second - 1]++;
  }

  for (int i = 0; i < m; i++) {
    answer.push_back(second[i] - first[i]);
  }

  return answer;
}
```

## 고생한 점
