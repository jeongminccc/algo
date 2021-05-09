#include <string>
#include <vector>

using namespace std;
const int maxNode = 10001;

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;
    vector<int> node[maxNode];

    for (int i=0; i<links.size(); ++i){
        for (int j=0; j<2; ++j){
            if (links[i][j] != -1){
                node[i].push_back(links[i][j]);
                node[links[i][j]].push_back(i);
            }
        }
    }

    
    return answer;
}