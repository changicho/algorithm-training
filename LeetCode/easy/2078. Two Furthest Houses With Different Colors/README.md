# 2078. Two Furthest Houses With Different Colors

[링크](https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

완전 탐색을 진행할 경우 O(N^2)의 시간 복잡도를 사용한다.

순회를 이용해 풀이할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

탐색에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

정답이 될 수 있는 경우는 양끝을 제외한 특정 위치의 색이 양 끝의 색과 다른 경우이다.

(가장 큰 index차이를 만들 수 있다.)

따라서 index를 순회하며 맨앞, 맨끝과 비교해 색이 다른 경우 정답을 갱신한다.

```cpp
int maxDistance(vector<int>& colors) {
  int size = colors.size();

  int answer = 0;
  for (int i = 0; i < size; i++) {
    int cur = colors[i];
    if (colors[0] != cur) {
      answer = max(answer, i);
    }
    if (colors[size - 1] != cur) {
      answer = max(answer, size - 1 - i);
    }
  }
  return answer;
}
```

## 고생한 점
