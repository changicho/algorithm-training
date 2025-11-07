# 3494. Find the Minimum Amount of Time to Brew Potions

[링크](https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 skill의 크기를 N, mana의 크기를 M이라 하자.

각 마법사마다 직전 포션을 만드는데 끝나는 시간과 현재 포션을 만드는 데 걸리는 시간을 이용해 순서대로 연속해서 포션을 만들기 위한 최소 시간을 구한다.

이를 동적 계획법을 사용해 직전 값을 사용할 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 포션마다 정보를 저장할 경우 O(N \* M)의 공간 복잡도를 사용한다.

직전 값만을 사용하므로 이를 최적화 하면 O(N)의 공간 복잡도를 사용할 수 있다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     255      |  O(N \* M)  |    O(N)     |

각 마술사마다 직전 포션을 만드는 데 실제 끝난 시간을 기록한다.

이후 현재 i번째 마술사까지 포션을 만드는 데 가능한 최소 시간은 다음과 같다.

- max(직전 마술사의 끝난 시간, 현재 마술사의 끝난 시간) + 현재 포션을 만드는 데 걸리는 시간

이는 직전 마술사가 작업이 끝났을 때 바로 연속해서 현재 마술사가 작업을 시작해야 하기 때문이다.

따라서 현재 마술사가 실제 작업을 진행할 수 있는 시간으로 업데이트 한다.

이후 최종 마술사가 마지막 포션을 만드는 데 걸리는 시간을 구할 수 있으며, 이를 이용해 마술사들이 각각 실제 작업을 진행이 끝난 시간을 구한다.

이를 각 포션들에 대해 순서대로 진행한다.

```cpp
long long minTime(vector<int>& skill, vector<int>& mana) {
  int size = skill.size();
  int mSize = mana.size();
  vector<long long> endTimes(size, 0);

  endTimes[0] = mana[0] * skill[0];
  for (int i = 1; i < size; i++) {
    endTimes[i] = endTimes[i - 1] + skill[i] * mana[0];
  }

  for (int i = 1; i < mSize; i++) {
    endTimes[0] = endTimes[0] + skill[0] * mana[i];

    for (int j = 1; j < size; j++) {
      endTimes[j] = max(endTimes[j - 1], endTimes[j]) + skill[j] * mana[i];
    }

    // update real endTimes by last
    for (int j = size - 2; j >= 0; j--) {
      endTimes[j] = endTimes[j + 1] - skill[j + 1] * mana[i];
    }
  }

  return endTimes.back();
}
```

## 고생한 점
