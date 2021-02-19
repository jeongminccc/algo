//
//  test_tosos.cpp
//  algo
//
//  Created by jm on 2020/08/01.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> s;

int main() {
    string input;
    vector<string>::iterator iter;
    do{
        cin >> input;
        bool flag = false;
        
        for(iter = s.begin(); iter != s.end(); iter++){
            if( *iter == input ){
                s.erase(iter); flag = true;
                s.push_back(input); break;
            }
        }
        
        if(s.size() == 5 && !flag) {iter = s.begin(); s.erase(iter);    s.push_back(input);}
        else if(!flag) s.push_back(input);
        
        for(iter = s.end()-1; iter != s.begin()-1; iter--){
            cout << *iter << " ";
        }cout << endl;
        
    }while(getc(stdin) == ' ');
    
    return 0;
}

#include <iostream>
#include <unistd.h>
#include <map>

using namespace std;

int compute(int n);
map<int,int> cache;

int main() {
    int temp;
    do{
        cin >> temp;
        if(cache.find(temp) == cache.end()){
            cache.insert(make_pair(temp, compute(temp)));
        } cout << cache[temp] << " ";
    }while(getc(stdin) == ' ');
    
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    int temp;
    for(int i=0; i<6; i++) {
        cin >> temp;
        if( (getc(stdin) != ' ' && i != 5) || (temp < 1 || temp > 45) ) {cout << "false" << endl; return 0;}
        v.push_back(temp);
    }
    
    vector<int> v_uni = v;
    unique(v_uni.begin(), v_uni.end());
    if( v_uni != v ){ cout << "false" << endl; return 0;}
    
    vector<int> v_sort = v;
    sort(v_sort.begin(), v_sort.end());
    if( v_sort != v ){ cout << "false" << endl; return 0;}
    
    cout << "true" << endl;
    return 0;
}
