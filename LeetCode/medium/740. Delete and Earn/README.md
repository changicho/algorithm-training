# 740. Delete and Earn

[링크](https://leetcode.com/problems/delete-and-earn/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자의 개수를 N이라 하자.

숫자를 정렬후에 값과 count로 정렬할 수 있다.

이 과정에 O(N \* log_2(N))의 시간 복잡도가 소요된다.

이후 각 값에 대해서 동적 계획법을 이용해 최적의 값을 계산한다.

이를 한번의 순회로 해결할 수 있으므로 총 시간복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

입력받은 숫자들의 각 값마다의 count를 구해야한다.

유니크한 숫자의 개수를 N'라고 하자.

이를 저장해야 하므로 필요한 공간 복잡도는 O(N')이다.

동적 계획법을 위한 dp배열의 크기도 N'만큼 필요하다.

최악의 경우 N'는 N이므로 공간 복잡도는 O(N)이다.

### 동적 계획법

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      8       | O(N \* log_2(N)) |    O(N)     |

입력받은 숫자를 값과 빈도로 데이터를 가공해야 한다.

이를 위해 map을 사용한다.

- key : 값
- value : 빈도수 \* 값

이후 key에 대해 정렬되고 값과 빈도수를 같이 가지는 vector를 만든 뒤 이를 이용해 동적 계획법을 수행한다.

i-1번째 값과 i번째 값의 차이가 1인 경우 연속된 값이므로 선택 불가능하다.

이를 고려해 dp배열을 갱신할 때 분기 처리한다.

일반식은 다음과 같다.

```cpp
dp[i]; // i번째 숫자를 제거했을 때 얻을 수 있는 최대 이익

if (counts[i].first - counts[i - 1].first > 1) {
  // i-1번째 값을 이용할 수 있으므로 i-1, i-2 두 경우에 대해서 처리한다.
  dp[i] = counts[i].second + max(dp[i - 1], dp[i - 2]);
} else {
  // i-1번째 값을 이용할 수 없으므로 i-2, i-3 두 경우에 대해서 처리한다.
  dp[i] = counts[i].second + max(dp[i - 2], dp[i - 3]);
}
```

이 때 두 경우에 대해서만 처리하는 경우는 이전 index에서 정답의 경우가 발생했을 때 최근 2개 이내의 dp배열중 하나의 값은 무조건 그 정답의 경우를 포함하기 때문이다.

초기값은 다음과 같다.

```cpp
dp[0] = counts[0].second;

dp[1] = counts[1].second + (counts[1].first - counts[0].first > 1 ? dp[0] : 0);

dp[2] = counts[2].second + (counts[2].first - counts[1].first > 1 ? max(dp[0], dp[1]) : dp[0]);
```

이를 이용해 다음과 같이 풀이할 수 있다.

```cpp
int deleteAndEarn(vector<int> &nums) {
  map<int, int> um;

  for (int &num : nums) {
    um[num] += 1;
  }
  int size = um.size();

  vector<pair<int, int>> counts;
  for (auto &it : um) {
    counts.push_back({it.first, it.first * it.second});
  }

  vector<int> dp(size, 0);

  dp[0] = counts[0].second;

  if (size < 2) return dp[0];
  dp[1] =
      counts[1].second + (counts[1].first - counts[0].first > 1 ? dp[0] : 0);

  if (size < 3) return max(dp[0], dp[1]);
  dp[2] = counts[2].second +
          (counts[2].first - counts[1].first > 1 ? max(dp[0], dp[1]) : dp[0]);

  for (int i = 3; i < size; i++) {
    if (counts[i].first - counts[i - 1].first > 1) {
      dp[i] = counts[i].second + max(dp[i - 1], dp[i - 2]);
    } else {
      dp[i] = counts[i].second + max(dp[i - 2], dp[i - 3]);
    }
  }

  int answer = 0;
  for (int &num : dp) {
    answer = max(answer, num);
  }
  return answer;
}
```

## 고생한 점
