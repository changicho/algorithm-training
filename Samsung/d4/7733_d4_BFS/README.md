# 7733. 치즈 도둑

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWrDOdQqRCUDFARG&categoryId=AWrDOdQqRCUDFARG&categoryType=CODE)

난이도 : d4
정답률 : \_42%

## 설계

치즈를 먹는 (0으로 바꾸는) 동작을 수행할 필요는 없다.

남은 치즈 덩어리를 셀 때, 현재 일수 이하의 경우는 0으로 처리하면 되기 때문.

```cpp
for(1부터 100까지){
  answer = max(answer, 덩어리를 세는 함수());
}
```

숫자를 지운 자리를 0이라 하자.

덩어리를 세는 방법 :

```cpp
for(y축 탐색){
  for(x축 탐색){
    if(현재 위치 방문했는지? || map[y][x] <= day){
      continue;
    }
    현재 위치 방문;
    count++;

    현재 위치에서 BFS로 인접 지역 방문함

  }
}

if(모든 맵이 0 이면){
  return count;
}
```

visited를 이용해 방문한 치즈를 방문하지 않도록 설계했다.

## 정리

내 코드 : 498 ms;
빠른 코드 : 62 ms;

### memset을 이용한 배열 초기화

```cpp
int visited[101][101];
memset(visited, 0x00, sizeof(visited));
```

```cpp
int visited[101][101]{
  0,
};
```

위쪽의 방법이 아래쪽보다 빠르다.

## 고생한 점

### day 가 최대 값일 때 무한루프에 빠짐

치즈 day의 최대의 경우 전부 먹어버린 상태이므로 0이 되어 무한루프에 빠지기 때문.

최대 day인 경우 루프를 돌지 않게 처리함.

### 각 day마다 좌표 배열을 이용한 메모이제이션

```cpp
vector<axis> days[101];
```

위와 같은 axis의 모음인 vector를 선언해 관리하려 했으나, 위 방법의 경우 그 날짜인 axis만 탐색하므로 치즈 덩어리를 만드는 데 어려움이 있다.
