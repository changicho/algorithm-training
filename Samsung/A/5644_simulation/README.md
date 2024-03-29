# 5644. [모의 SW 역량테스트] 무선 충전

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRDL1aeugDFAUo)

난이도\_62%

## 정리

내 코드 : 11ms;
빠른 코드 : 2ms;

각 시간별로 A와 B를 이동시키며, 좌표에 따른 처리를 해주는 문제.

전체 map의 크기도 제한되어있고, AP의 갯수도 한정되어 있기 때문에 각 AP마다 지도를 만들었다.

```cpp
int map[10][10][8];
```

또한 유저 A와 B를 struct로 관리해 유저 정보를 모아서 관리.

```cpp
struct user {
  int x, y, sum;
};
```

각 테스트 케이스마다 초기화를 위해 clear() 함수를 만들어 solution마다 실행함.

여기서 user_A와 user_B의 초기 좌표가 다름에 주의해야한다.

```cpp
void clear() {
  for (int ap = 0; ap < A; ap++) {
    for (int y = 0; y < 10; y++) {
      for (int x = 0; x < 10; x++) {
        map[y][x][ap] = 0;
      }
    }
  }
  user_A = {0, 0, 0};
  user_B = {9, 9, 0};
}
```

각 AP별로 범위를 지정해줘야했다. 마름모 꼴을 어떻게 만들지 고민했었고 다음과 같은 방법을 이용했다.

```cpp
for (int i = 0; i < 10; i++) {
  for (int j = 0; j < 10; j++) {
    int distance = abs(i - y) + abs(j - x); // 절대값을 이용

    if (distance <= range) {
      map[i][j][ap_num] = charge;
    }
  }
}
```

서로 같은 AP를 갖고 있다면 다음과 같은 경우가 생긴다.

- 서로 선택할 것이 지금 것밖에 없음
- A 혹은 B가 선택지가 더 많음
- 둘다 여러개 선택 가능

여기서 서로 선택할 것이 지금 것밖에 없는 경우를 제외하고는 한쪽이 차선을 선택하게 구현했다.

이는 서로 같은걸 선택하는것보다, 한쪽이 다른 것을 선택하는 경우가 무조건 이득이기 때문이다.

(현재 100에 머물러있고, A와 B가 가능한 선택지가 여러개일 경우 둘 다 다르게 선택하면 무조건 100 초과지만, 둘다 100을 선택하면 총 량이 100밖에 안된다.)

### 고생한점

서로 같은것을 선택할 때만 충전량이 절반으로 줄어들어야 한다. 이 코드를 먼저 짜고 복사해서 붙여넣었더니 모든 충전량이 절반으로 줄어듬.

AP의 범위를 설정할 때 모두 탐색하지 않고 range만 탐색하려 했으나 실패

```cpp
int start_x = x - range, end_x = x + range;
int start_y = y - range, end_y = y + range;
```

10\*10이므로 모두 탐색해서 채워넣는것으로 변경했다.

각 유저의 초기 시작점이 다른 것을 깜빡해 실수를 저질렀다.

moves의 좌표를 문제와 동기화 시키지 않는 실수를 저질렀다.

```cpp
struct axis {
  int x, y;
};
axis moves[5] = {{0, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 0}};
```

x축은 -1, +1을 파악하기가 쉬웠으나 y축에서 정 반대로 움직임을 확인

- 이 오류를 찾는 가장 좋은 방법은, 시간별 움직임을 경로로 그리고 출력하는 것이다.
