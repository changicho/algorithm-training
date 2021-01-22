# 2166. 다각형의 면적

[링크](https://www.acmicpc.net/problem/2166)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold V |   23.217    |       2       |

## 설계

### 시간 복잡도

점의 개수 N은 최대 10,000개 까지이다.

다각형의 면적을 구하는 공식은 다음과 같다. [위키](https://ko.wikipedia.org/wiki/%EC%8B%A0%EB%B0%9C%EB%81%88_%EA%B3%B5%EC%8B%9D)

i-1, i, i+1 번째 점을 이용해 삼각형의 면적을 구하고, 이를 i를 증가시키며 N번 반복하는 것이다.

이 때 하나의 점을 기준으로 삼각형의 넓이를 구해야 하는데, 이는 임의의 한 점으로 고정한다.

시간 복잡도는 O(N) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

소수 첫재짜리까지 표현해야 하므로 double 형을 사용한다.

### 다각형의 넓이 공식

벡터의 외적을 구하는 CCW를 이용해 두 벡터의 평행 사변형을 구할 수 있고, 이것의 절반 크기가 삼각형이다.

CCW는 다음과 같다. (두 벡터의 시작접은 같다고 가정)

```cpp
// calculate ccw of vector (a, b), (a, c)
double ccw(Axis a, Axis b, Axis c) {
  return ((a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x));
}
```

이를 이용해 점들을 순회하며 삼각형의 넓이를 구하고 더한다.

이 때 정답이 음수가 나올 수도 있으므로 (오목한 삼각형의 점을 시작점으로 삼은 경우) 넓이를 절대값으로 바꿔준다.

```cpp
Axis start = points.front();

for (int i = 2; i < N; i++) {
  double ccw_answer = ccw(start, points[i - 1], points[i]) / 2;
  answer += ccw_answer;
}
answer = abs(answer);
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점
