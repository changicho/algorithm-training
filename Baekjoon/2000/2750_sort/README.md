# 2750. 수 정렬하기

[링크](https://www.acmicpc.net/problem/2750)

난이도\_57%

## 정리

단순히 오름차순으로 정렬하는 문제.
vector와 sort를 이용했다.

만약 내림차순으로 정렬하고 싶은 경우

```cpp
sort(v.begin(), v.end(), greater<int>());
```

혹은

```cpp
bool compare(int a, int b){
    return a > b;
}

// ...

sort(v.begin(), v.end(), compare);
```

직접 비교 함수를 만들어 주면 된다. (true일 때 뒤로 옮김에 유의)
