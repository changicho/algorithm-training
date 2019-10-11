# 5986. 새샘이와 세 소수

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWaJ3q8qV-4DFAUQ&categoryId=AWaJ3q8qV-4DFAUQ&categoryType=CODE)

난이도\_d3_42%

## 정리

내 코드 : 78 ms;
빠른 코드 : 7 ms;

소수를 구하기 위해 에라토스테네스의 채를 이용.
X <= Y <= Z 로 반복문을 설정해 풀이. 여기서 Z = N-X-Y로 구할 수 있다.

반복문에서 시작은 2 이고 3 이후부터는 2씩 증가시켜 짝수일 때 경우의 수를 줄였다.
