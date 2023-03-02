# 17608. 막대기

[링크](https://www.acmicpc.net/problem/17608)

|  난이도   |
| :-------: |
| 브론즈 II |

## 설계

### 시간 복잡도

막대기의 갯수를 N이라 하자.

오른쪽에서 부터 순회하며 현재 막대기의 높이가 이전 막대기의 높이보다 높은 경우에만 count를 증가시킨다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

막대기를 순회하며 높이를 저장할 배열이 필요하다.

이 경우 공간 복잡도는 O(N)이다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

현재 막대기의 높이가 이전 막대기의 높이보다 높은 경우에만 count를 증가시킨다.

```cpp
int solution(int size, vector<int> &sticks) {
  int answer = 0;
  int temp = -1;

  for (int i = size - 1; i >= 0; i--) {
    if (sticks[i] > temp) {
      answer++;
      temp = sticks[i];
    }
  }

  return answer;
}
```

## 고생한 점
