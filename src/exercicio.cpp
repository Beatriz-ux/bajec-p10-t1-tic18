#include <iostream>
#include <vector>
#include <string>

#include<ctime>
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

    cout << " -------------------- " << endl;

    for(int i = 0; i < nomes.size(); i++)
    {
        float med = (nota1[i] + nota2[i]) / 2;
        cout << "Nome: " << nomes[i] << endl << 
        "Nota 1: " << nota1[i] << endl << 
        "Nota 2: " << nota2[i] << endl <<
        "Media: " << med << endl <<
        (med >= 7 ? "Aprovado(a)" : "Reprovado(a)") << endl << 
        " -------------------- " << endl << endl;
    }


    return 0;
}