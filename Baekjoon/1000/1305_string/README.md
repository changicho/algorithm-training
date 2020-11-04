# 1305. 광고

[링크](https://www.acmicpc.net/problem/1305)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   50.813    |

## 설계

### 시간 복잡도

문자열의 최대 길이는 백만 이하의 자연수이다. 따라서 브루트 포스 방법으로는 풀이가 불가능하다.

kmp알고리즘을 이용해 입력받은 전광판의 문자열 내에서 반복되는 가장 큰 패턴을 찾는다.

그 패턴을 제거한 문자열이 광고하고싶은 문자열이다.

kmp알고리즘을 이용하는 경우 시간 복잡도는 O(N+M) 이므로 (N : 문자열길이, M : 패턴의 길이)

O(1,000,000 + 1,000,000) 이므로 제한시간 2초 내에 충분하다.

### 공간 복잡도

patternIndex에서 가질 수 있는 수는 1,000,000 이하의 정수이다.

따라서 int형으로 선언한다.

정답 또한 1,000,000 이하이다.

### kmp

접미사(prefix)도 되고 접두사(suffix)도 되는 문자열의 최대 길이를 저장한다.

즉 광고 문구로 찾는것이 아니라, 접두사 & 접미사를 찾아 전광판의 문구에서 빼면 광고 문구가 됨을 이용한다.

kmp알고리즘을 이용하면 입력받은 문자열에서 반복되는 패턴의 길이를 찾을 수 있다. (index를 이용)

따라서 입력받은 문자열을 원본문자열과 패턴으로 지정하고 patternIndex를 갱신한다.

patternIndex의 맨 마지막에 담긴 index가 반복되는 패턴인 접미사의 최대 길이이다.

따라서 전체 문자열의 길이에서 접미사의 길이 (패턴길이)를 빼면 광고의 길이가 나온다.

```cpp
for (int lineIdx = 1, patternIdx = 0; lineIdx < N; lineIdx++) {
  while (patternIdx > 0 && line[lineIdx] != line[patternIdx]) {
    patternIdx = patternIndex[patternIdx - 1];
  }
  if (line[lineIdx] == line[patternIdx]) {
    patternIdx++;
    patternIndex[lineIdx] = patternIdx;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       8        |

## 고생한 점
