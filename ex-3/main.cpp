#include <iostream>
#include <fstream>
#include <vector>

int main(){ 

    std::vector<std::vector<std::string>> dataBaseVec;
    std::ifstream dataBaseStream;
    int maxBill = 0, allSum = 0;
    std::string maxBillName;

    dataBaseStream.open(".\\dataBase.txt");

    while(!dataBaseStream.eof()){
        std::vector<std::string> personInformation;

        for(int i = 0; i < 4; ++i){
            std::string information;
            dataBaseStream >> information;
            personInformation.push_back(information);
        }

        allSum += std::stoi(personInformation[2]);

        if(std::stoi(personInformation[2]) > maxBill){
            maxBill = std::stoi(personInformation[2]);
            maxBillName = personInformation[0] + " " + personInformation[1];
        }

        dataBaseVec.push_back(personInformation);
    }

    dataBaseStream.close();

    std::cout << allSum << " - total. Maximum payout - " << maxBillName << "\n";
    std::cout << " - - - - - - - - - - - - - - - - - - \n";

    for(int i = 0; i < dataBaseVec.size(); ++i){
        for(int j = 0; j < dataBaseVec[i].size(); ++j){
            std::cout << dataBaseVec[i][j] << " ";
        }
        std::cout << "\n";
    }

}