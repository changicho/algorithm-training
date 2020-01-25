# 1436. 영화감독 숌

[링크](https://www.acmicpc.net/problem/1436)

난이도\_46%

## 정리

내 코드 : 248 ms;

숫자를 하나하나 증가시키며 조건에 맞는지 검사.
숫자 666 (연속된 3개) 를 체크하는 부분을 함수로 제작.
숫자를 문자열로 변환 후 find 로 찾는 방법으로 수행

```cpp
if (number_string.find("666") != string::npos){
    // ...
}
```

string의 find 메소드는 특정 문자열을찾지 못했을 때 string::npos를 반환한다.
