# 1871. Jump Game VII

[링크](https://leetcode.com/problems/jump-game-vii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 이동 가능한 범위를 D라 하자.

prefix sum을 이용해 이동 가능한 범위를 검색할 경우 O(N)의 시간 복잡도를 사용한다.

이분 탐색을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum, 이분 탐색에 O(N)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      25      |    O(N)     |    O(N)     |

배열의 원소는 1, 0만 존재하므로 특정 범위에 0 또는 1이 존재하는지 prefix sum을 이용해 빠르게 구할 수 있다.

따라서 특정 i를 순회하며 해당 i에 도달 가능한 이전 index를 검색한다.

```cpp
bool canReach(string s, int minJump, int maxJump) {
  int size = s.size();
  vector<bool> visited(size);
  vector<int> prefix(size);
  visited[0] = true;

  for (int i = 0; i < minJump; ++i) {
    prefix[i] = 1;
  }

  for (int i = minJump; i < size; ++i) {
    int left = i - maxJump, right = i - minJump;

    if (s[i] == '0') {
      int total = prefix[right] - (left <= 0 ? 0 : prefix[left - 1]);

      visited[i] = (total != 0);
    }

    prefix[i] = prefix[i - 1] + visited[i];
  }

  return visited[size - 1];
}
```

## 고생한 점
