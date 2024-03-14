#include <iostream>
#include <fstream>

int main(){
    char buffer[8];
    std::ifstream pngFile;
    std::string pathToFile;

    bool openCheck = false;
    while(!openCheck){
        std::cout << "-----";
        std::cout << "Input file link:\n";
        std::cin >> pathToFile;
        pngFile.open(pathToFile, std::ios::binary);
        openCheck = pngFile.is_open();
    }

    std::string LastFourSym = pathToFile.substr(pathToFile.size()-4, 4);
    std::cout << LastFourSym << "\n";


    pngFile.read(buffer, sizeof(buffer));
    buffer[7] = 0;
    std::cout << buffer << std::endl;
    std::cout << "-----here";


    if (LastFourSym == ".png" && buffer[0] == 45 && buffer[1] == 1 && buffer[2] == 1 && buffer[3] == 9 && buffer[4] == 80 && buffer[6] == 78 && buffer[6] == 71) {
        std::cout << "File is png\n";
    } else std::cout << "File is NOT png\n";


    pngFile.close();
}