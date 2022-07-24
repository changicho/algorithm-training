# Image Labeler (4pts, 6pts)

[링크](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008caea6/0000000000b76e11)

## 설계

### 시간 복잡도

배열 A의 크기를 N이라 하자.

그리디 알고리즘을 사용하기 위해 정렬을 이용할 경우 O(N \* log_2(N) + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

배열 A에 O(N)의 공간 복잡도를 사용한다.

### 정렬

|     시간 복잡도      | 공간 복잡도 |
| :------------------: | :---------: |
| O(N \* log_2(N) + M) |    O(N)     |

N개의 숫자를 M개의 그룹으로 나누고 각 그룹의 중앙값을 더한 값중 최대값을 찾아야 한다.

그룹의 중앙값은 그룹의 원소가 1개일 때 가장 큰 값을 가질 수 있다.

만약 그룹에 다음과 같은 수가 있다고 하자 A, B, C (A < B < C)

이 경우 중앙값은 B가 되며 C와 A를 이용해 최대값을 만드는 경우가 사라지게 된다.

따라서 배열 A에서 M-1개의 큰 수를 뽑아 그룹으로 생성하고, 남은 수들 중 중앙값을 구해 정답에 더한다.

```cpp
double solution(int n, int m, vector<int>& arr) {
  sort(arr.begin(), arr.end());

  double answer = 0;

  for (int i = 0; i < m - 1; i++) {
    answer += arr.back();
    arr.pop_back();
  }

  int size = arr.size();
  int center = size / 2;
  if (size % 2 == 0) {
    answer += ((double)arr[center - 1] + arr[center]) / 2;
  } else {
    answer += (arr[center]);
  }

  return answer;
}
```

## 고생한 점

A의 데이터를 double로 설정했을 때 정답이 틀린 경우가 있었음.
