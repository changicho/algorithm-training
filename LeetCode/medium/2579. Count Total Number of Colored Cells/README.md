# 2579. Count Total Number of Colored Cells

[링크](https://leetcode.com/problems/count-total-number-of-colored-cells/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

순차적으로 탐색하며 정답을 구할 경우 O(N)의 시간 복잡도가 필요하다.

수식을 이용해 구할 경우 O(1)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 과정마다 수를 더할 경우 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

각 과정마다 추가되는 셀의 갯수는 다음과 같다.

- 1번째 과정 : 1
- 2번째 과정 : 1 + 4
- 3번째 과정 : 1 + 4 + 8
- ...

각 단계마다 직전 단계 X \* 4 개 만큼의 셀이 늘어난다.

이는 현재 X번째 과정에서 상, 하, 좌, 우 4개 부분에서 중앙에서부터 변의 길이만큼 갯수가 증가하기 때문이다.

이를 구현하면 다음과 같다.

```cpp
long long coloredCells(int n) {
  long long answer = 1;

  for (int i = 1; i < n; i++) {
    answer += 4 * i;
  }

  return answer;
}
```

### 등차수열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

위 식은 등차수열이며 아래와 같이 구할 수 있다.

```cpp
long long coloredCells(int n) { return 1 + (long long)n * (n - 1) * 2; }
```

## 고생한 점
