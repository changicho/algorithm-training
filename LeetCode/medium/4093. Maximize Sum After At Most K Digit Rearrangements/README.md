# 4093. Maximize Sum After At Most K Digit Rearrangements

[링크](https://leetcode.com/problems/maximize-sum-after-at-most-k-digit-rearrangements/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 수마다 변환했을 때 유리한 값을 정렬을 이용해 찾을 수 있다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 순회하며 정답을 구한다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 그리디 & 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     207      | O(N \* log_2(N)) |    O(N)     |

각 값마다 변환했을 때 커지는 diff가 존재한다.

해당 diff가 큰 순으로 정렬 후 앞에서부터 K개는 변환한 값을 더하고 나머지는 원본 값을 더한다.

```cpp
long long convert(int num) {
  int count[10] = {
      0,
  };
  while (num > 0) {
    count[num % 10]++;
    num /= 10;
  }
  long long ret = 0;
  for (int d = 9; d >= 0; d--) {
    while (count[d]) {
      ret = ret * 10 + d;
      count[d]--;
    }
  }
  return ret;
}

long long maximizeSum(vector<int>& nums, int k) {
  int size = nums.size();
  vector<pair<long long, long long>> arr;
  for (int& num : nums) {
    arr.push_back({num, convert(num)});
  }

  sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
    return a.second - a.first > b.second - b.first;
  });

  long long answer = 0;

  for (int i = 0; i < size; i++) {
    if (i < k) {
      answer += arr[i].second;
    } else {
      answer += arr[i].first;
    }
  }
  return answer;
}
```

## 고생한 점
