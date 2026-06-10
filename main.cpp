#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    int mapa[16][16];

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (i == 8 && j == 8) {
                mapa[i][j] = 0;
            } else {
                int sorteio = rand() % 100;
                if (sorteio < 35) {
                    mapa[i][j] = 0;
                } else if (sorteio < 50) {
                    mapa[i][j] = 1;
                } else if (sorteio < 65) {
                    mapa[i][j] = 2;
                } else if (sorteio < 75) {
                    mapa[i][j] = 3;
                } else if (sorteio < 85) {
                    mapa[i][j] = 4;
                } else {
                    mapa[i][j] = 5;
                }
            }
        }
    }

    int objetivo = 0;
    while (objetivo < 1 || objetivo > 3) {
        cout << "Escolha o seu objetivo no jogo:" << endl;
        cout << "1 - Luz e calor (4 gravetos e 2 pedras)" << endl;
        cout << "2 - Comida (1 fruta e 3 animais)" << endl;
        cout << "3 - Construcao (8 pedras e 4 arvores)" << endl;
        cout << "Digite o numero da opcao: ";
        cin >> objetivo;
    }

    int inventario_gravetos = 0;
    int inventario_pedras = 0;
    int inventario_frutas = 0;
    int inventario_animais = 0;
    int inventario_arvores = 0;

    int posX = 8;
    int posY = 8;

    int jogando = 1;

    while (jogando == 1) {
        cout << endl << "=========================================" << endl;
        cout << "MAPA DO MUNDO" << endl;
        cout << "=========================================" << endl;

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (i == posX && j == posY) {
                    cout << "P ";
                } else if (mapa[i][j] == 0) {
                    cout << ". ";
                } else if (mapa[i][j] == 1) {
                    cout << "| ";
                } else if (mapa[i][j] == 2) {
                    cout << "o ";
                } else if (mapa[i][j] == 3) {
                    cout << "* ";
                } else if (mapa[i][j] == 4) {
                    cout << "M ";
                } else if (mapa[i][j] == 5) {
                    cout << "T ";
                }
            }
            cout << endl;
        }

        cout << endl << "INVENTARIO:" << endl;
        cout << "Gravetos: " << inventario_gravetos << " | Pedras: " << inventario_pedras;
        cout << " | Frutas: " << inventario_frutas << " | Animais: " << inventario_animais;
        cout << " | Arvores: " << inventario_arvores << endl;

        if (mapa[posX][posY] != 0) {
            int item = mapa[posX][posY];
            int coletar = 0;

            if (item == 1) {
                cout << "Voce encontrou um Graveto (|)!" << endl;
            } else if (item == 2) {
                cout << "Voce encontrou uma Pedra (o)!" << endl;
            } else if (item == 3) {
                cout << "Voce encontrou uma Fruta (*)!" << endl;
            } else if (item == 4) {
                cout << "Voce encontrou um Animal (M)!" << endl;
            } else if (item == 5) {
                cout << "Voce encontrou uma Arvore (T)!" << endl;
            }

            while (coletar < 1 || coletar > 2) {
                cout << "Deseja coletar? (1 - Sim / 2 - Nao): ";
                cin >> coletar;
            }

            if (coletar == 1) {
                if (item == 1) {
                    inventario_gravetos++;
                } else if (item == 2) {
                    inventario_pedras++;
                } else if (item == 3) {
                    inventario_frutas++;
                } else if (item == 4) {
                    inventario_animais++;
                } else if (item == 5) {
                    inventario_arvores++;
                }
                mapa[posX][posY] = 0;
                cout << "Item coletado com sucesso!" << endl;
            }
        }

        if (objetivo == 1) {
            if (inventario_gravetos >= 4 && inventario_pedras >= 2) {
                cout << endl << "PARABENS! Voce alcancou o objetivo 'Luz e calor'!" << endl;
                jogando = 0;
            }
        } else if (objetivo == 2) {
            if (inventario_frutas >= 1 && inventario_animais >= 3) {
                cout << endl << "PARABENS! Voce alcancou o objetivo 'Comida'!" << endl;
                jogando = 0;
            }
        } else if (objetivo == 3) {
            if (inventario_pedras >= 8 && inventario_arvores >= 4) {
                cout << endl << "PARABENS! Voce alcancou o objetivo 'Construcao'!" << endl;
                jogando = 0;
            }
        }

        if (jogando == 1) {
            int direcao = 0;
            while (direcao < 1 || direcao > 4) {
                cout << endl << "Escolha uma direcao para caminhar:" << endl;
                cout << "1 - Para Cima" << endl;
                cout << "2 - Para Baixo" << endl;
                cout << "3 - Para Esquerda" << endl;
                cout << "4 - Para Direita" << endl;
                cout << "Digite o numero correspondente: ";
                cin >> direcao;
            }

            if (direcao == 1) {
                if (posX > 0) {
                    posX--;
                } else {
                    cout << "Voce bateu nos limites do mapa ao norte!" << endl;
                }
            } else if (direcao == 2) {
                if (posX < 15) {
                    posX++;
                } else {
                    cout << "Voce bateu nos limites do mapa ao sul!" << endl;
                }
            } else if (direcao == 3) {
                if (posY > 0) {
                    posY--;
                } else {
                    cout << "Voce bateu nos limites do mapa a oeste!" << endl;
                }
            } else if (direcao == 4) {
                if (posY < 15) {
                    posY++;
                } else {
                    cout << "Voce bateu nos limites do mapa a leste!" << endl;
                }
            }
        }
    }

    cout << "Fim da partida. Obrigado por jogar Minecraft Quadrado!" << endl;

    return 0;
}