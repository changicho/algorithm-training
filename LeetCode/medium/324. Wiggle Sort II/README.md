# 324. Wiggle Sort II

[링크](https://leetcode.com/problems/wiggle-sort-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums 배열의 크기를 N이라고 하자.

정렬을 수행한 뒤에 순차적으로 값을 채워넣을 수 있다.

정렬을 수행할 경우 O(N \* log_2(N))의 시간 복잡도가 소요되며, 이후 one pass로 풀이가 가능하다.

three-way partitioning을 이용할 경우 한번의 순회로 풀이가 가능하므로 O(N)의 시간 복잡도를 소요한다.

### 공간 복잡도

정렬 이후에 새로운 배열을 만들 경우 O(N)의 공간 복잡도를 소요한다.

그 외에 swap을 이용할 경우 O(1)의 공간 복잡도를 소요한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      34      | O(N \* log_2(N)) |    O(N)     |

정렬을 수행해 오름차순으로 만든다.

이후 새로운 answer 배열을 만들고 오름차순으로 정렬된 수를 이용해 answer를 채워넣는다.

짝수번째 숫자는 인접한 두 숫자보다 커야한다. 따라서 큰 숫자들부터 짝수들을 채워넣는다.

이 때 가장 큰 숫자가 가장 앞에있는 짝수번째에 위치하도록 구성한다.

이는 이후에 홀수번째에도 동일하게 가장 큰 숫자가 가장 앞에 위치하도록 구성해 큰 값들은 큰 값들끼리, 작은 값들은 작은 값들끼리 인접하게 하기 위함이다.

이를 구현하면 다음과 같다.

```cpp
void wiggleSort(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());
  vector<int> answer(size);

  int cur = size - 1;
  // odd
  for (int i = 1; i < size; i += 2) {
    answer[i] = nums[cur];
    cur--;
  }
  // even
  for (int i = 0; i < size; i += 2) {
    answer[i] = nums[cur];
    cur--;
  }

  nums = answer;
}
```

## 고생한 점

정렬을 수행 후에 작은 숫자부터 앞에 채워넣을 경우, 특정 부분에서 인접한 값들이 같은 문제가 발생했었다.
