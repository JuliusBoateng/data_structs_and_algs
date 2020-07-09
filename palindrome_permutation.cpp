#include <iostream>
#include <string>
#include <unordered_map>

void palPermChecker(std::string str){
    std::unordered_map<char, int> counter;

    for (int i = 0; i < str.length(); i++){
        char letter = tolower(str[i]);

        if (str[i] == ' ') {
            continue;
        }
        else if (counter.find(letter) == counter.end() ) {
            counter[letter] = 1;
        }
        else {
            counter[letter] = counter[letter] + 1;
        }
    }

    int num_of_odd = 0;
    for (auto x : counter) {
        if ( x.second % 2 != 0 ){
            num_of_odd += 1;
        }
        // std::cout << x.first << x.second << std::endl;
    }
    if (num_of_odd > 1 || counter.size() == 0) {
        std::cout << "\"" << str << "\"" " is not a permutation of a palindrome." << std::endl;
    }
    else {
        std::cout << "\"" << str << "\"" << " is a permutation of a palindrome." << std::endl;
    }
}

int main(){
    std::string str  = "Tact Coa";
    // std::string str = "not";
    palPermChecker(str);

    return 0;
}