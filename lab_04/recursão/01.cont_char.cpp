#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c)
{
    if(n == str.size()) return 0;
    return (str[n] == c) + contaCaracteres(str, n+1, c);
}

int main() 
{
   string str;
   char c;

   getline(cin, str);
   cin >> c;

   cout << contaCaracteres(str, 0, c); << endl;
}