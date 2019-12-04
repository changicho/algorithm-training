# 8931. 제로

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW5jBWLq7jwDFATQ&categoryId=AW5jBWLq7jwDFATQ&categoryType=CODE)

난이도 : d3
정답률 : \_57%

## 설계

스택을 만들고 0이 입력될 때마다 pop을 한다.

입력이 모두 끝났을 때, 스택을 비워가면서 답을 구함.

### 최대값

100000 X 100000 이므로

10^5 X 10^5 = 10^10 정도이다.

따라서 answer는 long long형으로 선언되어야 한다.

## 정리

내 코드 : 73 ms;
빠른 코드 : 34 ms;

스택이 빈 상태에서 pop을 하는 경우 에러가 발생하므로, 예외처리 필요함.

## 고생한 점

없음
