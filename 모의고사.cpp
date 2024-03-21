#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    arr.push_back({ 1,2,3,4,5 });
    arr.push_back({ 2,1,2,3,2,4,2,5 });
    arr.push_back({ 3,3,1,1,2,2,4,4,5,5 });

    vector<pair<int, int>> v;

    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (int j = 0; j < answers.size(); j++) {
            if (arr[i][j % arr[i].size()] == answers[j]) {
                cnt++;
            }
            // v.push_back(arr[i][j % arr[i].size()]);
        }
        v.push_back({ cnt, i + 1 });
    }

    sort(v.begin(), v.end(), cmp);

    int tmp = v[0].first;

    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == tmp) {
            answer.push_back(v[i].second);
        }
    }
    return answer;
}