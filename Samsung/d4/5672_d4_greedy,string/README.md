# 5672. [Professional] 올해의 조련사

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRgX36gSIDFAUo&categoryId=AWXRgX36gSIDFAUo&categoryType=CODE)

난이도 : d4
정답률 : \_25%

## 설계

원본 문자열 s와 새로운 문자열 n이 있다고 하자.

s에서 맨 앞과 맨 뒤를 비교해 사전순으로 빠른 순서대로 n의 맨 끝에 추가하고, 삭제한다.

이를 s가 끝날 때까지 반복.

맨 앞과 맨 뒤가 같은 경우, 그 다음문자들을 차례차례 비교해서, 다음문자가 더 작은 쪽을 뺀다.

### 자료구조

기존 문자열에 start_index, end_index를 사용한다.

## 정리

내 코드 : 6 ms
빠른 코드 : 6 ms

## 고생한 점
