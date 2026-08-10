# 4007. Widest Possible Fence

[링크](https://leetcode.com/problems/widest-possible-fence/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

배열의 원소를 카운트 후 카운트 쌍을 이용해 합의 경우의 수를 구한다. 이에 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 카운팅에 O(N^2)의 공간 복잡도를 사용한다.

### hash map & frequency counting

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1153     |   O(N^2)    |   O(N^2)    |

plank 하나만 이용해 만들 수 있는 경우와 2개를 이용해 만들 수 있는 경우를 구한다.

planks의 카운팅을 한 뒤 해당 카운팅 hash map을 2중으로 순회하며 조합의 수를 구한다.

이 때 중복 계산을 막기 위해 (a + b)를 구할 때 a < b인 경우와 a == b인 경우만 카운팅한다.

이 때 1개만 이용해 height를 만드는 경우 또한 정답에 추가해야한다.

```cpp
int maximumWidth(vector<int>& planks) {
  unordered_map<int, int> count, twoCount;

  for (int& p : planks) {
    count[p]++;
    twoCount[p]++;
  }

  for (auto it1 : count) {
    for (auto& it2 : count) {
      int a = it1.first, b = it2.first;
      int countA = it1.second, countB = it2.second;

      if (a < b) {
        twoCount[a + b] += min(countA, countB);
      }
      if (a == b) {
        twoCount[a + b] += countA / 2;
      }
    }
  }

  int answer = 0;
  for (auto& [key, count] : twoCount) {
    answer = max(answer, count);
  }
  return answer;
}
```

## 고생한 점
