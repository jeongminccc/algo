#include <string>
#include <vector>
#include <map>

using namespace std;

// data structure for put flag rules
// first thing in pair is flag argument
// second thing in pair is alias string
map<string,pair<string,string>> rules; 

// split commands line
vector<string> split(string str){
    vector<string> ret;
    string temp = "";
    
    for (int i=0; i<str.size(); ++i){
        if (str[i] == ' '){
            ret.push_back(temp);
            temp = "";
        } else{
            temp += str[i];
        }
    }
    ret.push_back(temp);

    return (ret);
}

// make Flag rules and put Map data structure
void makeFlagRules(vector<string> flag_rules){
    string flag_name = "";

    // because flag_name comes first,
    // the even index is the flag_name
    // And the odd index is the argument_type
    // if get ALIAS command, initialize each second pair to alias name
    for (int i=0; i<flag_rules.size(); ++i){
        if (!(i%2)) flag_name = flag_rules[i];
        else {
            if (flag_rules[i] == "ALIAS"){
                rules[flag_name].first = rules[flag_rules[i+1]].first;
                rules[flag_rules[i+1]].second = flag_name;
                rules[flag_name].second = flag_rules[i+1];
                break;
            }
            else
                rules[flag_name].first = flag_rules[i];
        }
    }
}

// check if input is Number
bool isNumber(string input){
    for (int i=0; i<input.size(); ++i){
        if (!('0' <= input[i] && input[i] <= '9'))
            return (false);
    }
    return (true);
}

// check if input is String
bool isString(string input){
    for (int i=0; i<input.size(); ++i){
        if (!(('a' <= input[i] && input[i] <= 'z') || ('A' <= input[i] && input[i] <= 'Z')))
            return (false);
    }
    return (true);
}

// check if valid input program name
bool checkProgram(string program, string commands){
    return (program == commands);
}

// check if valid input flag rules
// make used vector for do not use same flag (alias)
bool checkFlags(vector<string> commands){
    vector<string> used;
    string flag_name = "";
    string arg = "";
    string alias_tmp = "";
    bool is_exist_flag = false;

    // index 0 is for program name so start from index 1
    // make two more case for NUMBERS and STRINGS
    // make logic to forbidden that use same flag by alias command
    for (int i=1; i<commands.size(); ++i){

        if (commands[i][0] == '-') {
            if (is_exist_flag && rules[flag_name].first != "NULL") return (false);
            
            flag_name = commands[i];
            for (int j=0; j<used.size(); ++j){
                if (flag_name == used[j]) 
                    return (false);
            }

            if (rules[flag_name].second != ""){
                alias_tmp = rules[flag_name].second;
                used.push_back(alias_tmp);
            }
            used.push_back(flag_name);
            
            is_exist_flag = true;
        }
        else {
            arg = commands[i];
            if (rules[flag_name].first == "NULL")
                continue;
            else if (rules[flag_name].first == "NUMBER"){
                if (!isNumber(arg) || commands[i-1][0] != '-') 
                    return (false);
            }
            else if (rules[flag_name].first == "STRING"){
                if (!isString(arg) || commands[i-1][0] != '-')
                    return (false);
            }
            else if (rules[flag_name].first == "NUMBERS"){
                if (!isNumber(arg)) 
                    return (false);
            }
            else if (rules[flag_name].first == "STRINGS"){
                if (!isString(arg))
                    return (false);
            }
            else
                return (false);

            is_exist_flag = false;
        }
    }
    if (is_exist_flag && rules[flag_name].first != "NULL") return (false);
    return (true);
}

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
    vector<bool> answer;
    vector<string> splited_commands, splited_rules;
    bool tmp_ans;
    
    for (int i=0; i<flag_rules.size(); ++i){
        splited_rules = split(flag_rules[i]);
        makeFlagRules(splited_rules);
    }
    
    for (int i=0; i<commands.size(); ++i){
        tmp_ans = true;

        splited_commands = split(commands[i]);
        if (!checkProgram(program, splited_commands[0]))
            tmp_ans = false;
        if (!checkFlags(splited_commands))
            tmp_ans = false;

        answer.push_back(tmp_ans);
    }

    return answer;
}