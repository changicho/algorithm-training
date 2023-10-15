# C. Minimum Varied Number

[링크](https://codeforces.com/contest/1714/problem/C)

| 난이도 |
| :----: |
| \*800  |

## 설계

### 시간 복잡도

1부터 9까지 수의 조합으로 나타내는 경우를 모두 나열할 경우 2^9이며 이를 모두 탐색 후 주어지는 S에 대해서 결과를 반환할 수 있다.

이 경우 시간 복잡도는 모든 경우를 탐색하는 경우이며 이는 1024보다 작다.

따라서 O(1)이다.

### 공간 복잡도

2^9가지 경우를 모두 미리 저장해놓을 공간이 필요하다.

이에 O(1)의 공간 복잡도를 사용한다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      30      |    O(1)     |    O(1)     |

DFS로 모든 경우를 탐색한 후 각 조합된 수의 합과 수의 갯수가 적은 순으로 정답을 갱신한다.

이 때 같은 수의 조합일 때 작은 수가 앞에있을수록 숫자로 변환한 값이 작아진다.

이를 이용해 다음과 같이 구현할 수 있다.

```cpp
string table[46] = {
    "",
};

void recursive(int num, int sum, string val) {
  if (num > 10) return;

  if (table[sum] == "") {
    table[sum] = val;
  } else {
    if (val != "" && stoi(val) < stoi(table[sum])) {
      table[sum] = val;
    }
  }

  string next = val;
  next += (num + '0');
  recursive(num + 1, sum + num, next);
  recursive(num + 1, sum, val);
}

// fill answer
recursive(1, 0, "");
```

## 고생한 점
