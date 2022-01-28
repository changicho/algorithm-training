# 523. Continuous Subarray Sum

[링크](https://leetcode.com/problems/continuous-subarray-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

원소의 갯수를 N이라 하자.

모든 원소를 순회하며 prefixSum을 구한다.

동시에 k로 나눈 나머지에 대해서 이전에 구한 나머지중에 현재 나머지와 더했을 때 k가 되는 경우를 찾는다.

이를 위해 이전에 구한 나머지들을 hash set에 저장하고 O(1)의 시간 복잡도로 검색한다.

이 경우 모든 원소의 순회에 O(N)의 시간 복잡도를 소모한다.

### 공간 복잡도

hash set을 생성하는 데 O(K)의 공간 복잡도를 사용한다.

### prefixSum & 나머지

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     160      |    O(N)     |    O(K)     |

subArray를 다음과 같이 나눠서 생각하자.

```javascript
array = [leftPart, ...subArray, rightPart];
```

여기서 우리가 구해야 하는것은 subArray의 합이 k의 배수가 되는 경우이다.

따라서 배열을 위와 같이 생각했을 subArray의 합이 k의 배수가 되는 경우는 다음과 같이 생각할 수 있다.

- A : leftPart의 원소의 합을 k로 나눈 나머지
- B : subArray의 원소의 합을 k로 나눈 나머지
- (A + B)를 k로 나눴을 때 나누어 떨어지는 경우 subArray가 정답의 후보가 된다.

그러므로 위 방법을 이용해 prefixSum을 구하면서 A와 B에 대해 k로 나누어 떨어지는지를 판단한다.

이 때 subArray의 크기는 2 이상이여야 하므로 직전의 prefixSum을 한단계 뒤에 갱신해야 한다.

즉 A가 될 수 있는 후보군을 hash set에 저장할 때 다음 단계에서 저장한다.

```cpp
bool checkSubarraySum(vector<int>& nums, int k) {
  int size = nums.size();
  int sum = 0, prevMod = 0;

  unordered_set<int> mods;

  for (int i = 0; i < size; i++) {
    sum += nums[i];

    int mod = sum % k;  // current mod

    // find x that (mod + x == k)
    if (mods.count(mod)) return true;
    mods.insert(prevMod);

    // update remain mod value
    prevMod = mod;
  }

  return false;
}
```

위 방법에서 prevMod를 hash set에 저장할 때 index를 같이 저장해 크기를 바로 계산할 수 있다.

```cpp
bool checkSubarraySum(vector<int>& nums, int k) {
  unordered_map<int, int> mods;  // {mod, index}
  mods[0] = -1;

  int sum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];
    sum %= k;

    // store first case of mods
    if (mods.count(sum) == 0) {
      mods[sum] = i;
    }

    // calculate size of subArray
    if (i - mods[sum] > 1) return true;
  }

  return false;
}
```

## 고생한 점
