#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use BST map
// time : O((N + M) * log_2(N))
// space : O(N)
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

// use BST map
// time : O((N + M) * log_2(N))
// space : O(N)
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

// use priority queue
// time : O(N * log_2(N) + M * log_2(N + M))
// space : O(N + M)
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