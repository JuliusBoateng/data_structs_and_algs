#include <string>
#include <set>
#include <iostream>

int main(){
    std::string input = "";
    std::getline(std::cin, input);
    std::set <char> prevChars;
    int spaces = 0;

    for (int index = 0; index < input.length(); index++){
        if (input[index] == ' '){
            spaces++;
            continue;
        }
        if (prevChars.find(input[index]) == prevChars.end()){
            prevChars.insert(input[index]);
        }
        else {
            std::cout << "Duplicate char \'" << input[index] << "\' found." << std::endl;
            break;
        }
    }

    if ( (prevChars.size() + spaces) == input.length()){
        std::cout << "No duplicates found." << std::endl;
    }

    return 0;
}