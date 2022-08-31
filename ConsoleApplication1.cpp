// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>

int subStrRepeatsNum(std::string subStr, std::string txt)      // возвращает количество вхождений подстроки в строке
{
    int M = subStr.size();
    int N = txt.size();
    int i = 0;
    int count = 0;

    while (i <= N - M)
    {
        int j;

        for (j = 0; j < M; j++)
            if (txt[i + j] != subStr[j])
                break;

        if (j == M)
        {
            //cout << "Pattern found at index " << i << " M = " << M << endl;
            i = i + M;
            count++;
        }
        else if (j == 0)
            i = i + 1;
        else
            i = i + j;
    }

    return count;
}

void IsKPeriodic(std::string str, int k)
{
    int N = str.size();

    std::string subStr;
    int repeatsNum = 0;
    // идем по индексу, соответствующему номеру символа в строке, начиная с i = 1, так как насинтересуют подстроки минимальной длины 1
    for (int i = 1; i <= N; i++)
    {
        // выделяем подстроку длины i, начиная с начала строки
        subStr = str.substr(0, i);

        // если длина подстроки совпадает с входным параметром k
        if (k == subStr.size())
        {
            // вычисляем количество вхождений подстроки
            repeatsNum = subStrRepeatsNum(subStr, str);

            // если количество вхождений подстроки ненулевое и подстрока кратно заполняет строку, то исходная строка кратна числу K
            if (repeatsNum > 0 && repeatsNum * subStr.size() == N)
            {
                std::cout << "The string '" << str << "' is periodic with base k = " << k << std::endl;
                return;
            }
        }
    }

    std::cout << "The string '" << str << "' is NOT a periodic with base k = " << k << std::endl;
}

int main()
{
    std::string str = "abcabcabcabc";
    IsKPeriodic(str, 3);

    std::string str1 = "aaaaaaaa";
    IsKPeriodic(str1, 4);

    std::string str2 = "abcde";
    IsKPeriodic(str2, 5);

    std::string str3 = "bbb";
    IsKPeriodic(str3, 1);

    std::string str4 = "abcd";
    IsKPeriodic(str4, 2);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
