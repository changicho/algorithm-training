# 3741. Minimum Distance Between Three Equal Elements II

[링크](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 값마다 최근 index를 저장해 3개의 index 차이들의 최소합을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

각 값마다의 index를 저장할 때 O(N)만큼의 공간 복잡도를 가진다.

### index 저장

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(N)     |    O(N)     |

[3740. Minimum Distance Between Three Equal Elements I](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/)

위 문제와 유사한 문제.

각 값마다의 최근 2개의 index를 저장하는 배열을 만든다. 이후 index를 왼쪽부터 순회하며 현재 index가 최근에 나온 index보다 크다면 3개의 index 차이들의 최소합을 구한다.

```cpp
int minimumDistance(vector<int>& nums) {
  int size = nums.size();
  vector<pair<int, int>> indexes(size + 1, {-1, -1});

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
