# 40. Combination Sum II

[링크](https://leetcode.com/problems/combination-sum-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 최대 크기는 100이다.

모든 경우를 탐색하는 경우 O(2^N)이므로 제한시간 내에 불가능하다.

따라서 백트래킹을 이용해 중복되는 경우와 불필요한 경우를 건너 뛰어 시간을 최적화 해야 한다.

### 공간 복잡도

정답의 개수를 M이라 하자.

set을 이용해 정답의 중복 체크를 하는 경우 O(M)의 공간이 필요하다.

백트래킹을 이용해 중복을 건너 뛰는 경우 정답을 저장하는 공간 외에 별도의 공간이 필요하지 않으므로 O(1)이다.

### 백트래킹 & set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     640      |   O(2^N)    |    O(N)     |

탐색에서 백트래킹을 이용해 정답이 될 수 없는 경우를 건너뛴다.

이 때 처음 candidates를 정렬해 정답이 될 수 없는 경우를 모두 순회하지 않고 판단할 수 있다.

모든 숫자는 한번씩만 사용할 수 있으므로 이전에 사용한 index는 건너뛴다.

이 때 정답에서 유일한 경우만 넣어야 하므로 set을 이용해 unique하게 관리한다.

hash_set의 경우는 key가 vector이므로 사용할 수 없다.

```cpp
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  set<vector<int>> s;
  sort(candidates.begin(), candidates.end());

  vector<int> array;
  recursive(-1, target, array, candidates, s);

  vector<vector<int>> answers;

  for (vector<int> cur : s) {
    answers.push_back(cur);
  }

  return answers;
}

void recursive(int index, int diff, vector<int>& array, vector<int>& candidates, set<vector<int>>& s) {
  if (diff == 0) {
    s.insert(array);
    return;
  }

  int size = candidates.size();
  for (int i = index + 1; i < size; i++) {
    int cur = candidates[i];
    if (diff - cur < 0) break;

    array.push_back(cur);
    recursive(i, diff - cur, array, candidates, s);
    array.pop_back();
  }
}
```

### 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(2^N)    |    O(1)     |

위 방법에서 정렬을 이용하면 중복되는 경우를 제외할 수 있다.

만약 다음과 같은 candidates 배열이 있다고 하자.

```javascript
[A, A, B, C];
```

여기서 정답은 A + B + C 하나만 나와야 한다.

그러나 0번째 index에서 시작하는 경우와 1번째 index에서 시작하는 경우의 답이 같다.

이 경우 i번째 index에서 모든 탐색을 끝내고, 만약 i+1번째 숫자가 i번째와 같지 않을 때 까지 i를 증가시킨다.

i번째에서 탐색을 이미 끝마쳤기 때문에 i+1번째에서 탐색하는 것과 동일한 탐색을 건너 뛸 수 있다.

```cpp
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  vector<vector<int>> answers;
  sort(candidates.begin(), candidates.end());

  vector<int> array;
  recursive(-1, target, array, candidates, answers);

  return answers;
}

void recursive(int index, int diff, vector<int>& array, vector<int>& candidates, vector<vector<int>>& answers) {
  if (diff == 0) {
    answers.push_back(array);
    return;
  }

  int size = candidates.size();
  for (int i = index + 1; i < size; i++) {
    int cur = candidates[i];
    if (diff - cur < 0) break;

    array.push_back(cur);
    recursive(i, diff - cur, array, candidates, answers);
    array.pop_back();
    while (i + 1 < size && candidates[i] == candidates[i + 1]) {
      i++;
    }
  }
}
```

## 고생한 점

index를 직접 건드릴 때 size를 초과하지 않도록 항상 조심한다.
