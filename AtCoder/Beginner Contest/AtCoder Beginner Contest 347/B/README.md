# B - Substring

[링크](https://atcoder.jp/contests/abc347/tasks/abc347_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

모든 substring을 탐색할 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

유니크한 substring의 개수를 구해야 한다. 이를 위해 hash set을 사용할 경우 O(N^2)의 공간 복잡도가 필요하다.

### 완전 탐색 & hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |   O(N^2)    |   O(N^2)    |

모든 substring을 탐색하며 hash set에 삽입한다.

이후 hash set의 크기를 반환한다.

```cpp
int solution(string &s) {
  unordered_set<string> us;

  int size = s.size();

  for (int left = 0; left < size; left++) {
    string temp = "";
    for (int right = left; right < size; right++) {
      temp += s[right];
      us.insert(temp);
    }
  }

  return us.size();
}
```

## 고생한 점
