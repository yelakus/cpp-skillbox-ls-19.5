#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> usedQuestions;

void readAndOutputQuestion(const int &numOfSector){
    std::ifstream questionFile;
    std::string numOfSectorStr = std::to_string(numOfSector);
    if(numOfSectorStr == "0") numOfSectorStr = "13";

    questionFile.open(".\\question" + numOfSectorStr + ".txt");

        while(!questionFile.eof()){
            std::string word;
            questionFile >> word;
            std::cout << word << " ";
    }
    std::cout << std::endl;
    questionFile.close();
}

bool isUserAnswerCorrect(const std::string &userAnswer2, const int &numOfSector){
    std::ifstream answerFile;
    std::string answer;

    std::string numOfSectorStr = std::to_string(numOfSector);
    if(numOfSectorStr == "0") numOfSectorStr = "13";

    answerFile.open(".\\answer" + numOfSectorStr + ".txt");
    answerFile >> answer;
    //std::cout << "здесь был";
    answerFile.close();

    if (answer == userAnswer2) return true;
    return false;
}

bool check_number(std::string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}

bool isItUsedQuestions(int num){
    for (int i = 0; i < usedQuestions.size(); ++i){
        if (usedQuestions[i] == num) return true;
    }
    return false;
}

void changeNumOfSector(int &numOfSector){
    std::string numOffset;

    bool isInputCorrect = true;
    while (isInputCorrect) {
        std::cout << "Now you'r in sector #" << numOfSector <<". Input offset(1-13):" << std::endl;
        std::cin >> numOffset;
        if (check_number(numOffset) && (stoi(numOffset) > 0) && (stoi(numOffset) <= 13)) isInputCorrect = false;
    }

    numOfSector += stoi(numOffset);

    numOfSector %= 13;

    while (isItUsedQuestions(numOfSector)) ++numOfSector;
    usedQuestions.push_back(numOfSector);
}

int main(){
    int userScore = 0, viewersScore = 0;
    std::string usersAnswer;

    int numOfSector = 1;

    while(userScore < 6 && viewersScore < 6){
        changeNumOfSector(numOfSector);
        readAndOutputQuestion(numOfSector);

        std::cout << "Your asnwer:\n";
        std::cin >> usersAnswer;

        if (isUserAnswerCorrect(usersAnswer, numOfSector)) {
            ++userScore;
            std::cout << "Right!\n";
            }
        else {
            ++viewersScore;
            std::cout << "Wrong!!\n";
        }

        std::cout << "userScore " << userScore <<" viewersScore " << viewersScore << std::endl;
    }

    if(userScore > viewersScore) std::cout << "Player wins!\n";
    else std::cout << "Viewers wins!\n";

}