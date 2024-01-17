#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;

int tamanhoCedula = 30;
int grade[20][10];
//int valorCedula;
int modoRotacao = 0;
int id = 1;
int tpeca[3][3];
int X = 2;
int Y = 3;
int seconds = 0;



void tetraminoe(int id, int modoRotacao, int X, int Y);

int main () {

    const int screenWidth = 300;
    const int screenHeight = 600;

    //int linhas;
    //int colunas;
    

    

    InitWindow(screenWidth, screenHeight, "My first TETRIS program!");
    SetTargetFPS(60);


        for(int linha = 0; linha < 20; linha++){
                for(int coluna = 0; coluna < 10; coluna++){
                    grade[linha][coluna] = 0;
                }
        }

            for(int linhas = 0; linhas < 20; linhas++){
                for(int colunas = 0; colunas < 10; colunas++){
                    std::cout << grade[linhas][colunas] << " ";
                }
                std::cout << endl;
            }

    //cout << "Hello World" << endl;



    //for(int i=0;i<20;i++){
    //        for(int j=0;j<10;j++){
    //            grade[i][j] = GetRandomValue(0,7);
    //            cout << grade[i][j] << " ";
    //        }
    //        cout << endl;
    //    }

    while (!(WindowShouldClose())){ 

        BeginDrawing();
        seconds++;
        bool down = IsKeyPressed(264);
        bool right = IsKeyPressed(262);
        

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

            tetraminoe(id, modoRotacao, X, Y);

            if(IsKeyPressed(264)){
                Y++;
            } 
            if(IsKeyPressed(262)){
                X++;
            }
            if(IsKeyPressed(263)){
                X--;
            }
            if(seconds == 60){
                seconds = 0;
                Y++;
            }
            

            ClearBackground(RAYWHITE);

            //DrawText("Congrats! You created \n your first window!", 100, 200, 10, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void tetraminoe(int id, int modoRotacao, int X, int Y){
    switch (id)
    {
    case 1:
        if(modoRotacao == 0){
            DrawRectangle(X*tamanhoCedula - 1, Y*tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
            DrawRectangle((X-1)*tamanhoCedula - 1, Y*tamanhoCedula -1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
            DrawRectangle((X+1)*tamanhoCedula - 1, Y*tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
            DrawRectangle(X*tamanhoCedula - 1, (Y+1)*tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
        } else if(modoRotacao == 1){
            DrawRectangle(X*tamanhoCedula - 1, Y*tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
            DrawRectangle(X*tamanhoCedula - 1, (Y-1)*tamanhoCedula -1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
            DrawRectangle(X*tamanhoCedula - 1, (Y+1)*tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
            DrawRectangle((X+1)*tamanhoCedula - 1, Y*tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
        } else 
        break;
    
    default:
        break;
    }
}