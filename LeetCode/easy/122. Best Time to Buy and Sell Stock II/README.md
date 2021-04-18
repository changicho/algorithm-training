# 122. Best Time to Buy and Sell Stock II

[링크](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

prices의 길이는 최대 3 \* 10^4이다.

브루트 포스 방법으로 풀이할 경우 시간 복잡도는 O(N^2) 이므로 제한시간 내에 아슬아슬하다.

따라서 그리디 알고리즘으로 풀이한다.

### 공간 복잡도

한번 순회하며 해를 구하기 때문에 별도의 공간이 필요하지 않다.

따라서 공간 복잡도는 O(1) 이다.

### 변곡점

주어지는 prices들로 꺽은선 그래프를 그려볼 경우 변곡점이 여러개 나타나는 그래프를 찾을 수 있다.

결국 낮은 점에 사서 높은 점에서 팔아야 하므로 이 방법을 이용한다.

예를 들어 a, b, c 점이 있다고 해보자

```javascript
[a, b, c]; // (a < b < c)
```

정답이 될 수 있는 경우는 a점에 사서 b, c에 팔거나, b점에 사서 c에서 파는 3가지 경우 중 하나이다.

이 때 정담은 a, c일 수 밖에 없는데 이는 대소관계가 명확하므로 c-a가 가장 큰 차이이기 때문이다.

만약 다음과 같은 경우는 어떨까?

```javascript
[a, c, b, d]; // (a < b < c < d)
```

이 경우에 d-a 혹은 c-a + d-b가 정답이 될 수 있다.

여기서 d-a보다는 c-a + d-b가 더 크다는 것이 증명되는데 이는 c가 b보다 크기 때문이다.

따라서 변곡점들을 구하고, 그 변곡점들의 차이를 더해나가면 정답이 된다.

valley는 기울기가 -에서 +로 변하는 변곡점, peek은 기울기가 +에서 -로 변하는 변곡점이라고 하자

```cpp
int maxProfit(vector<int>& prices) {
  int size = prices.size();
  int answer = 0;
  int i = 0;

  while (i < size - 1) {
    // find valley
    while (i < size - 1 && prices[i] >= prices[i + 1]) {
      i++;
    }
    int valley = prices[i];

    // find peek
    while (i < size - 1 && prices[i] <= prices[i + 1]) {
      i++;
    }
    int peek = prices[i];

    answer += peek - valley;
  }

  return answer;
}
```

### one pass

위 방법에서 a, b, c 점이 있고 이 구간의 정답을 구한다고 가정해보자.

```javascript
[a, b, c]; // (a < b < c)
```

c - a는 b - a + c - b 두 구간의 합임을 알 수 있다.

이 점에서 알 수 있듯이 모든 변곡점 구간에서 차이는 각 두 점마다의 차의의 합이다.

따라서 정답을 더 간단한 방법으로 구할 수 있다.

```cpp
int maxProfit(vector<int>& prices) {
  int size = prices.size();
  int answer = 0;

  for (int i = 1; i < size; i++) {
    // 현재값이 이전값보다 증가한 경우만 더함
    if (prices[i - 1] < prices[i]) {
      answer += prices[i] - prices[i - 1];
    }
  }
  return answer;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
