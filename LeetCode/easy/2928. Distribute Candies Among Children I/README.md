# 2928. Distribute Candies Among Children I

[링크](https://leetcode.com/problems/distribute-candies-among-children-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수에서 한 인원이 가질 수 있는 최대 수를 N이라 하자.

모든 경우를 직접 탐색할 경우 O(N^3)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

완전 탐색을 수행할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      19      |   O(N^3)    |    O(1)     |

세 인원이 고를 수 있는 수들의 모든 쌍에 대해 비교를 진행한다.

```cpp
int distributeCandies(int n, int limit) {
  int answer = 0;
  for (int i = 0; i <= limit; i++) {
    for (int j = 0; j <= limit; j++) {
      for (int k = 0; k <= limit; k++) {
        if (i + j + k != n) continue;
        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
