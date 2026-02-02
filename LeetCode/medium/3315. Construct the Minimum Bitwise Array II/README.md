# 3315. Construct the Minimum Bitwise Array II

[링크](https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N, 최대값을 M이라 하자.

각 원소에 대해 모두 비트연산으로 답을 구할 경우 O(N \* M)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

비트 연산을 이용해 각 원소에 대해 빠르게 구할 수 있다. 이 경우 O(N \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 비트 연산

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(M)) |    O(N)     |

`3314. Construct the Minimum Bitwise Array I`와 같은 문제

```cpp
vector<int> minBitwiseArray(vector<int>& nums) {
  int size = nums.size();

  vector<int> answer(size);
  for (int i = 0; i < size; i++) {
    int x = nums[i];
    int res = -1;
    int d = 1;
    while ((x & d) != 0) {
      res = x - d;
      d <<= 1;
    }

    answer[i] = res;
  }
  return answer;
}
```

## 고생한 점
