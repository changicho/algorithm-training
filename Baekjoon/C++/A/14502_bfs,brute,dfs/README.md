# 14502번. 연구소

[링크](https://www.acmicpc.net/problem/14502)

난이도\_54%

## 정리

내 코드 : 36 ms;

모든 경우에 기둥을 놓아보고, 그때마다 결과를 분석하는 문제.

기둥을 3개를 놓아야 하므로 기둥을 놓는 위치는 dfs로 탐색했다.

박테리아가 증식하는것은 bfs로 구현

상황을 파악하기 위한 print 함수

```cpp
void print(int current_map[][8]) {
  cout << "\n### print map ###\n";
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cout << current_map[y][x];
    }
    cout << "\n";
  }
}
```

이차원 배열을 넘기고 싶을 땐 저렇게 넘기면 된다.

### 고생한 점

dfs를 호출하면서, 이전에 탐색했던 좌표부터 시작해야한다.

y축은 그대로 진행하면 되나, x축 좌표의 경우
그 행을 전부 탐색한 뒤에는 0부터 탐색해야 한다.

```cpp
 // 진행 중이던 상황부터 진행
  for (int x = start_x; x < M; x++) {
    // 같은 y인덱스를 가진 것 탐색
    // 비어있어야 기둥을 놓을 수 있음
    if (map[start_y][x] == 0) {
      map[start_y][x] = 3;
      dfs(depth + 1, start_y, x);
      map[start_y][x] = 0;
    }
  }

  // y번째 일 때 탐색 완료했으므로 y+1부터
  for (int y = start_y + 1; y < N; y++) {
    for (int x = 0; x < M; x++) {
      // 비어있어야 기둥을 놓을 수 있음
      if (map[y][x] == 0) {
        map[y][x] = 3;
        dfs(depth + 1, y, x);
        map[y][x] = 0;
      }
    }
  }
```

y+1부터 탐색하는 코드에서 if문을 써주지 않은 오류,
map[start_y][x]를 탐색하는 오류 때문에 시간을 잡아먹었다.

이를 확인하기 위해선 3X3정도의 작은 map에서
print()함수를 호출하면서 확인하는것이 가장 빠르다.
