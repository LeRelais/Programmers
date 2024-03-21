#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
bool used[8];
bool arr[10000000];

void makeNumber(int length, string num, string cur) {
    if (cur.length() == length) {
        v.push_back(stoi(cur));
        return;
    }

    for (int i = 0; i < num.length(); i++) {
        if (!used[i]) {
            used[i] = true;
            makeNumber(length, num, cur + num[i]);
            used[i] = false;
        }
    }
    return;
}

int solution(string numbers) {
    int answer = 0;

    string tmp = "";

    for (int i = 1; i <= numbers.length(); i++) {
        for (int j = 0; j < numbers.length(); j++) {
            tmp = "";
            if (!used[j]) {
                used[j] = true;
                makeNumber(i, numbers, tmp + numbers[j]);
                used[j] = false;
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    arr[1] = true;
    for (int i = 2; i <= 9999999; i++) {
        if (arr[i] == true)
            continue;

        for (int j = 2 * i; j <= 9999999; j += i) {
            arr[j] = true;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (arr[v[i]] == false && v[i] >= 2)
            answer++;
    }

    return answer;
}