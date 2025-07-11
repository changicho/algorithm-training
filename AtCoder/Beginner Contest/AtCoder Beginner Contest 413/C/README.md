# C - Large Queue

[링크](https://atcoder.jp/contests/abc413/tasks/abc413_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

입력받은 쿼리의 수를 Q, 저장되는 수의 크기를 N이라 하자.

모든 경우를 직접 구현할 경우 O(Q \* N)의 시간 복잡도를 사용한다.

큐에 숫자를 압축해 저장할 경우 O(Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 쿼리마다 숫자를 저장하는데 최대 O(Q)의 공간 복잡도를 사용한다.

### 압축 저장

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      47      |    O(Q)     |    O(Q)     |

각 쿼리마다 숫자를 저장할 때, 현재 숫자와 갯수를 묶어 저장한다.

이후 숫자를 제거하는 쿼리를 수행할 때, 제거해야 하는 갯수와 큐에 저장된 숫자의 갯수를 비교하여, 제거해야 하는 갯수만큼 제거한다.

만약 갯수가 사라진 경우 큐에서 제거하며, 갯수가 남아있는 경우 갯수만큼 감소시킨다.

이 과정에서 반환하는 값을 계산한다.

```cpp
vector<long long> solution(int size, vector<vector<int>> &queries) {
  vector<long long> answer;

  deque<pair<int, int>> dq;

  for (vector<int> &query : queries) {
    if (query[0] == 1) {
      int a = query[1];
      int b = query[2];

      dq.push_back({a, b});
    } else {
      long long sum = 0;
      int a = query[1];

      while (!dq.empty() && a > 0) {
        int diff = min(a, dq.front().first);
        a -= diff;

        dq.front().first -= diff;

        sum += (long long) dq.front().second * diff;
        if (dq.front().first == 0) {
          dq.pop_front();
        }
      }

      answer.push_back(sum);
    }
  }

  return answer;
}
```

## 고생한 점
