# 2025 프로그래머스 코드챌린지 2차 예선 - 봉인된 주문

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/389481)

| 난이도 |
| :----: |
|  lv3   |

## 설계

### 시간 복잡도

입력받은 수를 N, bans의 크기를 M이라 하자.

각 숫자, 문자를 치환하는데 O(log_10(X))의 시간 복잡도를 사용하며 이는 X가 10^15 까지 이므로 O(1)의 시간 복잡도가 소요된다.

각 bans에 대해 처리하며 실제 주문의 번째 수를 구해야한다.

문제 조건에 따라 bans를 정렬해 풀이할 수 있다. 이 경우 O(M \* log_2(M))의 시간 복잡도가 소요된다.

이후 각 bans를 숫자로 변환하는데 O(M)의 시간 복잡도가 소요된다.

이후 입력받은 수로 실제 주문의 번째 수를 구해야한다.

이에 O(1)의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 O(M)의 공간 복잡도가 필요하다.

### 정렬 & 진법

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(M \* log_2(M)) |    O(M)     |

다음 2가지 함수가 존재한다고 하자.

- 숫자를 문자로 변환 : f1
- 문자를 숫자로 변환 : f2

bans에서 N보다 작은 수들이 존재하는 경우 해당 ban들은 무시해야 하므로 N의 값을 변동해야 한다.

bans를 정렬 후 N보다 작은 수의 갯수를 센 뒤 실제 찾아야 하는 N을 구한다.

이 때 각 bans에 대해 f2함수를 사용한다.

이후 보정된 N에 대해서 f1함수를 사용해 정답을 구한다.

f2함수는 진법을 이용해 구할 수 있으며, a는 1을 의미하므로 치환해준다.

f1함수 또한 진법을 이용해 구하며 직전 값이 'z'인 경우 carry가 발생했으므로 이를 처리해준다.

```cpp
string convertToStr(long long target) {
  string ret = "";

  while (target > 0) {
    int add = target % 26;
    target /= 26;

    int cur = -1;

    cur += add;

    if (!ret.empty() && ret.back() == 'z') {
      cur--;
    }

    ret += (cur == -1 ? 'z' : (cur + 'a'));
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

long long convertToNum(string ban) {
  int size = ban.size();

  long long ret = 0;
  for (int i = 0; i < size; i++) {
    ret *= 26;
    ret += (ban[i] - 'a') + 1;
  }

  return ret;
}

string solution(long long n, vector<string> bans) {
  sort(bans.begin(), bans.end(), [](string &a, string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
  });

  for (string &ban : bans) {
    if (convertToNum(ban) <= n) n++;
  }

  return convertToStr(n);
}
```

## 고생한 점
