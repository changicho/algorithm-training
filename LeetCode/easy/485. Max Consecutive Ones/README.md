# 485. Max Consecutive Ones

[링크](https://leetcode.com/problems/max-consecutive-ones/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

한번 순회하며 연속된 1의 갯수를 센다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

연속된 1의 갯수를 세는데 O(1)의 공간 복잡도로 구현 가능한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      57      |    O(N)     |    O(1)     |

원소를 순회하며 1이 있는 경우 count를 증가시키고, 0인 경우 count를 초기화시킨다.

이를 반복하며 정답을 갱신한다.

```cpp
int findMaxConsecutiveOnes(vector<int>& nums) {
  int count = 0;
  int answer = 0;
  for (int& n : nums) {
    if (n == 1) {
      count++;
    } else {
      count = 0;
    }

    answer = max(answer, count);
  }
  return answer;
}
```

## 고생한 점
