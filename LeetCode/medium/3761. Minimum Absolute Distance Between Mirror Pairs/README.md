# 3761. Minimum Absolute Distance Between Mirror Pairs

[링크](https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

값을 순회하며 현재 값을 뒤집은 값의 마지막 index가 있는지 확인해 정답을 구한다.

hash map에 이를 저장하는데 O(1)이 걸리므로 전체적으로 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      85      |    O(N)     |    O(N)     |

각 값을 순회하며 현재 값을 뒤집은 값을 key로 현재 index를 value로 hash map에 저장한다.

현재 값이 hash map에 존재한다면 현재 index와 hash map에 저장된 index의 차이를 구해 정답을 갱신한다.

```cpp
int reverse(int num) {
  int ret = 0;
  while (num > 0) {
    ret = ret * 10 + num % 10;
    num /= 10;
  }
  return ret;
}

int minMirrorPairDistance(vector<int>& nums) {
  int size = nums.size();

  unordered_map<int, int> befores;

  int answer = INT_MAX;

  for (int i = 0; i < nums.size(); i++) {
    int cur = nums[i];
    int r = reverse(cur);

    if (befores.count(cur)) {
      int diff = i - befores[cur];
      answer = min(answer, diff);
    }

    befores[r] = i;
  }

  if (answer == INT_MAX) return -1;

  return answer;
}
```

## 고생한 점
