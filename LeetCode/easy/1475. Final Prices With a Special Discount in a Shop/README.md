# 1475. Final Prices With a Special Discount in a Shop

[링크](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 prices의 크기를 N이라 하자.

매번 모든 경우를 직접 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

모노토닉 스택을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 사용한다.

모노토닉 스택에 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 index에 존재하는 수는 현재 index 이후의 값들 중 자신보다 작은 가장 먼저 나타나는 값 만큼 discount를 수행할 수 있다.

이를 모노토닉 스택을 사용해 순회와 동시에 이 값을 구할 수 있다.

top으로 갈수록 증가하는 스택을 만들고 현재 값이 top보다 작은 경우 pop을 수행한다.

매 경우마다 스택을 유효하게 유지하며 스택에 값이 존재하는 경우 discount를 적용한다.

그 외의 경우 discount를 적용하지 않는다.

```cpp
vector<int> finalPrices(vector<int>& prices) {
  int size = prices.size();

  vector<int> answer(size);

  stack<int> incStack;
  for (int i = size - 1; i >= 0; i--) {
    int cur = prices[i];
    while (!incStack.empty() && cur < incStack.top()) {
      incStack.pop();
    }

    if (!incStack.empty()) {
      answer[i] = cur - incStack.top();
    } else {
      answer[i] = cur;
    }
    incStack.push(cur);
  }
  return answer;
}
```

## 고생한 점
