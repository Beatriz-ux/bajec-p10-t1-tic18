#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int i;
    string nome;
    float nota1, nota2;
    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    cout << "Digite o limite de alunos: ";
    cin >> N;

    for(i=0; i<N; i++)
    {
        cout << "Digite o nome do aluno " << i+1 << ": ";
        cin >> nome;
        nomes.push_back(nome);
        cout << "Digite a primeira nota do aluno " << i+1 << ": ";
        cin >> nota1;
        notas1.push_back(nota1);
        cout << "Digite a segunda nota do aluno " << i+1 << ": ";
        cin >> nota2;
        notas2.push_back(nota2);
    }

    int j;
    string auxNome;
    float auxNota1, auxNota2;

    for(i=0; i<N-1; i++)
    {
        for(j=0; j<N-1-i; j++)
        {
            if(nomes[j] > nomes[j+1])
            {
                auxNome = nomes[j];
                nomes[j] = nomes[j+1];
                nomes[j+1] = auxNome;

                auxNota1 = notas1[j];
                notas1[j] = notas1[j+1];
                notas1[j+1] = auxNota1;

                auxNota2 = notas2[j];
                notas2[j] = notas2[j+1];
                notas2[j+1] = auxNota2;
            }
        }
    }

    return 0;
}