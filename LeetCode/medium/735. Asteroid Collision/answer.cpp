#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    int size = asteroids.size();

    vector<int> answers;
    answers.push_back(asteroids.front());

    for (int i = 1; i < size; i++) {
      int asteroid = asteroids[i];

      if (answers.empty()) {
        answers.emplace_back(asteroid);
        continue;
      }
      if (asteroid * answers.back() > 0) {
        answers.emplace_back(asteroid);
        continue;
      }
      if (answers.back() < 0 && 0 < asteroid) {
        answers.emplace_back(asteroid);
        continue;
      }

      while (!answers.empty() && answers.back() > 0 && asteroid < 0 && abs(asteroid) > abs(answers.back())) {
        answers.pop_back();
      }

      if (!answers.empty() && answers.back() > 0 && asteroid < 0 && abs(answers.back()) == abs(asteroid)) {
        answers.pop_back();
        continue;
      }
      if (!answers.empty() && answers.back() > 0 && asteroid < 0 && abs(answers.back()) > abs(asteroid)) {
        continue;
      }
      answers.emplace_back(asteroid);
    }
    return answers;
  }
};

// use stack (short)

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> answer;

    for (int asteroid : asteroids) {
      while (!answer.empty() && answer.back() > 0 && answer.back() < -asteroid) {
        answer.pop_back();
      }

      if (answer.empty() || asteroid > 0 || answer.back() < 0) {
        answer.push_back(asteroid);
      } else if (asteroid < 0 && answer.back() == -asteroid) {
        answer.pop_back();
      } else {
        continue;
      }
    }

    return answer;
  }
};