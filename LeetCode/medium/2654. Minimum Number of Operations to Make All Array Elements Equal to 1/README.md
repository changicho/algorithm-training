# 2654. Minimum Number of Operations to Make All Array Elements Equal to 1

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 가장 큰 값을 M이라 하자.

두 값의 gcd를 구하는데 O(log_2(M))의 시간 복잡도를 사용한다.

배열의 값들 중 하나라도 1이 존재하는 경우 모두 1로 만들 수 있다.

그 외의 경우 배열의 두 값을 선택해 1로 만들 수 있는 최소횟수를 구해야 한다.

이에 O(N^2 \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

gcd연산에 O(1)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      0       | O(N^2 \* log_2(M)) |    O(1)     |

배열의 모든 값을 gcd로 변환했을 때 1이 되지 않는경우, 1이 아닌 최대공약수가 존재한다는 의미이므로 모든 수를 1로 만드는 것이 불가능하다.

배열에서 1이 이미 존재하는 경우 다른 모든 수를 1로 만들 수 있다.

이 때의 연산 횟수는 전체 크기에서 1의 개수를 뺀 값이다.

그 외의 경우는 1을 만든 뒤 해당 만들어진 1을 사용해 다른 모든 값을 1로 바꾸는 경우이다.

이 경우 배열의 두 원소를 선택했을 때 1을 만드는 최소 횟수를 구한다.

이후 해당 1을 사용해 다른 모든 값을 1로 바꾸는 연산 횟수를 더한다.

(이는 전체 갯수 - 1) + (1로 만드는 최소 횟수 - 1) 이 된다.

```cpp
int minOperations(vector<int>& nums) {
  int size = nums.size();

  int oneCount = 0;
  int allGcd = nums[0];

  for (int& num : nums) {
    if (num == 1) oneCount++;

    allGcd = gcd(num, allGcd);
  }

  if (allGcd != 1) return -1;
  if (oneCount > 0) {
    return size - oneCount;
  }

  int makeOneDiff = size;
  for (int left = 0; left < size; left++) {
    int val = 0;
    for (int right = left; right < size; right++) {
      val = gcd(val, nums[right]);
      if (val == 1) {
        makeOneDiff = min(makeOneDiff, right - left + 1);
        break;
      }
    }
  }

  return size - 1 + makeOneDiff - 1;
}
```

## 고생한 점
