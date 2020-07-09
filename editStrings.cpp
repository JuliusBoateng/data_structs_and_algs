#include <iostream>
#include <string>
#include <unordered_map>

void editStringChecker(std::string str1, std::string str2){
    std::unordered_map<char, int> counter = {};

    for (int i = 0; i < str1.length(); i++){
        if (counter.find(str1[i]) == counter.end() ) {
            counter[str1[i]] = 1;
        }
        else {
            counter[str1[i]] = counter[str1[i]] + 1;
        }
    }

    for (int i = 0; i < str2.length(); i++){
        if (counter.find(str1[i]) == counter.end() ) {
            counter[str2[i]] = -1;
        }
        else {
            counter[str2[i]] = counter[str2[i]] - 1;
        }
    }
    
    int numInsert = 0;
    int numRemove = 0;
    for (auto x : counter){
        if (x.second == 0){
            continue;
        }
        else if (x.second == 1){
            numInsert += 1;
        }
        else if (x.second == -1){
            numRemove += 1;
        }
        else {
            std::cout << "\"" << str1 << "\"" << " and " << "\"" << str2 << "\"" << " are not \"one away\"."  << std::endl;
            return;
        }
        
        // std::cout << x.first << " " << x.second << std::endl;
    }
    
    if ( (numInsert == 0) && (numRemove == 0) ){
        std::cout << "\"" << str1 << "\"" << " and " << "\"" << str2 << "\"" << " are \"zero edits away\"."  << std::endl;
    }
    else if (numInsert > 1 || numRemove > 1){
        std::cout << "\"" << str1 << "\"" << " and " << "\"" << str2 << "\"" << " are NOT \"one edit away\"."  << std::endl;
    }
    else {
        std::cout << "\"" << str1 << "\"" << " and " << "\"" << str2 << "\"" << " are \"one edit away\"."  << std::endl;
    }
}

int main(){

    std::string str1 = "pa";
    std::string str2 = "pale";
    editStringChecker(str1, str2);

    return 0;
}