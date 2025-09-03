# C - Alternated

[링크](https://atcoder.jp/contests/abc421/tasks/abc421_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

두 문자열의 길이를 N이라 하자.

결과적으로 생성되는 문자열은 2종류이다.

각 종류별로 생성 가능한지 판단하기 위해 큐를 사용할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

큐에 index들을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      22      |    O(N)     |    O(N)     |

현재 문자열의 A, B에 해당하는 index들을 순서대로 각 큐에 저장한다.

이후 결과로 만들어야 하는 문자열에 대해서 현재 index 정보를 이용해 최소 교환 횟수를 구한다.

만약 현재 'A' 문자의 차례이며 A인덱스 큐의 front가 B인덱스 큐의 front보다 작다면, 현재 'A' 문자는 제자리에 있으므로 A인덱스 큐에서 pop한다.

반대의 경우 A인덱스 큐의 front가 B인덱스 큐의 front보다 크므로 (더 뒤에 있으므로), 현재 'A' 문자는 B문자와 교환해야 한다.

따라서 현재 A의 index를 앞으로 이동시켜야 하며 앞으로 이동하는 횟수는 현재 index와 A의 index의 차이값이 된다.

이와 유사하게 B에 대해서도 같은 과정을 수행할 수 있다.

```cpp
long long calc(string s, string &target, queue<int> aIs, queue<int> bIs) {
  int size = s.size();

  long long ret = 0;
  for (int i = 0; i < size; i++) {
    if (target[i] == 'A') {
      if (bIs.empty() || aIs.front() < bIs.front()) {
        aIs.pop();
      } else {
        ret += aIs.front() - i;

        aIs.pop();
      }
    } else {
      if (aIs.empty() || bIs.front() < aIs.front()) {
        bIs.pop();
      } else {
        ret += bIs.front() - i;

        bIs.pop();
      }
    }
  }

  return ret;
}

auto solution(int n, string &s) {
  long long answer = 0;

  int size = n * 2;

  queue<int> aIs;
  queue<int> bIs;

  for (int i = 0; i < size; i++) {
    if (s[i] == 'A') {
      aIs.push(i);
    } else {
      bIs.push(i);
    }
  }
  aIs.push(INT_MAX);
  bIs.push(INT_MAX);

  string target = "";
  for (int i = 0; i < size; i++) {
    target += (i % 2) ? 'A' : 'B';
  }

  answer = calc(s, target, aIs, bIs);

  target = "";
  for (int i = 0; i < size; i++) {
    target += (i % 2) ? 'B' : 'A';
  }

  answer = min(answer, calc(s, target, aIs, bIs));

  return answer;
}
```

## 고생한 점
