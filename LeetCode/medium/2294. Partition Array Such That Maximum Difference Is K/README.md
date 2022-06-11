# 2294. Partition Array Such That Maximum Difference Is K

[링크](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

값의 차이가 적은 것들끼리 그룹으로 묶어야 최소갯수의 그룹을 만들 수 있다.

따라서 정렬을 이용한다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 순회하며 diff가 K 이하인 값들끼리 최대한 묶는다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬 이후 별도의 배열등을 사용하지 않는다. 따라서 공간 복잡도는 O(1)이다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     224      | O(N \* log_2(N)) |    O(1)     |

각 값들을 정렬한다.

이후 첫번째 값부터 순회하며 차이가 K이하인 경우 같이 묶는다.

만약 차이가 K 초과인 경우 해당 값을 기준점으로 잡고 순회를 계속한다.

```cpp
int partitionArray(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());

  int count = 0;
  int before = nums.front();
  for (int& num : nums) {
    if (num - before > k) {
      count++;
      before = num;
      continue;
    }
  }

  return count + 1;
}
```

## 고생한 점
