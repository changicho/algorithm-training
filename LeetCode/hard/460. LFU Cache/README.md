# 460. LFU Cache

[링크](https://leetcode.com/problems/lfu-cache/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

LFU 캐시를 구현할 때 key, value쌍에 O(1)의 시간 복잡도로 바로 접근하기 위해 hash map을 사용할 수 있다.

이 경우 시간 복잡도는 평균 O(1)이다.

### 공간 복잡도

용량의 크기를 N이라 하자. hash map에 총 N개의 데이터가 저장되므로 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     484      |    O(1)     |    O(N)     |

데이터를 삭제할 때 현재 가장 낮은 freq를 알아야한다.

또한 각 데이터들을 조회할 때 freq를 증가시켜야 한다.

또한 같은 freq일 때는 가장 오래전에 사용된 key를 삭제한다.

이를 위해 다음과 같은 자료구조가 필요하다.

- {freq : keys} : freq로 해당 빈도수를 가지는 key들을 조회
- {key : {value, freq}} : 값을 key로 해당 값과 빈도수를 조회
- {key : iterator} : 값을 key로 삭제시 사용할 iterator를 조회
- lfu : 현재 가장 낮은 빈도값
- 현재 크기와 최대크기

이 자료들을 구현하면 다음과 같이 구현할 수 있다. (빠른 key value 세트 조회를 위해 hash map을 이용)

```cpp
int capacity, size;
int lfu = 0;                                    // minimum freq
unordered_map<int, list<int>> keys;             // freq : keys
unordered_map<int, pair<int, int>> values;      // key : {value,freq}
unordered_map<int, list<int>::iterator> iters;  // key : list iterator
```

우선순위를 update하는 로직은 다음과 같다.

- 해당 값에 대한 freq와 iterator를 찾는다.
- 해당 값의 freq를 증가시키고, 기존 freq로 검색할 수 있는 목록에서 값을 삭제한다.
- 증가된 freq에 현재 key값을 저장한다. (맨 뒤에)
- 이후 해당 iterator를 갱신한다. (리스트의 맨 뒤에 삽입했으므로 해당 iterator로)
- 마지막으로 필요하다면 현재 데이터의 가장 낮은 빈도수를 갱신한다.

우선순위가 낮은 데이터를 삭제하는 방법은 다음과 같다.

- 가장 낮은 빈도수에서 가장 오래된 key를 찾는다.
- 이후 값, iterator에서 해당 값을 제거한다.

데이터의 삽입은 다음과 같다.

- value, freq 쌍의 데이터를 만들어 저장한다.
- freq가 1인 key들의 리스트에 현재 키를 제일 마지막에 삽입한다.
- 해당 key에 대한 iterator를 갱신한다.
- 새로운 데이터가 추가되었으므로 가장 낮은 빈도는 1이다.

이를 구현하면 다음과 같다.

```cpp
class LFUCache {
 private:
  int capacity, size;
  int lfu = 0;                                    // minimum freq
  unordered_map<int, list<int>> keys;             // freq : keys
  unordered_map<int, pair<int, int>> values;      // key : {value,freq}
  unordered_map<int, list<int>::iterator> iters;  // key : list iterator

  void update(int key) {
    int freq = values[key].second;
    auto iter = iters[key];

    values[key].second++;    // increase freq
    keys[freq].erase(iter);  // remove cur iter from before freq
    keys[freq + 1].push_back(key);

    iters[key] = prev(keys[freq + 1].end());

    // trim minimum freq
    while (keys[lfu].empty()) lfu++;
  }

 public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
  }

  int get(int key) {
    if (values.find(key) == values.end()) return -1;

    update(key);
    return values[key].first;
  }

  void put(int key, int value) {
    // do nothing if there are no capacity
    if (capacity == 0) return;

    if (values.find(key) != values.end()) {
      values[key].first = value;
      update(key);
      return;
    }

    if (size == capacity) {
      int remove = keys[lfu].front();
      keys[lfu].pop_front();
      values.erase(remove);
      iters.erase(remove);
    } else {
      size++;
    }

    // put new value. freq is 1
    values[key] = {value, 1};
    keys[1].push_back(key);
    iters[key] = prev(keys[1].end());
    lfu = 1;
  }
};
```

## 고생한 점
