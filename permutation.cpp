#include <iostream>
#include <string>
#include <algorithm>

bool isPermutation(std::string string1, std::string string2){     
    bool x;

    if (string1.length() == string2.length()) {
        std::sort(string1.begin(), string1.end());
        std::sort(string2.begin(), string2.end());
        x = true;

        for (int i = 0; i < string1.length(); i++){
            // std::cout << string1[i] << string2[ string1.length() - (i + 1) ] << std::endl;
            if (string1[i] != string2[i]){
                x = false;
                break;
            }
        }
    }
    else {
        x = false;
    }

    return x;
}

int main(){
    std::string string1 = "bacca";
    std::string string2 = "acbac";
    
    isPermutation(string1, string2) ? 
        std::cout << string1 << " and " << string2 << " are permutations " << std::endl : 
        std::cout << string1 << " and " << string2 << " are not permutations." << std::endl;

    return 0;
}