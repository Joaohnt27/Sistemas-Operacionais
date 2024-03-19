#include <iostream>
#include <vector>
#include <algorithm> // Biblioteca para funções de análise e manipulação de dados 

using namespace std;

// Definição da estrutura para representar um processo
struct Processo {
    int id;                // Identificador do processo
    int tempo_chegada;     // Tempo de chegada do processo
    int tempo_execucao;    // Tempo de execução do processo
    int tempo_espera;      // Tempo de espera do processo
    int tempo_retorno;     // Tempo de retorno do processo
};

// Função de comparação para ordenar os processos pelo tempo de execução
bool comparar_tempo_execucao(const Processo &a, const Processo &b) {
    return a.tempo_execucao < b.tempo_execucao;
}

// Função que implementa o escalonamento Shortest Process Next (SPN)
void escalonamento_SPN(vector<Processo>& processos) {
    int tempo_total = 0; // Variável para armazenar o tempo total de execução

    cout << "Execucao usando o algoritmo Shortest Process Next (SPN):" << endl << endl;

    // Ordena os processos pelo tempo de execução
    sort(processos.begin(), processos.end(), comparar_tempo_execucao);

    // Loop que executa para cada processo na ordem ordenada
    for (auto& processo : processos) {
        cout << "Executando processo " << processo.id << " por " << processo.tempo_execucao << " unidades de tempo." << endl;
        
        // Calcula o tempo de espera do processo
        processo.tempo_espera = tempo_total - processo.tempo_chegada;
        if (processo.tempo_espera < 0) {
            processo.tempo_espera = 0; // Garante que o tempo de espera não seja negativo
        }
        
        // Calcula o tempo de retorno do processo
        processo.tempo_retorno = processo.tempo_espera + processo.tempo_execucao;

        tempo_total += processo.tempo_execucao; // Atualiza o tempo total de execução
    }
    cout << "" << endl;
    cout << "--> Tempo total de execucao: " << tempo_total << " unidades de tempo." << endl;

    // Calcula o tempo médio de espera e o tempo médio de retorno
    float tempo_medio_espera = 0;
    float tempo_medio_retorno = 0;
    for (const auto& processo : processos) {
        tempo_medio_espera += processo.tempo_espera;
        tempo_medio_retorno += processo.tempo_retorno;
    }
    tempo_medio_espera /= processos.size();
    tempo_medio_retorno /= processos.size();
    
    cout << "" << endl;
    cout << "Tempo medio de espera: " << tempo_medio_espera << " unidades de tempo." << endl;
    cout << "Tempo medio de retorno: " << tempo_medio_retorno << " unidades de tempo." << endl;
}

int main() {
    // Criação de um vetor de processos com tempos de execução iniciais
    vector<Processo> processos = {
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

    // Chama a função que implementa o escalonamento SPN
    escalonamento_SPN(processos);

    return 0;
}
