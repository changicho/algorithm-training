# A - Penalty Kick

[링크](https://atcoder.jp/contests/abc348/tasks/abc348_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

N까지 순회하며 성공하는 경우와 실패하는 경우를 계산한다. 이에 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답 문자열을 생성할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

1부터 N까지 순회하며 성공하는 경우와 실패하는 경우를 계산한다.

```cpp
string solution(int num) {
  string ret = string(num, 'o');

  for (int i = 2; i < num; i += 3) {
    ret[i] = 'x';
  }

  return ret;
}
```

## 고생한 점
