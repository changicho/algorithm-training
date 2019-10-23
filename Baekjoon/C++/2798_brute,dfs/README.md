# 2798. 블랙잭

[링크](https://www.acmicpc.net/problem/2798)

난이도\_40%

## 정리

dfs를 이용해 완전 탐색해서 풀이한 문제.

```cpp
dfs(index + 1, count + 1, sum + cards[index]);
dfs(index + 1, count, sum);
```

이 방법을 요긴하게 잘 써먹고 있다.

### 실수한 부분

맨 마지막 세 카드가 연달아 답인 경우, index == N 이지만 답을 갱신해야 한다.
이 부분을 고려하지 않고 index == N 이면 return 해버려 오류가 발생했다.

재귀함수의 경우 return 처리를 정말 잘 생각해야한다는 교훈을 다시 얻었다.
