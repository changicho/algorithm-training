# 628. Maximum Product of Three Numbers

[링크](https://leetcode.com/problems/maximum-product-of-three-numbers/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

정렬 후 가장 큰 순으로, 작은순으로 값을 선택할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

순회하며 값을 갱신 후 필요한 값들을 선택할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

배열에 음수 또한 포함되어있으므로 정답은 다음 2가지 경우 중 하나이다.

- 가장 큰 양수 3개
- 가장 작은 음수 2개 + 가장 큰 양수 1개

순회하며 각 숫자들을 갱신해 구하고 정답을 반환한다.

```cpp
int maximumProduct(vector<int>& nums) {
  int a = max({nums[0], nums[1], nums[2]});
  int c = min({nums[0], nums[1], nums[2]});
  int b = nums[0] + nums[1] + nums[2] - a - c;

  int d = b;
  int e = c;

  int size = nums.size();
  for (int i = 3; i < size; i++) {
    int cur = nums[i];
    if (cur > a) {
      c = b;
      b = a;
      a = cur;
    } else if (cur > b) {
      c = b;
      b = cur;
    } else if (cur > c) {
      c = cur;
    }

    if (cur < e) {
      d = e;
      e = cur;
    } else if (cur < d) {
      d = cur;
    }
  }

  return max(a * b * c, a * d * e);
}
```

## 고생한 점
