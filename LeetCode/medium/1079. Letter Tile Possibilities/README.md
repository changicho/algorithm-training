# 1079. Letter Tile Possibilities

[링크](https://leetcode.com/problems/letter-tile-possibilities/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 tiles의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(N!)의 시간 복잡도를 사용하며, 각 경우마다 O(N)의 시간 복잡도를 사용한다.

따라서 총 O(N! \* N)의 시간 복잡도가 소요된다.

최적화된 재귀 호출을 사용할 경우 O(2^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 경우를 hash set에 넣어 저장할 경우 O(N! \* N)의 공간 복잡도가 필요하다.

최적화된 재귀 호출을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      39      | O(N! \* N)  | O(N! \* N)  |

모든 경우를 직접 탐색하며 hash set에 저장해 중복을 제거한다.

```cpp
int numTilePossibilities(string tiles) {
  int size = tiles.size();

  unordered_set<string> us;

  string temp = "";
  vector<bool> visited(size, false);

  function<void(int)> dfs = [&](int index) {
    us.insert(temp);

    for (int i = 0; i < size; i++) {
      if (visited[i]) continue;

      visited[i] = true;
      temp.push_back(tiles[i]);

      dfs(index + 1);

      visited[i] = false;
      temp.pop_back();
    }
  };

  dfs(0);

  return us.size() - 1;
}
```

### 재귀호출 최적화

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(2^N)    |    O(N)     |

```cpp
int recursive(int counts[26]) {
  int ret = 0;

  for (int c = 0; c < 26; c++) {
    if (counts[c] == 0) {
      continue;
    }

    ret++;
    counts[c]--;
    ret += recursive(counts);
    counts[c]++;
  }

  return ret;
}

int numTilePossibilities(string tiles) {
  int counts[26] = {0};
  for (char &c : tiles) {
    counts[c - 'A']++;
  }

  return recursive(counts);
}
```

## 고생한 점
