# 17219. 비밀번호 찾기

[링크](https://www.acmicpc.net/problem/17219)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver IV |   69.685    |

## 설계

### 시간 복잡도

1 ≤ N, M ≤ 100,000이므로 배열에 저장후 순서대로 탐색 할 경우 시간 복잡도는 O(NM) 이므로 제한시간 내에 불가능하다.

따라서 검색에 logN 이하가 걸려야 하므로 map 자료구조를 사용한다.

이 경우 시간 복잡도는 O(Nlog(M)) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

key, value 모두 string으로 선언한다.

### map

insert

```cpp
cin >> id >> password;

m[id] = password;
m.insert({id, password});
```

find

```cpp
cin >> id;

cout << m[id] << "\n";
cout << m.find(id)->second << "\n";
```

### hash map

사용법은 map과 동일하다.

```cpp
unordered_map<string, string> m;
```

### string.reserve()

reserve() 함수를 호출하여, 컨테이너 용량(최대로 담을수 있는 원소의 갯수)을 내가 예측할수 있는 최대 범위 범위만큼 할당할 수 있다.

이 경우 이후에 재할당 비용을 아낄 수 있다.

- size() : 현재 원소의 갯수를 알려 준다. (함수 호출에 따른 부하는 거의 없음)
- capacity() : 최대 용량을 알려 준다. (더 담을수 있는 용량이 아닌 최대 용량이다)
- resize(size_t n) : 컨테이너의 원소의 갯수를 인자 만큼 늘려주거나 줄여 준다.
- reserve(size_t n) : 최대 용량을 n개로 만들어 준다. (기존 최대용량보다 작으면 무시)

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     132      |       36       |

## 고생한 점
