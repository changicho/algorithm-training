# 4522. 세상의 모든 팰린드롬

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWO6Oao6N4QDFAWw&categoryId=AWO6Oao6N4QDFAWw&categoryType=CODE)

난이도 : d3
정답률 : \_39%

## 설계

문자열을 절반으로 자름.

자른 두번째 문자열을 reverse.

index 0부터 N/2 까지 순회하면서 검사함

?이면 continue

## 정리

내 코드 : 5 ms;
빠른 코드 : 1 ms;

## 고생한 점

문자열의 길이가 홀 수 일때, 정 가운데 글자를 제외하는 부분 구현이 헷갈렸다.

```cpp
string first = word.substr(0, length / 2);
string second = word.substr((length + 1) / 2, length);
```

다음과 같이 (길이+1)/2 번째 부터 잘라서 해결했다.
