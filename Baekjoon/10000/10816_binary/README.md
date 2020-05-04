# 10816. 숫자 카드 2

[링크](https://www.acmicpc.net/problem/10816)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver IV |   34.982    |

## 설계

### 시간복잡도

N은 최대 500,000 까지이며 M 또한 500,000 까지이다.

완전탐색으로 풀이할 경우 시간복잡도는 O(MN) 이며 이는 제한시간 1초 내에 불가능하다.

입력받은 N을 정렬할 경우 NlogN의 시간이 소요되며, 이는 9,465,784 정도이다.

이는 제한시간 내에 풀이가 가능하므로 최대 시간복잡도를 NlogN으로 풀이해야한다.

풀이 방법은 다음을 사용한다

- 이분탐색 (upper_bound, lower_bound) 이용

### 공간 복잡도

입력받은 값의 범위는 -10,000,000 ~ 10,000,000 이므로 int형으로 충분하다.

### lower_bound

찾는 key 이상의 값이 처음 나오는 위치를 반환한다.

```cpp
int mylower_bound(int* arr, int size, int key) {
  int start = 0;
  int end = size;

  int mid = size;

  while (end - start > 0) {
    mid = (start + end) / 2;

    if (arr[mid] < key) {  // key 값이 중앙 값보다 크면
      start = mid + 1;     // mid 보다 오른쪽으로
    } else {               // key 값이 중앙값보다 작거나 같으면
      end = mid;  // mid 포함 왼쪽 (포함하는 이유는 key값과 같은게 없을 때
                  // 큰수중 가장 작은값을 위해)
    }
  }
  return end + 1;
}
```

### upper_bound

찾는 key를 초과한 값이 처음 나오는 위치를 반환한다.

```cpp
int myupper_bound(int* arr, int size, int key) {
  int start = 0;
  int end = size;
  int mid;

  while (end - start > 0) {
    mid = (start + end) / 2;

    if (arr[mid] <= key) {  // lower_bound와 다른 점은 여기 '=' 하나
      start = mid + 1;
    } else {
      end = mid;
    }
  }

  return end + 1;
}
```

### 갯수 세기

입력받은 숫자를 정렬한 경우의 upper_bound와 lower_bound는 다음을 의미한다.

upper_bound : target 초과 값이 처음 나오는 위치.
lower_bound : target 이상 값이 처음 나오는 위치.

아래의 경우를 예시로 살펴보자

```cpp
index : 0 1 2 3 4 5 6 7
value : 1 2 3 3 3 5 5 6

// target이 3일때
arr[2] : lower_bound
arr[5] : upper_bound

// target이 4일때
arr[5] : lower_bound
arr[5] : upper_bound
```

위 배열에서 3의 갯수는 3이다. 이는 upper_bound - lower_bound한 값과 일치한다.

만약 target이 존재하지 않는 경우에는 upper_bound와 lower_bound가 같으므로 0이다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     316      |       88       |

## 고생한 점
