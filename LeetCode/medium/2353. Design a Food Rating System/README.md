# 2353. Design a Food Rating System

[링크](https://leetcode.com/problems/design-a-food-rating-system/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 데이터의 개수를 N, 쿼리의 개수를 M이라 하자.

각 cuisine마다 가장 rating이 높은 음식을 찾으며, 추후 음식의 rating이 변경될 수 있다.

BST기반 map을 이용해 사용할 경우 매번 rating이 높은 음식을 찾는데 O(log_2(N))의 시간 복잡도가 소요된다.

이를 각 쿼리마다, 처음 데이터 저장시 수행할 경우 총 O((N + M) \* log_2(N))의 시간 복잡도를 사용한다.

혹은 우선순위 큐를 사용할 수 있다.

이 경우 큐에 저장에 O(N \* log_2(N))의 시간 복잡도를, 변경 쿼리마다 새로 추가되는 음식의 rating을 갱신하는데 O(log_2(N + M))의 시간 복잡도가 소요된다.

따라서 총 O(N \* log_2(N) + M \* log_2(N + M))의 시간 복잡도를 사용한다.

### 공간 복잡도

음식의 정보를 저장하는데 O(N)의 공간 복잡도를 사용한다.

우선순위 큐를 사용할 때 새로 생성된 정보 또한 저장되므로 O(N + M)의 공간 복잡도를 사용한다.

### BST map

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     522      | O((N + M) \* log_2(N)) |    O(N)     |

각 음식이 속하는 cuisine과 각 음식마다의 rating을 저장한다.

이후 각 음식과 rating을 cuisine별로 묶어서 저장한다.

이 때 가장 높은 rating을 기준으로 찾아야 하므로 rating을 key로 묶어서 저장한다.

음식의 rating의 변경될 경우 기존의 rating을 제거하고 새로운 rating을 추가한다.

```cpp
class FoodRatings {
 private:
  unordered_map<string, string> f2c;
  unordered_map<string, int> f2r;
  unordered_map<string, map<int, set<string>>> foodMap;

 public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines,
              vector<int>& ratings) {
    int size = foods.size();
    for (int i = 0; i < size; i++) {
      string food = foods[i];
      string cuisine = cuisines[i];
      int rating = ratings[i];

      f2c[food] = cuisine;
      f2r[food] = rating;
      foodMap[cuisine][rating].insert(food);
    }
  }

  void changeRating(string food, int newRating) {
    int before = f2r[food];
    f2r[food] = newRating;

    string cuisine = f2c[food];
    foodMap[cuisine][before].erase(food);
    if (foodMap[cuisine][before].empty()) {
      foodMap[cuisine].erase(before);
    }
    foodMap[cuisine][newRating].insert(food);
  }

  string highestRated(string cuisine) {
    return *(foodMap[cuisine].rbegin()->second.begin());
  }
};
```

### BST pair set

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     464      | O((N + M) \* log_2(N)) |    O(N)     |

위 방법에서 set에 rating과 음식을 pair로 묶어 저장한다.

```cpp
class FoodRatings {
 private:
  struct Food {
    string name;
    int rating;
  };

  unordered_map<string, string> f2c;
  unordered_map<string, int> f2r;
  unordered_map<string, set<pair<int, string>>> foodMap;

 public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines,
              vector<int>& ratings) {
    int size = foods.size();
    for (int i = 0; i < size; i++) {
      string food = foods[i];
      string cuisine = cuisines[i];
      int rating = ratings[i];

      f2c[food] = cuisine;
      f2r[food] = rating;
      foodMap[cuisine].insert({-rating, food});
    }
  }

  void changeRating(string food, int newRating) {
    int before = f2r[food];
    string cuisine = f2c[food];

    foodMap[cuisine].erase({-before, food});

    f2r[food] = newRating;
    foodMap[cuisine].insert({-newRating, food});
  }

  string highestRated(string cuisine) {
    pair<int, string> target = *foodMap[cuisine].begin();

    return (target).second;
  }
};
```

### 우선순위 큐

| 내 코드 (ms) |            시간 복잡도             | 공간 복잡도 |
| :----------: | :--------------------------------: | :---------: |
|     372      | O(N _ log_2(N) + M _ log_2(N + M)) |  O(N + M)   |

음식의 rating이 변경될 때마다 우선순위 큐에 저장 후 해당 음식의 rating을 저장하는 map을 갱신한다.

이후 쿼리마다 해당 cuisine의 우선순위 큐에서 가장 rating이 높은 음식을 찾는다.

이 때 해당 음식의 rating이 변경되었을 수 있으므로 rating이 일치하지 않는 경우 갱신된 rating이므로 삭제한다.

```cpp
class FoodRatings {
 private:
  struct Food {
    int rating;
    string name;

    Food(int foodRating, string foodName) {
      this->rating = foodRating;
      this->name = foodName;
    }

    bool operator<(const Food& b) const {
      if (rating == b.rating) {
        return name > b.name;
      }
      return rating < b.rating;
    }
  };

  unordered_map<string, int> f2r;
  unordered_map<string, string> f2c;
  unordered_map<string, priority_queue<Food>> foodMap;

 public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines,
              vector<int>& ratings) {
    int size = foods.size();
    for (int i = 0; i < size; ++i) {
      f2r[foods[i]] = ratings[i];
      f2c[foods[i]] = cuisines[i];

      foodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
    }
  }

  void changeRating(string food, int newRating) {
    f2r[food] = newRating;

    string cuisine = f2c[food];
    foodMap[cuisine].push(Food(newRating, food));
  }

  string highestRated(string cuisine) {
    Food target = foodMap[cuisine].top();

    while (f2r[target.name] != target.rating) {
      foodMap[cuisine].pop();
      target = foodMap[cuisine].top();
    }

    return target.name;
  }
};
```

## 고생한 점
