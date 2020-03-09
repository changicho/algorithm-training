# 9012. 괄호

[링크](https://www.acmicpc.net/problem/9012)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver IV |   39.168    |

## 설계

### stack을 이용

여는 괄호인 경우 push

닫는 괄호인 경우

- 직전 괄호가 여는 괄호인 경우 pass && stack.pop()
- 직전 괄호가 닫는 괄호인경우 fail
- stack이 빈 경우 fail

stack이 비어있는 경우 pass
stack이 비어있지 않은 경우 fail

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
