# 2007. 패턴 마디의 길이

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P1kNKAl8DFAUq&categoryId=AV5P1kNKAl8DFAUq&categoryType=CODE)

### 난이도 d2

## 정리
string.find(pattern, start_point) 메소드를 이용해 푼 문제.
입력 문자열에 무조건 패턴이 존재하고, 패턴의 최대길이가 10인것을 이용

입력 문자열의 첫글자부터 패턴에 등록 후, find 메소드의 start_point만 변화시켜 계속 위치를 찾는다.

start_point = pattern.length() * pattern_number
string.find(pattern, start_point) == start_point