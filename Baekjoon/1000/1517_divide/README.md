# 1517. 버블 소트

[링크](https://www.acmicpc.net/problem/1517)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold II |   27.856    |

## 설계

### 시간 복잡도

N은 최대 500,000 까지이다.

버블 소트를 직접 계산하는 경우 500,000^2 = 250,000,000,000 번 만큼 수행해야 한다.

이는 제한시간 내에 불가능하다.

따라서 병합정렬을 이용해 NlogN 내에 풀이한다.

### 공간 복잡도

병합정렬을 이용해야 하므로 N 크기의 배열 2개를 선언한다.

정답은 최악의 경우 500,000^2 일 수 있으므로 long long 형으로 선언한다.

### 병합정렬

병합 정렬에서 버블소트의 교환이 일어나는 횟수를 생각해보자

```sh
0 1 / 2 3
A B / C D

# 아래와 같이 바뀌는 경우

0 1 2 3
C A B D
# C의 이동 횟수는 앞 덩어리의 갯수만큼 이동했다

0 1 2 3
C D A B
# 위 경우도 C, D는 앞 덩어리의 갯수만큼 이동했다.

0 1 2 3
A C B D
# C의 이동 횟수는 (앞 덩어리의 수 - 이미 채워진 수) 만큼 이동했다
```

따라서 병합 정렬에서 현재 숫자가 이동하는 (swap) 횟수는

- 뒤 덩어리가 앞 덩어리로 이동할 때
- (앞 덩어리의 수 - 이미 채워진 수) 만큼 더해진다.

병합 정렬은 다음과 같다.

```cpp

void merge(int start, int end) {
  int mid = (end + start) / 2;
  int idx = start;
  int left = start;
  int right = mid + 1;

  while (left <= mid && right <= end) {
    if (arr[left] <= arr[right]) {  // 왼쪽 덩어리에서 채움
      temp[idx++] = arr[left++];
    } else {  // 오른쪽 덩어리에서 채움
      temp[idx++] = arr[right++];

      answer += (mid - left + 1); // 이동해야 하는 만큼 증가. 개수를 세기 때문에 + 1
    }
  }

  // 채워지지 않은 수(왼쪽) 채우기
  while (left <= mid) {
    temp[idx++] = arr[left++];
  }
  // 채워지지 않은 수(오른쪽) 채우기
  while (right <= end) {
    temp[idx++] = arr[right++];
  }
  // 배열 복사
  for (int i = start; i <= end; i++) {
    arr[i] = temp[i];
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     116      |       60       |

## 고생한 점
