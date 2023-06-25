#include <iostream>
#include <cctype>

using namespace std;

int OpSelect;
float Num1, Num2;
float SoResult, SubResult, MultResult, DivResult;
float PrevNum = 0;
bool Prev = false;
float LResult;

// prototipos das funcoes utilizadas
void Limpar(); 
void soma();
void subtracao();
void multiplicacao();
void divisao();
void ContinueOp();
void OpMenu();

// inicia a calculadora
int main(){
	cout << "                " <<
		"Calculadora Basica" << endl << endl;
	OpMenu();
	
	return 0;
}

// Funcao para limpar a tela
void Limpar(){
	system("CLS");
    cout << flush;
    system("CLS");
}

void divisao(){
	cout << "Operacao selecionada: Divisao" << endl;
	cout << "    " << "Digite dois numeros a serem divididos" << endl;
	cout << "Ultimo resultado:     | " << PrevNum  << " | " << endl;
	cin >> Num1;
	cout << "/ ";
	cin >> Num2; 
	DivResult = Num1 / Num2;
	cout << " = " << DivResult << endl; 
	
	PrevNum += DivResult;
	if(Prev == true){
		cout << " + " << LResult << endl;  
		cout << "O resultado das operacoes e: " << PrevNum << endl;
		LResult = PrevNum;
	} else{
		cout << "O resultado da multiplicacao e: " << DivResult << endl;
		LResult = DivResult;
	}
	
	ContinueOp();
}

void multiplicacao(){
	cout << "Operacao selecionada: Multiplicacao" << endl;
	cout << "    " << "Digite dois numeros a serem multiplicados" << endl;
	cout << "Ultimo resultado:     | " << PrevNum  << " | " << endl;
	cin >> Num1;
	cout << "* ";
	cin >> Num2;
	MultResult = Num1 * Num2;
	cout << " = " << MultResult << endl;
	
	PrevNum += MultResult;
	if(Prev == true){
		cout << " + " << LResult << endl;  
		cout << "O resultado das operacoes e: " << PrevNum << endl;
		LResult = PrevNum;
	} else{
		cout << "O resultado da multiplicacao e: " << MultResult << endl;
		LResult = MultResult;
	}
	
	ContinueOp();
}

void subtracao(){
	cout << "Operacao selecionada: Subtracao" << endl;
	cout << "    " << "Digite dois numeros a serem subtraidos" << endl;
	cout << "Ultimo resultado:     | " << PrevNum  << " | " << endl;
	cin >> Num1;
	cout << "- ";
	cin >> Num2; 
	SubResult = Num1 - Num2;
	cout << " = " << SubResult << endl; 
	
	PrevNum += SubResult;
	if(Prev == true){
		cout << " + " << LResult << endl;  
		cout << "O resultado das operacoes e: " << PrevNum << endl;
		LResult = PrevNum;
	} else{
		cout << "O resultado da soma e: " << SubResult << endl;
		LResult = SubResult;
	}
	
	ContinueOp();
}

void soma(){
	
	cout << "Operacao selecionada: Soma" << endl;
	cout << "    " << "Digite dois numeros a serem somados" << endl;
	cout << "     Ultimo resultado:     | " << PrevNum  << " | " << endl;
	cin >> Num1;
	cout << "+ ";
	cin >> Num2;
	SoResult = Num1 + Num2;
	cout << " = " << SoResult << endl;
	PrevNum += SoResult;
	if(Prev == true){
		cout << " + " << LResult << endl;  
		cout << "O resultado das operacoes e: " << PrevNum << endl;
		LResult = PrevNum;
	} else{
		cout << "O resultado da soma e: " << SoResult << endl;
		LResult = SoResult;
	}

	ContinueOp();
}

// Menu com as opcoes de operacoes disponiveis
void OpMenu(){
		cout << "Qual operacao deseja executar?" << endl;
		cout << "1. Soma" << endl
		 << "2. Subtracao" << endl
		 << "3. Multiplicacao" << endl
		 << "4. Divisao" << endl
		 << "0. Encerrar calculadora" << endl;
	cin >> OpSelect;
	switch(OpSelect){
		case 1:
			Limpar();
			soma();
			break;
		case 2:
			subtracao();
			break;
		case 3:
			multiplicacao();
			break;
		case 4:
			divisao();
			break;
		case 0:
			cout << "Fechando a calculadora!" << endl;
			break;
		default:
			cout << "Opcao invalida! Digite novamente." << endl;
			OpMenu();
	}
}

// Verifica se o usuario deseja continuar a utilizar a calculadora
// 1: continua e mantem o resultado da ultima operacao
// 2: continua e apaga o resultado da ultima operacao
// 3: encerra a calculadora
void ContinueOp(){
	cout << endl <<  "Deseja continuar a fazer operacoes?" << endl
		 << "    " << "1. Sim, e manter ultimo resultado    2. Sim, e limpar ultimo resultado   3. Nao, encerrar a calculadora" << endl;
	cin >> OpSelect;
	switch(OpSelect){
		case 1:
			Limpar();
			Prev = true;
			OpMenu();
			break;
		case 2:
			Limpar();
			Prev = false;
			LResult = 0;
			PrevNum = 0;
			OpMenu();
			break;
		case 3:
			cout << "Fechando a calculadora!" << endl;
			break;
		default:
			Limpar();
			cout << "Opcao invalida! Digite novamente." << endl;
			ContinueOp();
			break;
	}//
	
}
