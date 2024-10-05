# 2491. Divide Players Into Teams of Equal Skill

[링크](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 skill의 크기를 N이라 하자.

정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

hash map을 이용해 count한 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

hash map에 저장하는 데 skill의 범위 만큼의 크기를 사용한다. 이는 O(1000)이므로 O(1)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      69      |    O(N)     |    O(1)     |

skill의 모든 원소의 합을 구한다. 해당 합이 N/2로 나누어 떨어지지 않는 경우 -1을 반환한다.

나누어 떨어 지는 경우 각 쌍마다 만들여야 하는 합을 구한다.

skill의 모든 원소를 hash map에 count 한 뒤, 각 쌍을 만들어야 하는 합을 구한다.

이 때 쌍을 못 만드는 경우 -1을 반환한다.

```cpp
long long dividePlayers(vector<int> &skill) {
  int size = skill.size();
  unordered_map<int, int> counts;
  long long sum = 0;
  for (int &num : skill) {
    counts[num]++;
    sum += num;
  }

  if (sum % (size / 2) != 0) return -1;
  int target = sum / (size / 2);

  long long answer = 0;

  for (int &num : skill) {
    if (counts[num] == 0) continue;
    int needed = target - num;
    if (counts[needed] == 0) return -1;

    answer += num * needed;
    counts[num]--;
    counts[needed]--;
  }
  return answer;
}
```

## 고생한 점
