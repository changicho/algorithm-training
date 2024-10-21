# 3321. Find X-Sum of All K-Long Subarrays II

[링크](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. subArray의 크기를 K라 하자.

set과 슬라이딩 윈도우를 이용해 k길이의 subarray의 합을 빠르게 구할 수 있다.

이 경우 set에 후보군이 들어가있으므로 각 경우마다 갱신에 시간 복잡도는 O(log_2(N)) 이다.

이를 모든 원소에 대해 수행하므로 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

set을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### set & 슬라이딩 윈도우

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     957      | O(N \* log_2(N)) |    O(N)     |

슬라이딩 윈도우를 사용해 K크기의 subArray의 이동을 구현한다.

이 때 subArray에서 삭제되는 값과 새로 추가되는 값이 존재한다.

각 값들에서 count가 큰 순으로 관리하기 위해 BST기반의 set을 사용한다.

이 때 후보군에 대한 set과 정답의 연산에 추가되는 set을 따로 관리한다.

현재 정답에 포함되어있는 값을 chosen, 포함되지 않은 값을 rest에 저장한다.

수를 삭제할 때 chosen에서는 가장 count가 작은 값을 제거하고,

새로 추가될 때는 rest에서는 가장 count가 큰 값을 추가한다.

현재 값이 삭제되는 경우 chosen에서 삭제하고, rest에 추가한다.

이후 rest에서 chosen으로 이동하는 경우 chosen에 추가하고, rest에서 삭제한다.

```cpp
struct DataSet {
  private:
  unordered_map<int, int> counts;
  set<pair<int, int>> chosen, rest;

  long long sum = 0;
  int limit;
  int size = 0;

  void innerUpdate(int num) {
    if (chosen.empty() && rest.empty()) return;

    if (!counts.count(num)) return;

    pair<int, int> p = {counts[num], num};

    if (chosen.count(p)) {
      sum -= 1LL * num * counts[num];
      chosen.erase(p);
    } else if (rest.count(p)) {
      rest.erase(p);
    }
  }

  public:
  void add(int num) {
    size++;

    innerUpdate(num);
    counts[num]++;

    chosen.insert({counts[num], num});
    sum += 1LL * num * counts[num];

    if (chosen.size() > limit) {
      auto it = chosen.begin();
      rest.insert(*it);
      sum -= 1LL * it->first * it->second;
      chosen.erase(*it);
    }
  }

  void remove(int num) {
    size--;

    innerUpdate(num);

    counts[num]--;
    if (counts[num] == 0) {
      counts.erase(num);
    } else {
      rest.insert({counts[num], num});
    }

    while (chosen.size() < limit && !rest.empty()) {
      auto it = rest.rbegin();
      sum += 1LL * it->first * it->second;
      chosen.insert(*it);
      rest.erase(*it);
    }
  }

  long long getSum() { return sum; }
  int getSize() { return size; }

  DataSet(int limit) { this->limit = limit; }
};

vector<long long> findXSum(vector<int>& nums, int k, int x) {
  int size = nums.size();

  DataSet ds(x);

  vector<long long> answer;

  for (int i = 0; i < size; i++) {
    ds.add(nums[i]);

    if (i >= k) {
      ds.remove(nums[i - k]);
    }

    if (ds.getSize() == k) {
      long long cur = ds.getSum();
      answer.push_back(cur);
    }
  }

  return answer;
}
```

## 고생한 점
