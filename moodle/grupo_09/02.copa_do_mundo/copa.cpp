#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Filas de times.
    queue<char> teams;

    // Inicializa fila de times.
    for (char team = 'A'; team <= 'P'; team++) {
        teams.push(team);
    }

    // Simula jogos.
    for (int i = 0; i < 15; i++) {
        // Leitura de gols.
        int goal1, goal2;
        cin >> goal1 >> goal2;

        // Remove dois times consecutivos da fila.
        char team1 = teams.front();
        teams.pop();
        char team2 = teams.front();
        teams.pop();

        // Adiciona o time vencedor na fila.
        if (goal1 > goal2) {
            teams.push(team1);
        } else {
            teams.push(team2);
        }
    }

    // Imprime o time campeão. (Time que sobrou na fila.)
    cout << teams.front() << endl;
}