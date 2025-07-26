# D - Get Many Stickers

[링크](https://atcoder.jp/contests/abc415/tasks/abc415_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

입력받은 수를 N, 액션의 갯수를 M이라 하자.

각 액션을 정렬 하는데 O(M \* log_2(M))의 시간 복잡도를 사용한다.

이후 각 액션에 대해 순회하며 이분 탐색을 이용해 현재 가장 유리한 액션을 찾는다. 이에 O(M)의 시간 복잡도를 사용한다.

각 숫자에 대해 시뮬레이션을 직접 수행할 경우 시간내에 해결할 수 없으므로 수식을 이용해 구현한다.

이 경우 총 시간 복잡도는 O(M \* log_2(M))이다.

### 공간 복잡도

정렬에 O(M)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘 & 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      50      | O(M \* log_2(M)) |    O(M)     |

교환하는 병의 수를 give, 받는 병의 수를 receive라고 하자.

교환횟수를 최대화 하기 위해선 액션의 `give`가 작고 `receive`가 큰 액션을 선택해야 한다.

이 때 만약 give - receive의 차이가 같은 경우 give가 작은 액션을 선택한다.

각 액션을 give를 기준으로 오름차순으로 정렬한다. give가 같은 경우 receive를 기준으로 내림차순으로 정렬한다.

이후 정렬된 배열에 대해서, 현재 선택 가능한 give 중에서 가장 유리한 액션을 선택하기 위해 별도 배열을 만들어준다.

이 배열을 이용해 현재 선택 가능한 액션 중 가장 유리한 액션을 저장한다.

이후 액션을 역으로 순회하며 현재 n에 대해서 가장 유리한 액션을 선택해 병을 교환한다.

이 때 매번 교환을 직접 수행하면 제한시간 내에 불가능하므로 수식을 이용해 교환 횟수를 계산한다.

```cpp
struct Action {
  long long give;
  long long receive;
};

long long solution(long long n, int actionSize, vector<Action> &actions) {
  long long answer = 0;

  sort(actions.begin(), actions.end(), [](const Action &a, const Action &b) {
    if (a.give == b.give) {
      return a.receive > b.receive;
    }
    return a.give < b.give;
  });

  vector<int> optimalGive(actionSize);
  optimalGive[0] = 0;
  for (int i = 1; i < actionSize; i++) {
    long long diff = actions[i].give - actions[i].receive;
    long long beforeDiff =
        actions[optimalGive[i - 1]].give - actions[optimalGive[i - 1]].receive;

    if (diff < beforeDiff) {
      optimalGive[i] = i;
    } else {
      optimalGive[i] = optimalGive[i - 1];
    }
  }

  for (int targetIndex = actionSize - 1; targetIndex >= 0; targetIndex--) {
    if (actions[targetIndex].give > n) {
      continue;
    }

    int choose = optimalGive[targetIndex];
    long long targetGive = actions[choose].give;
    long long targetReceive = actions[choose].receive;

    long long diff = targetGive - targetReceive;

    long long count = 1 + (n - targetGive) / diff;
    answer += count;

    n -= count * diff;
  }

  return answer;
}
```

## 고생한 점
