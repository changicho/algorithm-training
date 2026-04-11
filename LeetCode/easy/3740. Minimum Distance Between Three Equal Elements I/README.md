# 3740. Minimum Distance Between Three Equal Elements I

[링크](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

값의 범위가 정해져 있으므로 값마다 순회하며 3개의 연속된 index 차이들의 최소합을 구할 수 있다.

이 경우 O(N^2)의 시간 복잡도를 가진다.

각 값마다 최근 index를 저장해 3개의 index 차이들의 최소합을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

각 값마다의 index를 저장할 때 O(N)만큼의 공간 복잡도를 가진다.

### 완전탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 값마다 최근에 나온 index를 저장하는 배열을 만든다.

이후 index를 왼쪽부터 순회하며 현재 index가 최근에 나온 index보다 크다면 3개의 index 차이들의 최소합을 구한다.

```cpp
int minimumDistance(vector<int>& nums) {
  int size = nums.size();
  vector<pair<int, int>> indexes(101, {-1, -1});

  int answer = INT_MAX;
  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    if (indexes[cur].first != -1) {
      int first = indexes[cur].first, second = indexes[cur].second, third = i;

      int diff = second - first + third - second + third - first;
      answer = min(diff, answer);
    }

    indexes[cur].first = indexes[cur].second;
    indexes[cur].second = i;
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
