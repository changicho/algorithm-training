# 714. Best Time to Buy and Sell Stock with Transaction Fee

[링크](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(2^N)만큼의 시간이 소요되며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 한번의 순회에 문제를 해결한다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

매 index마다 dp값을 저장할 경우 O(N)의 공간 복잡도가 필요하다.

그러나 직전의 값만을 필요로 하므로 O(1)의 공간복잡도로 해결이 가능하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      96      |    O(N)     |    O(N)     |

물건을 샀을때와 팔았을 때 2가지 경우에 대한 값이 필요하다.

따라서 다음과 같은 2개의 dp배열을 만든다.

```cpp
buyDp[i]; // i번째 까지 물건을 샀을 때의 최대값
sellDp[i] // i번째 까지 물건을 팔았을 때의 최대값
```

위 값들의 초기값은 다음과 같다.

```cpp
sellDp[0] = 0; // 팔 가격이 아무것도 없음
buyDp[0] = -prices[i]; // 첫번째 물건을 삼
```

일반식은 다음과 같이 나타낼 수 있다.

```cpp
buyDp[i] = max(buyDp[i - 1], sellDp[i - 1] - prices[i]);
sellDp[i] = max(sellDp[i - 1], buyDp[i - 1] + prices[i] - fee);
```

이를 이용해 정답을 구할 경우 다음과 같다.

```cpp
int maxProfit(vector<int>& prices, int fee) {
  int size = prices.size();

  vector<int> buyDp(size, 0);  // i번째 까지 물건을 샀을 때의 최대값
  vector<int> sellDp(size, 0);  // i번째 까지 물건을 팔았을 때의 최대값

  buyDp.front() = -prices.front();

  for (int i = 1; i < size; i++) {
    buyDp[i] = max(buyDp[i - 1], sellDp[i - 1] - prices[i]);
    sellDp[i] = max(sellDp[i - 1], buyDp[i - 1] + prices[i] - fee);
  }

  return sellDp.back();
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     142      |    O(N)     |    O(1)     |

위 동적 계획법 풀이방법에서 직전의 값만을 사용하므로

직전값만을 저장해 공간복잡도 O(1)의 방법으로 풀이가 가능하다.

```cpp
int maxProfit(vector<int>& prices, int fee) {
  int size = prices.size();
  int sell = 0, buy = -prices.front();

  for (int i = 1; i < size; ++i) {
    sell = max(sell, buy + prices[i] - fee);
    buy = max(buy, sell - prices[i]);
  }

  return sell;
}
```

## 고생한 점
