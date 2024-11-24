# 1072. Flip Columns For Maximum Number of Equal Rows

[링크](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 R \* C라 하자.

각 행마다의 패턴을 분석해 같은 패턴의 수를 셀 수 있다.

이에 hash map을 사용할 경우 O(R \* C)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

hash map에 O(R \* C)의 공간 복잡도가 필요하다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |  O(R \* C)  |  O(R \* C)  |

각 열을 뒤집었을 때 여러 행의 모든 갯수가 같아지는 경우는 아래와 같다.

- 여러 행의 패턴이 같은 경우
- 이 때 패턴이 같아도 실제 값은 다를 수 있다.

두 행의 패턴이 같은 경우, 두 행에서 다른 값을 가진 열들을 뒤집을 경우 두 행의 모든 원소는 같게 된다.

이를 이용해 각 행의 패턴을 분석하고, 같은 패턴을 가진 행들의 수를 센다.

```cpp
string convert(vector<int>& row) {
  string ret = "";
  int first = row[0];
  for (int& i : row) {
    ret += first == i ? '0' : '1';
  }
  return ret;
}

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
  unordered_map<string, int> count;

  for (vector<int>& row : matrix) {
    string line = convert(row);

    count[line]++;
  }

  int answer = 0;
  for (auto& cur : count) {
    answer = max(cur.second, answer);
  }

  return answer;
}
```

## 고생한 점
