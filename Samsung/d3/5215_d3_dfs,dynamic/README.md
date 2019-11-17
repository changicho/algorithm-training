# 5215. 햄버거 다이어트

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-lPB6dHUDFAVT&categoryId=AWT-lPB6dHUDFAVT&categoryType=CODE)

난이도\_d3_44%

## 정리

내 코드 : 129 ms
빠른 코드 : 2 ms

깊이 우선 탐색으로 가능한 조합을 구하고, 기준을 초과하면 제거.

```cpp
for (int i = start; i < checked.size(); i++) {
    if (checked[i]) {
        continue;
    }

    checked[i] = true;
    dfs(checked, i, score + scores[i], calorie + calories[i]);
    checked[i] = false;
}
```

위 방법으로 실행했을 경우 시간 초과 에러가 났다.

```cpp
dfs(start + 1, score, calorie);
dfs(start + 1, score + scores[start], calorie + calories[start]);
```

따라서 탐색 시 현재 정보를 더한 경우와 더하지 않은 경우를 동시해 탐색 시키도록 구현.

이 방법의 경우는 탐색하는 양이 2^N 개의 경우가 된다.

좀더 공부해야 할 필요가 있다.
