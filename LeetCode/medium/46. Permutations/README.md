# 46. Permutations

[링크](https://leetcode.com/problems/permutations/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums 배열의 길이는 최대 6 이다.

가능한 모든 permutation을 구해야 하며 이는 최악의 경우 6! 이다. 이는 720이므로 제한시간 내에 가능하다.

### 공간 복잡도

정답의 경우를 저장할 배열이 필요하다. O(N)

### STL

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N!)    |    O(N)     |

STL의 next_permutation을 사용하기 위해선 오름차수능로 정렬이 되어있어야 한다.

이후 next_permutation을 통해 정답의 경우를 구한다.

```cpp
vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> answer;

  sort(nums.begin(), nums.end());

  do {
    answer.push_back(nums);
  } while (next_permutation(nums.begin(), nums.end()));

  return answer;
}
```

### 직접 구현

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N!)    |    O(N)     |

문제에서 조합에서의 순서는 상관하지 않는다.

따라서 현재 숫자의 위치를 바꿔가며 재귀호출한다.

```cpp
vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> answer;

  permutation(nums, answer, 0);

  return answer;
}

void permutation(vector<int>& nums, vector<vector<int>>& array, int start) {
  int size = nums.size();
  if (start >= size) {
    array.push_back(nums);
    return;
  }

  for (int i = start; i < size; i++) {
    swap(nums[start], nums[i]);
    permutation(nums, array, start + 1);
    swap(nums[start], nums[i]);
  }
}
```

## 고생한 점
