# 2107. Number of Unique Flavors After Sharing K Candies

[링크](https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 candies의 길이를 N이라 하자.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우를 사용하며 캔디의 종류와 갯수를 저장해야 한다. 이에 O(N)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      88      |    O(N)     |    O(N)     |

크기가 K인 슬라이딩 윈도우를 사용한다.

이 때 윈도우의 캔디의 종류와 갯수를 저장하는게 아닌 윈도우에 포함되지 않는 부분의 캔디의 종류와 갯수를 저장한다.

이는 윈도우에 포함되는 캔디는 자신이 아닌 다른 사람에게 주는 캔디이기 때문이다.

각 슬라이딩 윈도우의 경우마다 캔디의 갯수를 갱신하며, 캔디의 종류가 가장 많은 경우를 구한다.

```cpp
int shareCandies(vector<int>& candies, int k) {
  int size = candies.size();

  unordered_map<int, int> um;
  for (int& c : candies) {
    um[c]++;
  }

  for (int i = 0; i < k; i++) {
    um[candies[i]]--;
    if (um[candies[i]] == 0) um.erase(candies[i]);
  }

  int answer = um.size();
  for (int right = k; right < size; right++) {
    int left = right - k;

    um[candies[right]]--;
    um[candies[left]]++;

    if (um[candies[right]] == 0) um.erase(candies[right]);

    answer = max(answer, (int)um.size());
  }

  return answer;
}
```

## 고생한 점
