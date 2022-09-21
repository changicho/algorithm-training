# Problem A1: Weak Typing - Chapter 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/A1)

| 난이도 |
| :----: |
| 10 pt  |

## 설계

### 시간 복잡도

문자열 T의 길이를 N이라 하자.

한번씩 순회하며 직전에 입력했던 O, X에 대해서 체크하고 변경될 때마다 이를 센다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

직전에 입력한 문자가 O, X인지에 대해서 체크할 변수가 필요하다. 이에 O(1)의 공간 복잡도를 사용한다.

### 브루트 포스

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

문자열을 왼쪽에서부터 순회하며 O, 또는 X가 나타날 때마다 체크한다.

이때 직전에 나온 문자와 다른 경우 손을 바꿔야 하므로 정답을 증가시킨다.

이를 구현하면 다음과 같다.

```cpp
int solution(int length, string t) {
  int index = 0;

  int answer = 0;
  bool isLeft = true;
  while (index < length) {
    if (t[index] == 'F') {
      index++;
      continue;
    }

    if (t[index] == 'O') {
      isLeft = false;
      break;
    }
    break;
  }

  while (index < length) {
    if (t[index] == 'O' && isLeft) {
      isLeft = false;
      answer++;
    } else if (t[index] == 'X' && !isLeft) {
      isLeft = true;
      answer++;
    }
    index++;
  }

  return answer;
}
```

## 고생한 점
