# 309. Best Time to Buy and Sell Stock with Cooldown

[링크](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-coolDown/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열안의 값의 개수를 N이라 하자.

모든 경우를 탐색할 경우 현재 경우에서 coolDown, buy, sell 3가지 경우가 존재한다.

직접 모든 경우를 탐색할 경우 시간 복잡도는 O(N^3)이 되며 이는 시간 내에 불가능하다.

따라서 동적 계획법을 이용해 한번의 순회로 정답을 구한다.

이 경우 시간 복잡도는 O(N)이 된다.

### 공간 복잡도

각 index마다의 최선의 값을 구한다.

여기서 우리가 선택할 수 있는 경우는 3가지가 된다.

- coolDown
- buy
- sell

각 경우마다 dp배열을 생성해 이용한다.

이 경우 공간 복잡도는 O(N)이 된다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

다음 3가지 경우에서 다음 상태로 넘어갈 수 있는 경우는 다음과 같다.

- coolDown : coolDown, Buy
- buy : buy, sell
- sell : coolDown

각 dp배열을 다음과 같이 정의하자.

```cpp
restDp[i] // i번째 까지 최대값
buyDp[i]; // i번째까지 물건을 산 경우 중 가장 이익이 큰 경우
sellDp[i]; // i번째 가격에 주식을 팔았을 때의 값
```

각 경우에 대한 일반식은 다음과 같다.

```cpp
buyDp[i] = max(buyDp[i - 1], coolDownDp[i - 1] - prices[i]);
coolDownDp[i] = max(coolDownDp[i - 1], sellDp[i - 1]);
sellDp[i] = buyDp[i - 1] + prices[i];
```

여기서 sell의 경우는 직전 buy를 해야만 할 수 있으므로 일반식이 다음과 같이 나온다.

또한 구매의 경우 그만큼 돈을 사용하는 것이므로 음수가 된다.

각 경우마다 초기값은 다음과 같다.

```cpp
coolDownDp[0] = 0; // 아무것도 안하는 경우
buyDp[0] = -prices.front(); // 첫번째 주식을 구매한 경우이므로
sellDp[0] = 0; // 팔 주식이 없다.
```

이를 이용해 정답을 구한다.

이 때 정답은 맨 마지막 주식을 buy한 경우는 절대 될 수 없음에 유의한다.

```cpp
int maxProfit(vector<int>& prices) {
  int size = prices.size();
  vector<int> coolDownDp(size, 0);
  vector<int> buyDp(size, 0);
  vector<int> sellDp(size, 0);

  // restDp[i] // i번째 까지 최대값
  // buyDp[i]; // i번째까지 물건을 산 경우 중 가장 이익이 큰 경우
  // sellDp[i]; // i번째 가격에 주식을 팔았을 때의 값

  coolDownDp[0] = 0;
  buyDp[0] = -prices.front();
  sellDp[0] = 0;

  for (int i = 1; i < size; ++i) {
    buyDp[i] = max(buyDp[i - 1], coolDownDp[i - 1] - prices[i]);
    coolDownDp[i] = max(coolDownDp[i - 1], sellDp[i - 1]);
    sellDp[i] = buyDp[i - 1] + prices[i];
  }

  // 물건을 사는 경우는 절대 최대값이 될 수 없음
  int answer = max(coolDownDp.back(), sellDp.back());
  return answer;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

위 동적 계획법에서 직전의 값만 사용함에 유의한다.

따라서 일반식을 다음과 같이 나타낼 수 있다. (갱신되는 값의 순서에 주의)

```cpp
buy = max(buy, coolDown - prices[i]);
coolDown = max(coolDown, sell);
sell = buy + prices[i];
```

이를 이용해 정답을 갱신한다.

```cpp
int maxProfit(vector<int>& prices) {
  int size = prices.size();

  int coolDown = 0;
  int buy = -prices.front();
  int sell = 0;

  for (int i = 1; i < size; ++i) {
    buy = max(buy, coolDown - prices[i]);
    coolDown = max(coolDown, sell);
    sell = buy + prices[i];
  }

  return max(sell, coolDown);
}
```

## 고생한 점
