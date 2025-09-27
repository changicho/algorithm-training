# 611. Valid Triangle Number

[링크](https://leetcode.com/problems/valid-triangle-number/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

크기순으로 사용하기 위해 정렬을 수행해야 하므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

3개의 숫자를 골라야 한다.

이분 탐색을 이용해 나머지 숫자를 탐색할 경우 O(N^2 \* log_2(N))의 시간 복잡도를 사용한다.

선형 순회를 이용할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)만큼의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|     182      | O(N^2 * log_2(N)) |    O(N)     |

3개의 숫자를 A,B,C라 하자 (A <= B <= C)

여기서 세 숫자는 다음 조건을 만족해야 한다.

- A + B > C

A와 B에 대해 순회하며 나머지 C를 이분 탐색으로 찾는다.

```cpp
int triangleNumber(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  int answer = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      int right = nums[i] + nums[j];

      int k = lower_bound(nums.begin(), nums.end(), right) - nums.begin() - 1;

      // j+1 ~ k
      int count = k - (j + 1) + 1;
      if (count > 0) {
        answer += count;
      }
    }
  }

  return answer;
}
```

### 선형 스캔

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |   O(N^2)    |    O(N)     |

위 방법에서 A와 B를 순회하며 C는 이전에 찾은 위치부터 선형 탐색을 수행한다.

이 때 가능한 최대의 C를 고르며, 이때 가능한 쌍의 갯수는 B와 C 사이의 개수만큼이다.

```cpp
int triangleNumber(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  int answer = 0;
  for (int i = 0; i < size - 2; i++) {
    if (nums[i] == 0) continue;

    int k = i + 2;
    for (int j = i + 1; j < size - 1; j++) {
      while (k < size && nums[i] + nums[j] > nums[k]) {
        k++;
      }

      answer += (k - 1) - j;
    }
  }

  return answer;
}
```

## 고생한 점
