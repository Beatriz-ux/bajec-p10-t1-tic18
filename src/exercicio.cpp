#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<string> nomes;
    vector<float> nota1, nota2;
    int qtdeAlunos;

    cout << "Entre com a quantidade max de alunos: ";
    cin >> qtdeAlunos;

    nomes.resize(qtdeAlunos);
    nota1.resize(qtdeAlunos);
    nota2.resize(qtdeAlunos);

    for(int i = 0; i < qtdeAlunos; i++){
        cout << "Nome do aluno: ";
        cin >> nomes[i];

        cout << "Nota 1: ";
        cin >> nota1[i];

        cout << "Nota 2: ";
        cin >> nota2[i];

        cout << endl;
    }

    return 0;
}