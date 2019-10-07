# 6057. 그래프의 삼각형

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWbHcWd6AFcDFAV0&categoryId=AWbHcWd6AFcDFAV0&categoryType=CODE)

난이도\_d3_35%

## 정리

내 코드 : 770 ms;
빠른 코드 : 17 ms;
내 코드 (개선) : 117 ms;

모든 경우의 수를 탐색하고, 중복의 경우를 처리하면 된다.

정점 탐색의 단계가 3단계 일 때, 현재 점과 시작한 점을 비교해 같으면 정답 증가.

```cpp
void dfs(int start, int current, int before, int depth) {
    if (depth == 2) {   // 시작이 0부터 이므로 0, 1, 2 번째가 3 단계이다.
        return;
    }
}
```

결국 마지막에 시작점으로 돌아와야 하므로 현재 정점에서 가능한 경우를 모두 탐색해야 한다.
이 경우 (시계방향, 반시계방향) * (첫 번째 점, 두 번째 점, 세 번째 점) 경우로
한 경우에 총 6개의 중복 경우가 생긴다. 따라서 답을 6으로 나눈 수가 정답. 770ms가 걸렸다.

시간을 줄이기 위해, n번째 일 때 n번째 미만의 정점은 탐색하지 않는 방식으로 변경.
(한쪽 방향으로만 탐색한다.)
그리고 2 단계의 경우에만 반대 방향으로 탐색을 진행한다.
이 방법으론 중복되는 경우의 수가 존재하지 않는다. 107 ms
