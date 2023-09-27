#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    int N;
    cout << "Digite a quantidade de alunos: ";
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        string nome;
        float nota1, nota2;
        cout << "Digite o nome do aluno [" << i + 1 << "]: ";
        getline(cin, nome);
        do
        {
            cout << "Digite a primeira nota: ";
            cin >> nota1;
            if (nota1 < 0)
            {
                cout << "Nota invalida!" << endl;
            }
        } while (nota1 < 0);
        do
        {
            cout << "Digite a segunda nota: ";
            cin >> nota2;
            if (nota2 < 0)
            {
                cout << "Nota invalida!" << endl;
            }
        } while (nota2 < 0);

        cin.ignore();
        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);
        cout << endl;
    }
    return 0;
}