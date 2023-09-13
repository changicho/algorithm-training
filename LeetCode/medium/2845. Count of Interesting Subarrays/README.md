# 2845. Count of Interesting Subarrays

[링크](https://leetcode.com/problems/count-of-interesting-subarrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자. 이는 최대 10^5이다.

모든 경우에 대해 탐색할 경우 경우의 수는 N^2개가 존재한다. 이를 모두 탐색할 경우 O(N^2)의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

prefix sum을 이용해 이전 결과를 재사용할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum에 최대 O(N)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     151      |    O(N)     |    O(N)     |

다음 식을 만족하는 range를 모두 구해야한다.

```cpp
for(int i = left; i <= right; i++){
  cnt += nums[i] % modulo == k;
}

if(cnt % modulo == k) answer++;
```

이를 위해서 prefix sum을 이용한다.

왼쪽부터 순회하며 현재까지 num % modulo가 k인 경우를 count한다.

현재까지 count에서 k를 뺀 값이 modulo로 나누어 떨어지는 경우 해당 구간은 정답에 포함된다.

따라서 왼쪽부터 prefix sum으로 modulo로 나눈 나머지에 대한 갯수를 정답에 더한다.

```cpp
long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
  int size = nums.size();
  unordered_map<int, int> prefixCounts;
  prefixCounts[0]++;

  int count = 0;
  long long answer = 0;
  for (int& num : nums) {
    if (num % modulo == k) {
      count++;
    }
    count %= modulo;

    int target = (count - k + modulo) % modulo;
    if (prefixCounts.count(target) > 0) {
      answer += prefixCounts[target];
    }
    prefixCounts[count]++;
  }
  return answer;
}
```

## 고생한 점
