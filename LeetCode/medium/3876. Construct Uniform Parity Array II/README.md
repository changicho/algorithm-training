# 3876. Construct Uniform Parity Array II

[링크](https://leetcode.com/problems/construct-uniform-parity-array-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

짝수에 홀수를 빼면 홀수가 나오고 홀수에 짝수를 빼면 홀수가 나온다.

즉 홀수의 갯수가 몇개 인지가 모든 수를 짝수 혹은 홀수로 만들 수 있는 판단의 기준이 된다.

조건에 따라 최소값 또한 정해야 한다.

이를 세기 위해 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

짝수, 홀수의 갯수를 세는 데 O(1)의 공간 복잡도를 사용한다.

### 홀수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

모든 수가 짝수/홀수로 동일한 경우 연산을 수행할 필요가 없다.

그 외의 경우 가장 작은 수가 홀수인 경우 다음과 같은 연산이 가능하다.

- 다른 짝수들에 해당 수를 전부 빼면 모두 홀수로 만들 수 있다.
- 다른 홀수들은 그대로 사용한다.

이 경우 모든 값을 홀수로 만들 수 있다.

가장 작은 수가 짝수인 경우는 불가능하다. 이는 홀수에서 짝수를 빼도 홀수이기 때문이다.

순회를 이용해 이를 세고 정답을 구한다.

```cpp
bool uniformArray(vector<int>& nums1) {
  int odd = 0;
  int minimum = nums1[0];
  for (int& num : nums1) {
    minimum = min(minimum, num);
    if (num % 2 == 1) {
      odd++;
    }
  }

  if (odd == 0) return true;
  if (minimum % 2 == 1) return true;
  return false;
}
```

## 고생한 점
