# B - 1D Akari

[링크](https://atcoder.jp/contests/abc416/tasks/abc416_b)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회를 이용해 문자열을 한 번만 탐색하므로 시간 복잡도는 O(N)이다.

순회와 동시에 탐욕 알고리즘을 사용해 가장 유리한 위치에 'o'를 배치한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 순회 & 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

o 문자 사이에는 최소한 하나의 # 문자가 있어야 한다.

순회하며 현재 가능한 경우 o를 배치한다.

#을 만날 때마다 배치가 가능하도록 flag를 설정하며, o를 배치한 후에는 flag를 해제한다.

이 때 최초 상태는 배치가 가능하므로 flag를 true로 설정한다.

```cpp
string solution(string &s) {
  int size = s.size();

  bool find = true;
  string answer = "";

  for (int i = 0; i < size; i++) {
    if (s[i] == '#') {
      find = true;
      answer += '#';
      continue;
    } else {
      if (find) {
        answer += 'o';
        find = false;
      } else {
        answer += '.';
      }
    }
  }

  return answer;
}
```

## 고생한 점
