# C - Concat (X-th)

[링크](https://atcoder.jp/contests/abc416/tasks/abc416_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

문자열의 갯수를 N, 조합의 경우의 수를 K, 문자열의 길이를 L이라 하자. (L은 10 이하)

조합으로 만들어 질 수 있는 문자열의 최대 길이는 K \* L 이다.

가능한 모든 조합의 수는 N^K 이다.

완전 탐색으로 배열에 삽입하는데 O(N^K \* K \* L)의 시간 복잡도를 사용한다. (L은 무시 가능)

이를 정렬하는데 O(N^K \* log_2(N^K) \* K \* L)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 조합을 저장할 경우 O(N^K \* K \* L) 이다.

### 완전 탐색

| 내 코드 (ms) |          시간 복잡도           |   공간 복잡도    |
| :----------: | :----------------------------: | :--------------: |
|      24      | O(N^K \* log_2(N^K) \* K \* L) | O(N^K \* K \* L) |

가능한 모든 조합을 생성한 뒤 정렬 후 X번째 문자열을 출력한다.

```cpp
string solution(int n, int k, int x, vector<string> &s) {
  vector<string> arr;

  function<void(int, string &)> dfs = [&](int idx, string &current) {
    if (idx == k) {
      arr.push_back(current);
      return;
    }

    for (int i = 0; i < n; i++) {
      string before = current;
      current += s[i];
      dfs(idx + 1, current);
      current = before;
    }
  };

  string current = "";
  dfs(0, current);

  sort(arr.begin(), arr.end());

  return arr[x - 1];
}
```

## 고생한 점
