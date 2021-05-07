# 72411. 메뉴 리뉴얼

[링크](https://programmers.co.kr/learn/courses/30/lessons/72411)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv2   |   2873    |

## 설계

### 시간 복잡도

코스에 포함될 요리의 수 배열이 주어진다.

크기가 최대 10까지 요리를 선택할 수 있다.

이 경우 조합의 개수는 최대 2^26 이다. (백트래킹을 이용해 최적화가 가능하다.)

그리고 각 조합이 손님들이 주문한 목록에서 실현 가능한지 따져봐야 한다.

손님의 주문 수는 최악의 경우 20이다.

매 경우 마다 직접 비교를 할 경우 O(26)만큼의 복잡도가 필요하며, 비트마스킹을 이용할 경우 O(1)만에 비교가 가능하다.

따라서 최종 시간 복잡도는 대략 다음과 같다.

O(2^26 \* 20)

이는 제한시간 1초 내에 가능하다.

### 공간 복잡도

손님들의 주문한 요리 목록의 비트마스크가 필요하다. 이는 최대 O(10)이다.

또한 각 조합에 따른 조합의 key와, 손님의 count를 저장할 공간이 필요하다. 이는 최악의 경우 O(2^26) 이내이다.

### 비트마스킹

손님들이 주문할 수 있는 음식의 개수는 최대 26개이다.

비트마스크로 표현할 경우 범위는 2^26이며 이는 int형으로 충분하다.

```cpp
vector<int> table;
for (string order : orders) {
  int bitMask = 0;

  for (char c : order) {
    bitMask |= 1 << (c - 'A');
  }

  table.push_back(bitMask);
}
```

또한 메뉴 조합에서 손님들의 주문한 목록과 비교할 때도 비트마스킹을 이용한다.

손님들이 주문한 목록 내에 현재 비트마스크가 포함되는지를 검사하면 되므로 다음과 같이 검사한다.

```cpp
int bitMask = 0;
for (int i = 0; i < ALPHA_SIZE; i++) {
  if (visited[i]) {
    bitMask |= 1 << i;
  }
}

int count = 0;
for (int order : table) {
  if ((bitMask & order) == bitMask) count += 1;
}
```

### 조합 (next permutation)

현재 course에 대해 가능한 alphabet의 조합을 만들어야한다.

모든 경우를 탐색하면 되므로 next_permutation을 이용해 간단하게 구현한다.

```cpp
for (int curCount : course) {
  vector<bool> visited(ALPHA_SIZE, false);
  for (int i = 0; i < curCount; i++) {
    visited[i] = true;
  }
  sort(visited.begin(), visited.end());

  do {
    // search
  } while (next_permutation(visited.begin(), visited.end()));
}
```

### 정답을 찾기

현재 조합이 가능한 손님 수가 2명 이상인 경우 정답이 가능할 수도 있으므로 저장한다.

이 때 조합의 자료 구조는 다음과 같이 설정한다. 이는 이후에 조합이 가능한 손님 수가 가장 많은 것들을 정답에 포함시키기 위함이다.

```cpp
struct Menu {
  string menu;
  int count;
};

bool compare(Menu a, Menu b) {
  return a.count > b.count;
}

// 최대 10개까지 메뉴가 가능하므로 가능한 조합에 포함된 메뉴의 수에 따라 구분함
vector<Menu> menus[11];

string menu = "";
for (int i = 0; i < ALPHA_SIZE; i++) {
  if (visited[i]) {
    menu += (char)('A' + i);
  }
}
// 가능한 손님의 수를 함께 저장해 이후에 정답이 아닌것들을 제외할때 사용
menus[curCount].push_back({menu, count});
```

이후 각 course별로 가장 빈도가 높은 것들만 정답으로 인정한다.

정답은 알파벳 순으로 정렬해야 하므로 다시 정렬해준다.

```cpp
for (int i = 1; i <= 10; i++) {
  if (menus[i].size() == 0) continue;
  sort(menus[i].begin(), menus[i].end(), compare);

  int count = menus[i].front().count;

  for (Menu cur : menus[i]) {
    if (cur.count == count) {
      answer.push_back(cur.menu);
    }
  }
}

sort(answer.begin(), answer.end());
```

## 고생한 점
