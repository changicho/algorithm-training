# B - cat 2

[링크](https://atcoder.jp/contests/abc413/tasks/abc413_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 배열의 길이를 N, 문자열의 평균 길이를 L이라 하자.

모든 경우의 수를 순회하는데 O(N^2 \* L) 의 시간 복잡도를 갖는다.

hash set을 사용해 유니크한 문자열을 저장하는데 O(L) 의 시간 복잡도를 갖는다.

### 공간 복잡도

hash set에 O(N^2 \* L) 만큼의 공간을 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | O(N^2 \* L) | O(N^2 \* L) |

모든 경우의 수를 순회하며 각 문자열을 합친 후 hash set에 저장한다.

이후 hash set의 크기를 반환한다.

```cpp
int solution(int size, vector<string> &arr) {
  unordered_set<string> us;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) continue;  // Skip if both indices are the same
      string s1 = arr[i];
      string s2 = arr[j];

      string cur = s1 + s2;

      us.insert(cur);
    }
  }

  return us.size();
}
```

## 고생한 점
