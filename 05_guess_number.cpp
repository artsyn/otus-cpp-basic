#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>

// поулчаем случайные числа в диапазоне от min до max
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);  
    // распределяем случайные числа
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// функция для игры
int playGame()
{
    int guessCount = 0;
    int guess;
    int randomNumber = getRandomNumber(1, 100);

    std::cout << "Guess the number from 1 to 100\n";

    while (true)
    {
        std::cout << "Enter your number: ";
        std::cin >> guess;
        guessCount++;

        if (guess == randomNumber)
        {
            std::cout << "you guessed right on the " << guessCount << " try!\n";
            break;
        }
        else if (guess < randomNumber)
        {
            std::cout << "It's more than you think.\n";
        }
        else
        {
            std::cout << "It's less them you think.\n";
        }
    }

    return guessCount;
}

// структура для хранения информации о рекорде
struct HighScore
{
    std::string name;
    int score;
};

// функция для отображения рекордов
void showHighScores(const std::vector<HighScore>& scores)
{
    std::cout << "Records:\n";
    std::cout << "Name\t\tScore\n";
    for (const auto& score : scores)
    {
        std::cout << score.name << "\t\t" << score.score << std::endl;
    }
}

// функция для сохранения рекорда
void saveHighScore(std::vector<HighScore>& scores, const HighScore& newScore)
{
    scores.push_back(newScore);
    std::sort(scores.begin(), scores.end(), [](const HighScore& a, const HighScore& b) {
        return a.score < b.score;
    });
}

int main()
{
    SetConsoleCP(1251); // попытки пофиксить краказябры (не вышло почему-то, пришлось на английском писать)
    SetConsoleOutputCP(1251); // попытки пофиксить краказябры (не вышло почему-то, пришлось на английском писать)
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::vector<HighScore> highScores;

    char choice;
    do
    {
        int guessCount = playGame();

        HighScore newScore;
        std::cout << "Enter your name: ";
        std::cin >> newScore.name;
        newScore.score = 100 - (guessCount - 1);
        saveHighScore(highScores, newScore);

        showHighScores
        (highScores);

        std::cout << "Wanna play more? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y');

    std::cout << "Thanks for the game!\n";
    return 0;
}