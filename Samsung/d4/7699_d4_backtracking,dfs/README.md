# 7699. 수지의 수지 맞는 여행

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqUzj0arpkDFARG&categoryId=AWqUzj0arpkDFARG&categoryType=CODE)

난이도 : d4
정답률 : \_51%

## 설계

### 자료구조

이미 방문한 알파벳은 방분하지 않으므로 visited['Z' - 'A'] 를 만들어 사용한다.

### backtracking

이미 정답의 max를 구한 경우, 더이상 탐색하지 않아도 된다.

가능한 max의 경우는 입력된 지도의 알파벳 종류 + 1이다.

따라서 dfs 함수에 다음 코드를 추가해준다

```cpp
if (answer > MAX) {
  return;
}
```

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  18 ms  |   18 ms   |

> 내 코드가 제일 빠른 코드이다.

## 고생한 점

처음에 BFS로 풀려고 한 경우 계속 시간초과가 발생했다.

DFS로 바꾼 뒤 완전탐색을 수행했을 때 약 3초정도의 시간이 걸렸다.
