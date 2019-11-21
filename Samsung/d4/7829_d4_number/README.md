# 7829. 보물왕 태혁

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWtInr3auH0DFASy&categoryId=AWtInr3auH0DFASy&categoryType=CODE)

난이도 : d4
정답률 : \_80%

## 설계

모든 약수를 제공해준다.

약수들의 배열을 만들고, min, max를 구해 곱하면 된다.

약수들은 2이상 100만 이하이므로 1,000,000이 최대.

이는 int형으로 충분히 커버 가능하다.

## 정리

내 코드 : 7 ms;
빠른 코드 : 2 ms;

## 고생한 점

### answer를 초기화 하지 않음

answer를 초기화 하지 않고 출력해 이상한 값이 출력되었다.

(이 문제에선 asnwer를 사용해 답을 저장하지 않았음)
