# 5881. Bookshelf

[링크](https://www.acmicpc.net/problem/5881)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| 골드 4 |   80.282    |       1       |

## 설계

### 시간 복잡도

입력받은 책 배열의 크기를 N이라 하자. (N <= 2,000)

모든 경우를 직접 수행할 경우 O(2^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 현재까지 책을 쌓은 높이를 최소 높이를 구하고, 이를 이용해 다음 최소 높이들을 구한다.

이 경우 현재 값을 갱신하는데 이전 값들을 순회해야 하므로 O(N)의 시간 복잡도를 사용하며 이를 N번 반복하므로 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 index까지의 최소값을 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

## 동적 계획법 & 누적 합

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(N^2)    |    O(N)     |

현재 index까지 책을 쌓았을 때의 최소 높이를 알 경우 다음과 같이 현재 index까지 책을 쌓았을 때의 최소 높이를 구할 수 있다.

- 0 ~ index-1까지 순회하며 이를 before라고 하자.
- before까지 쌓은 높이 + before+1 ~ index까지 최대 높이를 구한다.
- (현재 선반에 before+1 ~ index)까지 책을 둠
- 이 중 최소값으로 현재 dp값을 갱신한다

이 때 현재 선반의 책의 너비의 합이 L을 넘지 않아야 한다

따라서 해당 구간의 너비의 합을 빠르게 구하기 위해 누적합을 사용한다.

또한 현재 선반에 놓을 책의 최대 높이를 구해야 한다.

이를 위해 before를 index에 가까운 순서부터 0까지 순회하며 최대 높이를 갱신한다.

만약 0 ~ index까지 책의 너비의 합이 L을 넘지 않는 경우 해당 경우 또한 갱신한다.

```cpp
struct Book {
  int h, w;
};

int solution(vector<Book> &books, int length) {
  int size = books.size();

  int heightSum = accumulate(books.begin(), books.end(), 0,
                             [](int acc, Book &book) { return acc + book.h; });

  vector<int> prefix(books.size(), 0);
  vector<int> dp(books.size(), heightSum);

  for (int i = 0; i < size; i++) {
    prefix[i] = (i > 0 ? prefix[i - 1] : 0) + books[i].w;
  }

  dp[0] = books[0].h;

  for (int i = 1; i < size; i++) {
    int curMaxH = books[i].h;

    for (int before = i - 1; before >= 0; before--) {
      if (prefix[i] - prefix[before] > length) break;

      dp[i] = min(dp[i], dp[before] + curMaxH);

      curMaxH = max(curMaxH, books[before].h);
    }

    if (prefix[i] <= length) {
      dp[i] = min(curMaxH, dp[i]);
    }
  }

  return dp.back();
}
```

## 동적 계획법

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(N^2)    |    O(N)     |

위 방법에서 누적합을 미리 구하지 않고 최대 높이를 계산하며 너비를 더한다.

```cpp
struct Book {
  int h, w;
};

int solution(vector<Book> &books, int length) {
  int size = books.size();

  vector<int> dp(books.size(), INT_MAX);

  dp[0] = books[0].h;

  for (int i = 1; i < size; i++) {
    int curMaxH = books[i].h;
    int widthSum = books[i].w;

    for (int before = i - 1; before >= 0; before--) {
      if (widthSum > length) break;
      widthSum += books[before].w;

      dp[i] = min(dp[i], dp[before] + curMaxH);

      curMaxH = max(curMaxH, books[before].h);
    }

    if (widthSum <= length) {
      dp[i] = min(curMaxH, dp[i]);
    }
  }

  return dp.back();
}
```

## 고생한 점
