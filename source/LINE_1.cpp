#include <string>
#include <vector>
#include <iostream>

using namespace std;
string chunk[6];

void strsplit(string s){
    int idx=0;
    for (int i=0; i<6; ++i)
        chunk[i] = "";

    for (int i=0; i<s.size(); ++i){
        if (s[i] != ' ')
            chunk[idx] += s[i];
        else
            idx++;
    }
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    int sum, max=0;
    for (int i=0; i<table.size(); ++i){
        sum = 0;
        strsplit(table[i]);

        for (int j=1; j<6; ++j){
            for (int k=0; k<languages.size(); ++k){
                if (chunk[j] == languages[k])
                    sum += preference[k] * (6 - j);
            }
        }
        
        if (max <= sum){
            if (max == sum)
                answer = chunk[0] < answer ? chunk[0] : answer;
            else answer = chunk[0];
            max = sum;
        }
    }
    return answer;
}