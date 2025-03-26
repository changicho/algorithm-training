# 에어컨

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/214289)

| 난이도 |
| :----: |
|  lv3   |

## 설계

### 시간 복잡도

입력받은 onboard 배열의 크기를 N이라 하자.

온도의 범위는 -10 ~ 50 까지이다.

동적 계획법을 사용해 매 시간마다 온도에 대한 최소값을 구한다.

이 경우 시간 복잡도는 O(N \* 61) 이므로 O(N)이다.

제한시간 내에 충분하다.

### 공간 복잡도

동적 계획법을 사용할 경우 매 온도에 대한 dp배열을 선언한다.

이를 모두 선언할 경우 O(N)이며 직전값만 사용해 최적화 할 경우 O(1)이다.

### 동적 계획법

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

각 시간마다 온도에 대한 최소 에너지 비용 dp 배열을 선언한다.

이후 각 시간마다 온도에 대해 최소값을 갱신한다.

이 때 에어컨을 켜는 경우와 끄는 경우를 나눠서 생각한다.

에어컨을 켰을 때 희망온도가 현재 온도와 다른 경우 에너지 a만큼 추가로 든다.

이는 현재 온도와 다른 모든 온도에 대해 동일하므로, 현재 온도에 대해서만 고려한다.

에어컨을 끄는 경우, 켜는 경우 각각 현재 온도를 만들 수 있는 경우는 3가지이다.

- 이전 온도에서 올라오는 경우
- 이전 온도에서 내려가는 경우
- 이전 온도에서 유지하는 경우

```cpp
const int LIMIT = 50;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
  // while(!onboard.empty() && onboard.back() == 0){
  //     onboard.pop_back();
  // }

  int size = onboard.size();

  temperature += 10;
  t1 += 10;
  t2 += 10;

  vector<int> dp(LIMIT + 1, INT_MAX);

  dp[temperature] = 0;

  for (int day = 1; day < size; day++) {
    vector<int> newDp(LIMIT + 1, INT_MAX);

    bool hasHuman = onboard[day];
    int leftT = hasHuman ? t1 : 0;
    int rightT = hasHuman ? t2 : LIMIT;

    for (int t = leftT; t <= rightT; t++) {
      // turn off air conditioner case
      if (t <= temperature && t - 1 >= 0) {
        newDp[t] = min(newDp[t], dp[t - 1]);
      }
      if (t >= temperature && t + 1 <= LIMIT) {
        newDp[t] = min(newDp[t], dp[t + 1]);
      }
      if (t == temperature) {
        newDp[t] = min(newDp[t], dp[t]);
      }

      // turn on conditioner case
      if (t + 1 <= LIMIT && dp[t + 1] != INT_MAX)
        newDp[t] = min(newDp[t], dp[t + 1] + a);
      if (dp[t] != INT_MAX) newDp[t] = min(newDp[t], dp[t] + b);
      if (t - 1 >= 0 && dp[t - 1] != INT_MAX)
        newDp[t] = min(newDp[t], dp[t - 1] + a);
    }

    dp = newDp;
  }

  int answer = INT_MAX;
  for (int t = 0; t <= LIMIT; t++) {
    answer = min(answer, dp[t]);
  }

  return answer;
}
```

## 고생한 점

온도 범위가 -10 ~ 50 이며 이 범위를 초과하는 상황에서 정답을 생성하는 경우는 없다.

(에어컨을 이용해 온도를 범위 밖으로 설정하는 경우)