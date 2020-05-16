# 5604. [Professional] 구간 합

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXGGNB6cnEDFAUo)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|   d4   |    24.33    |

## 설계

### 시간복잡도

숫자 A와 B는 10^15까지이며 테스트케이스는 20개 까지이다.

A와 B가 너무 크므로 브루트 포스 방법으로는 불가능하다.

백준 1019번과 비슷한 방법으로 자리수 별로 분할해 풀이한다.

이 경우 한 테스트 케이스 당 최대 15번 내에 풀이가 가능하다.

모든 테스트 케이스를 고려하더라도 상수 범위이므로 시간 내에 해결이 가능하다.

### 공간복잡도

10^15 까지 이므로 long long 형을 선언해야한다.

### 부분별로 나눠 생각하기

start ~ end 사이의 모든 수의 자리수를 더한다고 생각해보자.

만약 10 단위로 끊어서 생각한다고 했을 때, start가 10 미만이라면 앞에 붙는 0을 처리해줘야 한다.

(01, 0011 등과 같이 앞에 붙는 0의 처리가 필요함)

이를 처리하기 위해 0을 처리하지 않아도 되는 최소 수 까지 start를 증가시킨다.

이 경우 start는 0으로 끝나는 단위가 될 것이다.

또한 end도 끝자리가 9가 되도록 감소시킨다.

이렇게 증가하고 감소시킨 수들은 자리수를 분해한다.

이 경우 0~9까지 (10단위) 로 문제를 잘라 생각할 수 있고, 정답에 각 자리수를 counting 한다.

이렇게 나올 수 있는 모든 10^0의 자리의 경우를 counting 할 수 있다.

```cpp
for(int i=0;i<10;i++){
  answers[i] += (end / 10) - (start / 10) + 1
}
```

이제 이를 단위를 증가시키며 10의자리, 100의자리 ... X자리 만큼 count한다.

### 재귀

단위를 증가시킬 때마다 이전에 계산한 자리 수는 더이상 계산하지 않아도 되므로 start, end는 다음과 같이 변한다.

```cpp
start /= 10;
end /= 10;
```

자리 수는 10씩 증가한다.

```cpp
digits *= 10;
```

그리고 start는 증가하고, end는 감소하므로 start가 end보다 커지는 경우가 생기는데, 이 경우 더이상 탐색을 중지한다.

따라서 식은 다음과 같다.

```cpp
void recur(int start, int end, int digits) {
  while (start % 10 != 0 && start <= end) {
    counting(start, digits);
    start++;
  }
  if (start > end) return;
  while (end % 10 != 9 && end >= start) {
    counting(end, digits);
    end--;
  }
  int diff = (end / 10 - start / 10 + 1);
  addAll(diff * digits);
  recur(start / 10, end / 10, digits * 10);
}
```

### 재귀가 아닌 while문

위 식은 재귀함수가 아닌 while문으로 풀이가 가능하다.

```cpp
while (start <= end) {
  while(start%10!=0 && start<=end) {
    cal(start);
    start++;
  }

  if(start > end) return
  while(end % 10 != 9 && start <= end) {
    cal(end);
    end--;
  }

  long long diff = end/10 - start/10 +1;
  for(int i = 0; i < 10; i++){
    number[i] += diff * digits;
  }

  digits *= 10;
  start /= 10;
  end /= 10;
}
```

### start가 0 인 경우

start가 0인 경우 끝자리가 0 이기 때문에 재귀함수에서 0인 경우를 처리하는데 문제가 발생한다.

이 경우 start를 1부터 시작하더라도 정답에 변화가 없으므로 1로 치환해준다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      6       |       5        |

## 고생한 점

start 가 0 일때 처리
