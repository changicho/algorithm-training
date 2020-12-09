# 11723. 집합

[링크](https://www.acmicpc.net/problem/11723)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver V |   29.905    |

## 설계

### 시간 복잡도

연산의 개수는 최대 3,000,000개 까지이며,

집합에 들어가는 수는 1~20까지이다.

set 자료구조를 사용하는경우

있는지 없는지의 여부를 판단할 때 log(N), 초기화 혹은 전부 넣는 경우 20씩 시간 복잡도가 걸린다고 할 때,

최악의 경우 시간 복잡도는 60,000,000 이고 이는 제한시간 내에 충분하다.

집합에 들어가는 수는 20까지이므로 비트마스크를 사용하는 경우 더 쉽게 구현 가능하다.

### 공간 복잡도

입력받는 자료들의 크기는 int형을 벗어나지 않는다.

### set을 이용한 방법

이 방법은 시간이 728ms 가량 소요되었다.

```cpp
set<int> s;

while (M--) {
  cin >> command;
  if (command == "add") {
    cin >> number;
    s.insert(number);
  } else if (command == "remove") {
    cin >> number;
    s.erase(number);
  } else if (command == "check") {
    cin >> number;

    if (s.find(number) != s.end()) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }

  } else if (command == "toggle") {
    cin >> number;

    if (s.find(number) != s.end()) {
      s.erase(number);
    } else {
      s.insert(number);
    }
  } else if (command == "all") {
    for (int i = 1; i <= 20; i++) {
      s.insert(i);
    }
  } else if (command == "empty") {
    s.clear();
  }
}
```

### 비트마스크를 이용한 방법

```text
- add : |(1 << number)
- remove : &(1 << number)
- check : &1
- toggle : ^1
- all : (1<<n) - 1
- empty : 0
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     616      |       36       |

## 고생한 점
