# C - Plumage Palette

[링크](https://atcoder.jp/contests/abc464/tasks/abc464_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

날짜의 수를 M, 새의 수를 N이라 하자.

각 새룰 색이 변화하는 날짜에 맞춰 저장하는데 O(N), 날짜를 순회하는데 O(M)의 시간 복잡도를 사용한다.

유니크한 색의 수를 관리하기 위해 hash map을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

날짜와 색에 대해 저장하는데 O(N + M)의 공간 복잡도를 사용한다.

### hash map & count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     143      |  O(N + M)   |  O(N + M)   |

각 날짜별로 색이 변화하는 새들을 저장한다.

이후 날짜를 순회하며 색이 변하는 새들을 순회하며 색의 갯수들을 변화시킨다.

이를 hash map으로 관리하며 hash map의 키값을 정답에 추가한다.

```cpp
struct Bird {
  int a, d, b;
};

vector<int> solution(int size, int day, vector<Bird>& birds) {
  vector<vector<Bird>> changes(day);

  unordered_map<int, int> count;
  for (Bird& b : birds) {
    count[b.a]++;

    changes[b.d - 1].push_back(b);
  }

  vector<int> answer(day);

  for (int d = 0; d < day; d++) {
    for(Bird &b : changes[d]){
      count[b.a]--;
      if(count[b.a] == 0){
        count.erase(b.a);
      }

      count[b.b]++;
    }

    answer[d] = count.size();
  }

  return answer;
}
```

## 고생한 점
