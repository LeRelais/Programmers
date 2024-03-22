#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a1, int b1) {
    string a = to_string(a1);
    string b = to_string(b1);

    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);

    for (int i = 0; i < numbers.size(); i++)
        answer += to_string(numbers[i]);

    if (answer[0] == '0')
        answer = "0";
    return answer;
}