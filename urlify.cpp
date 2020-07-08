#include <iostream>
#include <string>

int main(){
    std::string string1 = "Mr John Smith    ";
    int length = 13; 
    int shift_amt = string1.length() - 13;
    int index_of_last_char = length - 1;
    
    for ( int i = index_of_last_char; i >= 0; i-- ){
        if (string1[i] != ' ') {
            string1[i + shift_amt] = string1[i];
        }
        else {
            string1[i + shift_amt] = '0';
            string1[i + shift_amt - 1] = '2';
            string1[i + shift_amt - 2] = '%';
            shift_amt = shift_amt - 2;
        }
    }

    std::cout << string1 << std::endl;

    return 0;
}