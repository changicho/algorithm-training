# D - Conflict 2

[링크](https://atcoder.jp/contests/abc411/tasks/abc411_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

입력받은 컴퓨터의 수를 N, 쿼리의 수를 Q, 문자열의 총 길이를 S라고 하자.

매번 직접 문자열을 추가할 경우 O(Q \* N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

쿼리를 역순으로 순회하며 유효한 문자열들을 저장한다. 이에 O(Q + S)의 시간 복잡도로 해결할 수 있다.

### 공간 복잡도

정답에 O(S)의 공간 복잡도를 사용한다.

각 쿼리를 저장하는데 O(Q)의 공간 복잡도를 사용한다.

### 역순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      33      |  O(Q + S)   |  O(Q + S)   |

쿼리를 역으로 순회하며 현재 서버에 영향을 주는 서버의 index를 저장한다.

각 쿼리마다 해당 index를 갱신하는 경우 갱신한다.

현재 index에 영향을 주는 문자열이 추가되는 경우 해당 문자열을 정답에 추가한다.

이후 정답의 문자열을 역순으로 덧붙여 최종 문자열을 완성한다.

```cpp
struct Query {
  int type, p;
  string s;
};

string solution(int size, int qSize, vector<Query> &queries) {
  string answer = "";

  stack<int> wordIndexs;

  int target = 0;
  for (int i = qSize - 1; i >= 0; i--) {
    if (queries[i].type == 1) {
      if (target == queries[i].p) {
        target = 0;
      }
    } else if (queries[i].type == 2) {
      if (queries[i].p == target) {
        wordIndexs.push(i);
      }
    } else if (queries[i].type == 3) {
      if (target == 0) {
        target = queries[i].p;
      }
    }
  }

  while (!wordIndexs.empty()) {
    int index = wordIndexs.top();
    wordIndexs.pop();

    answer += queries[index].s;
  }

  return answer;
}
```

## 고생한 점
