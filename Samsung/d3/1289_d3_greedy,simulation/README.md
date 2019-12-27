# 1289. 원재의 메모리 복구하기

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV19AcoKI9sCFAZN&categoryId=AV19AcoKI9sCFAZN&categoryType=CODE)

난이도 : d3
정답률 : \_83%

## 설계

메모리의 길이는 50이다.

### 알고리즘

0번째 index 부터 시작.

정답과 같으면 넘어가고, 정답과 다를 경우 toggle을 수행한다.

이 방법을 끝까지 수행.

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  5 ms   |   1 ms    |

### string의 assign 메소드

str.assign(base) : base의 내용을 그대로 복사

str.assign(base, 10, 9) : base의 10번째 index부터 9글자를 복사

str.assign(base, 7) : base의 0번째부터 7번째 까지 복사

str.assign(10, symbol) : symbol로 채운 10자리 문자열 반환

## 고생한 점
