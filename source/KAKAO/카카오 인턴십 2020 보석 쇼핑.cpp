#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    map<string, int> num_of_gem;
    int ans_size;
    for (string &s:gems)
        num_of_gem[s]++;
    ans_size = num_of_gem.size();
    num_of_gem.clear();

    int left = 0, right = 0, min_section=1e9;
    while (right < gems.size()){
        num_of_gem[gems[right]]++;
        while (num_of_gem[gems[left]] > 1) 
            num_of_gem[gems[left++]]--;

        if (num_of_gem.size() == ans_size) {
            if (min_section > right - left){
                min_section = right - left;
                answer = {left+1, right+1};
            }
        }
        right++;
    }
    return answer;
}