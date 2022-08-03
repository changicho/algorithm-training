# 477. Total Hamming Distance

[링크](https://leetcode.com/problems/total-hamming-distance/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

num은 32비트 정수이므로 비트를 최대 32개 가질 수 있다.

각 비트의 0의갯수, 1의 갯수를 세고 각 비트마다의 갯수의 곱을 더해 모든 distance를 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 비트의 갯수를 저장할 공간이 필요하며 이는 O(1)의 공간 복잡도를 사용한다.

### bit count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      63      |    O(N)     |    O(1)     |

해밍 거리는 각 자리별로 다른 문자의 거리이다.

각 자리에 대해 모든 비트들의 거리차이는 다음과 같다.

- 0인 비트의 갯수 \* 1인 비트의 갯수

이는 같은 비트끼리는 해밍 거리가 0이고, 각 비트는 자기와 다른 비트들 모두에 해밍거리를 1씩 가질 수 있기 때문이다.

즉 이를 모든 비트에대해 반복한 값을 구할 수 있다.

이를 이용해 각 자리에 대한 비트수를 구하고 각 자리별로 곱하고 더한다.

이를 구현하면 다음과 같다.

```cpp
int totalHammingDistance(vector<int>& nums) {
  int size = nums.size();

  vector<int> countPlus(32, 0), countMinus(32, 0);
  for (int& num : nums) {
    for (int i = 0; i < 32; i++) {
      bool isPlus = (num & (1 << i)) > 0;

      if (isPlus) {
        countPlus[i]++;
      } else {
        countMinus[i]++;
      }
    }
  }

  int count = 0;
  for (int i = 0; i < 32; i++) {
    count += countPlus[i] * countMinus[i];
  }

  return count;
}
```

## 고생한 점
