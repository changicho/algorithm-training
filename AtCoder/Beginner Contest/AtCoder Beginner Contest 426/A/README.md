# A - OS Versions

[링크](https://atcoder.jp/contests/abc426/tasks/abc426_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 두 문자열의 우선순위를 비교한다.

이에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

3가지 종류가 주어지므로 O(1)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
auto solution(string &x, string &y) {
  unordered_map<string, int> os;
  // "Ocelot", "Serval", "Lynx"
  os["Ocelot"] = 1;
  os["Serval"] = 2;
  os["Lynx"] = 3;

  return os[y] <= os[x];
}
```

## 고생한 점
