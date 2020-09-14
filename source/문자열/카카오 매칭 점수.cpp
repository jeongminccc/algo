//
//  카카오 매칭 점수.cpp
//  algo
//
//  Created by jm on 2020/09/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Page{
    int idx;
    int basic, link;
    double score;
};

bool compare(Page& a, Page& b){
    if(a.score == b.score) return a.idx < b.idx;
    return a.score > b.score;
}
int solution(string word, vector<string> pages) {
    int wsize  = word.size();
    map<string, int> pagehash; //url, index
    vector<Page> pagelist;
    transform(word.begin(),word.end(),word.begin(),::tolower); // word를 소문자로
    
    for(int i = 0; i < pages.size(); ++i){
        string& s = pages[i];
        transform(s.begin(),s.end(),s.begin(),::tolower);
        
        int mid = 0, left = 0, right;
        while(mid <= left){
            left = s.find("<meta",left + 1); //meta의 시작위치가 left에 저장
            right = s.find(">",left);
            mid = s.rfind("https://",right); //끝에서부터 https가 있는지 찾음
        }// url 시작위치가 mid에 저장됨.
        
        right = s.find("\"",mid);
        string url = s.substr(mid, right - mid);
        // 이 페이지를 나타내는 url을 구함.
        
        left = s.find("<body>",right); //body의 시작 위치
        int basic = 0;
        for(int start = left; ;){ // 기본 점수를 구함.
            start = s.find(word, start + 1);
            if(start == string::npos) break; // 못찾으면
            if(!isalpha(s[start-1]) && !isalpha(s[start+wsize])){
                basic++;
                start += wsize;
            }
        }
        
        int link = 0;
        for(int start = left; ;){
            start = s.find("<a href",start + 1);
            if(start == string::npos) break;
            link++;
        }
        
        pagehash[url] = i;
        pagelist.push_back({i, basic, link, (double)basic});
    }
    
    for(int i = 0; i < pages.size(); ++i){
        string& s = pages[i];
        for(int left = 0, right = 0; ;){
            left = s.find("<a href",right);
            if(left == string :: npos) break;
            
            left = s.find("https://",left);
            right = s.find("\"", left);
            // url
            string linkurl = s.substr(left,right - left);
            
            map<string,int>::iterator it = pagehash.find(linkurl);
            if(it != pagehash.end()){
                pagelist[it->second].score += (double)pagelist[i].basic / pagelist[i].link; //index
            }
        }
    }
    
    sort(pagelist.begin(),pagelist.end(),compare);
    return pagelist.begin()->idx;
}
