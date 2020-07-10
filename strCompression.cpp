#include <iostream>
#include <string>

void strCompressor(std::string str){
    str += '*';
    char temp = ' ';
    int count = 0;
    std::string result = "";

    for (int i = 0; i < str.length(); i++){
        if (i == 0){
            temp = str[i];
            count = 1;
            continue;
        }

        if (str[i] == temp){
            count += 1;
        }
        else{
            result += temp + std::to_string(count);
            count = 1;
            temp = str[i];;
        }
    }
    std::cout << result << std::endl;
}

int main(int argc, char** argv){
    
    strCompressor(argv[1]);

    return 0;
}