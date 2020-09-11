//
//  [trie]kakao_가사검색.cpp
//  algo
//
//  Created by jm on 2020/09/09.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
const int MAX = 26;

struct Trie{
    Trie* go[MAX]; // 다음 노드를 가리키는 포인터
    bool end;
    map<int,int> m; // 길이가 n남은 단어를 m개 가지고 있음을 표현
    
    Trie(){
        fill(go, go+MAX, nullptr);
        end = false;
    }
    ~Trie(){
        for(int i=0; i<MAX; ++i) if(go[i]) delete go[i];
    }
    
    void insert(const char* word, int size){
        if(*word == '\0') end = true;
        else{
            m[size]++;
            int next = *word - 'a';
            if(!go[next]) go[next] = new Trie;
            go[next]->insert(word+1, size-1);
        }
    }
    
    int cntWords(const char* query, int len){
        int ret = 0;
        if(*query == '\0' || end) return *query == '\0' && end ? 1 : 0; // 노드의 끝 혹은 쿼리의 끝일시 조건검사
        if(*query == '?') return m[len];
        
        for(int i=0; i<MAX; ++i){
            if((*query - 'a' == i || *query == '?') && go[i]) ret += go[i]->cntWords(query+1, len-1);
        }
        
        return ret;
    }
};


vector<int> solution(vector<string> words, vector<string> queries) {
    Trie* root = new Trie;
    Trie* rootReverse = new Trie;
    vector<int> answer;
    
    for(int i=0; i<words.size(); ++i){
        root->insert(words[i].c_str(), (int)words[i].length());
        reverse(words[i].begin(), words[i].end());
        rootReverse->insert(words[i].c_str(), (int)words[i].length());
    }
    for(int i=0; i<queries.size(); ++i)
        if(queries[i][0] == '?'){
            string temp = queries[i];
            reverse(temp.begin(), temp.end());
            answer.push_back(rootReverse->cntWords(temp.c_str(), (int)queries[i].length()));
        }
        else answer.push_back(root->cntWords(queries[i].c_str(), (int)queries[i].length()));
    
    delete root;
    return answer;
}

int main() {
    vector<string> a = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> b = { "fro??", "????o", "fr???", "fro???", "pro?"};

    vector<int> ans = solution(a,b);
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    return 0;
}
