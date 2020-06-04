# 14891. 톱니바퀴

[링크](https://www.acmicpc.net/problem/14891)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   51.422    |

## 설계

### 시간 복잡도

회전은 총 100번이다.

하나의 톱니바퀴의 한번 회전마다 8번의 연산이 수행되고 톱니바퀴는 총 8개이다.

따라서 시간 복잡도는

```cpp
O(100*8*8) = O(6,400)
```

이므로 제한시간 2초 내에 충분하다.

## 공간 복잡도

정답은 최대 15까지이다.

따라서 정답은 int형으로 선언한다.

톱니바퀴 정보에서 표시해야 하는 내용은 다음 2가지이다.

- N극
- S극

따라서 톱니바퀴는 8개의 bool 원소를 가지는 2차원 배열로 설정한다.

각 톱니바퀴별로 struct를 생성하고 내부 메소드를 생성한다.

### Gear 구조체의 생성

구조체 내부 변수의 선언을 통해 회전을 구현했다.

vector를 사용하는 경우 insert와 erase, pop 등을 이용해 회전을 구현할 수 있다.

```cpp
struct Gear {
  int score;
  vector<bool> gear;

  Gear() { gear.resize(8, false); }

  int getScore() { return gear[0] ? score : 0; }

  bool getLeft() { return gear[6]; }
  bool getRight() { return gear[2]; }

  void turnClock() {
    gear.insert(gear.begin(), gear.back());
    gear.pop_back();
  }
  void turnCounterClock() {
    gear.push_back(gear.front());
    gear.erase(gear.begin());
  }
};
```

현재 gear를 회전할 때 양 옆의 gear가 영향을 받는지의 판단은 다음과 같이 수행한다.

먼저 각 gear들의 회전 여부를 나타내는 배열을 만든다

```cpp
int dirs[4] = {
    0,
};
```

왼쪽을 탐색하는 경우

```cpp
curDir = dir; // 입력받는 방향 정보를 임시로 저장
for (int i = index_gear; i >= 1; i--) {
  // 다음 바퀴에 영향을 주지 못하는 경우 탐색 중지
  if (gears[i].getLeft() == gears[i - 1].getRight()) {
    break;
  }

  curDir = -curDir;
  dirs[i - 1] = curDir;
}
```

오른쪽을 탐색하는 경우

```cpp
curDir = dir;
for (int i = index_gear; i < 3; i++) {
  if (gears[i].getRight() == gears[i + 1].getLeft()) {
    break;
  }

  curDir = -curDir;
  dirs[i + 1] = curDir;
}
```

각 경우별로 iterator의 index 초기값 과 증감이 다름에 유의한다.

이후 각 gear들을 방향에 따라 회전시킨다

```cpp
for (int i = 0; i < 4; i++) {
  if (dirs[i] == -1) {
    gears[i].turnCounterClock();
  }
  if (dirs[i] == 1) {
    gears[i].turnClock();
  }
}
```

### struct 내부 변수 값의 원하지 않는 변경

Gear의 데이터 종류를 다음과 같이 설정하고 입력시 처음 각 gear 들의 score를 초기화했다.

```cpp
struct Gear {
  int score;
  bool gear[8];

  // ...
}

for (int i = 0; i < 4; i++) {
  string line;
  cin >> line;

  for (int c = 0; c < 8; c++) {
    gears[i].gear[c] = line[c] == '0' ? false : true;
  }
  gears[i].score = 1 << i;
}
```

이 때 simulation 이후 각 gear들의 score가 엉뚱하게 변경 되는 오류가 발생했다.

두 가지 방법으로 이를 해결했다.

- bool[8] 대신 vector 를 이용
- simulation 이후 다시 score를 초기화

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
