# D - Count Subgrid Sum = K

[링크](https://atcoder.jp/contests/abc461/tasks/abc461_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC라 하자.

한 축의 범위를 고정 후 나머지 축을 이동시키며 prefix sum을 이용해 정답을 구할 수 있다.

이 경우 O(R \* C^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum에 O(RC)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     2511     | O(R \* C^2) |    O(RC)    |

2차원 좌표에서 직사각형의 x범위를 모두 탐색한다.

이후 해당 범위에 대해서 y축에 대해 증가시켜가며 prefix sum을 구하며 조건을 만족하는 갯수를 정답에 더한다.

```cpp
using ll = long long;

ll solution(int rows, int cols, int k, vector<string>& board) {
  ll answer = 0;

  int prefixs[502][502] = {
      0,
  };
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      prefixs[y + 1][x + 1] = prefixs[y + 1][x] + board[y][x] - '0';
    }
  }

  int counts[250001] = {
      0,
  };
  for (int x = 0; x < cols; x++) {
    for (int xx = x; xx < cols; xx++) {
      counts[0] = 1;
      int sum = 0;

      for (int y = 0; y < rows; y++) {
        int curLine = prefixs[y + 1][xx + 1] - prefixs[y + 1][x];

        sum += curLine;

        if (sum - k >= 0) {
          answer += counts[sum - k];
        }

        counts[sum]++;
      }

      memset(counts, 0, sizeof(counts));
    }
  }

  return answer;
}
```

## 고생한 점
