# 3963. Create Grid With Exactly One Path

[링크](https://leetcode.com/problems/create-grid-with-exactly-one-path/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 M, N이라 하자.

모든 원소를 벽으로 만든 뒤 하나의 경로만 길로 만들 수 있다.

2차원 정답 배열을 생성하는데 O(MN)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(MN)의 공간 복잡도를 사용한다.

### 탐욕알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(MN)    |    O(MN)    |

모든 칸을 #으로 채운 2차원 배열을 만든다.

이후 특정 하나의 경로만 길로 만든다.

```cpp
vector<string> createGrid(int m, int n) {
  vector<string> answer(m, string(n, '#'));

  for (int x = 0; x < n; x++) {
    answer[0][x] = '.';
  }
  for (int y = 1; y < m; y++) {
    answer[y][n - 1] = '.';
  }
  return answer;
}
```

## 고생한 점
