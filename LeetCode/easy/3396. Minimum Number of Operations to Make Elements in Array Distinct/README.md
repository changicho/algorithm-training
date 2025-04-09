# 3396. Minimum Number of Operations to Make Elements in Array Distinct

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 값의 범위를 M이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

각 값마다 갯수를 센뒤 중복되는 숫자를 관리할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수마다의 갯수를 세는 데 O(M)의 공간 복잡도를 사용한다.

### 카운트 & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(M)     |

각 숫자들의 갯수를 미리 센다.

이후 현재 index에서 3개를 삭제했을 때 중복되는 숫자가 없는지 확인한다.

만약 중복되는 숫자가 존재한다면 index에서 연이어 3개의 숫자의 갯수를 줄인 뒤 index를 3씩 증가시킨다.

```cpp
int minimumOperations(vector<int>& nums) {
  int size = nums.size();
  int counts[101] = {
      0,
  };

  int overCount = 0;
  for (int& num : nums) {
    counts[num]++;
    if (counts[num] == 2) overCount++;
  }

  int answer = 0;
  for (int i = 0; i < size; i += 3) {
    if (overCount == 0) break;

    answer++;
    for (int j = 0; j < 3; j++) {
      if (i + j >= size) break;
      int num = nums[i + j];
      counts[num]--;
      if (counts[num] == 1) overCount--;
    }
  }
  return answer;
}
```

## 고생한 점
