# 2023 KAKAO BLIND RECRUITMENT - 이모티콘 할인행사

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/150368)

| 난이도 |
| :----: |
|  lv2   |

## 설계

### 시간 복잡도

배열 users의 크기를 N, emoticons의 크기를 M이라 하자.

각 emoticon 마다의 할인율의 갯수는 4가지 경우이다.

따라서 모든 할인율의 경우를 탐색할 경우 시간 복잡도는 O(4^M)이다.

이후 정답을 갱신할 때 O(N \* M)의 시간 복잡도를 사용한다.

따라서 완전 탐색시 시간 복잡도는 O(4^M \* N \* M)이다.

### 공간 복잡도

재귀호출로 완전 탐색할 경우 call stack에 O(M)의 공간 복잡도를 사용한다.

총 공간 복잡도는 O(M)이다.

### 완전 탐색

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(4^M \* N \* M) |    O(M)     |

각 이모티콘 마다 할인율에 대해 재귀 호출을 통해 모든 경우를 탐색한다.

이후 각 할인율에 대한 구독자와 이익을 구한 뒤 정답을 갱신한다.

```cpp
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
  vector<int> answer = {0, 0};

  vector<int> discounts(emoticons.size(), 0);

  // 1 이모티콘 플러스 서비스 가입자를 최대한 늘리는 것.
  // 2 이모티콘 판매액을 최대한 늘리는 것.
  auto updateAnswer = [&]() {
    int subscribe = 0;
    int cost = 0;

    for (vector<int>& u : users) {
      int target = u[0], limit = u[1];
      int curCost = 0;

      for (int i = 0; i < emoticons.size(); i++) {
        int discount = discounts[i];
        int e = emoticons[i];

        if (discount >= target) {
          curCost += (double)e * ((double)(100 - discount) / 100);
        }
      }

      if (curCost >= limit) {
        subscribe++;
      } else {
        cost += curCost;
      }
    }

    answer = max(answer, {subscribe, cost});
  };

  auto recursive = [&](int index, auto&& recursive) {
    if (index == discounts.size()) {
      updateAnswer();

      return;
    }

    for (int discount = 10; discount <= 40; discount += 10) {
      discounts[index] = discount;
      recursive(index + 1, recursive);
    }
  };

  recursive(0, recursive);

  return answer;
}
```

## 고생한 점
