#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;


int main () {

    const int screenWidth = 300;
    const int screenHeight = 600;

    //int linhas;
    //int colunas;
    int grade[20][10];
    int tamanhoCedula = 30;
    //int valorCedula;

    int jpeca[3][3];

    InitWindow(screenWidth, screenHeight, "My first TETRIS program!");
    SetTargetFPS(60);


    for(int linha = 0; linha < 20; linha++){
                for(int coluna = 0; coluna < 10; coluna++){
                    grade[linha][coluna] = 0;
                }
        }

        

            //for(int linhas = 0; linhas < 20; linhas++){
            //    for(int colunas = 0; colunas < 10; colunas++){
            //        std::cout << grade[linhas][colunas] << " ";
            //    }
            //    std::cout << endl;
            //}

    //cout << "Hello World" << endl;



    for(int i=0;i<20;i++){
            for(int j=0;j<10;j++){
                grade[i][j] = GetRandomValue(0,7);
                cout << grade[i][j] << " ";
            }
            cout << endl;
        }

    while (!(WindowShouldClose())){ 

        BeginDrawing();

            for(int linhas = 0; linhas < 20; linhas++){
                for(int colunas = 0; colunas < 10; colunas++){
                    if(grade[linhas][colunas] == 0){
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, GRAY);
                    } else if(grade[linhas][colunas] == 1){
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, BLUE);
                    } else if(grade[linhas][colunas] == 2){
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, YELLOW);
                    }else if(grade[linhas][colunas] == 3){
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, RED);
                    }else if(grade[linhas][colunas] == 4){
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
                    }else if(grade[linhas][colunas] == 5){
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, ORANGE);
                    }else if(grade[linhas][colunas] == 6){
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, GREEN);
                    } else if(grade[linhas][colunas] == 7){
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, DARKBLUE);
                    }
                }
            }
        
            ClearBackground(RAYWHITE);

            //DrawText("Congrats! You created \n your first window!", 100, 200, 10, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}