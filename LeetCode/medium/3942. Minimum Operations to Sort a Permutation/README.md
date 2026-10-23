# 3942. Minimum Operations to Sort a Permutation

[링크](https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

배열을 순회하며 상태를 파악하고 각 종류별로 어떤지 분석 가능하다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회하며 비교하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(N)     |    O(1)     |

다음과 같은 경우들로 분석할 수 있다.

배열의 최소값을 M이라 하자. 배열의 원소는 중복되지 않는다.

- M을 기준으로 오른쪽으로 오름차순 정렬된 경우
- M을 기준으로 왼쪽방향으로 오름차순 정렬된 경우
- 어느 방향으로도 정렬되지 않은 경우

여기서 어느 방향으로도 정렬되지 않은 경우 최종적으로 오름차순 정렬이 불가능하다.

이후 각 경우마다 정답에 가능한 최소 횟수를 구한다.

- 오른쪽 오름차순 : M을 0번째로 옮기는 횟수, 뒤집은 뒤 M을 마지막으로 보낸 후 다시 뒤집는 횟수
- 왼쪽 오름차순 : M을 0번쨰로 옮기고 뒤집는 횟수, M을 마지막으로 보내고 뒤집는 횟수

```cpp
int minOperations(vector<int>& nums) {
  int size = nums.size();

  int minimum = nums[0];
  int minI = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] < minimum) {
      minI = i;
      minimum = nums[i];
    }
  }

  bool alreadySorted = true;
  // check already sorted
  for (int i = 0; i < size - 1; i++) {
    if (nums[(minI + i) % size] > nums[(minI + i + 1) % size]) {
      alreadySorted = false;
      break;
    }
  }
  if (alreadySorted) return min(minI, size - 1 - minI + 1 + 2);

  // check is sorted by reverse
  for (int i = 0; i < size - 1; i++) {
    if (nums[(minI - i + size) % size] > nums[(minI - i - 1 + size) % size])
      return -1;
  }

  return 1 + min(minI + 1, size - 1 - minI);
}
```

## 고생한 점
