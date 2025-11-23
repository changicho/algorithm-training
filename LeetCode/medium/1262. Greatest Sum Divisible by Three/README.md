# 1262. Greatest Sum Divisible by Three

[링크](https://leetcode.com/problems/greatest-sum-divisible-by-three/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하며 제한시간 내에 불가능하다.

나머지를 이용할 경우 순회에 O(N)의 시간 복잡도를 사용한다.

이 때 각 나머지에 해당하는 값들 중 가장 작은 2개의 값을 선택하는데 정렬을 사용할 경우 O(N \* log_2(N))의 시간복잡도를 사용한다.

대소비교만 사용할 경우 O(N)의 시간복잡도를 사용한다.

### 공간 복잡도

가장 작은 2개의 값을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 나머지 & 가장 작은 2개의 값

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 숫자를 3으로 나눈 나머지에 따라 그룹화 한다.

이후 각 그룹에서 가장 작은 2개의 값을 고른다.

모든 수를 더한 값의 나머지가 0, 1, 2인 경우에 따라 제거할 값을 결정한다.

- 0 : 제거할 값이 없음
- 1 : 나머지가 1인 값 중 가장 작은 값 1개 혹은 나머지가 2인 값 중 가장 작은 값 2개
- 2 : 나머지가 2인 값 중 가장 작은 값 1개 혹은 나머지가 1인 값 중 가장 작은 값 2개

즉 제거하는 값들의 합이 현재 3으로 나눈 나머지와 같아야 하며, 이 값들은 최소값을 선택해야 한다.

```cpp
void insert(pair<long long, long long>& p, int num) {
  if (p.first >= num) {
    p.second = p.first;
    p.first = num;
  } else if (p.second > num) {
    p.second = num;
  }
}

int maxSumDivThree(vector<int>& nums) {
  int size = nums.size();

  int sum = 0;
  vector<pair<long long, long long>> mods(3, {INT_MAX, INT_MAX});
  for (int& num : nums) {
    sum += num;
    int key = num % 3;

    if (key == 0) continue;
    insert(mods[key], num);
  }

  int mod = sum % 3;
  long long oneDiff = INT_MAX;
  long long twoDiff = INT_MAX;
  if (mod == 0) {
    oneDiff = twoDiff = 0;
  } else if (mod == 1) {
    oneDiff = mods[1].first;
    twoDiff = 0LL + mods[2].first + mods[2].second;
  } else if (mod == 2) {
    oneDiff = mods[1].first + mods[1].second;
    twoDiff = mods[2].first;
  }

  long long diff = min(oneDiff, twoDiff);
  if (diff == INT_MAX) return 0;
  sum -= diff;

  return sum;
}
```

## 고생한 점
