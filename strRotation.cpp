#include <iostream>
#include <set>

bool isSubstring(std::string completestr, std::string substr){
    int len_matched = 0;
    int j = 0;

    for (int i = 0; i < completestr.length(); i++){
        while (j < substr.length()){
            if (substr[j] == completestr[i]){
                j += 1;
                len_matched += 1;
                if (len_matched == substr.length()){
                    return true;
                } 
            }
            else {
                j = 0;
                len_matched = 0;
            }
            break;
        }
    }

    return false;
}

bool strRotation(std::string str1, std::string str2){
    int i = 0;
    int j = 0;
    std::set <int> skip = {};
    std::string cmp_str1 = "";
    std::string cmp_str2 = "";

    if (str1.length() != str2.length()){
        return false;
    }

    for (int x = 0; x <= 1; x++){
        while (j < str2.length()){
            if (str2[j] != str1[i]){
                j += 1;
            }
            else {
                break;
            }
        }

        while (j < str2.length()){
            if (str2[j] == str1[i]){
                skip.insert(j);
                j += 1;
                i += 1;
            }
            else {
                j = 0;
                break;
            }
        }
    }

    for (int k = i; k < str1.length();k++){
        cmp_str1 += str1[k];
    }

    for (int l = 0; l < str2.length(); l++){
        if (skip.find(l) != skip.end()){
            continue;
        }
        else {
            cmp_str2 += str2[l];
        }
    }

    return isSubstring(cmp_str1,cmp_str2);
}

int main(){
    strRotation("waterbottle", "watboerttle") ? std::cout << "S2 is a rotation" << std::endl : std::cout << "S2 is NOT a rotation" << std::endl;

    return 0;
}