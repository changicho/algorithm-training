# B - Which is ahead?

[링크](https://atcoder.jp/contests/abc342/tasks/abc342_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열 P의 크기를 N, 쿼리의 크기를 Q라 하자.

배열 P를 순회하며 각 인원마다의 위치를 저장하고 쿼리를 수행한다.

이에 O(N + Q)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 인원의 위치를 저장하는데 O(N)의 공간 복잡도가 필요하다.

정답 배열을 생성하는데 O(Q)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |  O(N + Q)   |  O(N + Q)   |

P를 순회하며 각 인원들의 위치를 저장한다.

이후 각 쿼리를 순회하며 앞선 인원을 찾아 정답 배열에 저장한다.

```cpp
vector<int> solution(vector<int> &positions, vector<vector<int>> &queries) {
  int size = positions.size();

  vector<int> answer;
  vector<int> orders(size + 1);
  for (int i = 0; i < size; i++) {
    orders[positions[i]] = i + 1;
  }

  for (vector<int> &query : queries) {
    int a = query[0], b = query[1];

    if (orders[a] < orders[b]) {
      answer.push_back(a);
    } else {
      answer.push_back(b);
    }
  }

  return answer;
}
```

## 고생한 점
