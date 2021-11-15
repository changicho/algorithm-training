# 359. Logger Rate Limiter

[링크](https://leetcode.com/problems/logger-rate-limiter/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

shouldPrintMessage 연산의 개수를 N이라 하자.

10초 전까지의 message를 저장해야 하며 이는 같은 message가 나왔을 때를 판단해야 한다.

최악의 경우 message는 N개까지 쌓일 수 있다.

입력받은 message가 프린트 가능한지 탐색 하는데 hash map을 이용할 경우 O(1)의 시간 복잡도로 탐색 가능하다.

### 공간 복잡도

hash map에 O(N)의 공간복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      68      |    O(1)     |    O(N)     |

unordered_map을 이용해 해당 message가 마지막으로 출력된 시간을 저장해 사용할 수 있다.

이 경우 hash map에 초기값에 0이 부여되므로 timestamp가 0으로 입력되는 경우를 피하기 위해 1초씩 더한 값을 hash map에 저장한다.

출력 가능한 경우는 hash map을 갱신하고 true를 반환하고 그 외의 경우는 false만 반환한다.

```cpp
class Logger {
 private:
  unordered_map<string, int> um;  // last printed

 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message) {
    // not found or over 10 seconds
    if (um[message] == 0 || timestamp - (um[message] - 1) >= 10) {
      um[message] = timestamp + 1;
      return true;
    }

    return false;
  }
};
```

혹은 find연산을 이용해 0인 경우를 따로 처리하지 않을 수 있다.

```cpp
class Logger {
 private:
  unordered_map<string, int> um;  // last printed

 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message) {
    // not found or over 10 seconds
    if (um.find(message) == um.end() || timestamp - um[message] >= 10) {
      um[message] = timestamp;
      return true;
    }

    return false;
  }
};
```

## 고생한 점

hash map에 저장되지 않은 값을 찾기 위해 key를 이용할 때, 검색과 동시에 0으로 초기화 될 수도 있으므로 key로 직접 접근하지 않는걸 추천
