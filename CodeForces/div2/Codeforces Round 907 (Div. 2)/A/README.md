# A. Sorting with Twos

[링크](https://codeforces.com/contest/1891/problem/A)

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

배열을 순회하며 오른쪽 값과 같이 감소되는 index들을 찾는다.

이후 같이 감소되는 index끼리 양옆의 값의 대소를 비교한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

배열의 크기 할당에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

문제에서 주어진 조건으로 한번에 감소시킬 수 있는 수의 갯수는 다음과 같다.

(맨 왼쪽부터 해당 갯수의 수를 감소시킴)

- 1
- 2
- 4
- 2^X...

여기서 현재 범위를 감소시킬 때만 같이 감소되는 값들이 존재한다.

감소되는 index들을 묶을 경우 다음과 같다.

- 0
- 0,1
- 0,1,2,3
- 0,1,2,3,4,5,6,7

위 경우 2,3과 4,5,6,7은 같이 감소되는 값의 index들이다.

따라서 같이 감소되는 index들인 경우 양옆의 값의 대소를 비교해야 한다.

만약 양 옆의 수를 비교했을 때 감소되는 경우 해당 구간은 내림차순이 유지된다.

```cpp
bool solution(vector<int> &nums) {
  int size = nums.size();
  int windowSize = 1;

  for (int i = 0; i < size - 1; i++) {
    if (i == windowSize - 1) {
      windowSize *= 2;
      continue;
    }
    if (nums[i] > nums[i + 1]) return false;
  }
  return true;
}
```

## 고생한 점
