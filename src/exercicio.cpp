#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<string> nomes;
    vector<float> nota1, nota2;
    int qtdeAlunos;
    string auxNome;
    float auxNota1, auxNota2;

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

    for(int i=0; i<qtdeAlunos-1; i++)
    {
        for(int j=0; j<qtdeAlunos-1-i; j++)
        {
            if(nomes[j] > nomes[j+1])
            {
                auxNome = nomes[j];
                nomes[j] = nomes[j+1];
                nomes[j+1] = auxNome;

                auxNota1 = nota1[j];
                nota1[j] = nota1[j+1];
                nota1[j+1] = auxNota1;

                auxNota2 = nota2[j];
                nota2[j] = nota2[j+1];
                nota2[j+1] = auxNota2;
            }
        }
    }

    for(int i=0; i<qtdeAlunos; i++)
    {
        cout << nomes[i] << " " << nota1[i] << " " << nota2[i] << endl;
    }

    return 0;
}