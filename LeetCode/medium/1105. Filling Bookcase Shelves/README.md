# 1105. Filling Bookcase Shelves

[링크](https://leetcode.com/problems/filling-bookcase-shelves/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 배열 books의 길이를 N, 책장의 너비를 W라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이므로 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전의 결과를 이용할 경우 각 index마다 너비에 대해 탐색할 수 있다.

이 경우 O(N \* W)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 index마다의 최소 높이를 저장해야 하므로 dp배열을 사용한다.

이 경우 O(N)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(N \* W)  |    O(N)     |

다음과 같은 dp 배열을 선언한다.

```cpp
int dp[index]; // index번째 책까지 책장을 채웠을 때 최소 높이

dp[0] = books[0][1]; // 첫번째 책의 높이

dp[i] = dp[i-1] + books[i][1]; // i번째 책을 새로운 책장에 넣었을 때의 높이
// j : i-1 ~ 0
dp[i] = dp[j-1] + max(height, books[j][1]);
```

현재 book의 index를 i라 하자. 현재 책을 새로운 책장에 넣었을 때와 이전 책장에 넣었을 때의 높이를 비교한다.

이 때 이전 책장에 넣을 수 있는 경우에만 dp값을 갱신한다.

```cpp
int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
  int size = books.size();

  vector<int> dp(size, 0);

  for (int i = 0; i < size; i++) {
    int width = books[i][0], height = books[i][1];
    dp[i] = (i > 0 ? dp[i - 1] : 0) + height;

    for (int j = i - 1; j >= 0; j--) {
      width += books[j][0];

      if (width > shelfWidth) {
        break;
      }

      height = max(height, books[j][1]);
      dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + height);
    }
  }

  return dp[size - 1];
}
```

## 고생한 점
