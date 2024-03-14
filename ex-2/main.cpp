#include <iostream>
#include <fstream>

int main(){
    char buffer[200];
    std::ifstream textFile;
    std::string link, continueV;

    bool openCheck = false;
    while(!openCheck){
        std::cout << "Input file link:\n";
        std::cin >> link;
        textFile.open(link, std::ios::binary);
        openCheck = textFile.is_open();
    }
    
    while(!textFile.eof()){
        textFile.read(buffer, sizeof(buffer));
        buffer[199] = 0;
        std::cout << buffer << std::endl;
        std::cout << "**type smth to continue...**";
        std::cin >> continueV;
        std::cout << "----------------------------\n";

    }

    textFile.close();
    
}