# 9935. 문자열 폭발

[링크](https://www.acmicpc.net/problem/9935)

| 난이도  | 정답률(\_%) | 제한 시간 |
| :-----: | :---------: | :-------: |
| Gold IV |   21.520    |   2 초    |

## 설계

### 시간 복잡도

문자열의 길이는 최대 1,000,000 까지이다.

폭발 문자열의 길이는 최대 36이다.

### 공간 복잡도

string을 이용한다.

### 각 자리별 시작

문자열을 순회하며 결과 문자열에 현재 문자를 추가한다.

이 때 현재 문자가 패턴의 마지막 자리인 경우에 패턴이 존재하는지 탐색한다.

만약 패턴이 존재헀을 경우 패턴의 길이만큼 결과 문자열으 index를 수정한다.

```cpp
reverse(pattern.begin(), pattern.end());  // 패턴 탐색을 쉽게하기 위해 반전시킴
int index = 0;

for (char c : line) {
  result[index] = c;

  if (c == pattern.front()) {
    bool check = true;

    int size = index + 1 - pattern.length();
    int patternIndex = 0;

    for (int reverseIndex = index; reverseIndex >= size; reverseIndex -= 1) {
      if (reverseIndex < 0 || result[reverseIndex] != pattern[patternIndex]) {
        check = false;
        break;
      }
      patternIndex += 1;
    }

    if (check) index -= pattern.length();
  }
  index++;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       4        |

## 고생한 점
