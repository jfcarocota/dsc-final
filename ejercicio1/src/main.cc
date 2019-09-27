#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include<sstream>
#include <numeric>

std::string data;
std::ifstream in("ejercicio1/src/express.in");
std::ifstream out("ejercicio1/src/express.out");

SolveSpression(std::string &data)
{
    int balanceParentheses = 0;
    int balanceBrackets = 0;

    if(data[0] != '(' && data[0] != '{')
    {
        std::cout << "\nCadena no valida" << std::endl;
    }

    for(int i = 0; i < data.size(); i++)
    {
        char current = data[i];
        char next = data[i + 1];
        char back = data[i - 1];

        switch (current)
        {
        case '(':
            balanceParentheses++;
            break;
        case ')':
            balanceParentheses--;
            break;
        case '{':
        if(current == '{' && next == '}')
            {
                //std::cout << "\n" << data.erase(i, i + 1) << std::endl;
                SolveSpression(data.erase(i, i + 1));
                break;
            }
            balanceBrackets++;
            break;
        case '}':
            balanceBrackets--;
            break;
        case '+':
            if(i == data.size() - 1)
            {
                data.pop_back();
                SolveSpression(data);
                break;
            }
            if(next == '{' && back == '}')
            {
                data[i] = ' ';
                data[i + 1] = ' ';
                data[i - 1] = ' ';

                int startAt = 0;
                int whiteSpaces = 0;

                for(int j = i; j > 0; j--)
                {
                    if(data[j] == '{')
                    {   
                        startAt = j + 1;
                        break;
                    }
                }

                for(int j = startAt; j < data.size(); j++)
                {
                    if(data[j] == '}')
                    {
                        break;
                    }
                    if(data[j] != ',')
                    {
                        for(int k = startAt; k < data.size(); k++)
                        {
                            if(data[j] == data[k] && j != k)
                            {
                                data[k] = ' ';
                            }
                        }
                    }
                }

                data.erase(remove(data.begin(), data.end(), ' '), data.end());

                std::cout << "\nwhiteSpaces: " << whiteSpaces << std::endl;
                SolveSpression(data);
                //std::cout << "\nsuma" << std::endl;
            }
            break;
        case '*':
            if(next == '{' && back == '}')
            {
                std::string a;
                std::string b;

                std::cout << "\nMul" << std::endl;
            }
            break;
        default:
            break;
        }
    }

     if(balanceParentheses != 0 || balanceBrackets != 0)
     {
         std::cout << "\nCadena no valida" << std::endl;
     }
}

int main()
{
    if(in.is_open())
    {
        std::getline(in, data);
        std::cout << "Expresion: " << data << std::endl;
        SolveSpression(data);
        std::cout << "\nResultado: " << data << std::endl;

    } 
    else
    {
         std::cout << "Unable to open file";
    }
    in.close();
    std::getchar();
    return 0;
}