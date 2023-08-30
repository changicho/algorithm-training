# 2483. Minimum Penalty for a Shop

[링크](https://leetcode.com/problems/minimum-penalty-for-a-shop/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 customers의 길이를 N이라 하자. (N <= 10^5)

특정 시간에 문을 닫는 경우를 모두 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

이전시간에서 현재시간으로 문을 닫는 시간을 변경할 때 하나의 customer에 대해서만 값이 변경된다.

이를 이용해 한번 순회하며 각 시간에 대해서 최소 비용을 갱신한다. 이 경우 O(N)의 시간 복잡도를 사용한다.

이 때 실제 cost를 이용해 정답을 구할 경우 전처리에 O(N)의 시간 복잡도를 사용한다.

감소하는 cost를 penalty로 설정하고 정답을 구할 경우 전처리가 따로 필요하지 않다.

### 공간 복잡도

one pass에 O(1)의 공간 복잡도를 사용한다.

### two pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(N)     |    O(1)     |

0번째 시간에 문을 닫았다 가정하고 미리 비용을 구한다.

이후 1번째 시간부터 N번째 시간까지 닫는 시간을 순회하며 비용을 갱신하며 정답을 구한다.

```cpp
int bestClosingTime(string customers) {
  int size = customers.size();

  // cost of close at 0
  int curCost = size;
  for (char &c : customers) {
    if (c == 'N') curCost--;
  }

  int cost = curCost;
  int answer = 0;

  // close at i+1
  for (int i = 0; i <= size; i++) {
    char cur = customers[i];

    if (cur == 'Y') {
      curCost--;
    } else {
      curCost++;
    }

    if (curCost < cost) {
      answer = i + 1;
      cost = curCost;
    }
  }

  return answer;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(1)     |

위 방법에서 실제로 모든 cost를 미리 구하지 않고 cost에서 변화되는 값만을 이용해 정답을 구할 수 있다.

초기 cost는 0번째 시간에 문을 닫는 경우의 시간으로 가정하자.

이후 각 시간에 문을 닫을 때 마다의 cost가 갱신될때 초기 cost와 diff만을 비교해 정답을 갱신한다.

```cpp
int bestClosingTime(string customers) {
  int size = customers.size();

  int minDiff = 0, diff = 0;
  int answer = 0;

  // close at i+1
  for (int i = 0; i <= size; i++) {
    char cur = customers[i];

    if (cur == 'Y') {
      diff--;
    } else {
      diff++;
    }

    if (diff < minDiff) {
      answer = i + 1;
      minDiff = diff;
    }
  }

  return answer;
}
```

## 고생한 점
