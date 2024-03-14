#include <iostream>
#include <fstream>

int main(){ 
    
    std::ifstream words;
    std::string searchWord, actualCompareWord;
    int res = 0;

    std::cout << "Input a search word\n";
    std::cin >> searchWord;

    words.open(".\\words.txt");

    while(!words.eof()){
        words >> actualCompareWord;
        if (searchWord == actualCompareWord) ++res;
    }

    words.close();

    std::cout << res << " times\n";

}