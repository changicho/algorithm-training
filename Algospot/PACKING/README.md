# 알고스팟. 여행 짐 싸기

[링크](https://www.algospot.com/judge/problem/read/PACKING)

| 정답률 |
| :----: |
|  30%   |

## 설계

### 시간 복잡도

입력받은 물건의 갯수를 N, 무게를 W이라 하자.

해당 문제는 knapsack 문제이다. 따라서 동적 계획법을 이용해 풀이할 수 있다.

이 경우 채워야 하는 모든 경우에 O(N \* W)의 시간 복잡도를 사용한다.

각 과정마다 물건들의 index들을 같이 넘기는방법과, dp를 계산한 후 물건의 목록을 구하는 방법이 존재한다.

각 과정마다 index를 같이 넘기는 경우 시간 복잡도는 O(N^2 \* W)이다.

dp를 계산한 후 다시 생성할 경우 O(N \* W)의 시간 복잡도를 사용한다.

### 공간 복잡도

dp의 종류에 최소 O(N \* W)의 공간 복잡도를 사용한다.

각 과정에 index를 같이 넘길 경우 O(N^2 \* W)의 공간 복잡도를 사용한다.

### bottom-up (index status)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|    632ms     | O(N^2 \* W) | O(N^2 \* W) |

knapsack 풀이 알고리즘을 이용하며, 각 상태마다 물건의 index들 또한 같이 넘긴다.

이 때 물건의 index가 아니라 string 문자를 같이 넘길 경우 오답으로 측정되므로 주의한다.

dp식을 다음과 같이 선언한다.

```cpp
// definition
dp[i][w]; // maximum value when until (i-1)'th stuff, use w weight

// initialize
dp[0][w] = dp[i][0] = 0;

// update
dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - stuff.weight] + stuff.value);
```

위 dp식의 값에 현재까지 넣은 물건의 index들 또한 같이 저장하고 넘긴다.

이 경우 dp식을 갱신할 때마다, 물건들의 index또한 같이 넘겨야 하므로 O(N)의 시간 복잡도를 더 사용한다.

```cpp
struct Stuff {
  string name;
  int weight;
  int value;
};

struct Status {
  int totalValue;
  vector<int> indexes;
};

struct Data {
  int totalValue;
  vector<string> stuffs;
};

Data solution(vector<Stuff> &stuffs, int totalWeight) {
  int size = stuffs.size();

  vector<vector<Status>> dp(size + 1, vector<Status>(totalWeight + 1));

  for (int i = 1; i <= size; i++) {
    for (int w = 1; w <= totalWeight; w++) {
      Stuff stuff = stuffs[i - 1];

      if (w - stuff.weight >= 0) {
        int nextValue = dp[i - 1][w - stuff.weight].totalValue + stuff.value;

        if (nextValue >= dp[i - 1][w].totalValue) {
          dp[i][w].totalValue = nextValue;
          dp[i][w].indexes = dp[i - 1][w - stuff.weight].indexes;
          dp[i][w].indexes.push_back(i - 1);
          continue;
        }
      }
      dp[i][w] = dp[i - 1][w];
    }
  }

  Data ret;
  ret.totalValue = dp.back().back().totalValue;
  for (int &idx : dp.back().back().indexes) {
    ret.stuffs.push_back(stuffs[idx].name);
  }
  return ret;
}
```

### bottom-up (reconstruct)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     28ms     |  O(N \* W)  |  O(N \* W)  |

knapsack 문제로 dp식에서 최대 이익을 구한 뒤, 해당 dp배열을 역으로 순회하며 물건의 리스트를 채워나간다.

가장 마지막 index, weight부터 순회하며, 만약 현재값이 index-1에 존재하는 값보다 큰 경우 현재 index의 물건을 정답에 추가한다.

이후 weight를 갱신하며, index가 0이 될 때까지 순회한다.

실제로는 0-index가 아닌 1-index로 선언했으므로 이에 주의한다.

```cpp
Data solution(vector<Stuff> &stuffs, int totalWeight) {
  int size = stuffs.size();

  vector<vector<int>> dp(size + 1, vector<int>(totalWeight + 1, 0));

  for (int i = 1; i <= size; i++) {
    for (int w = 1; w <= totalWeight; w++) {
      Stuff stuff = stuffs[i - 1];

      if (w - stuff.weight >= 0) {
        int nextValue = dp[i - 1][w - stuff.weight] + stuff.value;
        dp[i][w] = max(dp[i - 1][w], nextValue);
        continue;
      }
      dp[i][w] = dp[i - 1][w];
    }
  }

  // reconstruct
  vector<string> answerStuffs;
  for (int i = size, w = totalWeight; i >= 1 && w >= 1; i--) {
    if (dp[i][w] == dp[i - 1][w]) continue;
    answerStuffs.push_back(stuffs[i - 1].name);

    w -= stuffs[i - 1].weight;
  }

  Data ret = {dp.back().back(), answerStuffs};
  return ret;
}
```

### top-down

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     28ms     |  O(N \* W)  |  O(N \* W)  |

```cpp
struct Stuff {
  string name;
  int weight;
  int value;
};

struct Data {
  int totalValue;
  vector<string> stuffs;
};

int pack(int leftWeight, int index, vector<vector<int>> &dp,
         vector<Stuff> &stuffs) {
  int size = stuffs.size();

  if (index == size + 1) return 0;
  int &res = dp[leftWeight][index];
  if (res != -1) return res;

  res = pack(leftWeight, index + 1, dp, stuffs);

  if (leftWeight >= stuffs[index].weight) {
    int next = pack(leftWeight - stuffs[index].weight, index + 1, dp, stuffs) +
               stuffs[index].value;
    res = max(res, next);
  }
  return res;
}

void reconstruct(int leftWeight, int index, vector<vector<int>> &dp,
                 vector<Stuff> &stuffs, vector<string> &answerStuffs) {
  int size = stuffs.size();
  if (index == size) return;

  if (dp[leftWeight][index] == dp[leftWeight][index + 1]) {
    reconstruct(leftWeight, index + 1, dp, stuffs, answerStuffs);
  } else {
    answerStuffs.push_back(stuffs[index].name);
    reconstruct(leftWeight - stuffs[index].weight, index + 1, dp, stuffs,
                answerStuffs);
  }
}

Data solution(vector<Stuff> &stuffs, int totalWeight) {
  int size = stuffs.size();
  int answer = 0;
  vector<string> answerStuffs;
  vector<vector<int>> dp(totalWeight + 1, vector<int>(size + 1, -1));

  pack(totalWeight, 1, dp, stuffs);
  reconstruct(totalWeight, 1, dp, stuffs, answerStuffs);

  Data ret = {dp[totalWeight][1], answerStuffs};

  return ret;
}
```

## 고생한 점
