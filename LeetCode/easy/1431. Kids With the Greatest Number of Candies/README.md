# 1431. Kids With the Greatest Number of Candies

[링크](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

캔디의 개수를 N이라 하자.

현재 캔디에 extra를 더했을 때 가장 큰 수인지 매번 판별할 경우 O(N^2)의 시간 복잡도가 소요된다.

기존에 가장 큰 캔디를 찾고 이를 이용할 경우 one pass만에 풀이할 수 있으므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열을 생성하는데 O(N)의 공간 복잡도가 필요하다.

그 외에는 최대값을 저장할 공간만 필요하다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

candies에서 최대값을 찾는다.

각 candy를 순회해며 extra를 더했을 때 이 값이 최대값 이상인 경우 캔디 묶음에서 최대값이 될 수 있으므로 이를 비교한다.

algorithm 헤더의 max_element를 이용하면 maximum을 바로 찾을 수 있다.

```cpp
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
  int size = candies.size();
  int maximum = *max_element(candies.begin(), candies.end());

  vector<bool> answer(size, false);
  for (int i = 0; i < size; i++) {
    if (candies[i] + extraCandies >= maximum) {
      answer[i] = true;
    }
  }

  return answer;
}
```

## 고생한 점
