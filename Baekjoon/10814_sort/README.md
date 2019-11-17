# 10814. 나이순 정렬

[링크](https://www.acmicpc.net/problem/10814)

난이도\_41%

## 정리

stable_sort를 이용해 풀이

```cpp
stable_sort(accounts.begin(), accounts.end(), compare);
```

stable_sort()는 구조체처럼 여러 값들이 묶여 있는 경우, 하나의 요소를 정렬 했을 때 다른 요소들의 정렬 순서를 그대로 유지 될 수 있도록 하는 정렬이다.

### 문제점

기존 사용자 정보에 order 요소를 넣어두고, comapre에서 같이 비교하도록 구현했으나 계속 런타임 오류가 발생했다.
order 요소를 비교하기 위해 접근할 때 문제가 발생하는것 같은데 이유를 모르겠다.
