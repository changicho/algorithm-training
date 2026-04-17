# E - Team Division

[링크](https://atcoder.jp/contests/abc453/tasks/abc453_e)

| 난이도 |
| :----: |
|  475   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

각 팀의 인원수를 조정하며 정답을 갱신한다.

diff array를 사용해 팀 인원마다 조건을 만족하는 사람의 수를 구할 수 있다.

이를 구하는데 O(N)의 시간 복잡도를 사용한다.

이후 팀의 인원수를 조정하며 조합론을 사용해 정답을 갱신하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

diff array를 사용하기 위해 O(N)의 공간 복잡도를 사용한다.

### diff array & 조합론

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |    O(N)     |    O(N)     |

**조합론**

총 인원이 N명일때 A팀의 인원이 x명 일 경우 B팀의 인원은 N-x명이다.

이 경우 각 인원마다 각 팀마다의 조건을 만족하는 인원과, 두 팀의 조건을 모두 만족하는 인원의 수를 알 수 있다.

이 경우 현재 A팀에 꼭 배정해야 하는 인원 외에 남은자리에 배정할 자리와 배정할 수 있는 인원의 수를 각각 n, r이라 하자.

해당 경우 조합론을 사용해 nCr을 정답에 더할 수 있다.

이 때 두 팀 모두 불만족하는 인원이 하나라도 있는 경우 해당 x에 대한 정답은 없다.

**diff array**

x를 변화시킬 때마다 각 팀마다 조건을 만족하는 인원의 수를 구하기 위해 diff array를 사용한다.

각 인원마다 A팀에 속하기 위한 조건, B팀에 속하기 위한 조건, 두 팀 모두에 속하기 위한 조건을 만족하는 인원의 수를 구하기 위해 diff array를 사용한다.

이 경우 현재 인원이 속한 팀의 최소인원수 L, 최대인원수를 R이라 하면 각 조건은 다음과 같다.

- A팀에 속하기 위한 조건: A팀의 인원수가 L 이상 R 이하
- B팀에 속하기 위한 조건: B팀의 인원수가 L 이상 R 이하 -> A팀의 인원수가 N-R 이상 N-L 이하
- 두 팀에 속하기 위한 조건 : 두 조건의 교집합 -> 팀의 인원수가 max(L, N-R) 이상 min(R, N-L) 이하

이를 이용해 각 x마다의 3가지 조건에 대해서 각각 만족하는 인원의 수를 구한다.

이는 특정 x를 포함하는 range가 몇개인지를 구하는 문제로 변환할 수 있다.

**조합론**

N이 크며 MOD가 들어간 조합론을 구해야 한다.

이를 페르마의 소정리를 이용해 구한다. (팩토리얼, pow연산을 이용)

[이항 계수 3](https://www.acmicpc.net/problem/11401) 해당 문제를 참고하면 된다.

```cpp
static const int MOD = 998244353;

long long factorial[200001];

long long myPow(long long base, long long expo) {
  long long result = 1;

  while (expo > 0) {
    if (expo % 2 == 1) {
      result *= base;
      result %= MOD;
    }
    base = (base * base) % MOD;
    expo /= 2;
  }
  return result;
}

// nCk
long long myCombi(int n, int k) {
  if (k > n || k < 0) return 0;
  if (k == 0 || k == n) return 1;

  long long numer = factorial[n] % MOD;
  long long denom = (factorial[k] * factorial[n - k]) % MOD;

  return numer * myPow(denom, MOD - 2) % MOD;
};

void init() {
  factorial[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }
}

long long solve(int size, const vector<int>& lefts, const vector<int>& rights) {
  vector<int> diffA(size + 2);
  vector<int> diffB(size + 2);
  vector<int> diffBoth(size + 2);

  for (int i = 0; i < size; i++) {
    // A
    {
      diffA[lefts[i]]++;
      diffA[rights[i] + 1]--;
    }

    // B
    {
      int l = size - rights[i];
      int r = size - lefts[i];
      if (l <= r) {
        diffB[l]++;
        diffB[r + 1]--;
      }
    }

    // both
    {
      int l = max(lefts[i], size - rights[i]);
      int r = min(rights[i], size - lefts[i]);
      if (l <= r) {
        diffBoth[l]++;
        diffBoth[r + 1]--;
      }
    }
  }

  vector<int> canA(size + 1), canB(size + 1), canBoth(size + 1);

  for (int teamA = 1; teamA <= size - 1; teamA++) {
    canA[teamA] = canA[teamA - 1] + diffA[teamA];
    canB[teamA] = canB[teamA - 1] + diffB[teamA];
    canBoth[teamA] = canBoth[teamA - 1] + diffBoth[teamA];
  }

  long long answer = 0;

  for (int teamA = 1; teamA <= size - 1; teamA++) {
    int teamB = size - teamA;

    int both = canBoth[teamA];
    int onlyA = canA[teamA] - both;
    int onlyB = canB[teamA] - both;
    int neither = size - (onlyA + onlyB + both);

    if (onlyA > teamA) continue;
    if (onlyB > teamB) continue;
    if (neither > 0) continue;

    int need = teamA - onlyA;
    if (need < 0 || need > both) continue;

    answer = (answer + myCombi(both, need)) % MOD;
  }

  return answer;
}
```

## 고생한 점
