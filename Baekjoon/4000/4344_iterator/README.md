# 4344. 평균은 넘겠지

[링크](https://www.acmicpc.net/problem/4344)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Bronze I |   37.622    |

## 설계

### 시간 복잡도

학생의 수는 최대 1000 까지이다.

평균을 구할 때 시간 복잡도는 O(N) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

소숫점 셋째 자리 까지 구해야 하므로 double로 선언한다.

### 평균

```cpp
for (int i = 0; i < N; i++) {
  cin >> arr[i];
  sum += arr[i];
}
double avg = sum / N;
int count = 0;

for (double d : arr) {
  if (d > avg) count += 1;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
