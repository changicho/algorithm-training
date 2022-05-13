# 2266. Count Number of Texts

[링크](https://leetcode.com/problems/count-number-of-texts/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

pressedKeys의 길이를 N이라 하자.

모든 경우를 brute force로 셀 경우 제한시간 내에 불가능하다.

따라서 연속된 수의 갯수에 따라 dp를 이용해 풀이할 수 있다.

각 연속된 수에 따른 경우의 수는 O(N)의 시간 복잡도로 구할 수 있다.

해당 경우의 수를 이용해 정답에서 연속된 숫자 부분들만 분리하고, 각 경우의 수를 곱해 정답을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      76      |    O(N)     |    O(N)     |

문제에서 주어진 숫자는 2가지로 나눌 수 있다.

- 만들 수 있는 문자의 종류가 3개
- 만들 수 있는 문자의 종류가 4개

두 경우마다 연속된 숫자의 갯수에 따른 경우의 수가 다르다.

따라서 두 경우에 대한 dp값을 생성한다.

```cpp
// 정의
dpTree[i]; // i개의 숫자가 연속되어 있을 때 경우의 수 (종류 3개)
dpFour[i]; // i개의 숫자가 연속되어 있을 때 경우의 수 (종류 4개)

// 초기값
dpThree[1] = 1;
dpThree[2] = 2;
dpThree[3] = 4;
dpThree[4] = 7;

dpFour[1] = 1;
dpFour[2] = 2;
dpFour[3] = 4;
dpFour[4] = 8;

// 일반식
dpThree[i] = dpThree[i-1] + dpThree[i-2] + dpThree[i-3];
dpFour[i] = dpFour[i-1] + dpFour[i-2] + dpFour[i-3] + dpFour[i-4];
```

이 과정에서 MOD연산을 수행해 dp값을 갱신한다.

위 dp값을 생성한 뒤 각 문자열을 순회하며 연속된 숫자의 문자열로 분해해 생각한다.

정답은 총 경우의 수 이며, 이는 각 문자열의 경우의 수들의 곱이 된다.

이를 구현하면 다음과 같다.

```cpp
int countTexts(string pressedKeys) {
  int length = pressedKeys.length();
  unordered_set<char> fours = {'7', '9'};

  vector<int> dpThree = {
      0, 1, 2, 4, 7,
  };
  vector<int> dpFour = {
      0, 1, 2, 4, 8,
  };

  for (int i = 5; i <= length; i++) {
    long long three = 0;
    long long four = 0;

    for (int j = 1; j <= 3; j++) {
      three += dpThree[i - j];
      three %= MOD;
    }

    for (int j = 1; j <= 4; j++) {
      four += dpFour[i - j];
      four %= MOD;
    }

    dpThree.push_back((int)three);
    dpFour.push_back((int)four);
  }

  long long count = 1;
  string before = "";
  for (char &c : pressedKeys) {
    if (c != before.back() && before != "") {
      if (fours.count(before.back()) > 0) {
        count *= (long long)dpFour[before.length()];
      } else {
        count *= (long long)dpThree[before.length()];
      }
      count %= MOD;
      before = "";
    }

    before += c;
  }

  if (fours.count(before.back()) > 0) {
    count *= (long long)dpFour[before.length()];
  } else {
    count *= (long long)dpThree[before.length()];
  }
  count %= MOD;

  return (int)count;
}
```

## 고생한 점
