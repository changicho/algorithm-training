# E - Paint

[링크](https://atcoder.jp/contests/abc346/tasks/abc346_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

입력받은 2차원 좌표의 각 길이를 H, W, 그리고 연산의 갯수를 M이라 하자.

각 연산을 수행하는 데 O(M)의 시간 복잡도가 소요된다.

각 좌표별 최종 연산을 수행하는 데 O(H \* W)의 시간 복잡도가 소요된다. 이는 제한시간 내에 불가능하다.

연산을 역순으로 순회하며 최종적으로 칠해지는 색의 갯수만 구하고 정답을 갱신한다.

각 색마다 갯수를 저장하는 데 hash map을 사용할 경우 O(1)의 시간 복잡도로 참조 가능하다.

연산을 순회하는 데 O(M)의 시간 복잡도를 사용한다.

이후 정렬하는데 O(M \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

map에 O(M)의 공간 복잡도가 필요하다.

이미 칠해진 좌표들을 저장하는 데 O(M)의 공간 복잡도가 필요하다.

### BST map, 역순회

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     114      | O(M \* log_2(M)) |    O(M)     |

색을 칠하는 연산을 역순회한다.

이 경우 이전에 수행한 연산의 결과는 변경되지 않으므로 현재 연산을 수행할 때 이전의 결과를 참조해 갯수를 변경할 수 있다.

초기에는 모두 0으로 칠해여 있으므로 정답 배열에 0의 count를 2차원 좌표의 갯수만큼 저장한다.

이후 역순으로 순회하며 현재 row, col에 대해 칠해야 하는 만큼 색칠한다.

이 때 현재 row를 칠한다고 했을 때 아래와 같이 고려한다.

- 현재 row가 이미 칠해져있는 경우 : 무시함
- 이전에 칠해진 col들의 갯수 : 해당 갯수만큼 빼고 수를 갱신

이후 칠해진 row의 갯수를 갱신한다.

이 때 색을 칠할 때 마다 0으로 칠해진 갯수를 감소시키고, 해당 색의 갯수를 증가시킨다.

이를 col에 대해서도 동일하게 수행한다.

```cpp
map<long long, long long> solution(long long height, long long width,
                                   int operSize, vector<vector<int>> &opers) {
  unordered_set<int> rows;
  unordered_set<int> cols;

  int size = opers.size();

  map<long long, long long> answer;
  answer[0] = (long long)height * width;

  reverse(opers.begin(), opers.end());

  for (vector<int> &oper : opers) {
    if (oper[0] == 1) {
      int row = oper[1] - 1;
      int color = oper[2];

      if (rows.find(row) != rows.end()) continue;

      int count = width - cols.size();
      if (count == 0) continue;

      answer[color] += count;
      answer[0] -= count;
      rows.insert(row);
    } else {
      int col = oper[1] - 1;
      int color = oper[2];

      if (cols.find(col) != cols.end()) continue;

      int count = height - rows.size();
      if (count == 0) continue;

      answer[color] += count;
      answer[0] -= count;
      cols.insert(col);
    }
  }

  if (answer[0] == 0) answer.erase(0);

  return answer;
}
```


## 고생한 점
