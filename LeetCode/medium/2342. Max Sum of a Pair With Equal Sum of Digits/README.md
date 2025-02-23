# 2342. Max Sum of a Pair With Equal Sum of Digits

[링크](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. 배열의 수의 최대값을 M이라 하자.

각 수의 자리수를 모두 더한 뒤 해당 합에 대한 가장 큰 두 값을 찾는다.

순회하며 변환하는데 각각 O(log_10(M))의 시간 복잡도가 소요된다.

hash map을 이용해 직전 최대값과 현재값을 이용해 정답을 갱신할 경우 O(N \* log_10(M))의 시간 복잡도가 소요된다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도가 필요하다.

### hash map

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      21      | O(N \* log_10(M)) |    O(N)     |

각 자리수 합별로 가장 큰 두 개의 값을 찾아야 한다.

nums를 순회하며 자리수 합에 대한 최대값을 hash map에 저장한다.

이 때 현재 값과 같은 자리수의 직전 합을 이용해 매번 정답을 갱신한다.

```cpp
int getDigit(int num) {
  int ret = 0;
  while (num > 0) {
    ret += num % 10;
    num /= 10;
  }
  return ret;
}

int maximumSum(vector<int>& nums) {
  unordered_map<int, int> um;

  int answer = -1;
  for (int& num : nums) {
    int digit = getDigit(num);

    if (um.count(digit)) {
      answer = max(answer, num + um[digit]);
    }
    um[digit] = max(um[digit], num);
  }
  return answer;
}
```

## 고생한 점
