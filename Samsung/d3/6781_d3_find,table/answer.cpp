#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define CARD_SIZE 9

using namespace std;

int check_continous(vector<int> cards, vector<bool> &visited) {
    int count_pair = 0;

    // 연속 숫자 판별
    for (int count = 0; count < cards.size() / 3; count++) {
        vector<bool> inner_visited = visited;

        int index = 0;
        for (int i = 0; i < cards.size(); i++) {
            if (inner_visited[i]) {
                continue;
            }
            index = i;
            break;
        }

        int temp = cards[index];
        int inner_count = 0;
        for (int i = 0; i < cards.size(); i++) {
            if (inner_visited[i]) {
                continue;
            }

            if (temp == cards[i]) {
                inner_count++;
                temp++;
                inner_visited[i] = true;
            }

            if (inner_count == 3) {
                visited = inner_visited;
                count_pair++;
                break;
            }
        }
    }

    return count_pair;
}

int check_same(vector<int> cards, vector<bool> &visited) {
    int count_pair = 0;

    // 같은 숫자 세개 판별
    int temp_number = 10;
    int same_count = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (visited[i]) {
            continue;
        }
        if (cards[i] == temp_number) {
            same_count++;
        } else {
            temp_number = cards[i];
            same_count = 0;
        }
        if (same_count == 2) {
            same_count = 0;

            visited[i] = true;
            visited[i - 1] = true;
            visited[i - 2] = true;

            int temp_number = 10;

            count_pair++;
        }
    }

    return count_pair;
}

int check(vector<int> cards) {
    int first, second;

    vector<bool> visited(cards.size());

    int count_pair = 0;
    count_pair += check_continous(cards, visited);
    count_pair += check_same(cards, visited);
    first = count_pair;

    visited.clear();
    visited.resize(cards.size());

    count_pair = 0;
    count_pair += check_same(cards, visited);
    count_pair += check_continous(cards, visited);
    second = count_pair;
    
    if (first > second) {
        return first;
    }
    return second;
}

void solution(int test_case) {
    string numbers, colors;
    int count_pair = 0;

    vector<int> cards_R;
    vector<int> cards_G;
    vector<int> cards_B;

    // 문자열 째로 입력하고 나눔
    cin >> numbers >> colors;
    for (int i = 0; i < CARD_SIZE; i++) {
        switch (colors[i]) {
            case 'R':
                cards_R.push_back(numbers[i] - '0');
                break;
            case 'G':
                cards_G.push_back(numbers[i] - '0');
                break;
            case 'B':
                cards_B.push_back(numbers[i] - '0');
                break;
        }
    }

    // 카드 색중 한가지가 3의 배수가 아니면
    // 무조건 승리할 수 없다.
    if (cards_R.size() % 3 != 0 || cards_G.size() % 3 != 0 ||
        cards_B.size() % 3 != 0) {
        cout << "#" << test_case << " Continue\n";
        return;
    }

    // 오름차순으로 정렬
    sort(cards_R.begin(), cards_R.end());
    sort(cards_G.begin(), cards_G.end());
    sort(cards_B.begin(), cards_B.end());

    count_pair += check(cards_R);
    count_pair += check(cards_G);
    count_pair += check(cards_B);

    cout << "#" << test_case << " ";
    if (count_pair == 3) {
        cout << "Win";
    } else {
        cout << "Continue";
    }
    cout << "\n";

    return;
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