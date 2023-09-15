#include <iostream>
#include <vector>
#include <string>

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

    for (int i = 0; i < qtdeAlunos; i++){
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


    do
    {
        cout << "\n(1) Deseja excluir algum aluno.\n";
        cout << "(2) Deseja incluir algum aluno.\n";
        cout << "(0) Sair.\n";
        cout << "Escolha uma das opcoes acima: ";
        cin >> opcao;

        int inf = 0;
        int sup = nomes.size() - 1;
        int meio;

        if (opcao == 1){
            cout << "Nome do aluno: ";
            cin >> auxNome;

            // busca binaria
            while (inf <= sup){
                meio = inf + ((sup - inf)/2);
                if (auxNome == nomes[meio]){
                    inf = meio;
                    break;
                }
                else if(auxNome < nomes[meio])
                    sup = meio - 1;
                else
                    inf = meio + 1;
            }

            if(auxNome == nomes[inf]){
                nomes.erase(nomes.begin()+inf);
                nota1.erase(nota1.begin()+inf);
                nota2.erase(nota2.begin()+inf);
            }else{
                cout << "\n\nNome nao encontrado.\n\n";
            }
        }
        else if (opcao == 2){
            if (nomes.size() < qtdeAlunos){
                cout << "Nome do aluno: ";
                cin >> auxNome;
                cout << "Nota 1: ";
                cin >> auxNota1;
                cout << "Nota 2: ";
                cin >> auxNota2;

                // busca binaria
                while (inf <= sup){
                    meio = inf + ((sup - inf)/2);
                    if (auxNome == nomes[meio]){ // retorno seria meio + 1
                        cout << "\n\nNome ja existe.\n\n";
                        sup = -1; // sai do while e sinaliza que nao vai ser inserido nada
                        break;
                    }
                    else if(auxNome < nomes[meio])
                        sup = meio - 1;
                    else
                        inf = meio + 1;
                }
                if(sup > 0){
                    nomes.insert(nomes.begin()+inf, auxNome);
                    nota1.insert(nota1.begin()+inf, auxNota1);
                    nota2.insert(nota2.begin()+inf, auxNota2);
                }
            }
            else{
                cout << "\n\nNao eh possivel incluir mais alunos.\n\n";
            }   
        }
    } while (opcao == 1 || opcao == 2);

    return 0;
}