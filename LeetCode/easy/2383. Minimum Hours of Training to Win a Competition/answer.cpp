#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minNumberOfHours(int initialEnergy, int initialExperience,
                       vector<int>& energy, vector<int>& experience) {
    int size = energy.size();

    int myEnergy = initialEnergy;
    int myExperience = initialExperience;
    int answer = 0;

    for (int i = 0; i < size; i++) {
      int curEnergy = energy[i];
      int curExperience = experience[i];

      if (myEnergy <= curEnergy) {
        answer += abs(curEnergy - myEnergy) + 1;
        myEnergy = curEnergy + 1;
      }
      myEnergy -= curEnergy;

      if (myExperience <= curExperience) {
        answer += abs(curExperience - myExperience) + 1;
        myExperience = curExperience + 1;
      }
      myExperience += curExperience;
    }

    return answer;
  }
};