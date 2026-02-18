# 401. Binary Watch

[링크](https://leetcode.com/problems/binary-watch/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

모든 시간에 대해 탐색할 경우 O(1)의 시간 복잡도를 사용한다. (60 \* 12 = 720)

### 공간 복잡도

모든 경우를 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

가능한 모든 조합에 대해서 탐색하며 이때 켜진 LED의 개수가 입력받은 수와 같은 경우에만 정답에 추가한다.

```cpp
vector<string> readBinaryWatch(int turnedOn) {
  vector<string> answer;

  for (int h = 0; h < 12; ++h) {
    for (int m = 0; m < 60; ++m) {
      if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
        string cur = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
        answer.push_back(cur);
      }
    }
  }

  return answer;
}
```

## 고생한 점
