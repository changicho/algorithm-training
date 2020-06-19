# 64063. 호텔 방 배정

[링크](https://programmers.co.kr/learn/courses/30/lessons/64063)

| 난이도 | 완료한 사람 |
| :----: | :---------: |
|  lv4   |     911     |

## 설계

### 시간복잡도

K의 범위 M만큼 visited 배열을 만들고 매 경우 탐색한다고 했을 때 시간복잡도는 NM 이며 이는 제한시간 내에 불가능하다.

방 번호가 겹쳤을 때, 빈 방이 있을 때 까지 연속해서 찾아가면 되므로 union find를 이용한다.

N은 줄일 수 없는 수 이므로 M을 줄여야 한다. 따라서 logM으로 줄이도록 다음 방법을 사용할 수 있다.

- map

따라서 시간 복잡도는 Nlog(M) 이며 이는 최악의 경우

```cpp
N*log(M) = 200000 * log(10^12) = 200000 * 40 = 8,000,000
```

이므로 제한 시간 내에 충분하다.

### 공간복잡도

K의 범위만큼 visited를 구현할 경우, 공간복잡도를 초과한다. 따라서 union find를 배열로 하는것이 아닌 map으로 구성한다.

c++의 map의 경우 해당 key의 값이 없는 경우 다음과 같이 판단할 수 있다.

```cpp
if (m.find(room) == m.end());
if (m[room] == 0);
if (m[room]);
```

이 경우 map의 size는 배열의 크기 200,000을 초과하지 않는다.

### union find

현재 방 번호를 세팅할 때, 연결된 다음 방 번호를 (현재 방 번호 + 1)로 연결한다.

이 경우 다음과 같은 구조이다

| 현재 방 번호 | 다음 방 번호 |
| :----------: | :----------: |
|      1       |      2       |
|      3       |      4       |

만약 현재 방 번호가 사용중일 경우에는, 현재 방 번호의 다음 방 번호를 탐색한다.

이를 반복하며 다음 방이 비어있는 경우 그 방을 배정한다.

이 때 union find를 사용해, 탐색한 모든 방들의 다음 방 번호를 갱신한다.

union find는 다음과 같이 구성한다.

```cpp
long long findRoom(long long room) {
  if (m.find(room) == m.end()) return room;

  return m[room] = findRoom(m[room]);
};
```

다음 방 번호는 다음과 같이 갱신한다.

```cpp
long long room_target = findRoom(room);
m[room_target] = room_target + 1;
```

## 고생한 점
