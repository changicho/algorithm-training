# E - Yacht

[링크](https://atcoder.jp/contests/abc421/tasks/abc421_e)

| 난이도 |
| :----: |
|  475   |

## 설계

### 시간 복잡도

주사위의 수를 N = 6, 이라 하자. 주사위를 던지는 횟수는 최대 3번이다.

동적 계획법을 사용해 풀이할 경우, 각 상태마다 남은 던지는 횟수와 현재까지 유지하고 있는 주사위의 수를 저장한다.

이는 1초 이내에 가능하다.

### 공간 복잡도

각 상태별 메모이제이션에 O(10^6)의 공간 복잡도를 사용한다.

### 동적계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     163      |   O(10^6)   |   O(10^6)   |

```cpp
double solution(vector<int> &arr) {
  vector<map<vector<int>, double>> memo(4);

  function<double(int, vector<int>)> recursive = [&](int chance, vector<int> keep) {
    if (chance == 0) {
      double res = 0;

      for (int i = 0; i < 6; i++) {
        int count = 0;
        for (int x : keep) {
          if (x == arr[i]) count++;
        }

        res = max(res, (double)count * arr[i]);
      }

      return res;
    }

    chance--;

    if (memo[chance].count(keep)) {
      return memo[chance][keep];
    }

    function<double(int, vector<int>)> go = [&](int num, vector<int> dice) {
      if (num == 0) {
        int diceSize = dice.size();
        double res = 0;
        for (int s = 0; s < (1 << diceSize); s++) {
          vector<int> newKeep = keep;

          for (int i = 0; i < diceSize; i++) {
            if ((s >> i) & 1) newKeep.push_back(dice[i]);
          }

          res = max(res, recursive(chance, newKeep));
        }

        return res;
      }

      double res = 0;
      dice.push_back(0);
      for (int i = 0; i < 6; i++) {
        dice.back() = arr[i];
        res += go(num - 1, dice);
      }

      return res / 6.0;
    };

    double res = go(5 - keep.size(), {});
    return memo[chance][keep] = res;
  };

  double ans = recursive(3, {});

  return ans;
}
```

## 고생한 점
