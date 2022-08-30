# 2383. Minimum Hours of Training to Win a Competition

[링크](https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

energy, experience의 크기를 N이라 하자.

시뮬레이션을 이용해 초기 상태에서 i번째 경험치와 에너지를 순회하며 필요한 만큼을 계산한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션을 수행할 때 필요한 값은 에너지, 경험치 2가지 이므로 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

현재 자신의 에너지와 경험치를 갖고 첫번째 부터 순회하며 필요한 만큼 더하고, 정답에도 더한다.

이 때 현재 에너지, 경험치가 기존값 이하인 경우에 더함에 유의한다.

이를 구현하면 다음과 같다.

```cpp
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
```

## 고생한 점
