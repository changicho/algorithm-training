# 904. Fruit Into Baskets

[링크](https://leetcode.com/problems/fruit-into-baskets/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 나무의 갯수를 N이라 하자. (N <= 10^5)

매 시작점마다 가능한 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

과일의 종류와 갯수를 저장해야 한다. 과일은 최대 2종류까지 저장 가능하므로 hash map을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     188      |    O(N)     |    O(1)     |

범위에 포함할 시작 index와 끝 index에 대해 탐색을 진행한다.

이 때 끝 index를 증가시킬 때마다 시작 index를 가능한 곳까지 이동시킨다.

```cpp
int totalFruit(vector<int>& fruits) {
  int size = fruits.size();

  unordered_map<int, int> baskets;
  int left = 0;
  int answer = 0;
  for (int right = 0; right < size; right++) {
    baskets[fruits[right]]++;

    while (baskets.size() > 2 && left < right) {
      baskets[fruits[left]]--;

      if (baskets[fruits[left]] == 0) {
        baskets.erase(fruits[left]);
      }
      left++;
    }

    answer = max(answer, right - left + 1);
  }
  return answer;
}
```

## 고생한 점
