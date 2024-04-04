# C - Ideal Holidays

[링크](https://atcoder.jp/contests/abc347/tasks/abc347_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

입력받은 수를 A, B, 날짜 배열의 크기를 N이라 하자.

각 날짜를 순회하며 나머지 값을 구한 뒤 해당 날짜들의 묶음을 A 안에 넣을 수 있는지 판단한다.

해당 값들을 빠르게 판단하기 위해 정렬을 사용해야 하므로 정렬에 시간 복잡도 O(N \* log_2(N))를 사용한다.

이후 해당 사이클의 판단을 위해 순회를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 날짜의 나머지 값을 구해야 하므로 O(N)의 공간 복잡도가 필요하다.

### 정렬 & 사이클 순회

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      95      | O(N \* log_2(N)) |    O(N)     |

일주일의 크기는 A + B이다. 이 때 모든 일정을 A일 이내에 넣을 수 있는 경우를 찾아야 한다.

각 날짜를 A+B값으로 나눈 나머지로 치환한다.

이후 해당 날짜들을 정렬한다.

각 날짜들을 순회하며, 해당 날짜를 휴일의 시작점으로 했을 때 휴일이 끝나는 날 까지 다른 날짜들을 모두 포함할 수 있는지 판단한다.

이 때 나머지값들을 순회하기 때문에 현재 날짜보다 나머지값이 작은 값들 또한 포함하기 위해 처리해야한다.

각 날짜들에 A+B값을 더한 값을 그대로 나머지 배열에 삽입 후, 같은 사이클에 대해 판단해 정답을 구한다.

```cpp
bool solution(int a, int b, vector<int> &days) {
  int allDays = a + b;

  unordered_set<int> us;
  for (int &day : days) {
    int cur = day % allDays;
    us.insert(cur);
  }

  vector<int> remainders(us.begin(), us.end());
  sort(remainders.begin(), remainders.end());

  int size = remainders.size();

  for (int i = 0; i < size; i++) {
    remainders.push_back(remainders[i] + allDays);
  }

  for (int i = 0; i < size; i++) {
    int start = remainders[i];
    int end = remainders[i + size - 1];

    if (end - start + 1 <= a) {
      return true;
    }
  }

  return false;
}
```

## 고생한 점
