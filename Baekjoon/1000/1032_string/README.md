# 1032. 명령 프롬프트

[링크](https://www.acmicpc.net/problem/1032)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Bronze I |   50.414    |

## 설계

### 시간 복잡도

N은 50까지이며, 각 문자열의 길이 또한 최대 50까지이다.

모든 경우 시작 index부터 비교하며 같은지 검사한다.

모든 경우를 탐색해도 시간 복잡도는 50^2 이므로 제한시간 내에 충분하다.

### 공간 복잡도

문자열의 길이는 최대 50이다. string으로 선언한다.

### 모든 경우 비교

모든 문자들의 길이는 동일하므로, index를 증가시키며 검사한다.

```cpp
for (int i = 0; i < lines[0].length(); i++) {
  char target = lines[0][i];

  bool isFine = true;
  for (string line : lines) {
    if (line[i] != target) {
      isFine = false;
      break;
    }
  }

  answer += isFine ? target : '?';
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
