# C - Reindeer and Sleigh 2

[링크](https://atcoder.jp/contests/abc437/tasks/abc437_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

그리디 알고리즘을 사용해 유리한 순서대로 정렬 후 순회하며 답을 구할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      56      | O(N \* log_2(N)) |    O(N)     |

순록을 태우는 경우와 수레를 끄는 경우 수레의 무게와 끄는 힘을 각각 W, P라 하자.

각 순록의 값을 r.w, r.p라 정의할 때 영향을 다음과 같이 준다.

- 수레를 끄는 경우 P + r.p
- 수레를 태우는 경우 W + r.w

수레를 끌던 순록을 태우는 경우 전체 값의 변화는 다음과 같다.

- P = P - r.p
- W = W + r.w

여기서 전체 P는 W보다 커야하므로 따라서 전체 P에 영향은 r.p + r.w만큼의 영향을 주게 된다.

따라서 전체 순록들을 p, w의 합이 작은 순으로 정렬한 뒤 순서대로 수레에 태우는것이 가능한지 확인하며 답을 구할 수 있다.

```cpp
struct Reindeer {
  int w, p;
};

int solution(int size, vector<Reindeer>& reindeers) {
  sort(reindeers.begin(), reindeers.end(),
       [](const Reindeer& a, const Reindeer& b) {
         int diffA = a.p + a.w;
         int diffB = b.p + b.w;

         if (diffA == diffB) {
           return a.w < b.w;
         }
         return diffA < diffB;
       });

  long long totalPower = 0;
  long long totalWeight = 0;
  for (Reindeer& reindeer : reindeers) {
    totalPower += reindeer.p;
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    Reindeer& reindeer = reindeers[i];
    totalPower -= reindeer.p;
    totalWeight += reindeer.w;

    if (totalPower < totalWeight) {
      totalPower += reindeer.p;
      totalWeight -= reindeer.w;
      continue;
    }
    answer++;
  }

  return answer;
}
```

## 고생한 점
