# 3147. Taking Maximum Energy From the Mystic Dungeon

[링크](https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 energy의 길이를 N이라 하자.

각 배열을 순회하며 조건을 만족하는 K번째 이전 값을 사용해 현재 최대값을 갱신한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 배열을 사용할 경우 O(1)의 시간 복잡도를 사용한다.

### 동적 계획법 (in-place)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     139      |    O(N)     |    O(1)     |

현재 index를 i라 할 때, i-k번째 값이 존재할 경우 해당 값에 현재 값을 더한 경우와, 현재 값 자체를 사용하는 경우 중 큰 값을 현재 값으로 갱신한다.

이후 i+k번째 값이 존재하지 않을 경우 정답을 갱신한다.

```cpp
int maximumEnergy(vector<int>& energy, int k) {
  int size = energy.size();

  int answer = INT_MIN;
  for (int i = 0; i < size; i++) {
    if (i - k >= 0) {
      int before = energy[i - k];

      energy[i] = max(energy[i], before + energy[i]);
    }

    if (i + k >= size) {
      answer = max(answer, energy[i]);
    }
  }
  return answer;
}
```

## 고생한 점
