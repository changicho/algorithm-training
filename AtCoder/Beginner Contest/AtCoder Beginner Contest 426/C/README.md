# C - Upgrade Required

[링크](https://atcoder.jp/contests/abc426/tasks/abc426_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

입력받은 컴퓨터의 갯수를 N, 쿼리의 수를 Q라 하자.

현재 가장 낮은 버전을 저장하며, 쿼리마다 가장 낮은 버전에서 부터 업그레이드가 필요한 버전까지 순회한다. 이후 가장 낮은 버전을 갱신한다.

이 경우 모든 쿼리에서 버전에 대해서는 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(Q + N)이다.

### 공간 복잡도

각 버전마다 갯수를 저장하는데 O(N)의 공간 복잡도를 사용한다.

정답에 O(Q)의 공간 복잡도를 사용한다.

### 내부 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |  O(Q + N)   |  O(Q + N)   |

매 쿼리를 수행하면 가장 낮은 버전이 변동된다.

따라서 현재 쿼리 X, Y에 대해서 X 이하의 값을 모두 순회할 필요 없이 이전까지 가장 낮은 버전부터 순회하면 된다.

이후 현재 업데이트된 버전의 갯수를 Y에 더해준다.

```cpp
auto solution(int n, int qSize, vector<pair<int, int>> &queries) {
  vector<int> os(n + 1);
  for (int i = 1; i <= n; i++) {
    os[i] = 1;
  }

  int minimum = 1;
  vector<int> answer;

  for (pair<int, int> &q : queries) {
    int x = q.first;
    int y = q.second;

    if (x < minimum) {
      answer.push_back(0);
      continue;
    }

    int count = 0;
    for (int i = minimum; i <= x; i++) {
      count += os[i];
      os[i] = 0;
    }

    os[y] += count;

    minimum = x + 1;
    answer.push_back(count);
  }

  return answer;
}
```

## 고생한 점
