# 465. Optimal Account Balancing

[링크](https://leetcode.com/problems/optimal-account-balancing/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

transaction의 갯수를 N이라 하자.

transaction을 수행하며 나오는 계좌의 from, to 정보는 최대 2 \* N개이다.

이를 순회하며 각 계좌별로 입금, 출금액으로 변하는 총 금액을 저장한다.

이 계좌마다의 차이 값에 대해서 DFS로 현재 금액을 다른 금액에 transaction 하는 경우들을 탐색한다.

이 과정에서 최소한의 transaction 횟수를 찾는다.

이 경우에 한번의 호출에 시작하는 위치부터 끝 위치까지 호출을 수행하게 된다.

- 1번째 호출 : 0 ~ N (N - 0)
- 2번째 호출 : 1 ~ N (N - 1)
- 3번째 호출 : 2 ~ N (N - 2)
- ...

따라서 시간 복잡도는 O(N!)이다.

N은 최대 8 이므로 최악의 경우 N!은 제한시간 내에 불가능하다.

따라서 백트래킹을 이용해 무의미한 경우의 탐색을 줄인다.

### 공간 복잡도

call stack에 최대 N개의 함수가 쌓일 수 있다.

또한 각 계좌별 차이를 저장할 때 O(N)의 공간 복잡도를 사용하므로 공간 복잡도는 O(N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      56      |    O(N!)    |    O(N)     |

transactions를 순회하며 각 계좌별로 최종 금액의 변경을 합산한다.

- 입금시 현재 계좌 +, 상대 계좌 -
- 출금시 현재 계좌 -, 상대 계좌 +

이렇게 정리한 금액의 변경 중에서 0인 경우는 제외하고 변경을 배열에 저장한다.

이 변경에 대해서 첫번째 index부터 DFS를 이용해 순회한다.

이 때 현재 금액 변경을 다른 금액 변경에 적용했을 때 앞으로 진행하는 과정중에서 가장 transaction이 적게 일어나는 경우를 찾는다.

현재 call stack에서 아무런 transaction이 일어나지 않은 경우는 0을 반환하고, 그 외에 transaction이 일어난 경우는 가장 최소의 횟수를 반환한다.

transaction의 구현은 다음과 같다.

현재 index에 해당하는 금액 차이를 index + 1 부터 순회하며 다른 금액에 더해본다. (이동시켜본다)

이 과정중에서 모든 index에 대해 현재 값을 다른 금액 변경들에 더해보는 경우들을 모두 탐색하게 된다.

이후 index + 1번째에 대해서 DFS를 톨린다.

이 때 현재 금액차이와, 다음 금액차이의 등호가 같은 경우는 절대값이 커지므로 이 경우는 건너뛴다.

```cpp
vector<int> diffArr;
int answer = INT_MAX;

void dfs(int from, int count) {
  // skip zero diff
  while (from < diffArr.size() && diffArr[from] == 0) {
    from++;
  }
  // if from reach to edge update answer
  if (from == diffArr.size()) {
    answer = min(count, answer);
    return;
  }

  int cur = diffArr[from];
  // start from (fromIdx + 1) cause we already moved all value before
  for (int to = from + 1; to < diffArr.size(); to++) {
    // skip to's diff is zero, or same plus or minus
    // cause it make absolute value bigger
    if (diffArr[to] * cur >= 0) {
      continue;
    }

    diffArr[to] += cur;
    dfs(from + 1, count + 1);
    diffArr[to] -= cur;
  }
}

int minTransfers(vector<vector<int>>& transactions) {
  unordered_map<int, int> accountDiff;
  for (vector<int>& t : transactions) {
    int from = t[0], to = t[1], amount = t[2];

    accountDiff[from] -= amount;
    accountDiff[to] += amount;
  }

  for (auto& it : accountDiff) {
    if (it.second == 0) continue;

    diffArr.push_back(it.second);
  }

  dfs(0, 0);
  return answer;
}
```

### 중복되는 경우 줄이기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      68      |    O(N!)    |    O(N)     |

DFS를 수행할 때 이전에 선택한 차이값과 똑같은 값으로 탐색을 진행하는 경우는 건너뛰어 중복 연산을 줄일 수 있다.

```cpp
int dfs(int start) {
  while (start < debts.size() && debts[start] == 0) {
    start++;  // get next debt index
  }

  int minimum = INT_MAX;
  int prev = 0;

  for (int i = start + 1; i < debts.size(); ++i) {
    // skip already tested or same sign debt
    if (debts[i] != prev && debts[i] * debts[start] >= 0) continue;

    debts[i] += debts[start];
    minimum = min(minimum, 1 + dfs(start + 1));
    debts[i] -= debts[start];

    prev = debts[i];
  }

  return minimum < INT_MAX ? minimum : 0;
}
```

## 고생한 점
