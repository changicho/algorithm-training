# 14889번. 스타트와 링크

[링크](https://www.acmicpc.net/problem/14889)

난이도\_50%

## 정리

내 코드 : 20 ms;
빠른 코드 : 0 ms;

1. 최대 20명의 인원을 10명, 10명 씩 나눈다.
2. 나누는 경우가 여러가지가 있을 수 있으므로 각 경우마다의 점수 차를 계산한다.
3. 점수 차가 0점이 나온 경우, 그 이상 탐색이 무의미하므로 탐색을 중지한다. (backtracking)

answer의 값이 나올 수 있는 가장 극단적인 경우

- 총 20명일 때, 한팀은 점수가 0점이다.
- 한 팀은 각각 시너지를 100점씩 받을 수 있다.
- 한사람이 다른 팀원에게 받을 수 있는 점수 900, 10명이므로 10을 곱합 9000

따라서 초기 answer의 값을 10000으로 시작했다.

각 팀의 상태를 관리하기 위해 struct를 이용함

```cpp
struct team {
  int total;
  vector<int> list;
};
```

팀을 분배하는 과정은 dfs로 수행

```cpp
dfs(int index, team team1, team team2){
  if (index == N) {
    answer = min(answer, abs(team1.total - team2.total));
    return;
  }
  // backtracking
  if (answer == 0) {
    return;
  }
  // ...
}
```

### 헷갈렸던 점

맨 처음 team1의 인원수를 따로 인자로 받아 구현했으나, 제대로 처리되지 않았다.

이는 index를 처음부터 끝까지 탐색할 때, 전부 team1에 소속되어있는 경우 index/2 번째부터 답을 구하려고 하기 때문이다.

따라서 모든 인원을 팀으로 배정했을 때 answer를 갱신하는 방식으로 변경했다.
