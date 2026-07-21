# 3867. Sum of GCD of Formed Pairs

[링크](https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

gcd값을 계산 후 정렬하는데 O(N \* log_2(N) + N \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & gcd

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      91      | O(N \* log_2(N) + N \* log_2(M)) |    O(N)     |

문제 조건에 따라 gcd값들을 배열에 담은 후 정렬한 뒤 조건에 맞춰 정답을 계산한다.

```cpp
long long gcdSum(vector<int>& nums) {
  int minimum = INT_MAX, maximum = INT_MIN;

  int curMax = nums[0];

  vector<int> gcds;
  for (int& num : nums) {
    curMax = max(curMax, num);
    int curGcd = gcd(curMax, num);

    gcds.push_back(curGcd);
  }

  sort(gcds.begin(), gcds.end());

  int size = gcds.size();

  long long answer = 0;
  for (int i = 0; i < size / 2; i++) {
    answer += gcd(gcds[i], gcds[size - 1 - i]);
  }
  return answer;
  ;
}
```

## 고생한 점
