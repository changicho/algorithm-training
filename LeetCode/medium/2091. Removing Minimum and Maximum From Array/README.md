# 2091. Removing Minimum and Maximum From Array

[링크](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회하며 가장 극값의 index를 찾는다.

이후 두 index를 이용해 정답을 계산한다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 극값을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

순회하며 가장 큰 값, 작은 값의 index를 찾는다.

두 index중 작은값과 큰값을 각각 A, B라 하고 정답은 다음 3가지 경우 중 하나이다.

- 둘다 front로 삭제하는경우 : B + 1
- 양 방향으로 삭제하는 경우 : (A + 1) + (N - 1 - B) + 1;
- 둘다 끝방향으로 삭제하는 경우 : (N - 1 - A) + 1;

세 경우 모두 판단 후 정답을 반환한다.

```cpp
int minimumDeletions(vector<int>& nums) {
  int size = nums.size();
  int minI = 0, maxI = 0;

  for (int i = 0; i < size; i++) {
    if (nums[i] < nums[minI]) {
      minI = i;
    }
    if (nums[i] > nums[maxI]) {
      maxI = i;
    }
  }

  int answer = INT_MAX;
  int left = min(minI, maxI), right = max(minI, maxI);

  answer = min(
      {right + 1, left + 1 + (size - 1 - right) + 1, size - 1 - left + 1});

  return answer;
}
```

## 고생한 점
