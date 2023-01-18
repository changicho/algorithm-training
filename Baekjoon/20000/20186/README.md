# 20186. 수 고르기

[링크](https://www.acmicpc.net/problem/20186)

| 정답률  |  난이도  |
| :-----: | :------: |
| 63.194% | 실버 III |

## 설계

### 시간 복잡도

입력받은 두 수를 N, K라 하자.

각 과정에서 최대 값을 고르기 위해 동적 계획법을 사용할 수 있다.

이 경우 N과 K에 대해 순회해야 하므로 O(N \* K)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N \* K)의 공간 복잡도를 사용한다.

이 때 직전 값들만을 사용하므로 이 공간에 대해 최적화를 할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |  O(N \* K)  |    O(N)     |

다음과 같은 동적 계획법 식을 선언한다.

```cpp
dp[i][k]; // i번째 까지 선택하고 k개의 수를 선택했을 때의 최대값?
dp[0][1] = array[0];
dp[i][k] = max(dp[i-1][k], dp[i-1][k-1] + array[i] - (k-1))
```

이후 해당 식에 따라 순회하며 정답을 갱신한다.

이 때 N과 K가 크므로 dp의 공간복잡도의 최적화를 수행한다.

```cpp
int solution(int size, const vector<int> &array, int k) {


  vector<int> curDp(size + 1, 0), beforeDp(size + 1, 0);

  for (int selected = 1; selected <= k; selected++) {
    curDp[selected] =
        beforeDp[selected - 1] + array[selected - 1] - (selected - 1);
    for (int i = selected + 1; i <= size; i++) {
      curDp[i] =
          max(curDp[i - 1], beforeDp[i - 1] + array[i - 1] - (selected - 1));
    }

    swap(beforeDp, curDp);
  }

  int answer = beforeDp[size];
  return answer;
}
```

### 정렬 & 그리디 알고리즘

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

각 원소들 중 가장 큰 값들부터 K개를 고른다.

만약 배열에서 어떤 수들을 K개 고르던지 간에 선택하는 각 경우의 수에 0, 1, 2, ... ,(K-1)개 만큼 앞에 위치하므로 정답애서 해당 수 만큼 빼줘야 한다.

따라서 최대한 큰 수들을 고르고 0 ~ (K-1)까지의 수를 빼준다.

```cpp
int solution(int size, vector<int> &array, int k) {
  int answer = 0;

  sort(array.begin(), array.end(), greater<int>());

  for (int i = 0; i < k; i++) {
    answer += array[i];
    answer -= i;
  }

  return answer;
}
```

## 고생한 점
