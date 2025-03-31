# B - Full House 3

[링크](https://atcoder.jp/contests/abc398/tasks/abc398_b)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

입력받은 카드의 수는 7개 이다.

숫자의 종류는 총 13개 이다.

각 수를 카운팅 한 뒤 정렬을 사용할 수 있다. 이 경우 O(13 \* log_2(13))의 시간 복잡도가 소요된다.

이는 O(1)이다.

### 공간 복잡도

13개의 숫자를 카운팅 하는데 O(1)의 공간 복잡도가 필요하다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

각 카드의 수를 카운팅 한 뒤, 가장 갯수가 많은 두개의 숫자를 고른다.

이후 첫번째 숫자가 3개, 두번째 숫자가 2개 이상인 경우 full house이다.

```cpp
bool solution(vector<int> &cards) {
  vector<int> count(15, 0);
  for (int &num : cards) {
    count[num]++;
  }

  sort(count.begin(), count.end(), greater<int>());

  if (count[0] >= 3 && count[1] >= 2) return true;
  return false;
}
```

## 고생한 점
