#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
        if ((100 - progresses[i]) % speeds[i] != 0)
            q.push((100 - progresses[i]) / speeds[i] + 1);
        else
            q.push((100 - progresses[i]) / speeds[i]);
    }



    while (!q.empty()) {
        int x = q.front();
        int cnt = 1;
        q.pop();

        while (x >= q.front() && !q.empty()) {
            cnt++;
            q.pop();
        }

        answer.push_back(cnt);
    }
    return answer;
}