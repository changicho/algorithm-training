# B - Pepper Addiction

[링크](https://atcoder.jp/contests/abc448/tasks/abc448_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

두 배열의 크기를 N, M이라 하자.

두 값을 포함한 배열을 순회하며 정답을 구하는데 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(M)     |    O(1)     |

요리마다 순회하며 각 종류의 pepper를 최대한 사용한다.

```cpp
auto solution(int size, int cSize, vector<int>& c, vector<pair<int, int>>& ab) {
  int answer = 0;

  for (pair<int, int>& p : ab) {
    int a = p.first;
    int b = p.second;

    answer += min(c[a - 1], b);
    c[a - 1] -= min(c[a - 1], b);
  }

  return answer;
}
```

## 고생한 점
