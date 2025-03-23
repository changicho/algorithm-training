# 2023 KAKAO BLIND RECRUITMENT - 표 병합

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/150366)

| 난이도 |
| :----: |
|  lv3   |

## 설계

### 시간 복잡도

표의 크기는 50^2이다. 배열 command의 길이를 N이라 하자.

각 연산을 수행하며 병합에 유니온 파인드를 사용할 수 있다. 이 경우 O(1)의 시간 복잡도로 병합과 검색이 가능하다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

유니온 파인드를 사용하기 위해 표의 좌표들 만큼의 공간이 필요하다. O(1)의 공간 복잡도가 필요하다.

정답 배열에 O(N)의 공간이 필요하다.

### 유니온 파인드

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

좌표들마다의 merge를 유니온 파인드를 이용해 구현한다.

이 때 unmerge 되는 경우 병합 상태를 모두 풀어야 하므로 모든 좌표를 돌며 unmerge를 수행한다.

값을 병합할 때 값을 할당하는 방법의 조건은 다음과 같다.

- 두 셀 중 한 셀이 값을 가지고 있을 경우 병합된 셀은 그 값을 가지게 됩니다.
- 두 셀 모두 값을 가지고 있을 경우 병합된 셀은 (r1, c1) 위치의 셀 값을 가지게 됩니다.

해당 조건에 주의해 구현한다.

```cpp
const int LIMIT = 50;

struct Axis {
  int y, x;
};

vector<string> split(string line) {
  stringstream ss(line);
  string temp;
  vector<string> ret;
  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

vector<vector<string>> board(LIMIT + 1, vector<string>(LIMIT + 1));
vector<vector<Axis>> parents(LIMIT + 1, vector<Axis>(LIMIT + 1));

Axis find(Axis a) {
  if (parents[a.y][a.x].y == a.y && parents[a.y][a.x].x == a.x) return a;
  return parents[a.y][a.x] = find(parents[a.y][a.x]);
}

void updateAxis(Axis a, string &value) {
  Axis target = find(a);
  board[target.y][target.x] = value;
}

void updateValue(string &from, string &to) {
  for (int y = 0; y <= LIMIT; y++) {
    for (int x = 0; x <= LIMIT; x++) {
      if (board[y][x] == from) {
        board[y][x] = to;
      }
    }
  }
}

void merge(Axis from, Axis to) {
  to = find(to);
  from = find(from);

  if (to.y == from.y && to.x == from.x) return;
  string value =
      board[to.y][to.x] == "" ? board[from.y][from.x] : board[to.y][to.x];
  parents[from.y][from.x] = to;

  for (int y = 0; y <= LIMIT; y++) {
    for (int x = 0; x <= LIMIT; x++) {
      Axis axis = find({y, x});

      if (axis.y == to.y && axis.x == to.x && y != to.y && x != to.x) {
        board[y][x] = "";
      }
    }
  }

  board[to.y][to.x] = value;
}

void unmerge(Axis a) {
  Axis target = find(a);
  string value = board[target.y][target.x];

  for (int y = 0; y <= LIMIT; y++) {
    for (int x = 0; x <= LIMIT; x++) {
      Axis parent = find({y, x});

      if (parent.y == target.y && parent.x == target.x) {
        parents[y][x] = {y, x};
        board[y][x] = "";
      }
    }
  }

  board[a.y][a.x] = value;
}

string print(Axis a) {
  Axis target = find(a);
  if (board[target.y][target.x] == "") {
    return "EMPTY";
  }
  return board[target.y][target.x];
}

vector<string> solution(vector<string> commands) {
  for (int y = 0; y <= LIMIT; y++) {
    for (int x = 0; x <= LIMIT; x++) {
      parents[y][x] = {y, x};
    }
  }

  vector<string> answer;

  for (string &c : commands) {
    vector<string> chunk = split(c);

    string key = chunk[0];
    if (key == "UPDATE") {
      if (chunk.size() == 3) {
        updateValue(chunk[1], chunk[2]);
      } else if (chunk.size() == 4) {
        Axis axis = {stoi(chunk[1]), stoi(chunk[2])};
        string value = chunk[3];

        updateAxis(axis, value);
      }
    } else if (key == "MERGE") {
      Axis to = {stoi(chunk[1]), stoi(chunk[2])};
      Axis from = {stoi(chunk[3]), stoi(chunk[4])};
      merge(from, to);
    } else if (key == "UNMERGE") {
      Axis to = {stoi(chunk[1]), stoi(chunk[2])};

      unmerge(to);
    } else if (key == "PRINT") {
      Axis axis = {stoi(chunk[1]), stoi(chunk[2])};

      string ret = print(axis);
      answer.push_back(ret);
    }
  }

  return answer;
}
```

## 고생한 점
