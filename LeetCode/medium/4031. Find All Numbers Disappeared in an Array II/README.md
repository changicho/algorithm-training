# 4031. Find All Numbers Disappeared in an Array II

[링크](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 값의 범위를 M이라 하자.

정렬 후 순회를 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

각 값마다 방문 배열을 사용 후 순회할 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 시간 복잡도를 사용한다. 방문 배열에 O(M)의 공간 복잡도를 사용한다.

### 정렬 & 순회

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      75      | O(N \* log_2(N)) |    O(N)     |

nums를 오름차순으로 정렬한다. 이후 배열을 순회하며 lower와 upper사이에 빈 구간을 정답에 추가한다.

이를 위해 직전 빈 구간의 시작값을 변수로 사용하며, 초기값을 lower를 할당한다.

이후 마지막에 마지막 구간의 시작값과 upper를 이용해 구간을 추가해야 하는 경우 추가한다.

```cpp
vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
  vector<vector<int>> answer;

  sort(nums.begin(), nums.end());

  int size = nums.size();

  int before = lower;

  for (int i = 0; i < size; i++) {
    int& num = nums[i];
    if (num > upper) break;
    if (before > num) {
      continue;
    }

    if (before != num) {
      answer.push_back({before, num - 1});
    }
    before = num + 1;
  }

  if (before <= upper) {
    answer.push_back({before, upper});
  }
  return answer;
}
```

## 고생한 점
