#include <iostream>
#include <vector>

using namespace std;

// Definição da estrutura para representar um processo
struct Process {
    int id;             // Identificador do processo
    int arrivalTime;    // Tempo de chegada do processo
    int burstTime;      // Tempo de execução necessário pelo processo
    int startTime;      // Momento em que o processo começa a ser executado
    int completionTime; // Momento em que o processo é concluído
};

// Função que implementa o algoritmo First-Come, First-Served (FCFS)
void agendamentoFIFO(vector<Process>& processes) {
    int currentTime = 0;            // Tempo atual do sistema
    float totalWaitingTime = 0;     // Tempo total de espera de todos os processos
    float totalTurnaroundTime = 0;  // Tempo total de retorno de todos os processos

    // Saída inicial para indicar o uso do algoritmo FCFS
    cout << "Execucao usando o algoritmo First-Come, First-Served:" << endl << endl;
    
    // Loop para iterar sobre todos os processos
    for (Process& p : processes) {
        // Verifica se o tempo atual é menor que o tempo de chegada do processo. Se sim, atualiza o tempo atual para o tempo de chegada do processo
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }
        
        p.startTime = currentTime; // Define o tempo de início de execução do processo como o tempo atual
        
        p.completionTime = currentTime + p.burstTime; // Calcula o tempo de conclusão do processo como a soma do tempo atual e do tempo de execução necessário
        
        totalWaitingTime += currentTime - p.arrivalTime; // Calcula o tempo de espera do processo como a diferença entre o tempo atual e o tempo de chegada do processo
         
        totalTurnaroundTime += p.completionTime - p.arrivalTime; // Calcula o tempo de retorno do processo como a diferença entre o tempo de conclusão e o tempo de chegada do processo
        
        currentTime = p.completionTime; // Atualiza o tempo atual para o tempo de conclusão do processo
        
        // Saída para indicar o início e a conclusão da execução do processo
        cout << "Processo " << p.id << " executou de " << p.startTime << " ate " << p.completionTime << endl;
    }
    
    // Calcula o tempo médio de espera dividindo o tempo total de espera pelo número de processos
    float averageWaitingTime = totalWaitingTime / processes.size();
    
    // Calcula o tempo médio de retorno dividindo o tempo total de retorno pelo número de processos
    float averageTurnaroundTime = totalTurnaroundTime / processes.size();
    
    // Saída para exibir o tempo médio de espera e o tempo médio de retorno
    cout << "" << endl;
    cout << "Tempo medio de espera: " << averageWaitingTime << " unidades de tempo." << endl;
    cout << "Tempo medio de retorno: " << averageTurnaroundTime << " unidades de tempo." << endl;
}

int main() {
    vector<Process> processes;  // Vetor para armazenar os processos
    
    // Exemplo de processos com seus respectivos identificadores, tempos de chegada e tempos de execução
    processes.push_back({1, 0, 3});   // Processo de curta duração
    processes.push_back({2, 1, 8});   // Processo de longa duração
    processes.push_back({3, 2, 4});   // Processo
    processes.push_back({4, 0, 6});   // Processo com operações de I/O
    processes.push_back({5, 1, 4});   // Processo sem operações de I/O
    processes.push_back({6, 2, 6});   // Processo I/O-Bound (mais tempo de execução devido a operações de I/O)
    processes.push_back({7, 3, 5});   // Processo I/O-Bound (mais tempo de execução devido a operações de I/O)
    processes.push_back({8, 0, 8});   // Processo CPU-Bound
    processes.push_back({9, 1, 4});   // Processo CPU-Bound
    processes.push_back({10, 4, 10}); // Processo CPU-Bound
    
    // Chama a função que implementa o algoritmo FCFS passando os processos como argumento
    agendamentoFIFO(processes);
    
    return 0;
}