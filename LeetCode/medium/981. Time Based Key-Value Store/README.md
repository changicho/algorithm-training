# 981. Time Based Key-Value Store

[링크](https://leetcode.com/problems/time-based-key-value-store/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 데이터의 개수를 N, 쿼리의 개수를 Q라 하자.

데이터를 저장하고 검색하는데 N번 이내에 수행할 경우 시간 복잡도는 O(N \* Q)이다.

연산은 각 테스트케이스마다 120,000번 수행되므로 위 방법으로는 시간초과가 발생한다.

따라서 O(log_2(N)) 이내에 수행해야 한다.

### 공간 복잡도

데이터는 저장되어 있어야 하므로 O(N)의 공간 복잡도가 필요하다.

### hash map, binary search

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     284      | O(Q \* log_2(N)) |    O(N)     |

데이터를 저장, 검색하는데 시간 복잡도를 최적화 해야 한다.

우선 outer에서 key, value쌍으로 저장하므로 이는 hash map을 이용한다.

이후 내부적으로 timestamp에 따라 검색해야 하며 이를 log_2(N) 이내로 최적화 해야 한다.

문제에서 주어지는 set 연산에서 timestamp는 점점 증가하며 입력되는것이 보장된다.

따라서 별도 정렬할 필요가 없으므로 vector에 저장한 뒤 get 연산시에 timestamp에 대해서 이분 탐색을 수행한다.

이 때 입력받은 timestamp 이하의 값을 찾아야 함에 유의한다.

```cpp
struct Data {
  int timestamp;
  string value;
};

unordered_map<string, vector<Data>> m;

void set(string key, string value, int timestamp) {
  m[key].push_back({timestamp, value});
}

string get(string key, int timestamp) {
  vector<Data>& array = m[key];
  if (array.size() == 0) return "";

  int left = 0, right = array.size();
  Data ret = array[left];
  if (ret.timestamp > timestamp) return "";

  while (left < right - 1) {
    int mid = (left + right) / 2;

    if (array[mid].timestamp <= timestamp) {
      ret = array[mid];
      left = mid;
    } else {
      right = mid;
    }
  }

  return ret.value;
}
```

### hash map, upper_bound

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     284      | O(Q \* log_2(N)) |    O(N)     |

위 방법에서 get연산을 수행할 때 upper_bound를 사용한다.

c++ 에서 map을 생성할 경우 내부적으로 BST로 이루어져 있으므로 선형적으로 탐색이 가능하다.

이 때 입력받은 timestamp 이하의 값을 찾아야 하므로 upper_bound로 찾은 iter값의 바로 전 값을 반환한다.

원하는 값이 없는 경우에 대한 예외 처리는 upper_bound를 한 값이 begin인지로 판단한다.

```cpp
unordered_map<string, map<int, string>> m;

void set(string key, string value, int timestamp) {
  m[key][timestamp] = value;
}

string get(string key, int timestamp) {
  auto it = m[key].upper_bound(timestamp);

  if (it == m[key].begin()) return "";

  // it--;
  // return it->second;
  return prev(it)->second;
}
```

## 고생한 점
