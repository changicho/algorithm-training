# 2003. 수들의 합 2

[링크](https://www.acmicpc.net/problem/2003)

난이도 : Silver III
정답률 : \_50%

## 설계

### 자료구조

배열을 탐색할 때, start와 end 포인트를 설정해 풀이

3가지 경우로 start와 end를 변화시킨다

- sum == M
  - start_window += 1;
- sum < M
  - end_window += 1;
- sum > M
  - start_window += 1;

## 정리

| 내 코드 |
| :-----: |
|  24 ms  |

## 고생한 점
