# 121. Best Time to Buy and Sell Stock

[링크](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 길이는 최대 10^5 이다.

브루트 포스 방법을 사용할 경우 시간 복잡도는 O(N^2) 이다.

그리디 알고리즘을 이용할 경우 시간 복잡도는 O(N) 이다.

### 공간 복잡도

브루트 포스, 그리디 모두 별도의 공간이 필요하지 않으므로 공간 복잡도는 O(1) 이다.

### 그리디 알고리즘

다음과 같은 숫자 a, b, c1 ... 가 있다고 하자 (a < b < c1, c2...)

다음과 같은 경우를 살펴보자

```cpp
c1, ... , a, c2, ... , b, c3, ...
```

이 경우 a가 b보다 먼저 나오므로 정답은 a와 c2, c3의 차이인 경우이다.

```cpp
c1, ... , b, c2, ... , a, c3, ...
```

이 경우에도 정답은 a와 c3의 차이 혹은 b와 c2의 차이인 경우이다.

이를 일반화 하면 현재까지 방문한 범위에서 첫번째 값을 가장 작은 값으로 유지되도록 범위를 늘려나가며 방문한다.

이 때 첫번째 값보다 작은 현재 값이 나온 경우 범위를 초기화하고 새로 범위를 생성한다. (작은 현재 값이 첫번째 값이 되도록)

각 구간별로 탐색을 이어나가며 정답을 갱신해간다.

```cpp
int maxProfit(vector<int>& prices) {
  int minimum = 10001;
  int answer = 0;
  for (int price : prices) {
    if (price < minimum) {
      minimum = price;
      // minimum을 초기화 하는 경우는 price - minimum이 정답이 될 수 없으므로
      // continue를 통해 최적화 할 수 있다.
      continue;
    }
    answer = max(price - minimum, answer);
  }

  return answer;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|     112      |

## 고생한 점
