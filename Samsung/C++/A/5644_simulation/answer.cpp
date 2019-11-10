#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct axis {
  int x, y;
};

struct user {
  int x, y, sum;
};

struct charging_list {
  int charge, ap;
};

axis moves[5] = {{0, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int map[10][10][8];
int moving_map[10][10];
user user_A;
user user_B;
int M, A;

void clear() {
  for (int ap = 0; ap < A; ap++) {
    for (int y = 0; y < 10; y++) {
      for (int x = 0; x < 10; x++) {
        map[y][x][ap] = 0;
      }
    }
  }
  user_A = {0, 0, 0};
  user_B = {9, 9, 0};
}

void setAP(int ap_num, int x, int y, int range, int charge) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int distance = abs(i - y) + abs(j - x);

      if (distance <= range) {
        map[i][j][ap_num] = charge;
      }
    }
  }
}

bool compareCharge(charging_list a, charging_list b) {
  return a.charge > b.charge;
}

void charging() {
  vector<charging_list> list_A;
  vector<charging_list> list_B;
  // 충전기 범위에 없는 경우를 위해 더미를 넣어줌
  list_A.push_back({0, -1});
  list_B.push_back({0, -1});
  charging_list A_choose;
  charging_list B_choose;

  // 각자 충전 가능한 ap를 리스트로 추림.
  for (int ap = 0; ap < A; ap++) {
    int current_charge = map[user_A.y][user_A.x][ap];
    if (current_charge != 0) {
      list_A.push_back({current_charge, ap});
    }
  }
  for (int ap = 0; ap < A; ap++) {
    int current_charge = map[user_B.y][user_B.x][ap];
    if (current_charge != 0) {
      list_B.push_back({current_charge, ap});
    }
  }

  sort(list_A.begin(), list_A.end(), compareCharge);
  sort(list_B.begin(), list_B.end(), compareCharge);

  A_choose = list_A[0];
  B_choose = list_B[0];

  if (A_choose.ap != B_choose.ap) {
    // 서로 겹치지 않으므로 충전함
    user_A.sum += A_choose.charge;
    user_B.sum += B_choose.charge;
    return;
  } else {
    // 둘다 충전범위가 아닐 때 처리
    if (A_choose.ap == -1) {
      return;
    }
    // 서로 선택할 것이 지금것밖에 없음
    if (list_A.size() == 2 && list_B.size() == 2) {
      user_A.sum += A_choose.charge / 2;
      user_B.sum += B_choose.charge / 2;
      return;
    }
    // b가 선택지가 더 많음
    if (list_A.size() == 2 && list_B.size() > 2) {
      B_choose = list_B[1];
      user_A.sum += A_choose.charge;
      user_B.sum += B_choose.charge;
      return;
    }

    // a가 선택지가 더 많음
    if (list_A.size() == 2 && list_B.size() > 2) {
      A_choose = list_A[1];
      user_A.sum += A_choose.charge;
      user_B.sum += B_choose.charge;
      return;
    }

    // 둘다 여러개 선택 가능
    if (list_A[1].charge > list_B[1].charge) {
      A_choose = list_A[1];
      user_A.sum += A_choose.charge;
      user_B.sum += B_choose.charge;
      return;
    } else {
      B_choose = list_B[1];
      user_A.sum += A_choose.charge;
      user_B.sum += B_choose.charge;
      return;
    }
  }
}

void solution(int test_case) {
  // 초기화
  clear();

  cin >> M >> A;
  vector<int> move_A(M);
  vector<int> move_B(M);

  for (int i = 0; i < M; i++) {
    cin >> move_A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> move_B[i];
  }

  // ap 정보를 입력받음
  for (int i = 0; i < A; i++) {
    int x, y, range, charge;
    cin >> x >> y >> range >> charge;
    setAP(i, x - 1, y - 1, range, charge);
  }

  // 충전 판단
  charging();
  for (int time = 0; time < M; time++) {
    // 이동
    user_A.x += moves[move_A[time]].x;
    user_A.y += moves[move_A[time]].y;
    user_B.x += moves[move_B[time]].x;
    user_B.y += moves[move_B[time]].y;
    moving_map[user_A.y][user_A.x] = 1;
    moving_map[user_B.y][user_B.x] = 2;

    // 이동 후 충전
    charging();
  }

  cout << "#" << test_case << " " << user_A.sum + user_B.sum << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}