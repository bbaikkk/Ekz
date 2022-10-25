#include <iostream>
#include <ctime>
#include <locale>
using namespace std;

const int N = 5;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n[N - 1];
    double mass[N][N];
    cout << "Выберите интересующие вас качества товара. 1/0" << endl;
    cout << "Время доставки: ";
    cin >> n[0];
    cout << endl << "Качество сборки: ";
    cin >> n[1];
    cout << endl << "Комплектация: ";
    cin >> n[2];
    cout << endl << "Цена: ";
    cin >> n[3];
    cout << endl;


    srand(time(NULL));
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mass[i][j] = (rand() % 11) * 0.1;
            if (n[i] == 0) {
                mass[i][j] = 0.0;
            }
        }
    }
    for (int j = 0; j < N; j++) {
        mass[N - 1][j] = 0.0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    double maxElement = 0.0;


    maxElement = mass[0][0];

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (maxElement < mass[i][j]) {
                maxElement = mass[i][j];
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (maxElement == mass[i][j]) {
                mass[N - 1][j] = mass[N - 1][j] + 0.1;
            }
        }
        maxElement = 0.0;
    }
    cout << endl;
    /*  for (int i = 0; i < N; i++)
      {
          for (int j = 0; j < N; j++)
          {
              cout << mass[i][j] << " ";
          }
          cout << endl;
      }
      cout << endl;*/
    for (int j = 0; j < N; j++)
    {
        if (maxElement < mass[N - 1][j]) {
            maxElement = mass[N - 1][j];
        }
    }
    for (int j = 0; j < N; j++)
    {
        if (maxElement == mass[N - 1][j]) {
            cout << "Лучший результат: " << j + 1 << endl;
        }
    }
    return 0;
}