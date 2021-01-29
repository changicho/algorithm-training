# 2467. 용액

[링크](https://www.acmicpc.net/problem/2467)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold V |   32.250    |       1       |

## 설계

### 시간 복잡도

N은 2이상 100,000미만의 자연수이다.

모든 경우를 탐색할 경우 시간 복잡도는 N^2 이므로 제한시간 내에 불가능하다.

따라서 투 포인터를 이용해 최대 N번 이내에 탐색한다.

### 공간 복잡도

용액의 값은 절대값 1,000,000,000 이하의 정수이다. 또한 용액의 차 또한 이 이내이므로 int형으로 선언한다.

### 투 포인터

용액들을 오름차순으로 정렬 후에 다음 경우에 따라서 투 포인터를 이동시킨다.

- 두 용액의 합이 음수인경우 : 시작점을 오른쪽으로 이동시킴
- 두 용액의 합이 양수인경우 : 끝점을 왼쪽으로 이동시킴

이는 두 용액의 합이 음수인 경우 시작점의 수의 절대값이 더 크고, 양수인 경우는 끝값의 절대값이 더 크기 때문이다.

```cpp
int left = 0, right = N - 1;
int diff = abs(array.back() + array.front());
int answer_start = array.front(), answer_end = array.back();

while (left < right) {
  int new_diff = array[left] + array[right];

  if (abs(new_diff) < diff) {
    diff = abs(new_diff);

    answer_start = array[left];
    answer_end = array[right];
  }

  if (new_diff < 0) {
    left++;
  } else {
    right--;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       0        |

## 고생한 점
