# 473. Matchsticks to Square

[링크](https://leetcode.com/problems/matchsticks-to-square/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

matchsticks의 크기를 N이라 하자.

N개의 성냥을 4분류 했을 때 정사각형을 만들 수 있는지 판단하는데 모두 탐색할 경우 O(4^N)의 시간 복잡도를 사용한다.

이는 매우 큰 값이므로 중복된 값을 줄이기 위해 backtracking을 사용한다.

또한 동적 계획법을 이용해 이전에 탐색한 결과에 대해선 넘어간다.

### 공간 복잡도

동적 계획법을 이용해 탐색 과정을 저장할 경우 O(4^N)의 공간 복잡도를 사용한다.

### DFS & backtracking

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     174      |   O(4^N)    |   O(4^N)    |

성냥의 모든 길이의 합이 4로 나누어 떨어지지 않는 경우 불가능하다.

각 성냥을 4개의 면중 하나에 담아가며 DFS를 진행해본다. 이 때 현재 각 면의 길이의 상태에 따른 탐색을 한번만 수행하기 위해 hash set에 visited 방문을 저장한다.

탐색 시에는 한 면의 길이가 총 합 / 4를 초과하는 경우는 정답이 불가능하므로 건너뛴다.

이를 구현하면 다음과 같다.

```cpp
bool answer = false;
unordered_set<string> visited;

string convert(vector<int> cur) {
  sort(cur.begin(), cur.end());
  string ret = "";
  for (int &c : cur) {
    ret += to_string(c) + '/';
  }
  return ret;
}

void recursive(int index, vector<int> matches, int length, vector<int> cur) {
  if (answer) return;
  string key = convert(cur);
  if (visited.count(key) > 0) return;
  visited.insert(key);

  int size = matches.size();
  if (index == size) {
    answer = true;
    return;
  }

  for (int i = 0; i < 4; i++) {
    cur[i] += matches[index];
    if (cur[i] <= length) {
      recursive(index + 1, matches, length, cur);
    }
    cur[i] -= matches[index];
  }
}

bool makesquare(vector<int> &matchsticks) {
  int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

  if (sum % 4 != 0) return false;
  int length = sum / 4;

  for (int &m : matchsticks) {
    if (m > length) return false;
  }

  sort(matchsticks.begin(), matchsticks.end(), greater<int>());

  vector<int> cur(4, 0);
  recursive(0, matchsticks, length, cur);

  return answer;
}
```

## 고생한 점
