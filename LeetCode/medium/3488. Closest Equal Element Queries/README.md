# 3488. Closest Equal Element Queries

[링크](https://leetcode.com/problems/closest-equal-element-queries/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 크기를 Q, 숫자의 최대 범위를 M이라 하자.

순회를 이용해 현재 값의 직전 index를 저장하며 차이를 구할 수 있다. 이 경우 시간 복잡도는 O(N + Q)이다.

### 공간 복잡도

각 index마다 값을 저장하는데 O(N)의 공간 복잡도를 사용한다.

정답에 O(Q)의 공간 복잡도를 사용한다.

각 값마다의 첫 index와 마지막 index를 저장하는데 O(M)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     110      |  O(N + Q)   |  O(N + Q)   |

각 index마다 같은 값의 이전값, 다음값의 거리를 저장한다.

이를 위해 각 값마다 마지막에 등장했던 위치를 저장하는 해시맵을 이용한다.

순회를 완료한 이후 각 값마다 제일 마지막에 등장했던 index가 저장되며, 이를 이용해 circular한 경우도 고려해 계산한다.

이후 각 쿼리마다 정답을 계산한다.

```cpp
vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
  int size = nums.size();

  vector<int> nexts(size, -1);
  vector<int> prevs(size, -1);

  unordered_map<int, int> last;

  for (int i = 0; i < size; i++) {
    int num = nums[i];

    if (last.count(num)) {
      int diff = i - last[num];
      nexts[last[num]] = diff;
      prevs[i] = diff;
    }

    last[num] = i;
  }

  for (int i = 0; i < size; i++) {
    int num = nums[i];
    if (last.count(num) && last[num] != i && prevs[i] == -1) {
      int diff = abs(size - last[num] + i);
      nexts[last[num]] = diff;
      prevs[i] = diff;
    }
  }

  vector<int> answer;
  for (int& q : queries) {
    int target = nums[q];

    if (nexts[q] == -1) {
      answer.push_back(-1);
      continue;
    }

    int minimum = min(nexts[q], prevs[q]);

    answer.push_back(minimum);
  }
  return answer;
}
```

## 고생한 점
