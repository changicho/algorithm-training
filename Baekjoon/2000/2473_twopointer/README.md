# 2473. 세 용액

[링크](https://www.acmicpc.net/problem/2473)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold IV |   24.729    |       1       |

## 설계

### 시간 복잡도

용액의 개수 N은 3 이상 5,000 이하의 정수이다.

모든 용액을 3개 골라 검사할 경우 시간 복잡도는 N^3이 소요되며 이는 제한시간 내에 불가능하다.

따라서 투 포인터 방법을 이용해 풀이한다.

이 경우 하나의 값을 고정으로 두고, 나머지는 투 포인터의 탐색을 이용한다.

따라서 시간 복잡도는 N^2이다.

### 공간 복잡도

용액은 절대값 1,000,000,000 이하의 정수이다.

3개의 용액의 합의 절대값은 int형을 초과할 수 있으므로 long long형으로 선언한다.

### 하나의 값을 고정

3개의 값을 골라야 한다.

이 때 1개의 값을 고정시키는 경우 나머지 2개의 값은 투 포인터를 이용해 구할 수 있다.

따라서 다음과 같이 하나의 값을 탐색하며 고정시키고 남은 값들로 투포인터를 수행한다.

```cpp
for (int index = 0; index < N - 2; index += 1) {
  int front = index + 1, back = N - 1;

  // two pointer
}
```

### 투 포인터

탐색을 진행하며 시작점과 끝점이 만날 때까지 배열을 순회하므로 시간 복잡도는 O(N)이다.

```cpp
long long sum = abs(array[0] + array[1] + array[2]);

while (front < back) {
  long long cur_sum = array[front] + array[back] + array[index];
  long long abs_cur = abs(cur_sum);

  if (abs_cur < sum) {
    sum = abs_cur;
    answers[0] = array[index];
    answers[1] = array[front];
    answers[2] = array[back];
  }

  if (cur_sum < 0) {
    front += 1;
  } else {
    back -= 1;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      32      |       8        |

## 고생한 점

투 포인터로 탐색할 때 변수 형을 long long 으로 선언하지 않아 틀림
