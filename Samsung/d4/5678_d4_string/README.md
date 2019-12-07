# 5678. [Professional] 팰린드롬

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRrK7KhO4DFAUo&categoryId=AWXRrK7KhO4DFAUo&categoryType=CODE)

난이도 : d4
정답률 : \_28%

## 제약조건

T <= 15,
문자열의 길이 <=1000
c++ 1초, java 2초, python 4초

## 설계

### 방법1 : 브루트 포스

입력받은 문자열의 길이 N

이중반복문으로 순회를 한다.

N부터 시작하며, 길이가 N인 부분문자열의 팰린드롬을 검사.

팰린드롬이 없는 경우 N을 감소시키며 부분문자열의 팰린드롬을 검사.

팰린드롬이 하나라도 나오는 경우 탐색을 중지하고, 그때의 N 값이 답이된다.

- 시간 복잡도

부분문자열의 최대 길이를 만드는 경우

N X N-1 X N-2 X ... X 1 : 약 N^2

부분 문자열을 탐색하는 경우 : N

따라서 N^3정도이다.

최악의 경우 1000^3 X 15 이므로 1억을 초과한다.

- 펠린드롬을 검사하는 방법

문자열 중간 (N = length / 2)까지 iteration을 돌리면서

N-i 와 N+i가 같은지 비교한다.

같지 않으면 false를 return함.

## 정리

내 코드 : 509 ms;
빠른 코드 : 6 ms;

## 고생한 점

string.substr 의 사용

string.substr(index, length) 로 사용한다.

index는 자르기 시작할 위치, length 는 자를 길이.
