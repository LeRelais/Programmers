#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;
vector<int> v;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    //answer += clothes.size();
    for (int i = 0; i < clothes.size(); i++) {
        string type = clothes[i][1];

        m[type]++;
    }

    map<string, int>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++) {
        answer *= iter->second + 1;
    }



    return answer - 1;
}