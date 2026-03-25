# C - Comfortable Distance

[링크](https://atcoder.jp/contests/abc449/tasks/abc449_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 문자들의 index를 모으고 현재 index에서 left ~ right 범위에 있는 index의 개수를 구하는 방식으로 풀이할 수 있다.

이를 위해 이분 탐색을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

index를 저장하는데 O(N)의 공간 복잡도를 가진다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      34      | O(N \* log_2(N)) |    O(N)     |

왼쪽부터 순회하며 각 문자열 index들을 저장한다.

현재 index에 서 이전 index들과의 차이 중 left ~ right 범위에 있는 index의 개수를 구해 answer에 더한다.

이를 위해 (i - left) ~ (i - right) 범위에 있는 index의 개수를 구하는데, 이분 탐색을 사용한다.

```cpp
long long solution(int size, int left, int right, string& s) {
  long long answer = 0;

  vector<vector<int>> index(26);

  for (int i = 0; i < size; i++) {
    int target = s[i] - 'a';

    // i - right ~ i - left
    int count =
        upper_bound(index[target].begin(), index[target].end(), i - left) -
        lower_bound(index[target].begin(), index[target].end(), i - right);

    answer += count;
    index[target].push_back(i);
  }

  return answer;
}
```

## 고생한 점
