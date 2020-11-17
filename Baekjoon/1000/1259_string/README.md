# 1259. 팰린드롬수

[링크](https://www.acmicpc.net/problem/1259)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Bronze I |   65.513    |

## 설계

### 시간 복잡도

문자열의 최대 길이는 99999, 5자리이다.

각 문자가 펠린드롬인지 아닌지 판별하는데 시간 복잡도가 O(N) 이므로 제한시간 1초 내에 충분하다.

### 공간 복잡도

단순 문자열만을 입력받으면 되므로 string으로 선언한다.

각 경우마다 string 변수를 재활용한다.

### 팰린드롬 판별

```cpp
bool isPalindrom(string word) {
  int length = word.length();

  for (int i = 0; i < length / 2; i++) {
    if (word[i] != word[length - 1 - i]) return false;
  }
  return true;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
