# 1921. Eliminate Maximum Number of Monsters

[링크](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 몬스터의 수를 N이라 하자. (N <= 10^5)

각 몬스터들 중에서 가장 위험한 몬스터들 부터 없애야 한다. 이를 위해 정렬을 사용한다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 시간과 몬스터를 순회하며 제거해나간다. 이에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

몬스터들의 우선순위를 저장하고 정렬하기 위해 O(N)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     118      | O(N \* log_2(N)) |    O(N)     |

각 몬스터들이 도달하는 시간을 구할 수 있다.

이 때 몬스터를 죽일 수 있는 시간은 1초마다 이므로 ceil(몬스터의 거리 / 몬스터의 속도)로 몬스터가 도달하는 시간을 구할 수 있다.

각 시간을 정렬하며 가장 위험한 몬스터들을 구할 수 있다.

각 초마다 현재 죽일 수 있는 가장 위험한 몬스터를 죽이며, 불가능할때까지 계속한다.

```cpp
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
  int size = dist.size();
  vector<int> times;

  for (int i = 0; i < size; i++) {
    int d = dist[i], s = speed[i];

    int t = ceil((double)d / s);

    times.push_back(t);
  }

  sort(times.begin(), times.end(), greater<int>());

  int answer = 0;
  int time = 0;
  while (answer < size) {
    if (time >= times.back()) break;
    times.pop_back();
    answer++;
    time++;
  }
  return answer;
}
```

## 고생한 점
