# 1427. Perform String Shifts

[링크](https://leetcode.com/problems/perform-string-shifts/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, 배열 shift의 길이를 M이라 하자.

매번 직접 shift를 수행할 경우 O(N \* M)의 시간 복잡도가 소요된다.

시작 index를 계산한 뒤 정답을 생성할 경우 O(N + M)의 시간 복잡도가 소요된다.

### 공간 복잡도

정답 문자열에 O(N)의 공간 복잡도가 필요하다.

### index 이동

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(N)     |

문자열을 shift하는 것을 시작 index를 이동시킨 뒤 추후에 문자열을 생성하는 방법으로 변환한다.

shift를 순회하며 시작 index를 변환한 뒤 정답을 생성한다.

이 때 이동 횟수가 N을 넘어가는 경우 무의미하므로 N으로 나눈 나머지를 이용한다.

```cpp
string stringShift(string s, vector<vector<int>>& shift) {
  int size = s.size();

  int start = 0;
  for (vector<int>& oper : shift) {
    int dir = oper[0], amount = oper[1];

    amount %= size;

    if (dir == 0) {
      start = (start + size + amount) % size;
    } else {
      start = (start + size - amount) % size;
    }
  }

  s += s.substr(0, start);
  s.erase(0, start);
  return s;
}
```

## 고생한 점
