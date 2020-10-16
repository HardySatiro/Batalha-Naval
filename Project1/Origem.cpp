#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <locale.h>


using namespace std;


class Table {

public:
	string playes[2];
	vector<vector<int>> playerOneMap;
	vector<vector<int>> playerTwoMap;
	int playerOneScore = 0;
	int playerTwoScore = 0;
	int quanti1 = 0;
	int quanti2 = 0;
	int size;

public: Table(string playerOne, string playerTwo, int size) {
	this->setSize(size);
	this->setPlayerOne(playerOne);
	this->setPlayerTwo(playerTwo);
	this->initalizePlayerOneOcean();
	this->initalizePlayerTwoOcean();
}
private: void initalizePlayerOneOcean() {
	for (int i = 0; i < this->size; i++) {
		vector<int> mat;
		for (int j = 0; j < this->size; j++) {
			mat.push_back(-1);
		}
		this->playerOneMap.push_back(mat);
	}
}
private: void initalizePlayerTwoOcean() {
	for (int i = 0; i < this->size; i++) {
		vector<int> mat;
		for (int j = 0; j < this->size; j++) {
			mat.push_back(-1);
		}
		this->playerTwoMap.push_back(mat);
	}
}
public: void printOcean(int player) {
	vector<vector<int>> *ocean = NULL;
	if (player == 1) {
		ocean = &this->playerOneMap;
	}
	else if (player == 2) {
		ocean = &this->playerTwoMap;
	}

	cout << "                ";
	for (int i = 0; i < this->size; i++) {
		if (i < 10) {
			cout << "  " << i << "  ";

		}
		else {
			cout << " " << i << "  ";
		}
	}
	cout << "\n";
	for (int i = 0; i < this->size; i++) {
		if (i < 10) {
			cout << "	Linha: " << i;

		}
		else {
			cout << "     ";
			cout << "   Linha:" << i;
		} // para alinhar Linha 9 com Linha 10
		for (int j = 0; j < this->size; j++) {
			int positionValue = ocean->at(i).at(j);
			if (positionValue == -1) {
				cout << " ~~~ ";

			}
			else if (positionValue != -2) {
				cout << "  " << positionValue << "  ";
			}

		}

		cout << "\n";
	}
}
public: void printOcean2(int player) {
	vector<vector<int>> *ocean = NULL;
	if (player == 1) {
		ocean = &this->playerTwoMap;
	}
	else if (player == 2) {
		ocean = &this->playerOneMap;
	}

	cout << "                ";
	for (int i = 0; i < this->size; i++) {
		if (i < 10) {
			cout << "  " << i << "  ";
		}
		else {
			cout << " " << i << "  ";
		}
	}
	cout << "\n";
	for (int i = 0; i < this->size; i++) {
		if (i < 10) {
			cout << "	Linha: " << i;
		}
		else {
			cout << "     ";
			cout << "   Linha:" << i;
		} // para alinhar Linha 9 com Linha 10

		for (int j = 0; j < this->size; j++) {
			int positionValue = ocean->at(i).at(j);
			if (positionValue == -1 || positionValue == 1) {
				cout << " ~~~ ";

			}
			if (positionValue == 2 || positionValue == 3) {
				cout << " ~~~ ";

			}
			if (positionValue == 4 || positionValue == 5) {
				cout << " ~~~ ";

			}
			if (positionValue == -2) {
				cout << " XXX ";

			}
			if (positionValue == -3) {
				cout << " 000 ";
			}

		}

		cout << "\n";
	}
}
private: void setSize(int size) {
	this->size = size;

}
private: void setPlayerOne(string nome) {
	this->playes[0] = nome;
}
private: void setPlayerTwo(string nome) {
	this->playes[1] = nome;
}
public: int verifica(int player, int lineNumber, int columnNumber, int warship) {
	vector<vector<int>> *ocean = NULL;
	int posi = 0;
	if (player == 1) {
		ocean = &this->playerOneMap;
		posi = quanti1;
	}
	else if (player == 2) {
		ocean = &this->playerTwoMap;
		posi = quanti2;
	}
	if (posi < 10) {
		if (ocean->at(lineNumber).at(columnNumber) == -1) {
			if (warship == 1) { // porta aviões
				
				if (lineNumber < this->size-3 && columnNumber < this->size - 1) {
					if (ocean->at(lineNumber + 1).at(columnNumber) == -1 && ocean->at(lineNumber + 2).at(columnNumber - 1) == -1 && ocean->at(lineNumber + 2).at(columnNumber + 1) == -1) {
						return 1;
					} else {
						system("cls");
							cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
							system("pause");
					}
				} else {
					system("cls");
					cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
					system("pause");
				}
			}
			if (warship == 2) {
				if (ocean->at(lineNumber).at(columnNumber) == -1) {
					return 1;
				}
				else {
					system("cls");
					cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
					system("pause");
				}
			}
			if (warship == 3) {
				if (columnNumber < this->size - 1) {
					if (ocean->at(lineNumber).at(columnNumber + 1) == -1) {
						return 1;
					}
					else {
						system("cls");
						cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
						system("pause");
					}
				} else {
					system("cls");
					cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
					system("pause");
				}
			}
			if (warship == 4) {
				if (columnNumber < this->size - 2) {
					if (ocean->at(lineNumber).at(columnNumber + 1) == -1 && ocean->at(lineNumber).at(columnNumber + 2) == -1) {
						return 1;
					}
					else {
						system("cls");
						cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
						system("pause");
					}

					if (warship == 5) {
						if (ocean->at(lineNumber + 1).at(columnNumber - 1) == -1 && ocean->at(lineNumber + 1).at(columnNumber + 1) == -1) {
							return 1;
						}
						else {
							system("cls");
							cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
							system("pause");
						}
					}
				} else {
					system("cls");
					cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
					system("pause");
				}
			}
		} else {
			system("cls");
			cout << "VOCE ESTA TENTANDO COLOCAR UMA EMBARCACAO EM UMA POSICAO INVALIDA\n";
			system("pause");
		}
	}
	else {
		system("cls");
		cout << "VOCÊ ATINGIU O NUMERO MAXIMO DE NAVIOS\n";
		system("pause");
	}

}
public: void setWarship(int player, int lineNumber, int columnNumber, int warshipType) {
	vector<vector<int>> *ocean = NULL;
	
	int resultado = verifica(player, lineNumber, columnNumber, warshipType);
	int posi = 0;
	if (player == 1) {
		ocean = &this->playerOneMap;
		posi = quanti1;
	} else if (player == 2) {
		ocean = &this->playerTwoMap;
		posi = quanti2;
	}
	if (resultado == 1) {
		if (warshipType == 1) {// porta aviões
			ocean->at(lineNumber).at(columnNumber) = 1;
			ocean->at(lineNumber + 1).at(columnNumber) = 1;
			ocean->at(lineNumber + 2).at(columnNumber - 1) = 1;
			ocean->at(lineNumber + 2).at(columnNumber + 1) = 1;
			posi = posi + 4;

		} else if (warshipType == 2) { // submaridno
			ocean->at(lineNumber).at(columnNumber) = 2;
			posi = posi + 1;

		} else if (warshipType == 3) { // submaridno
			ocean->at(lineNumber).at(columnNumber) = 3;
			ocean->at(lineNumber).at(columnNumber + 1) = 3;
			posi = posi + 2;

		} else if (warshipType == 4) { // Encouraçado
			ocean->at(lineNumber).at(columnNumber) = 4;
			ocean->at(lineNumber).at(columnNumber + 1) = 4;
			ocean->at(lineNumber).at(columnNumber + 2) = 4;
			posi = posi + 3;
		} else if (warshipType == 5) { // submaridno
			ocean->at(lineNumber).at(columnNumber) = 5;
			ocean->at(lineNumber + 1).at(columnNumber - 1) = 5;
			ocean->at(lineNumber + 1).at(columnNumber + 1) = 5;
			posi = posi + 3;
		}
	}
	if (player == 1) {
		quanti1 = posi;
		system("cls");
		cout << "Seu ponto de posicionamento é :" << quanti1 << "\n";

		//system("pause");
	} else if (player == 2) {
		quanti2 = posi;
		system("cls");
		cout << "Seu ponto de posicionamento é :" << quanti2 << "\n";
		//system("pause");
	}
}
public: bool shot(int player, int line, int column) {

	int Score = 0;
	vector<vector<int>> *ocean = NULL;
	cout << "JOGADOR" " " << player;
	cout << "\n";
	if (player == 1) {
		ocean = &this->playerTwoMap;
		system("cls");
		cout << " JOGADOR " << player;
	}
	else if (player == 2) {
		ocean = &this->playerTwoMap;
		system("cls");
		cout << " JOGADOR " << player;
	}
	int oceanValue = ocean->at(line).at(column);

	if (oceanValue == -1) {//if para adicionar o 000 no mapa ou seja aceitou a água.
		ocean->at(line).at(column) = -3;
	}
	if (oceanValue == 1 || oceanValue == 3 || oceanValue == 5) { // if para pontuação e mostrar XXX no mapa, pois acertou o objeto.
		ocean->at(line).at(column) = -2;
		Score = +10;
	}
	else if (oceanValue == 2) {
		ocean->at(line).at(column) = -2;
		Score = +5;

	}
	else if (oceanValue == 4) {
		ocean->at(line).at(column) = -2;
		Score = +15;
	}

	if (player == 1) {
		playerOneScore = playerOneScore + Score;
		system("cls");
		cout << " JOGADOR " << player << " Sua pontuação é:" << playerOneScore << "\n";
	}
	else if (player == 2) {
		playerTwoScore = playerTwoScore + Score;
		system("cls");
		cout << " JOGADOR " << player << " Sua pontuação é:" << playerTwoScore << "\n";
	}
	return true;
}
};
int main() {
	setlocale(LC_ALL, "");

	Table* map = new Table("Hardy", "JucaBala", 15);
	// while de preenchimento
	while (true) {
		int playerNumber = 0;
		int warshipType;
		int line;
		int column;

		cout << "Qual jogador você é ? (Jogar 1, Jogar 2 ou 3 para ir para a batalha!!!)";
		cin >> playerNumber;
		switch (playerNumber)
		{
		case 1:
			map->printOcean(playerNumber);
			cout << "Qual é o tipo de navio que quer adicionar? (1 para PORTA AVIÕES, 2 para SUBMARINO, 3 para CRUZADOR, 4 para ENCOURAÇADO, 5 para HIDROAVIÃO)";
			cin >> warshipType;
			cout << "Qual é a posição inicial no eixo X?";
			cin >> line;
			cout << "Qual é a posição inicial no eixo Y?";
			cin >> column;

			if (line > 0 && line < 15 && warshipType > 0 && warshipType < 15) {
				map->setWarship(playerNumber, line, column, warshipType);
				map->printOcean(playerNumber);
				system("pause");
				system("cls");
			}
			else {
				system("cls");
				cout << " VOCÊ NAO COLOCOU UMA POSIÇÃO OU EMBARCAÇÃO INVALIDA\n";
			}
			break;
		case 2:
			map->printOcean(playerNumber);
			cout << "Qual é o tipo de navio que quer adicionar? (1 para PORTA AVIÕES, 2 para SUBMARINO, 3 para CRUZADOR, 4 para ENCOURAÇADO, 5 para HIDROAVIÃO)";
			cin >> warshipType;
			cout << "Qual é a posição inicial no eixo X?";
			cin >> line;
			cout << "Qual é a posição inicial no eixo Y?";
			cin >> column;
			if (line > 0 && line < 15 && column > 0 && column < 15) {
				map->setWarship(playerNumber, line, column, warshipType);
				map->printOcean(playerNumber);
				system("pause");
				system("cls");
			}
			else {
				system("cls");
				cout << " VOCÊ NAO COLOCOU UMA POSIÇÃO OU EMBARCAÇÃO INVALIDA\n";
			}
			break;
		case 3:
			if (map->quanti1 >= 10 && map->quanti1 <= 15 && map->quanti2 >= 10 && map->quanti2 <= 15) {
				while (true) {
					int player;
					int line;
					int column;
					cout << " VOCE ENTROU NO MODULO BATALHA\n";
					cout << " DIGITE QUAL JOGADOR IRA COMEÇAR\n";
					cin >> player;
					for (int j = 0; j < 2; j++) {
						for (int k = 0; k < 3; k++) {
							cout << " JOGADOR " << player;
							cout << "\n";
							map->printOcean2(player);
							cout << " digite a linha de ataque: ";
							cin >> line;
							cout << " digite a coluna para ataque: ";
							cin >> column;
							if (line >= 0 && line < 15 && column >= 0 && column < 15) {
								cout << " JOGADOR " << player;
								map->shot(player, line, column);
								map->printOcean2(player);
								system("pause");
								system("cls");
							}
							else {
								system("cls");
								cout << " VOCÊ ATIROU EM UMA POSIÇÃO INVALIDA\n";
							}

						}system("pause");
						if (player == 1) {
							player = 2;
						}
						else
							player = 1;
					}
					system("cls");
					cout << "A PONTUAÇÃO DO JOGADOR 1 É:" << map->playerOneScore;
					cout << "\nA PONTUAÇÃO DO JOGADOR 2 É:" << map->playerTwoScore << "\n";
					system("pause");
					break;
				}
			}
			else {
				cout << "VOCÊ ESTA TENTANDO EXECUTAR O MODULO DE COMBATE SEM COLOCAR A QUANTIDADE DE NAVIOS\n";
				cout << "A QUANTIDADE DE POSICIONAMENTO JOGADOR 1: " << map->quanti1 << "\nA QUANTIDADE DE POSICIONAMENTO DO JOGADOR 2: " << map->quanti2 << "\n";
				system("pause");
				system("cls");
			}
			break;

		default:
			cout << "VOCÊ ESTA DIGITANDO UMA POSIÇÃO INVALIDA\n";
			system("pause");
			system("cls");
			break;
		}
	}
}