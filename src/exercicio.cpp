#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> nomes;
    vector<float> nota1, nota2;
    int qtdeAlunos, opcao = 0;
    string auxNome;
    float auxNota1, auxNota2;

    cout << "Entre com a quantidade max de alunos: ";
    cin >> qtdeAlunos;

    nomes.resize(qtdeAlunos);
    nota1.resize(qtdeAlunos);
    nota2.resize(qtdeAlunos);

    for (int i = 0; i < qtdeAlunos; i++)
    {
        cout << "Nome do aluno: ";
        cin >> nomes[i];

        cout << "Nota 1: ";
        cin >> nota1[i];

        cout << "Nota 2: ";
        cin >> nota2[i];

        cout << endl;
    }

    for (int i = 0; i < qtdeAlunos - 1; i++)
    {
        for (int j = 0; j < qtdeAlunos - 1 - i; j++)
        {
            if (nomes[j] > nomes[j + 1])
            {
                auxNome = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = auxNome;

                auxNota1 = nota1[j];
                nota1[j] = nota1[j + 1];
                nota1[j + 1] = auxNota1;

                auxNota2 = nota2[j];
                nota2[j] = nota2[j + 1];
                nota2[j + 1] = auxNota2;
            }
        }
    }


    for(int i=0; i<qtdeAlunos; i++)
    {
        cout << nomes[i] << endl;
    }

    do
    {
        cout << "\n(1) Deseja excluir algum aluno.\n";
        cout << "(2) Deseja incluir algum aluno.\n";
        cout << "(0) Sair.\n";
        cout << "Escolha uma das opcoes acima: ";
        cin >> opcao;

        if (opcao == 1)
        {
        }
        else if (opcao == 2)
        {
            //if (size(nomes) < qtdeAlunos){
                cout << "Nome do aluno: ";
                cin >> auxNome;

                cout << "Nota 1: ";
                cin >> auxNota1;

                cout << "Nota 2: ";
                cin >> auxNota2;

                int inf = 0;
                int sup = nomes.size() - 1;
                int meio;
                vector<string>::iterator itNome = nomes.begin();
                while (sup-inf >= 1)
                {
                    meio = (inf + sup) / 2;
                    advance(itNome, meio);
                    if (auxNome == *itNome)
                        cout << "Nome ja existe.\n";
                    if (auxNome < *itNome)
                    {
                        cout << "1inf: " << inf << " meio: " << meio << " sup: " << sup <<  endl;
                        itNome = nomes.begin() + inf;
                        sup = meio - 1;
                    }
                    else
                    {
                        cout << "2inf: " << inf << " meio: " << meio << " sup: " << sup <<  endl;
                        inf = meio + 1;
                        itNome = nomes.begin();
                        advance(itNome, inf);
                        cout << ".aqui";
                    }
                }

                cout << endl << inf << endl;
                nota1.push_back(auxNota1);
                nota2.push_back(auxNota2);
            //}
            /*else{
                cout << "Nao e possivel incluir mais alunos.\n";
            }
            */
        }

    } while (opcao == 1 || opcao == 2);

    return 0;
}