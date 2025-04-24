# B - Restaurant Queue

[링크](https://atcoder.jp/contests/abc402/tasks/abc402_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

쿼리의 크기를 Q라 하자.

큐를 사용해 각 경우마다 삽입과 삭제를 O(1)에 수행할 수 있다.

이 경우 O(Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

큐에 O(Q)의 공간 복잡도를 사용한다.

### 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(Q)     |    O(Q)     |

```cpp
vector<int> solution(vector<vector<int>> &queries) {
  queue<int> q;
  vector<int> answer;
  for (auto &query : queries) {
    if (query[0] == 1) {
      q.push(query[1]);
    } else {
      answer.push_back(q.front());
      q.pop();
    }
  }

  return answer;
}
```

## 고생한 점
