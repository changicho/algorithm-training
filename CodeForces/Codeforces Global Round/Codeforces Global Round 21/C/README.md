# C. Fishingprince Plays With Array

[링크](https://codeforces.com/contest/1696/problem/C)

## 설계

### 시간 복잡도

배열 a의 원소의 갯수를 N, b의 원소의 갯수를 K, 입력받은 수를 M이라 하자.

각 배열의 원소들을 M에 대해서 모두 분해한다.

이 경우 각 원소들을 순회하며 분해해야 하므로 O(N + K)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 배열의 숫자들을 분해할 때, 갯수가 매우 많을 수 있다.

따라서 이를 모두 배열에 저장하지 않고 (값, 갯수)로 묶어 관리한다.

이 경우 공간 복잡도는 최대 O(N + K)이다.

### 분해

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      62      |  O(N + K)   |  O(N + K)   |

A와 B를 모두 M에대해서 원소를 분리해서 같은 경우 둘을 같다고 할 수 있다.

이는 배열을 분해하고, 조합하는 과정에서 각 값들을 merge할 수 있기 때문이다.

각 값을 순회하며 현재 원소가 M으로 나누어 떨어 지는 경우 이 값을 변환한다.

이후 해당 값을 스택에 집어넣는다.

만약 스택의 top의 값이 현재 값이랑 같은 경우 둘을 merge한다. 이를 반복해 값들을 압축한다.

```cpp
struct Data {
  long long num, count;

  bool operator==(const Data& b) const {
    return num == b.num && count == b.count;
  }
};

Data divide(int num, int& m) {
  Data ret = {num, 1};

  while (ret.num > 0 && ret.num % m == 0) {
    ret.num /= m;
    ret.count *= m;
  }

  return ret;
}

void fillStack(int m, vector<int>& a, stack<Data>& stk) {
  for (int& num : a) {
    Data cur = {0, 0};

    if (num % m == 0) {
      cur = divide(num, m);
    } else {
      cur.num = num;
      cur.count = 1;
    }

    while (!stk.empty() && stk.top().num == cur.num) {
      cur.count += stk.top().count;
      stk.pop();
    }

    stk.push(cur);
  }
}

bool solution(int m, vector<int>& a, vector<int>& b) {
  int n = a.size(), k = b.size();

  stack<Data> stk;
  fillStack(m, a, stk);
  vector<Data> tempA, tempB;
  while (!stk.empty()) {
    tempA.push_back(stk.top());
    stk.pop();
  }

  fillStack(m, b, stk);
  while (!stk.empty()) {
    tempB.push_back(stk.top());
    stk.pop();
  }

  return tempA == tempB;
}
```

## 고생한 점
