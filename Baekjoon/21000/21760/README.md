# 21760. 야구 시즌

[링크](https://www.acmicpc.net/problem/21756)

| 정답률 (%) |  난이도  |
| :--------: | :------: |
|   44.362   | 브론즈 I |

## 설계

### 시간 복잡도

입력받는 테스트 케이스의 수를 T라 하자.

입력받은 수를 N, M, K, D라 하자.

각 영우에 대해서 만족하는 B를 가능할 때 까지 모두 순회할 경우, 최대 O(D)의 시간 복잡도를 사용한다.

(수식상 B는 최대 D/4 까지 가능)

이를 이분 탐색으로 구현할 경우 O(log_2(D))의 시간 복잡도를 사용한다.

### 공간 복잡도

이분 탐색을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(T \* log_2(D)) |    O(1)     |

총 경기수는 다음과 같이 계산이 가능하다.

한 팀에 대해서 같은 지역리그, 다른 지역리그와 게임을 하는 수를 다음과 같이 계산한다.

```text
같은 지역리그 경기 수 : (M-1) * A
다른 지역리그 경기 수 : (N-1) * M * B

모든 팀에 대한 경기 수 (중복 제거하기 위해 2를 나눠줌)
= (N * M) * ((M-1) * A + (N-1) * M * B) / 2

이를 A를 치환하면
= (N * M) * ((M-1) * (k * B) + (N-1) * M * B) / 2
```

여기서 B를 계산하면 최대 1부터 (D / 4) 까지 가능하다. (N, M, K가 최소이며 D가 최대값일 때)

따라서 B의 최대값은 대략 1e9 / 4 이다.

이는 매우 크므로 직접 순회로 탐색할 경우 제한시간 내에 불가능하다.

경기 수를 계산하는 식이 B에 따라 증가하므로 이분탐색을 사용한다.

이를 구현하면 다음과 같다.

```cpp
long long solution(int n, int m, int k, long long d) {
  long long answer = -1;
  long long left = 1, right = 1000000000 / 4 + 1;

  while (left < right) {
    long long mid = left + (right - left) / 2;

    long long curCost =
        ((long long)(m - 1) * k * mid + (long long)(n - 1) * m * mid);
    curCost *= (long long)(n * m);
    curCost /= 2;

    if (curCost <= d) {
      // pick right
      answer = curCost;
      left = mid + 1;
    } else {
      // pick left
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
