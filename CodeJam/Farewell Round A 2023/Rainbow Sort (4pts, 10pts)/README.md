# Rainbow Sort (4pts, 10pts)

[링크](https://codingcompetitions.withgoogle.com/codejam/round/0000000000c95b94/0000000000cada38)

## 설계

### 시간 복잡도

입력받은 색들의 길이를 N이라 하자.

각 색을 순회하며 이미 사용한 색이 이전에 존재하는지 확인한다.

이를 위해 hash set을 이용해 사용한 색을 저장한다.

이 때 연속된 색의 경우는 사용해도 괜찮다.

hash set에 처음 색이 추가될 때마다 정답에 색을 추가한다.

따라서 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set, 정답에 O(N)의 공간 복잡도를 사용한다.

### hash set

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

각 색마다 오름차순 순서를 유지해야 한다.

이는 이전에 사용한 색이 현재 존재할 경우,

해당 두 색 사이의 구간의 길이가 1 이상인 경우 (다른 색이 해당 구간 사이에 존재)

오름차순 순서를 유지 불가능하다.

이는 아래와 같은 경우이다.

```cpp
// 사용한 색과 절대값이 일치한다고 하자
// valid case
{1,1,1}

// invalid case
{1,2,1}
```

따라서 현재 숫자가 이전값과 같지 않으며 이전에 나온 경우가 존재하는 경우는 오름차순으로 변환이 불가능하다.

(같은 두 수의 거리가 0이 아닌 경우)

```cpp
vector<int> solution(vector<int> &colors) {
  int size = colors.size();

  unordered_set<int> used;
  vector<int> answer;
  used.insert(colors[0]);
  answer.push_back(colors[0]);
  for (int i = 1; i < size; i++) {
    if (colors[i] == colors[i - 1]) continue;

    if (used.count(colors[i])) return {};
    used.insert(colors[i]);
    answer.push_back(colors[i]);
  }

  return answer;
}
```

## 고생한 점
