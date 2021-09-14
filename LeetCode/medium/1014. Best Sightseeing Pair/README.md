# 1014. Best Sightseeing Pair

[링크](https://leetcode.com/problems/best-sightseeing-pair/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이므로 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 최대값을 갱신하며 탐색한다.

이 경우 직전의 최대값을 이용할 수 있으므로 시간 복잡도는 O(N)이 된다.

### 공간 복잡도

모든 직전값에 대한 dp를 만들 경우 O(N)의 공간 복잡도가 필요하다.

그러나 최대의 직전 값만을 이용할 경우 O(1)의 공간 복잡도가 필요하다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |    O(N)     |    O(1)     |

정답으로 뽑는 두 수를 left, right라고 하자.

매 index를 순회하며 최대값을 찾는 경우마다 해당 값을 갱신한다.

이는 시작점의 값이 큰값인 경우 정답이 될 수 있는 경우가 되기 때문이다.

여기서 해당 시작점의 값만을 비교하는 것이 아니라 index를 또한 같이 비교해야 한다.

따라서 해당 index의 값과 index를 더한 값이 현재 값, index보다 작은 경우에는 현재 값으로 교체한다.

최대값으로 지정할 index만 필요하므로 필요한 공간 복잡도는 O(1)이 된다.

```cpp
int maxScoreSightseeingPair(vector<int>& values) {
  int size = values.size();
  int left = 0;
  int answer = values.front() + values.back() + 0 - (size - 1);

  for (int right = 1; right < size; right++) {
    answer = max(answer, values[right] + values[left] + left - right);

    if (values[left] + left < values[right] + right) {
      left = right;
    }
  }

  return answer;
}
```

### one pass (count)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      52      |    O(N)     |    O(1)     |

위 one pass 방법에서 매번 index를 저장하지 않고 1씩 감소시킨다.

이는 left가 갱신되었을 때 결국 빼야햐는 만큼 감소하기 때문이다.

```cpp
int maxScoreSightseeingPair(vector<int>& values) {
  int answer = 0, before = 0;

  for (int value : values) {
    answer = max(answer, before + value);
    // before에 현재 value와 index 차이가 누적
    // before보다 현재 값이 큰 경우 left는 갱신됨
    before = max(before, value) - 1;
  }

  return answer;
}
```

### 동적 계획법 O(N)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      84      |    O(N)     |    O(N)     |

직전 값들 중에서 가장 가치가 높은 값들을 저장한다.

이 때 해당 값의 크기와 index를 같이 저장해야 한다. (index를 나중에 이용하므로)

dp배열의 정의는 다음과 같다.

```cpp
dp[i]; // 0부터 i번째 까지 values[i] + i의 값이 가장 큰 값
dp[0] = values[0] + 0;
```

일반식은 다음과 같다.

```cpp
dp[i] = max(dp[i - 1], values[i] + i);
```

이 값을 이용할 경우 정답은 다음과 같이 구할 수 있다.

```cpp
answer = max(answer, dp[i - 1] + values[i] - i);
```

모든 경우에 대해 구할경우 다음과 같다.

```cpp
int maxScoreSightseeingPair(vector<int>& values) {
  int size = values.size();

  vector<int> dp(size, 0);
  dp.front() = values.front() + 0;
  int answer = values.front() + values.back() + 0 - (size - 1);

  for (int i = 1; i < size; i++) {
    answer = max(answer, dp[i - 1] + values[i] - i);
    dp[i] = max(dp[i - 1], values[i] + i);
  }

  return answer;
}
```

## 고생한 점
