# 1590. Make Sum Divisible by P

[링크](https://leetcode.com/problems/make-sum-divisible-by-p/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

따라서 중복되는 경우를 제거하고 최소의 경우만 탐색해야한다.

누적합을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

누적합에 O(N)의 공간 복잡도가 필요하다.

### 누적합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     143      |    O(N)     |    O(N)     |

nums의 특정 subArray를 제거했을 때 합이 p로 나누어 떨어져야 한다.

따라서 nums의 모든 수를 더한 값을 p로 나눈 나머지를 구한다.

해당 값을 diff라고 하자.

diff가 0인 경우 아무 숫자도 제거하지 않아도 된다.

diff가 0이 아닌 경우 prefixSum을 구하고 해당 prefixSum의 마지막 index를 저장하는 map을 생성한다.

현재 prefixSum에서 특정 수 X를 더해 p로 나눈 나머지가 diff인 경우를 찾아야 한다.

해당 X가 이전에 나왔던 경우, 그 index와 현재 index의 차이를 구해 정답을 갱신한다.

이 때 모든 수를 제거해야 하는 경우가 나온 경우 -1을 반환한다.

```cpp
int minSubarray(vector<int>& nums, int p) {
  int size = nums.size();
  int sum = 0;

  for (int& num : nums) {
    sum = (sum + num) % p;
  }

  int diff = sum % p;
  if (diff == 0) return 0;

  unordered_map<int, int> beforeI;
  beforeI[0] = -1;
  int prefixSum = 0;
  int answer = size;

  for (int i = 0; i < size; i++) {
    prefixSum = (prefixSum + nums[i]) % p;

    int needed = (prefixSum - diff + p) % p;

    if (beforeI.count(needed) > 0) {
      answer = min(answer, i - beforeI[needed]);
    }

    beforeI[prefixSum] = i;
  }

  return answer == size ? -1 : answer;
}
```

## 고생한 점
