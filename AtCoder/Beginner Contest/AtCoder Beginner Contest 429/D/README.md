# D - On AtCoder Conference

[링크](https://atcoder.jp/contests/abc429/tasks/abc429_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 순회하며 이분탐색에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

순환하는 구조이므로 다음 순환을 처리하기 위해 다음 사이클의 숫자를 집어넣을 수 있다. 이 경우 O(N)의 공간 복잡도를 사용한다.

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 순환 & 이분탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     147      | O(N \* log_2(N)) |    O(N)     |

연못은 원형이므로 순환이 가능한 구조이다.

또한 0 ~ M까지 각 경우를 판단해야 하므로, 순환되는 경우를 처리하기 위해 각 인원의 위치에 M을 더한 값을 배열에 복사한다.

이후 배열을 정렬한다.

M은 매우 큰 값이므로 직접 시뮬레이션을 수행할 경우 제한시간 내에 불가능하다.

따라서 각 인원의 위치를 순회하며, (직전 인원의 위치 ~ 현재 인원의 위치) 사이의 각 위치에 대해서 정답을 한꺼번에 갱신한다.

이는 결국 만나는 사람의 수가 중요하므로, 사람 사이에 위치한 빈 공간에서는 모두 같은 결과값이 나오기 때문이다.

해당 빈 공간의 좌표의 수를 X라 하자.

현재 위치에서 C명을 만나기 위해선 최소 현재 위치에서 다음 C번째 사람의 위치까지는 도달해야 한다.

해당 사람의 위치값과 현재 위치값을 이용해 해당 구간 사이의 사람의 수를 구한다.

이 구간사이 사람의 수를 Y라 하자.

이후 X \* Y를 정답에 더한다.

이를 처음에 입력받은 사람들의 위치 정보를 순회하며 총 N번 반복한다.

```cpp
auto solution(int size, long long m, int c, vector<long long>& positions) {
  long long answer = 0;

  // double cycle
  for (int i = 0; i < size; i++) {
    positions.push_back(positions[i] + m);
  }

  sort(positions.begin(), positions.end());

  for (int i = 1; i < size + 1; i++) {
    // (positions[i-1]+0.5) ~ (positions[i]-0.5) -> same result
    long long before = positions[i - 1];
    long long cur = positions[i];

    long long duplicated = cur - before;

    // cur -> met c people position
    // already meet cur
    long long nextStop = positions[(i - 1) + c];

    long long metCount =
        upper_bound(positions.begin(), positions.end(), nextStop) -
        lower_bound(positions.begin(), positions.end(), cur);

    answer += metCount * duplicated;
  }

  return answer;
}
```

## 고생한 점
