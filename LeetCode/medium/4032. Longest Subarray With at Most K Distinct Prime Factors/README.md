# 4032. Longest Subarray With at Most K Distinct Prime Factors

[링크](https://leetcode.com/problems/longest-subarray-with-at-most-k-distinct-prime-factors/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 값의 범위를 M, 각 값마다 평균 소인수의 수를 F라 하자.

에라토스테네스의 채를 이용해 소수를 구하는데 O(M \* log_2(log_2(M)))의 시간 복잡도를 사용한다.

이후 슬라이딩 윈도우를 이용해 정답을 구하는데 O(N \* F)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 값마다 소인수 목록을 저장하는데 O(N \* F)의 공간 복잡도를 사용한다.

에라토스테네스의 채를 이용해 소수 여부를 저장하는데 O(M)의 공간 복잡도를 사용한다.

### 에라토스테네스의 채 & 슬라이딩 윈도우

| 내 코드 (ms) |           시간 복잡도            |  공간 복잡도  |
| :----------: | :------------------------------: | :-----------: |
|     1287     | O(M \* log_2(log_2(M)) + N \* F) | O(N \* F + M) |

각 값마다 소인수를 저장한다.

이후 슬라이딩 윈도우를 이용해 범위를 이동해가며 소인수의 종류의 수를 hash map으로 관리한다.

```cpp
bool isNotPrime[100001];
vector<int> primes;

vector<int> convert(int num) {
  vector<int> ret;

  for (int& i : primes) {
    if (num < i) break;

    if ((num % i) == 0) {
      ret.push_back(i);
      num /= i;
    }
  }

  return ret;
}

int longestSubarray(vector<int>& nums, int k) {
  isNotPrime[1] = true;
  for (int i = 2; i <= 100000; i++) {
    if (isNotPrime[i]) continue;
    primes.push_back(i);

    for (int j = i + i; j <= 100000; j += i) {
      isNotPrime[j] = true;
    }
  }

  int size = nums.size();

  vector<vector<int>> ps;

  for (int& num : nums) {
    if (!isNotPrime[num]) {
      ps.push_back({num});
      continue;
    }

    vector<int> cur = convert(num);

    ps.push_back(cur);
  }

  int answer = 0;
  unordered_map<int, int> um;
  for (int left = 0, right = 0; right < size; right++) {
    for (int& p : ps[right]) {
      um[p]++;
    }

    while (um.size() > k && left <= right) {
      for (int& p : ps[left]) {
        um[p]--;
        if (um[p] == 0) um.erase(p);
      }
      left++;
    }

    answer = max(answer, right - left + 1);
  }
  return answer;
}
```

## 고생한 점
