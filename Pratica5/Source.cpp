#include <iostream>
#include <string>

#define TAM 20

using namespace std;

struct Pilha
{
	char elementos[TAM];
	int topo = -1;
};

void push(Pilha* pilha, char valor)
{
	pilha->elementos[pilha->topo+1] = valor;
	pilha->topo++;
}

char pop(Pilha* pilha)
{
	int retorno = pilha->elementos[pilha->topo];
	pilha->topo--;
	return retorno;
}

string inverter(string texto)
{
	Pilha pilha;
	string invertido;
	int start = 0;
	for (int i = 0; i < texto.size(); i++)
	{
		if (texto.at(i) == ' ')
		{
			int caracteres = 0;
			for (int j = start; j <= i; j++)
			{
				push(&pilha, texto.at(j));
				caracteres++;
			}
			start = i + 1;
			for (int x = 0; x < caracteres; x++)
			{
				invertido.push_back(pop(&pilha));
			}
		}
		if (texto.size() == i + 1)
		{
			int caracteres = 0;
			for (int j = start; j <= i; j++)
			{
				push(&pilha, texto.at(j));
				caracteres++;
			}
			start = i + 1;
			invertido.push_back(' ');
			for (int x = 0; x < caracteres; x++)
			{
				invertido.push_back(pop(&pilha));
			}
		}
	}
	return invertido;
}

int main()
{
	string frase = "ESTE EXERCICIO E MUITO FACIL";
	cout << inverter(frase) << endl;

	system("pause");
	return 0;
}