# B - Gift

[링크](https://atcoder.jp/contests/abc462/tasks/abc462_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

인원의 수를 N, 선물의 수를 M이라 하자.

순회 후 선물받은 인원에 대해서 분류 할 수 있다.

이 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N + M)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |  O(N + M)   |  O(N + M)   |

배열을 순회하며 선물을 받은 인원을 기준으로 선물을 준 사람들을 분류한다.

```cpp
vector<vector<int>> solution(int n, vector<vector<int>>& arr) {
  vector<vector<int>> answer(n);

  for (int i = 0; i < n; i++) {
    for (int& cur : arr[i]) {
      answer[cur - 1].push_back(i + 1);
    }
  }

  for (int i = 0; i < n; i++) {
    answer[i].insert(answer[i].begin(), answer[i].size());
  }

  return answer;
}
```

## 고생한 점
