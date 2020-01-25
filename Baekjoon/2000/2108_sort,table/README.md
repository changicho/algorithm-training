# 2108. 통계학

[링크](https://www.acmicpc.net/problem/2108)

난이도\_27%

## 정리

내 코드 : 108 ms;

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이

이 네가지를 구하는 문제.

최빈값과 범위는 구하기 쉬우나, 산술평균과 중앙값의 경우가 구하기 힘들었다
산술평균 : 소숫점 자리의 반올림과, 더한 모든 값이 범위를 넘는지 아닌지 판단을 해줘야함.
중앙값 : 최대 개수가 500,000 이므로 빠른 정렬이 필요

산술 평균의 경우는 long long 형의 범위에 들어오므로 전부 더한 sum을 구하고,
math.h의 round 함수를 이용해 반올림 해줬다.

```cpp
long long avg = round((double)sum / (double)N);
```

중앙값의 경우 qsort 함수를 이용

```cpp
int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) return -1;

    if (num1 > num2) return 1;

    return 0;
}
// ...
qsort(numbers, N, sizeof(int), compare);
```

q sort의 경우 compare를 저런 식으로 만들어 줘야 하므로 까다롭다.
