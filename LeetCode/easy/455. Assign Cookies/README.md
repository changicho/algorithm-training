# 455. Assign Cookies

[링크](https://leetcode.com/problems/assign-cookies/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 g, s의 크기를 N, M이라 하자.

각 인원에게 쿠키를 나눠줄 때 가능한 가장 작은 쿠키를 배정해준다.

이를 위해 배열을 정렬하는데 O(N \* log_2(N)), O(M \* log_2(M))의 시간 복잡도가 소요된다.

이후 투 포인터를 이용해 쿠키를 배정해주며, 이 때 한번의 순회로 가능하다.

### 공간 복잡도

정렬에 최악의 경우 O(N + M)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |          시간 복잡도           | 공간 복잡도 |
| :----------: | :----------------------------: | :---------: |
|      25      | O(N _ log_2(N) + M _ log_2(M)) |  O(N + M)   |

두 배열을 오름차순으로 정렬한다.

한 인원에게 쿠키를 할당할 때 가능한 가장 작은 쿠키를 배정해야 한다.

이를 위해 쿠키에 대해 순회하며 인원을 배정한다.

```cpp
int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());

  int answer = 0;
  for (int i = 0, j = 0; i < g.size() && j < s.size(); j++) {
    if (g[i] <= s[j]) {
      answer++;
      i++;
    }
  }

  return answer;
}
```

## 고생한 점
