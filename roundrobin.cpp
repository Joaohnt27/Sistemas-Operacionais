#include <iostream>
using namespace std;

// Definindo constantes
const int MAX_PROCESSOS = 10;
const int QUANTUM = 2;

// Definindo estrutura para representar um processo
struct Processo {
    int id; // Identificador do processo
    int tempo_execucao; // Tempo de execução restante do processo
    int tempo_chegada; // Tempo de chegada do processo
    int turnaround_time; // Tempo de retorno do processo
    int waiting_time; // Tempo de espera do processo
};

// Função que implementa o algoritmo Round Robin
void RoundRobin(Processo processos[], int n) {
    int tempo_total = 0; // Variável para armazenar o tempo total de execução
    int i, count;

    cout << "Execucao usando o algoritmo Round Robin:" << endl << endl;

    // Loop principal que executa até todos os processos serem concluídos
    do {
        count = 0; // Inicializa o contador de processos concluídos

        // Itera sobre todos os processos
        for (i = 0; i < n; i++) {
            // Verifica se o processo ainda tem tempo de execução restante
            if (processos[i].tempo_execucao > 0) {
                cout << "Executando processo " << processos[i].id << " por " << QUANTUM << " unidades de tempo." << endl;
                tempo_total += QUANTUM;
                processos[i].tempo_execucao -= QUANTUM;

                // Garante que o tempo de execução não seja negativo
                if (processos[i].tempo_execucao < 0) {
                    processos[i].tempo_execucao = 0;
                }
            } else {
                // Se o processo já foi concluído, incrementa o contador
                count++;
            }
        }
    } while (count < n); // Repete o loop até todos os processos serem concluídos
    cout << "" << endl;
    cout << "--> Tempo total de execucao: " << tempo_total << " unidades de tempo." << endl;
    
    // Calculando o tempo médio de retorno e o tempo médio de espera
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    
    for (int i = 0; i < n; i++) {
        processos[i].turnaround_time = tempo_total - processos[i].tempo_chegada;
        processos[i].waiting_time = processos[i].turnaround_time - processos[i].tempo_execucao;
        total_turnaround_time += processos[i].turnaround_time;
        total_waiting_time += processos[i].waiting_time;
    }
    
    float tempo_medio_retorno = static_cast<float>(total_turnaround_time) / n;
    float tempo_medio_espera = static_cast<float>(total_waiting_time) / n;
        cout << "" << endl;

    cout << "Tempo medio de retorno: " << tempo_medio_retorno << " unidades de tempo." << endl;
    cout << "Tempo medio de espera: " << tempo_medio_espera << " unidades de tempo." << endl;
}

// Função principal
int main() {
    // Criação de um array de processos com tempos de execução iniciais
    Processo processos[MAX_PROCESSOS] = {
    {1, 0, 3}, // Processo de curta duração
    {2, 1, 8}, // Processo de longa duração
    {3, 2, 4}, // Processo
    {4, 0, 6}, // Processo com operações de I/O
    {5, 1, 4}, // Processo sem operações de I/O
    {6, 2, 6}, // Processo I/O-Bound (mais tempo de execução devido a operações de I/O)
    {7, 3, 5}, // Processo I/O-Bound (mais tempo de execução devido a operações de I/O)
    {8, 0, 8}, // Processo CPU-Bound
    {9, 1, 4}, // Processo CPU-Bound
    {10, 4, 10} // Processo CPU-Bound
    };

    // Chama a função que implementa o algoritmo Round Robin
    RoundRobin(processos, MAX_PROCESSOS);

    return 0;
}
