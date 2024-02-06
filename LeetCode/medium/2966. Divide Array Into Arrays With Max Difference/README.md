# 2966. Divide Array Into Arrays With Max Difference

[링크](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

배열을 정렬 후 순회하며 탐색할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     175      | O(N \* log_2(N)) |    O(N)     |

3개의 숫자로 묶을 때 차이가 가장 적은 값들끼리 묶어야 한다.

따라서 정렬 후 순서대로 3개씩 선택해서 묶을 경우 차이가 가장 적은 값들끼리 묶일 수 있다.

```cpp
vector<vector<int>> divideArray(vector<int>& nums, int k) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  vector<vector<int>> answer;
  for (int i = 0; i < size; i += 3) {
    vector<int> cur = {nums[i], nums[i + 1], nums[i + 2]};

    if (cur.back() - cur.front() > k) return {};
    answer.push_back(cur);
  }
  return answer;
}
```

## 고생한 점
