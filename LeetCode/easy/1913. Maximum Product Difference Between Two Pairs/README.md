# 1913. Maximum Product Difference Between Two Pairs

[링크](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 원소의 갯수를 N이라 하자.

가장 큰 2개 값과 가장 작은 2개 값을 고를 때 정답이 최대가 된다.

정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

한번의 순회로 최대값, 2번째 최대값을 갱신할 수 있다. 이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

순회에 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

순회를 진행하며 최대값, 2번째 최대값을 갱신한다.

같은 방법으로 최소값도 갱신한다.

```cpp
int maxProductDifference(vector<int>& nums) {
  int size = nums.size();
  int m1 = INT_MIN, m2 = INT_MIN;
  int s1 = INT_MAX, s2 = INT_MAX;

  for (int& num : nums) {
    if (num >= m1) {
      m2 = m1;
      m1 = num;
    } else if (num > m2) {
      m2 = num;
    }

    if (num <= s1) {
      s2 = s1;
      s1 = num;
    } else if (num < s2) {
      s2 = num;
    }
  }

  return (m1 * m2) - (s1 * s2);
}
```

## 고생한 점
