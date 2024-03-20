#include <vector>
#include <map>
#include <set>

using namespace std;

int arr[200001];

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;

    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }

    if (s.size() == 1)
        return 1;

    return s.size() > nums.size() / 2 ? nums.size() / 2 : s.size();
}