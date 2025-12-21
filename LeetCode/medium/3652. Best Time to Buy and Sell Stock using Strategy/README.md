# 3652. Best Time to Buy and Sell Stock using Strategy

[링크](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

prefix sum을 사용해 특정 구간의 연산결과를 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum에 O(N)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(N)     |

특정 연산을 수행하는 구간을 midPart라 하고 해당 구간 이전을 leftPart, 이후를 rightPart라 하자.

이 경우 정답에 포함되는 구간은 다음과 같이 표현할 수 있다.

```javascript
[...leftPart, ...midPart, ...rightPart]
```

이 때 leftPart와 rightPart의 값은 prefix sum을 통해 미리 구해둘 수 있다.

또한 midPart의 경우 해당 구간의 prices의 앞 절반은 더하지 않고 뒤 절반만 더하면 되므로 prefix sum을 통해 구할 수 있다.

따라서 미리 prefix sum을 구한 뒤 순회를 이용해 각 구간에 대한 값을 구해 최댓값을 갱신한다.

이 때 해당 연산을 한번도 수행하지 않고 주어진 prices와 strategy를 이용해 구한 값도 정답이 될 수 있다.

```cpp
long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
  int size = prices.size();

  vector<long long> pricePrefixes(size + 1, 0);
  vector<long long> profitPrefixes(size + 1, 0);
  for (int i = 0; i < size; i++) {
    pricePrefixes[i + 1] = pricePrefixes[i] + prices[i];
    profitPrefixes[i + 1] = profitPrefixes[i] + prices[i] * strategy[i];
  }

  long long answer = profitPrefixes[size];
  for (int i = 0; i <= size - k; i++) {
    int left = i, right = i + k - 1;
    long long leftPart = profitPrefixes[left];
    long long rightPart = profitPrefixes[size] - profitPrefixes[right + 1];

    long long midPart = pricePrefixes[right + 1] - pricePrefixes[right - k / 2 + 1];

    long long cur = leftPart + midPart + rightPart;
    answer = max(answer, cur);
  }
  return answer;
}
```

## 고생한 점
