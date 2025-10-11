# D - Pop and Insert

[링크](https://atcoder.jp/contests/abc426/tasks/abc426_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

특정 연속된 구간을 제외한 나머지를 모두 연산을 이용해 통일시키는 방법을 사용할 수 있다.

prefix sum, suffix sum을 미리 구해놓는 경우 나머지 구간에 대한 최소 횟수를 O(1)의 시간 복잡도로 구할 수 있다.

prefix sum을 구하는 데 O(N)의 시간 복잡도를 사용하며, 특정 연속된 구간을 순회하며 탐색하는데 O(N)의 시간 복잡도를 사용하므로, 전체 시간 복잡도는 O(N)이다.

### 공간 복잡도

prefix sum, suffix sum을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 구간합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      |    O(N)     |    O(N)     |

0인 숫자가 연속된 구간을 X라 하자.

이 경우 X 앞의 구간과 X 뒤의 구간 으로 나눌 수 있다. 이를 각각 A, B라 하자.

A를 모두 X와 같게 0으로 변경하는 경우 필요한 연산의 수는 다음과 같다.

- A에 존재하는 0을 X로 이동시키기 위해서는 2번의 연산이 필요하다.
- A에 존재하는 1을 X로 이동시키기 위해서는 1번의 연산이 필요하다.

이는 B 또한 마찬가지이다.

따라서 A, B에 존재하는 0과 1의 갯수를 안다면 각 구간을 모두 0으로 변경하는데 필요한 연산의 수를 구할 수 있다.

이는 X가 1로만 이루어진 경우에도 유사하다.

```cpp
auto solution(int size, string &s) {
  // {0 count, 1 count}
  vector<vector<int>> countL2R(size, vector<int>(2));
  vector<vector<int>> countR2L(size, vector<int>(2));

  for (int i = 0; i < size; i++) {
    if (i > 0) {
      countL2R[i] = countL2R[i - 1];
    }

    countL2R[i][s[i] - '0']++;
  }
  for (int i = size - 1; i >= 0; i--) {
    if (i < size - 1) {
      countR2L[i] = countR2L[i + 1];
    }

    countR2L[i][s[i] - '0']++;
  }

  int answer = countR2L[1][(s[0] - '0')] * 2 + countR2L[1][!(s[0] - '0')];

  for (int right = 1, left = 0; right < size; right++) {
    if (s[right] != s[right - 1]) {
      left = right;
    }

    char cur = s[right];
    int curI = cur - '0';
    int invertI = !(cur - '0');

    int count = 0;

    if (left > 0) {
      count += countL2R[left - 1][curI] * 2;
      count += countL2R[left - 1][invertI];
    }

    if (right < size - 1) {
      count += countR2L[right + 1][curI] * 2;
      count += countR2L[right + 1][invertI];
    }

    answer = min(answer, count);
  }

  return answer;
}
```

## 고생한 점
