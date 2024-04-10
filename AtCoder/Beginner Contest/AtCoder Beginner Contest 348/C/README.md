# C - Colorful Beans

[링크](https://atcoder.jp/contests/abc348/tasks/abc348_c)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

입력받은 콩의 갯수를 N이라 하자.

각 콩을 순회하며 색 별로 구분할 수 있다. 이에 hash map을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이후 각 색별로 가장 작은 값들 중 가장 큰 값을 선택한다.

이에 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      57      |    O(N)     |    O(N)     |

콩을 색별로 구분하며, 각 색마다 가장 작은 값을 찾는다.

이후 이 값들 중 가장 큰 값을 찾는다.

```cpp
struct Bean {
  int a, c;
};

int solution(int size, vector<Bean> &beans) {
  unordered_map<int, int> color2minA;

  for (Bean &bean : beans) {
    if (color2minA.find(bean.c) == color2minA.end()) {
      color2minA[bean.c] = bean.a;
    } else {
      color2minA[bean.c] = min(color2minA[bean.c], bean.a);
    }
  }

  int answer = -1;

  for (auto &it : color2minA) {
    answer = max(answer, it.second);
  }

  return answer;
}
```

## 고생한 점
