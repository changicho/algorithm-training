# 5653. [모의 SW 역량테스트] 줄기세포배양

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo)

난이도\_49%

## 정리

내 코드 : 999 ms;
빠른 코드 : 24 ms;

너무 복잡하고 어려웠던 문제.

줄기 세포가 3가지 상태를 지닌다. (활성 전, 활성, 사망)
시간이 지날 때마다 활성 전과 활성 상태의 세포에 대한 동작을 동시에 해줘야한다.

새로 복제된 세포는 timer를 줄이면 안되므로 새로 복제되었는지 여부를 판단이 필요하다.

따라서 세포 상태의 구성은 다음과 같이 했다.

```cpp
struct cell {
  int timer;  // 남은 생명력
  int power;  // 원래 지니고 있던 생명력
  bool isActivated; // 활성화 상태인지 판단
  bool isAlive; // 죽었는지 아닌지 판단
  bool isNew;   // 새로 복제되었는지 아닌지 판단
};
```

## 고생한 점

### 무한한 공간

공간의 확장이 무한히 이루어 질 수 있는 경우이다.
최대 시간 K가 정해져 있으므로, 최대 범위는 다음으로 한정지을 수 있다.
150+50+150
한 방향당 150개 까지 복제가 가능하고, 최초 입력시 최대 50개 까지 입력이 가능하기 때문.

다만 탐색 시 저걸 전부 탐색하기엔 시간이 모자라므로,
range를 지정해주어 필요한 범위만 탐색하도록 구현했다.

```cpp
struct range {
  int min;
  int max;
};
```

range를 갱신할 때는 다음을 조심해야 한다.

```cpp
// range 갱신
if (y == Y.max) {
  Y.max++;
} else if (y < Y.min) {
  Y.min--;
}
if (x == X.max) {
  X.max++;
} else if (x < X.min) {
  X.min--;
}
```

min 범위는 대소비교지만, max 범위는 동등비교임에 주의하자.

### 자리 싸움

새로 복제되는 세포 끼리는 생명력으로 자리 싸움을 수행한다.
이 부분 때문에 isNew flag를 추가했다.

### 디버깅

도데체 어떻게 디버깅을 해야 할 지 감도 안잡히는 문제였다.
각 time 별로 상태를 print 해서 예시와 비교해보며 디버깅을 수행했다.

```cpp
void print() {
  cout << "\n###print status###\n";
  for (int y = Y.min; y < Y.max; y++) {
    for (int x = X.min; x < X.max; x++) {
      if (!cells[y][x].isAlive && cells[y][x].isActivated) {
        cout << "D";
      } else {
        if (cells[y][x].isActivated) {
          cout << "A";
        } else {
          cout << cells[y][x].power;
        }
      }
    }
    cout << "\n";
  }
}
```

특별한 상황인 경우는 문자로 상태를 출력해서 상황을 판단했다.

## 개선 아이디어

속도가 999ms나 나오는 것을 봤을 때 개선할 부분이 많다.

1. 복제할 세포들을 모아서 생명력이 높은 순으로 복제를 수행한다면 자리 싸움시 좀더 편해진다.
