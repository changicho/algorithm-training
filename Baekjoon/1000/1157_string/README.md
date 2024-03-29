# 1157. 단어 공부

[링크](https://www.acmicpc.net/problem/1157)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Bronze I |   38.335    |

## 설계

### 시간복잡도

단어의 길이는 최대 1,000,000 이다.

counting은 한번 순회로 끝이 나므로 시간복잡도는 O(N)이므로 제한시간 2초 내를 만족한다.

### 대문자 치환

각 글자를 순회하며 소문자를 대문자로 바꿔준다.

cpp에서는 toupper 메소드를 이용해 각 글자마다 치환한다.

### 알파벳 최대 counting이 여러 개 존재

알파벳 counting 배열을 만들고 count한다.

maxCount를 찾는 시점은 다음과 같다.

1. 각 글자별로 count 할 때 maxCount를 갱신한다.
2. counting 배열을 순회하며 maxCount를 갱신한다.

2번 방법의 경우 A ~ Z까지 26번 수행하므로 시간복잡도에 큰 영향을 주지 않는다.

이후 counting 배열을 순회하며 maxCount가 유일한지 확인한다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      8       |       0        |

## 고생한 점
