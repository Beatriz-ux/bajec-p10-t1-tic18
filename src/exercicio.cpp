#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;
    string auxNome;
    float auxNota1, auxNota2;

    int qtdeAlunos;
    cout << "Digite a quantidade de alunos: ";
    cin >> qtdeAlunos;
    cin.ignore();

    for (int i = 0; i < qtdeAlunos; i++)
    {
        string nome;
        float nota1, nota2;
        cout << "Digite o nome do aluno [" << i + 1 << "]: ";
        getline(cin, nome);
        do
        {
            cout << "Digite a primeira nota: ";
            cin >> nota1;
            if (nota1 < 0 || nota1 > 10)
            {
                cout << "Nota invalida!" << endl;
            }
        } while (nota1 < 0 || nota1 > 10);
        do
        {
            cout << "Digite a segunda nota: ";
            cin >> nota2;
            if (nota2 < 0 || nota1 > 10)
            {
                cout << "Nota invalida!" << endl;
            }
        } while (nota2 < 0 || nota1 > 10);

        cin.ignore();
        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);
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

                auxNota1 = notas1[j];
                notas1[j] = notas1[j + 1];
                notas1[j + 1] = auxNota1;

                auxNota2 = notas2[j];
                notas2[j] = notas2[j + 1];
                notas2[j + 1] = auxNota2;
            }
        }
    }
    int opcao;
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

        if (opcao == 1)
        {
            cout << "Nome do aluno: ";
            cin.ignore();
            getline(cin, auxNome);

            // busca binaria
            while (inf <= sup)
            {
                meio = inf + ((sup - inf) / 2);
                if (auxNome == nomes[meio])
                {
                    inf = meio;
                    break;
                }
                else if (auxNome < nomes[meio])
                    sup = meio - 1;
                else
                    inf = meio + 1;
            }

            if (auxNome == nomes[inf])
            {
                nomes.erase(nomes.begin() + inf);
                notas1.erase(notas1.begin() + inf);
                notas2.erase(notas2.begin() + inf);
            }
            else
            {
                cout << "\n\nNome nao encontrado.\n\n";
            }
        }
        else if (opcao == 2)
        {
            cin.ignore();
            if (nomes.size() < qtdeAlunos)
            {
                cout << "Nome do aluno: ";
                getline(cin, auxNome);
                cout << "Nota 1: ";
                cin >> auxNota1;
                cout << "Nota 2: ";
                cin >> auxNota2;
                if (nomes.size() == 0)
                {
                    nomes.push_back(auxNome);
                    notas1.push_back(auxNota1);
                    notas2.push_back(auxNota2);
                }
                else
                {

                    // busca binaria
                    while (inf <= sup)
                    {
                        meio = inf + ((sup - inf) / 2);
                        if (auxNome == nomes[meio])
                        { // retorno seria meio + 1
                            cout << "\n\nNome ja existe.\n\n";
                            sup = -1; // sai do while e sinaliza que nao vai ser inserido nada
                            break;
                        }
                        else if (auxNome < nomes[meio])
                        {

                            sup = meio - 1;
                        }
                        else
                            inf = meio + 1;
                    }
                    if (sup >= 0 || sup == -1)
                    {
                        nomes.insert(nomes.begin() + inf, auxNome);
                        notas1.insert(notas1.begin() + inf, auxNota1);
                        notas2.insert(notas2.begin() + inf, auxNota2);
                    }
                }
            }
            else
            {
                cout << "\n\nNao eh possivel incluir mais alunos.\n\n";
            }
        }
    } while (opcao == 1 || opcao == 2);

    // mostrar nomes
    cout << "\n\n";
    for (int i = 0; i < nomes.size(); i++)
    {
        cout << nomes[i] << endl;
    }
    cout << " -------------------- " << endl;

    for (int i = 0; i < nomes.size(); i++)
    {
        float med = (notas1[i] + notas2[i]) / 2;
        cout << "Nome: " << nomes[i] << endl
             << "Nota 1: " << notas1[i] << endl
             << "Nota 2: " << notas2[i] << endl
             << "Media: " << med << endl
             << (med >= 7 ? "Aprovado(a)" : "Reprovado(a)") << endl
             << " -------------------- " << endl;
    }

    string alterar = "s";

    while (alterar == "s")
    {
        cout << "Deseja alterar alguma nota? (s/n): ";
        cin >> alterar;
        if (alterar == "s")
        {
            string aluno;
            cout << "Digite o nome do aluno: ";
            cin >> aluno;
            int index = -1;
            for (int i = 0; i < nomes.size(); i++)
            {
                if (nomes[i] == aluno)
                {
                    index = i;
                    i += nomes.size();
                }
            }

            if (index < 0)
            {
                cout << "Aluno não localizado." << endl;
            }
            else
            {
                cout << "Nota 1: " << notas1[index] << endl
                     << "Nota 2: " << notas2[index] << endl
                     << "Media: " << (notas1[index] + notas2[index]) / 2 << endl
                     << (notas1[index] + notas2[index] / 2 >= 7 ? "Aprovado(a)" : "Reprovado(a)") << endl;

                string alterarN;

                while (alterarN != "0")
                {
                    cout << "Alterar a primeira nota (1), a segunda nota (2) ou nenhuma (0)?: ";
                    cin >> alterarN;

                    if (alterarN == "1")
                    {
                        do
                        {
                            cout << "Digite a nova nota: ";
                            cin >> notas1[index];
                            if (notas1[index] < 0 || notas1[index] > 10)
                            {
                                cout << "Nota invalida!" << endl;
                            }
                        } while (notas1[index] < 0 || notas1[index] > 10);
                    }
                    else if (alterarN == "2")
                    {
                        do
                        {
                            cout << "Digite a nova nota: ";
                            cin >> notas2[index];
                            if (notas2[index] < 0 || notas2[index] > 10)
                            {
                                cout << "Nota invalida!" << endl;
                            }
                        } while (notas2[index] < 0 || notas2[index] > 10);
                    }
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < nomes.size(); i++)
    {
        float med = (notas1[i] + notas2[i]) / 2;
        cout << "Nome: " << nomes[i] << endl
             << "Nota 1: " << notas1[i] << endl
             << "Nota 2: " << notas2[i] << endl
             << "Media: " << med << endl
             << (med >= 7 ? "Aprovado(a)" : "Reprovado(a)") << endl
             << " -------------------- " << endl;
    }

    return 0;
}