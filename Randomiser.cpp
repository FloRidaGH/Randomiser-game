#include <iostream>
#include <cstdlib>  // Для генерации случайных чисел
#include <ctime>    // Для задания времени как источника случайных чисел
#include <limits>   // Для использования std::numeric_limits

using namespace std;


int generateRandomNumber() {
    return rand() % 100 + 1;  


void playGame() {
    int randomNumber = generateRandomNumber();  
    int guess;  
    int attempts = 0;  
    const int maxAttempts = 10;  
    bool gameWon = false;

    cout << "Угадайте число от 1 до 100!" << endl;

    
    while (attempts < maxAttempts && !gameWon) {
        cout << "Попытка " << (attempts + 1) << " из " << maxAttempts << ": ";
        cin >> guess;

        
        if (cin.fail() || guess < 1 || guess > 100) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Ошибка! Введите число в диапазоне от 1 до 100." << endl;
            continue;  
        }

        attempts++;

        if (guess < randomNumber) {
            cout << "Слишком маленькое число!" << endl;
        } else if (guess > randomNumber) {
            cout << "Слишком большое число!" << endl;
        } else {
            cout << "Поздравляю, вы угадали число " << randomNumber << "!" << endl;
            gameWon = true;  
        }
    }

    
    if (!gameWon) {
        cout << "Вы не угадали. Загаданное число было " << randomNumber << "." << endl;
    }

    
    char playAgain;
    cout << "Хотите сыграть снова? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();  
    } else {
        cout << "Спасибо за игру!" << endl;
    }
}

int main() {
    srand(time(0));  
    cout << "Добро пожаловать в игру Угадай число!" << endl;
    playGame();  
    return 0;
}