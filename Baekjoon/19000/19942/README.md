# 19942. 다이어트

[링크](https://www.acmicpc.net/problem/19942)

| 정답률 | 난이도 |
| :----: | :----: |
|  26%   | 골드 V |

## 설계

### 시간 복잡도

입력받은 식재료의 갯수를 N이라 하자. (N <= 15)

모든 경우를 탐색할 경우 총 2^N가지의 경우가 존재한다.

각 경우에서 적합한 정답을 찾을 경우 최소 O(2^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 이용해 모든 경우를 탐색할 경우 콜 스택에 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(N \* 2^N) |    O(N)     |

각 식재료들을 포함/미포함 하는 모든 경우에 대해 탐색을 진행한다.

이후 정답을 갱신하며 비용이 같은 경우 사전순으로 우선하는 쪽을 선택한다.

```cpp
struct Food {
  int p, f, s, v, cost;
};

bool isFine(Food &cur, Food &need) {
  return cur.f >= need.f && cur.p >= need.p && cur.s >= need.s &&
         cur.v >= need.v;
}

int getTotalCost(vector<int> &choose, vector<Food> &foods) {
  if (choose.empty()) return INT_MAX;
  int cost = 0;
  for (int &i : choose) {
    cost += foods[i].cost;
  }
  return cost;
}

void recursive(int index, Food &need, vector<Food> &foods, Food cur,
               vector<int> &choose, vector<int> &answer) {
  int size = foods.size();

  if (index == size) {
    if (!isFine(cur, need)) return;

    int answerCost = getTotalCost(answer, foods);
    if (cur.cost == answerCost) {
      answer = min(answer, choose);
    } else if (cur.cost < answerCost) {
      answer = choose;
    }
    return;
  }
  // not choose
  recursive(index + 1, need, foods, cur, choose, answer);
  // choose
  cur.f += foods[index].f;
  cur.p += foods[index].p;
  cur.s += foods[index].s;
  cur.v += foods[index].v;
  cur.cost += foods[index].cost;
  choose.push_back(index);

  recursive(index + 1, need, foods, cur, choose, answer);
  choose.pop_back();
}

vector<int> solution(Food &need, vector<Food> &foods) {
  int answerCost = 0;
  vector<int> answer;
  vector<int> choose;
  Food cur = {0, 0, 0, 0, 0};
  recursive(0, need, foods, cur, choose, answer);

  return answer;
}
```

## 고생한 점
