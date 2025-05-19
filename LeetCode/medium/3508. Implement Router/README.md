# 3508. Implement Router

[링크](https://leetcode.com/problems/implement-router/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

limit를 N 입력받은 연산의 수를 M이라 하자.

각 경우마다 저장받은 수를 모두 탐색할 경우 O(N \* M)의 시간 복잡도를 사용한다.

이분 탐색을 이용해 탐색할 경우 O(M \* log(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 데이터를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|     425      | O(M \* log(N)) |    O(N)     |

입력받은 정보의 timestamp는 오름차순으로 주어지는것이 정해져있다.

각 정보들을 저장할 때 순차적으로 쌓아도 오름차순으로 정렬됨이 보장된다.

따라서 각 데이터를 저장한 뒤 특정 범위를 탐색할 때 이분 탐색을 사용할 수 있다.

(upper_bound, lower_bound)

이 때 앞선 정보들이 빠져나가야 하므로 queue와 각 destination 마다 삭제된 수를 저장하는 map을 사용한다.

```cpp
class Router {
 private:
  int limit = 0;
  unordered_map<int, vector<long long>> um;
  unordered_map<int, int> erased;

  queue<vector<int>> q;

  unordered_set<string> us;

  string convert(vector<int> nums) {
    string ret = to_string(nums[0]) + "/" + to_string(nums[1]) + "/" +
                 to_string(nums[2]);

    return ret;
  }

 public:
  Router(int memoryLimit) { limit = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {
    string key = convert({source, destination, timestamp});

    if (us.count(key) > 0) return false;

    if (q.size() == limit) {
      forwardPacket();
    }

    us.insert(key);
    q.push({{source, destination, timestamp}});

    um[destination].push_back(timestamp);
    return true;
  }

  vector<int> forwardPacket() {
    if (q.empty()) return {};

    vector<int> target = q.front();
    q.pop();

    us.erase(convert(target));

    erased[target[1]]++;

    return target;
  }

  int getCount(int destination, int startTime, int endTime) {
    return upper_bound(um[destination].begin() + erased[destination],
                       um[destination].end(), endTime) -
           lower_bound(um[destination].begin() + erased[destination],
                       um[destination].end(), startTime);
  }
};
```

## 고생한 점
