# 2089. Find Target Indices After Sorting Array

[링크](https://leetcode.com/problems/find-target-indices-after-sorting-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 값의 범위를 M이라 하자.

정렬을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

카운트를 사용할 경우 O(N + M)의 시간 복잡도를 사용한다.

각 값이 target에 비해 작은지 같은지만 비교할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N), 카운트에 O(M)의 공간 복잡도를 사용한다.

각 값만 비교할 경우 O(1)의 공간 복잡도를 사용한다.

정답에 O(N)의 공간 복잡도를 사용한다.

### 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

배열을 정렬 후 target과 같은 원소들의 index만 찾으면 된다.

따라서 target보다 작은 갯수와 같은 갯수를 센 뒤 정답을 생성한다.

```cpp
vector<int> targetIndices(vector<int>& nums, int target) {
  int size = nums.size();

  int lowerCount = 0;
  int sameCount = 0;
  for (int& num : nums) {
    if (num < target) {
      lowerCount++;
    } else if (num == target) {
      sameCount++;
    }
  }

  vector<int> answer;
  for (int i = 0; i < sameCount; i++) {
    answer.push_back(lowerCount + i);
  }

  return answer;
}
```

## 고생한 점
