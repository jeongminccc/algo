#include <string>
#include <vector>
#include <map>

using namespace std;

// data structure for put flag rules
map<string,string> rules; 

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
    for (int i=0; i<flag_rules.size(); ++i){
        if (!(i%2)) flag_name = flag_rules[i];
        else 
            rules[flag_name] = flag_rules[i];
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
bool checkFlags(vector<string> commands){
    string flag_name = "", arg = "";
    bool is_exist_flag = false;

    // index 0 is for program name so start from index 1
    for (int i=1; i<commands.size(); ++i){
        if (!is_exist_flag) {
            flag_name = commands[i];
            is_exist_flag = true;
        }
        else {
            arg = commands[i];
            if (rules[flag_name] == "NULL")
                continue;
            else if (rules[flag_name] == "NUMBER"){
                if (!isNumber(arg)) 
                    return (false);
            }
            else if (rules[flag_name] == "STRING"){
                if (!isString(arg))
                    return (false);
            }
            else
                return (false);

            is_exist_flag = false;
        }
    }
    if (is_exist_flag && rules[flag_name] != "NULL") return (false);
    return (true);
}

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
    vector<bool> answer;
    vector<string> splited_commands, splited_rules;
    bool tmp_ans;

    for (int j=0; j<flag_rules.size(); ++j){
        splited_rules = split(flag_rules[j]);
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