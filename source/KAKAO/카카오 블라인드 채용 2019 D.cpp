#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> food_times, long long k) {
    long long answer = 0;
    long long i=0;
    long long temp =0;
    long long temp_k = k;
    long long temp_size=food_times.size();
    
    while(temp_size>0){
        temp += food_times[i];    
        temp_size--;
        i++;
    }
    if(temp <= temp_k)
        return -1;
    
    i=0;
    while(k>0){
       if(food_times[i%food_times.size()] > 0){
            food_times[i%food_times.size()]--;
            k--;
        }
        i++;
    }
    
    while(1){
        if(food_times[i%food_times.size()] > 0){
            break;
        }
        i++;
    }
    
    answer = i%food_times.size() + 1;
    return answer;
}
