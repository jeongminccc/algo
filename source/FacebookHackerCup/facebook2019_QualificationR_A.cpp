//
//  facebook2019_QualificationR_A.cpp
//  algo
//
//  Created by jm on 2020/07/24.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, k=0;
    string leapfrog;
    ifstream readFile;
    ofstream writeFile;
    readFile.open("test.txt");
    writeFile.open("output.txt");
    
    string n;
    getline(readFile, n);
    t = atoi(n.c_str());
    while(t--){
        leapfrog.clear();
        
        getline(readFile, leapfrog);
        string ans = "";
        k++;
        if(leapfrog.find('.') == string::npos) { ans += "Case #" + to_string(k) + ": N\n"; writeFile.write(ans.c_str(), ans.size()); continue;}
        
        int b = 0, dot =0;
        for(int i=0; i<leapfrog.size(); i++){
            if(leapfrog[i] == 'B') b++;
            else if(leapfrog[i] == '.') dot++;
        }
        
        if(dot > b) ans = "Case #" + to_string(k) + ": N\n";
        else ans = "Case #" + to_string(k) + ": Y\n";
        writeFile.write(ans.c_str(), ans.size());
    }
    
    readFile.close();
    writeFile.close();
    
    return 0;
}
