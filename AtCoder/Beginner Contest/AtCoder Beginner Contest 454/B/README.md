# B - Mapping

[링크](https://atcoder.jp/contests/abc454/tasks/abc454_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 수를 N, 옷의 갯수를 M이라 하자.

옷의 종류의 수를 찾는데 hash set을 사용할 경우 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(M)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(M)     |    O(M)     |

```cpp
vector<bool> solution(int size, int m, vector<int>& clothes) {
  vector<bool> answer;

  unordered_set<int> us;
  for (int& c : clothes) {
    us.insert(c);
  }

  answer.push_back(us.size() == size);
  answer.push_back(us.size() == m);

  return answer;
}
```

## 고생한 점
