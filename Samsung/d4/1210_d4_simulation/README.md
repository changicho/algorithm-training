# 1210. [S/W 문제해결 기본] 2일차 - Ladder1

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14ABYKADACFAYh&categoryId=AV14ABYKADACFAYh&categoryType=CODE&&&)

난이도 : d4
정답률 : \_67%

## 설계

map[100][100] 요소를 전부 입력받아야한다.

2를 입력받은 위치를 저장하고, 그 위치 바로 위칸부터 탐색을 시작한다.

현재 위치에서 좌, 우에 사다리가 있는지 확인하고 있으면 가로 사다리의 끝 점까지 이동한다.

없는경우 이동하지 않고 현재 위치에 머무른다.

한칸 올라간다.

이를 y=0일때까지 반복한다.

## 정리

내 코드 : 17 ms;
빠른 코드 : 5 ms;

### 가로 사다리 이동의 구현

좌, 우로 이동시 x의 증가, 감소값을 담은 directions 배열을 이용했다.

```cpp
for (int dir : directions) {
  if (start.x + dir < 0 || start.x + dir >= 100) {
    continue;
  }
  // 현재 위치에서 좌 우로 사다리가 연결되어 있는지 확인
  if (map[start.y][start.x + dir]) {
    int next_x = start.x;
    // 현재 위치에서 다음점으로 이동 가능한지 확인
    // 양 끝점을 초과하는 것을 막기 위함
    while (map[start.y][next_x + dir]) {
      // 이동
      next_x += dir;
      // 이동한 좌표가 양 끝이라면 탐색 중지
      if (next_x == 0 || next_x == 99) {
        break;
      }
    }
    // x좌표 이동
    start.x = next_x;
    break;
  }
}
// y좌표 이동
start.y -= 1;
```

## 고생한 점

사다리의 정보만 입력되는것이 아닌, 몇 번째 인지도 입력을 받기 때문에
이 부분을 처리해야 했다.

start point의 y좌표는 맨 아래에서 두 번째 여야 한다.

이는 98번쨰 index이다.
