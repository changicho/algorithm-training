# E - Count Sequences 2

[링크](https://atcoder.jp/contests/abc425/tasks/abc425_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

가능한 조합의 쌍 (combination)을 미리 구하는데 O(5000^2)의 시간 복잡도를 사용한다.

이후 각 테스트 케이스마다 배열의 크기를 N이라 하자.

각 케이스마다 조합론을 이용해 정답을 구하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

가능한 조합의 쌍 (combination)을 미리 구하는데 O(5000^2)의 공간 복잡도를 사용한다.

각 경우마다 조합론을 이용해 정답을 구하는데 O(1)의 공간 복잡도를 사용한다.

### 조합론

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|     183      | O(5000^2 + N) |  O(5000^2)  |

다항 계수를 사용해 문제를 다음과 같이 나타낼 수 있다.

현재 사용 가능한 숫자들의 갯수를 C1, C2, C2, ... , Ck라 하자.

이 때, 이 숫자들을 이용해 만들 수 있는 수열의 갯수는 다음과 같다.

```plain_text
(C1 + C2 + ... + Ck)! / (C1! * C2! * ... * Ck!)
```

이를 분리하면 다음과 같다.

```plain_text
(C1 / C1) * ((C1 + C2) / C2) * ... * ((C1 + C2 + ... + Ck) / Ck)
```

위 식을 이용해 정답을 구한다.

```cpp
long long combi[5001][5001] = {
    0,
};

auto solution(int n, long long m, vector<int> &counts) {
  long long answer = 1;

  int sum = 0;
  for (int &c : counts) {
    sum += c;
    answer *= combi[sum][c];
    answer %= m;
  }

  return answer;
}

void init(int mod) {
  combi[0][0] = 1;
  for (int i = 1; i <= 5000; i++) {
    combi[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % mod;
    }
  }
}
```

## 고생한 점
