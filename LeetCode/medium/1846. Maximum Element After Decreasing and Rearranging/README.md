# 1846. Maximum Element After Decreasing and Rearranging

[링크](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 원소의 갯수를 N이라 하자.

조건에 맞게 가장 큰 수를 만들기 위해 오름차순으로 배치하는 것이 유리하다. 따라서 오름차순으로 정렬 후 각 index까지 최대값을 할당하며 정답을 구할 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도이다.

유효한 답은 최대 N이므로 카운팅 정렬을 사용할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최악의 경우 O(N)의 공간 복잡도를 사용한다.

카운팅 정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      97      | O(N \* log_2(N)) |    O(N)     |

두 숫자의 위치를 변경하거나, 하나의 숫자를 감소시키는 연산을 수행할 수 있다.

이 때 시작숫자는 1이여야 하므로 왼쪽에 작은 값들이 위치하게 된다. 따라서 오름차순으로 정렬하는 편이 유리하다.

이후 직전값에 1을 더한 값으로 현재 수를 감소시킨다.

만약 현재 값이 직전 값과 같은 경우 증가시킬 수 없음에 유의한다.

이후 맨 오른쪽 값이 정답이 된다.

```cpp
int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
  int size = arr.size();

  sort(arr.begin(), arr.end());
  arr[0] = 1;
  for (int i = 1; i < size; i++) {
    arr[i] = min(arr[i], arr[i - 1] + 1);
  }

  return arr.back();
}
```

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      80      |    O(N)     |    O(N)     |

위 방법에서 유효한 정답의 범위는 1~N 이므로 카운팅 정렬을 사용할 수 있다.

현재 숫자를 x라 할 때 직전까지 순회했을 때 최대값에 x개 만큼의 수를 증가시킬 수 있다.

이 때 x를 초과해서 증가시킬 수 없음에 유의한다.

```cpp
int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
  int size = arr.size();
  vector<int> counts(size + 1);

  for (int &num : arr) {
    counts[min(num, size)]++;
  }

  int answer = 1;
  for (int num = 2; num <= size; num++) {
    answer = min(answer + counts[num], num);
  }

  return answer;
}
```

## 고생한 점
