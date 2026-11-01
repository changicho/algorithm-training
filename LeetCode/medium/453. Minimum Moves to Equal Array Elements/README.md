# 453. Minimum Moves to Equal Array Elements

[링크](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

수학을 이용해 최소값과의 차이를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

최소값 저장에 O(1)의 공간 복잡도를 사용한다.

### 최소값

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

문제 조건에 따라서 N-1개의 원소의 값을 1 증가시키는 연산은

반대로 1개의 값을 1 감소시키는 연산과 총 값들의 차이에 대해서는 동일하다.

따라서 매번 가장 큰 값을 최소값에 맞춰 1씩 감소 시키는 연산으로 변환 후 횟수를 구한다.

```cpp
int minMoves(vector<int>& nums) {
  int answer = 0;
  int minimum = *min_element(nums.begin(), nums.end());

  for (int& num : nums) {
    answer += num - minimum;
  }
  return answer;
}
```

## 고생한 점
