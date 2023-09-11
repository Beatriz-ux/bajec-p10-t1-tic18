#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    string nomeInput;
    float nota1Input, nota2Input;
    vector<string> nomes;
    vector<vector<float>> notas;

    cout << "Digite limite de alunos nos sistema: ";
    cin >> N;
    cin.ignore(); // ignora enter

    while(nomes.size()<N){
        cout << "\nDigite nome do aluno: ";
        getline(cin, nomeInput);
        nomes.push_back(nomeInput);

        // confere se notas sao validass
        do{
            cout << "Nota1 = ";
            cin >> nota1Input;
        }while(nota1Input<0 || nota1Input>10);
        do{
            cout << "Nota2 = ";
            cin >> nota2Input;
        }while(nota2Input<0 || nota2Input>10);
        cin.ignore(); // ignora enter
        notas.push_back({nota1Input, nota1Input});
    }

    return 0;
}