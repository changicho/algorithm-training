# 5688. 세제곱근을 찾아라

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXVyCaKugQDFAUo&categoryId=AWXVyCaKugQDFAUo&categoryType=CODE)

난이도\_d3_27%

## 정리

내 코드 : 223 ms;
빠른 코드 : 1 ms;
개선 코드 : 193 ms;
math.h의 cbrt 함수를 사용 : 6 ms;

부르트포스를 이용해 하나하나 구해도 제한시간 1초 내에 통과가 된다.
매우 큰 수 이므로 long long으로 선언해야 범위에 들어온다.

N의 세제곱근의 최대 값은 10^6이므로 이를 10단계로 나눠 메모이제이션 기법을 이용하니 193ms 까지 줄일 수 있었다.

마지막으로 math.h의 함수를 사용한 결과 6ms로 확연히 줄였다.

```cpp
if (pow(answer + 1, 3) == N) {
    answer += 1;
}
```

다만 이 경우를 추가해 줘야 4개의 테스트 케이스를 더 통과한다.
아마 x.99999 이런식으로 나오는 경우, 소숫점을 버린 값에 에러가 있기 때문인듯 하다.
