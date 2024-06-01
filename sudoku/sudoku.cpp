#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

void stroki(std::vector<std::vector<int>>& vec) {
    for (int i = 0; i < 3; i++) {
        int x = rand() % 2 + 1;
        int y = rand() % 2;
        for (int j = 0; j < 9; j++) {
            std::swap(vec[y + i * 3][j], vec[x + i * 3][j]);
        }
    }
}

void stolbci(std::vector<std::vector<int>>& vec) {
    for (int i = 0; i < 3; i++) {
        int x = rand() % 2 + 1;
        int y = rand() % 2;
        for (int j = 0; j < 9; j++) {
            std::swap(vec[j][y + i * 3], vec[j][x + i * 3]);
        }
    }
}

void kvadrati_vert(std::vector<std::vector<int>>& vec) {
    int x = rand() % 2 + 1;
    int y = rand() % 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            std::swap(vec[j][y * 3 + i], vec[j][x * 3 + i]);
        }
    }
}

void kvadrati_goriz(std::vector<std::vector<int>>& vec) {
    int x = rand() % 2 + 1;
    int y = rand() % 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            std::swap(vec[y * 3 + i][j], vec[x * 3 + i][j]);
        }
    }
}
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> transposedMatrix(matrix[0].size(), std::vector<int>(matrix.size()));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    return transposedMatrix;
}

// Остальная часть кода остается без изменений


    
int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(0));
    int n = 3;
    std::vector<std::vector<int>> table(n * n, std::vector<int>(n * n));

    for (int i = 0; i < n * n; i++) {
        for (int j = 0; j < n * n; j++) {
            table[i][j] = (((i * n + i / n + j) % (n * n)) + 1);
        }
    }
    int raz = rand() % 201 + 300;
    for (int i = 0;i < raz;i++) {//перемешиваем поле
        stroki(table);
        stolbci(table);
        kvadrati_vert(table);
        kvadrati_goriz(table);
    }
    table = transposeMatrix(table);
    int raz1 = rand() % 6 + 60;
    for (int i = 0;i < raz1;i++) {
        int x = rand() % 9;
        int y = rand() % 9;
        if (table[x][y] == -1) i--;
        table[x][y] = -1;
    }
    std::vector<std::vector<int>> table1(n * n, std::vector<int>(n * n));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            table1[i][j] = table[i][j];
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (table[i][j] == -1) {
                std::cout << " " << " "; // Выводим пробелы для пустых ячеек
            }
            else {
                std::cout << table[i][j] << " ";
            }
        }
        std::cout <<'|' << std::endl;
    }
    std::cout << "_ _ _ _ _ _ _ _ _"<<std::endl;
    std::cout << "Внесите решенный судоку:" << std::endl;
    
    //Вывод двумерного массива, нашего игрового поля
    int c = 0;
    while (c < 1) {
        std::vector<std::vector<int>> Ptable(n * n, std::vector<int>(n * n));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cin >> Ptable[i][j];
                
            }
        }
        bool a = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (Ptable[i][j] != table1[i][j]) a = false;
            }
        }
        if (a) {
            c++;
            std::cout << "Поздравляю вы сделали все правильно!";
        }
        else {
            std::cout << "Не правильно, попробуете ещё раз.";
        }
    }

}
    


