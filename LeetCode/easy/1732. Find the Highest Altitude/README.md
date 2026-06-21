# 1732. Find the Highest Altitude

[링크](https://leetcode.com/problems/find-the-highest-altitude/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회하며 현재 값을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

시작값부터 gain을 더해가며 현재 값을 구하고 이 중 최대값을 구한다.

```cpp
int largestAltitude(vector<int>& gain) {
  int answer = 0;
  int cur = 0;
  for (int& g : gain) {
    cur += g;

    answer = max(answer, cur);
  }
  return answer;
}
```

## 고생한 점
