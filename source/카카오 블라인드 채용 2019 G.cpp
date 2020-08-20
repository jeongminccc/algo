#include <bits/stdc++.h>

using namespace std;

int get_word_count(string word, string temp){
	string now = "<body>";
	int temp_num_begin = temp.find(now)+6;
	now = "</body>";
	int temp_num_end = temp.find(now)-1;
	string find_word = string(temp.begin()+temp_num_begin, temp.begin()+temp_num_end);
	
	for(int i=0; i<find_word.size(); i++){
		find_word[i] = tolower(find_word[i]);
	}
	for(int i=0; i<word.size(); i++){
		word[i] = tolower(word[i]);
	}
	int ret=0;
	temp_num_begin=0;
	while(1){
		if(find_word.find(word, temp_num_begin) == string::npos)
			break;
		else{
			temp_num_begin = find_word.find(word) + word.size();
			ret++;
		}
	}
	return ret;
}

string get_link(string str){
	string now = "<meta property=\"og:url\" content=\"";
	int temp_num_begin = str.find(now) + 33;
	string end = "\"/>";
	int temp_num_end = str.find(now, temp_num_begin) -1;
	string link = string(str.begin()+temp_num_begin, str.begin()+temp_num_end);
	
	return link;
}

bool compare(pair<double,int> &a, pair<double,int> &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
int solution(string word, vector<string> pages) {
    vector<vector<string>> link;
    double point_basic[20]={0}, point_link[20]={0}, point_ans[20]={0};
	vector<pair<double,int>> answer;
	string now = "<a href=\"";
	string end = "\"></a>";
	int temp_num_begin =0;
	
	for(int i=0; i<pages.size(); i++){
		link[i].push_back(get_link(pages[i]));
		point_basic[i] = get_word_count(word, pages[i]); 
	
		while(pages[i].find(now, temp_num_begin) != string::npos){
			temp_num_begin = pages[i].find(now) + 17;
			int temp_num_end = pages[i].find(now, temp_num_begin) -1;
			link[i].push_back(string(pages[i].begin()+temp_num_begin, pages[i].begin()+temp_num_end));
			point_link[i] += 1;
		}
	}
	
	for(int i=0; i<pages.size(); i++){
		for(int j=0; j<pages.size(); j++){
			for(int k=0; k<link[j].size(); k++){
				if(link[i][0] == link[j][k]){
					point_basic[i] += point_basic[j] / point_link[j];
					break;
 				}
			}
		}
		answer.push_back( {point_basic[i],i} );
	}
	
	sort(answer.begin(), answer.end(), compare);
	
    
	return answer[0].second;
    
}
