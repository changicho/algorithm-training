# B - Adjacency Matrix

[링크](https://atcoder.jp/contests/abc343/tasks/abc343_b)

| 난이도 |
| :----: |
|  150   |

## 설계

### 시간 복잡도

입력받은 정점의 갯수를 N이라 하자.

그래프는 N^2 크기로 주어지므로 이를 순회하며 정답을 구하는 데 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프에 O(N^2)의 공간 복잡도를 사용한다.

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |   O(N^2)    |   O(N^2)    |

그래프를 순회하며 각 정점마다 연결된 다른 정접을 오름차순으로 구한다.

```cpp
vector<vector<int>> solution(int n, vector<vector<int>> g) {
  vector<vector<int>> answer;

  for (int from = 0; from < n; from++) {
    vector<int> cur;
    for (int to = 0; to < n; to++) {
      if (g[from][to] == 1) {
        cur.push_back(to + 1);
      }
    }

    answer.push_back(cur);
  }

  return answer;
}
```


## 고생한 점
