# 1211. [S/W 문제해결 기본] 2일차 - Ladder2

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14BgD6AEECFAYh&categoryId=AV14BgD6AEECFAYh&categoryType=CODE)

난이도 : d4
정답률 : \_70%

## 설계

정답 x좌표와 min 값을 세팅한다. (min은 100\*100으로 설정)

map[100][100] 요소를 전부 입력받아야한다.

제일 마지막 끝점의 위치들을 저장한다.

각 위치부터 탐색을 시작하며 count를 0으로 세팅한다.

현재 위치에서 좌, 우에 사다리가 있는지 확인하고 있으면 가로 사다리의 끝 점까지 이동한다.

이동하는 만큼 count를 증가한다.

없는경우 이동하지 않고 현재 위치에 머무른다.

y좌표를 한칸 위로 움직이며 count를 증가한다.

이를 y=0일때까지 반복한다.

## 정리

내 코드 : 17 ms;
빠른 코드 : 1 ms;

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
