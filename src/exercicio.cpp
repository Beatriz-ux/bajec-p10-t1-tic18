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
        cout << nomes[i] << endl << 
        "Nota 1: " << nota1[i] << endl << 
        "Nota 2: " << nota2[i] << endl <<
        "Media: " << med << endl <<
        (med >= 7 ? "Aprovado(a)" : "Reprovado(a)") << endl << 
        " -------------------- " << endl;
    }

    string alterar = "s";

    while(alterar == "s")
    {
        cout << "Deseja alterar alguma nota? (s/n): ";
        cin >> alterar;
        if(alterar == "s")
        {
            string aluno;
            cout << "Digite o nome do aluno: ";
            cin >> aluno;
            int index = -1;
            for(int i = 0; i < nomes.size(); i++)
                {
                    if(nomes[i] == aluno)
                    {
                        index = i;
                        i += nomes.size();
                    }
                }
            
            if(index < 0)
                {cout << "Aluno não localizado." << endl;}
            else
            {
                cout << "Nota 1: " << nota1[index] << endl << 
                "Nota 2: " << nota2[index] << endl <<
                "Media: " << (nota1[index] + nota2[index]) / 2 << endl <<
                (nota1[index] + nota2[index] / 2 >= 7 ? "Aprovado(a)" : "Reprovado(a)") << endl;
                
                string alterarN;
                
                while(alterarN != "0")
                {
                    cout << "Alterar a primeira nota (1), a segunda nota (2) ou nenhuma (0)?: ";
                    cin >> alterarN;

                    if(alterarN == "1")
                    {
                        cout << "Digite a nova nota: ";
                        cin >> nota1[index];
                    }
                    else if(alterarN == "2")
                    {
                        cout << "Digite a nova nota: ";
                        cin >> nota2[index];
                    }
                }

            }
            
        }

    }

    return 0;
}