# 2115. Find All Possible Recipes from Given Supplies

[링크](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 recipes의 크기를 N, 모든 재료의 갯수를 M, supplies의 갯수를 S라 하자.

위상 정렬을 사용할 경우 O(N + M + S)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

위상 정렬에 O(N + M + S)의 공간 복잡도가 필요하다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도  |
| :----------: | :----------: | :----------: |
|     112      | O(N + M + S) | O(N + M + S) |

각 음식은 재료를 필요로 하며, 음식이 재료가 될 수도 있다.

따라서 위상 정렬을 사용해 각 음식마다 필요한 재료들을 미리 계산한다.

이후 supplies에 있는 재료들을 시작점으로 삼아 위상 정렬을 수행한다.

```cpp
vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
  int size = recipes.size();

  unordered_map<string, int> inDegrees;
  unordered_map<string, vector<string>> nexts;

  for (int i = 0; i < size; i++) {
    string target = recipes[i];

    for (string &need : ingredients[i]) {
      inDegrees[target]++;

      nexts[need].push_back(target);
    }
  }

  queue<string> q;
  for (string &key : supplies) {
    q.push(key);
  }

  while (!q.empty()) {
    string cur = q.front();
    q.pop();

    for (string &next : nexts[cur]) {
      inDegrees[next]--;

      if (inDegrees[next] == 0) {
        q.push(next);
      }
    }
  }

  vector<string> answer;

  for (string &r : recipes) {
    if (inDegrees[r] == 0) answer.push_back(r);
  }
  return answer;
}
```

## 고생한 점
