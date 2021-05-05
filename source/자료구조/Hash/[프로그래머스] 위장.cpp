#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    // int clothes_types[31] = {0};
    // int pos = 0;
    // for (vector<string> &vs : clothes){
    //     if (m.find(vs[1]) == m.end()){
    //         clothes_types[pos] = 2;
    //         m[vs[1]] = pos++;
    //     }
    //     else {
    //         clothes_types[m[vs[1]]]++;
    //     }
    // }
    
    // for (int i=0; i<pos; ++i){
    //     answer *= clothes_types[i];
    // } answer--;
    
    for (vector<string> &vs : clothes)
        m[vs[1]]++;

    for (auto iter = m.begin(); iter != m.end(); ++iter){
        answer *= ((*iter).second - 1);
    }

    return answer - 1;
}