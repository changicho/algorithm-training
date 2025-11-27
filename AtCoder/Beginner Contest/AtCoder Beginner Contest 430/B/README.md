# B - Count Subgrid

[링크](https://atcoder.jp/contests/abc430/tasks/abc430_b)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

입력받은 두 수를 N, M이라 하자.

2차원 격자에서 2차원 패턴을 모두 검색하는데 O(N^2 \* M^2)의 시간 복잡도를 사용한다.

이를 hash set으로 관리할 경우 저장에 O(M^2)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N^2 \* M^2)입니다.

### 공간 복잡도

hash set에 O(N^2 \* M^2)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |  시간 복잡도  |  공간 복잡도  |
| :----------: | :-----------: | :-----------: |
|      1       | O(N^2 \* M^2) | O(N^2 \* M^2) |

완전 탐색을 이용해 M^2 크기의 패턴을 모두 hash set에 저장한다.

```cpp
auto solution(int size, int m, vector<string>& board) {
  unordered_set<string> patterns;

  for (int y = 0; y <= size - m; y++) {
    for (int x = 0; x <= size - m; x++) {
      string pattern = "";

      for (int yy = y; yy < y + m; yy++) {
        pattern += board[yy].substr(x, m);
        pattern += "$";
      }

      patterns.insert(pattern);
    }
  }

  return patterns.size();
}
```

## 고생한 점
