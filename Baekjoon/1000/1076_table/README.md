# 1076. 저항

[링크](https://www.acmicpc.net/problem/1076)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Bronze II |   39.659    |

## 설계

### 시간 복잡도

색의 경우가 10가지 이내이므로 전부 순회해서 풀더라도 O(30) 이내이다.

### 공간 복잡도

최악의 경우 990억이므로 long long형으로 선언한다.

### map을 이용

map을 이용해 자료를 용이하게 관리한다.

```cpp
struct Ohm {
  long long value;
  long long multi;
};

map<string, Ohm> ohms = {
    {"black", {0, (long long)pow(10, 0)}},
    {"brown", {1, (long long)pow(10, 1)}},
    {"red", {2, (long long)pow(10, 2)}},
    {"orange", {3, (long long)pow(10, 3)}},
    {"yellow", {4, (long long)pow(10, 4)}},
    {"green", {5, (long long)pow(10, 5)}},
    {"blue", {6, (long long)pow(10, 6)}},
    {"violet", {7, (long long)pow(10, 7)}},
    {"grey", {8, (long long)pow(10, 8)}},
    {"white", {9, (long long)pow(10, 9)}}};
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
