#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    long win = 0, lose = 0;

    vector<int> cards(9);
    vector<bool> check(19);

    vector<int> combination;

    // 규영이가 받은 카드;
    for (int i = 0; i < 9; i++) {
        cin >> cards[i];
        check[cards[i]] = true;
    }

    // 인영이가 가질 수 있는 카드들
    // 오름차순으로 자동 정렬됨
    for (int i = 1; i < 19; i++) {
        if (!check[i]) {
            combination.push_back(i);
        }
    }

    // 인영이가 어떻게 내느냐에 따라 승패가 갈린다.
    do {
        int enemy_score = 0, my_score = 0;

        // 점수 계산
        for (int i = 0; i < 9; i++) {
            if (cards[i] > combination[i]) {
                my_score += cards[i] + combination[i];
            }
            if (cards[i] < combination[i]) {
                enemy_score += cards[i] + combination[i];
            }

            // 총점중 한쪽이 절반 이상 가져가면
            // 더이상 점수 계산 필요 없음
            if(my_score > 85){
                break;
            }
            if(enemy_score > 85){
                break;
            }
        }

        if (my_score > enemy_score) {
            win++;
        }
        if (my_score < enemy_score) {
            lose++;
        }

    } while (next_permutation(combination.begin(), combination.end()));

    cout << "#" << test_case << " " << win << " " << lose;
    cout << "\n";
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