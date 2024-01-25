#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;

int tamanhoCedula = 30;
int grade[20][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
//int valorCedula;
int modoRotacao = 0;
int id = 1;
int tpeca[3][3] = {{0,4,0},
                    {4,4,4},
                    {0,0,0}};
int X = 3;
int lastX = -1;
int Y = 4;
int lastY = -1;
int seconds = 0;



void tetraminoe(int id, int X, int Y);

int main () {

    const int screenWidth = 300;
    const int screenHeight = 600;

    //int linhas;
    //int colunas;
    

    

    InitWindow(screenWidth, screenHeight, "My first TETRIS program!");
    SetTargetFPS(60);

    for(int linhas = 0; linhas < 20; linhas++){
                for(int colunas = 0; colunas < 10; colunas++){
                    std::cout << grade[linhas][colunas] << " ";
                }
                std::cout << endl;
            }


        for(int linha = 0; linha < 20; linha++){
                for(int coluna = 0; coluna < 10; coluna++){
                    grade[linha][coluna] = 0;
                }
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
        

            for(int linhas = 0; linhas < 20; linhas++){
                for(int colunas = 0; colunas < 10; colunas++){
                    if(grade[linhas][colunas] == 0){  //BEGIN STATIC TETRAMINOE//                                                                -//
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
                    } else if(grade[linhas][colunas] == 7){  //FINAL STATIC TETRAMINOE//                                                            -//
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, DARKBLUE);
                    } else if(grade[linhas][colunas] == 8){  //BEGIN PLAYER//                                                                       -//
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, BLUE);
                    } else if(grade[linhas][colunas] == 9){ 
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, YELLOW);
                    } else if(grade[linhas][colunas] == 10){ 
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, RED);
                    } else if(grade[linhas][colunas] == 11){ 
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
                    } else if(grade[linhas][colunas] == 12){ 
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, ORANGE);
                    } else if(grade[linhas][colunas] == 13){ 
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, GREEN);
                    } else if(grade[linhas][colunas] == 14){ 
                        DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, DARKBLUE);
                    }                                        //BEGIN PLAYER//                                                                       -//
                }
            }

            tetraminoe(id, X, Y);

            
            if(seconds == 60){
                seconds = 0;
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y][1+X] = 0;
                grade[Y-1][X] = 0;
                Y++;
                grade[Y][X] = 4;
                grade[Y][X-1] = 4;
                grade[Y][1+X] = 4;
                grade[Y-1][X] = 4;

                //Y++;
                

                //for(int linhas = 0; linhas < 20; linhas++){
                //for(int colunas = 0; colunas < 10; colunas++){
                //    std::cout << grade[linhas][colunas] << " ";
                //}
                //std::cout << endl;
            //}


            }

            
            
            


             


            

            ClearBackground(RAYWHITE);

            //DrawText("Congrats! You created \n your first window!", 100, 200, 10, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void tetraminoeMove(int id, int X, int Y){
    switch (id)
    {
    case 1:

        break;
    case 11:
        if(IsKeyPressed(264)){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y][1+X] = 0;
                grade[Y-1][X] = 0;
                Y++;
                grade[Y][X] = 4;
                grade[Y][X-1] = 4;
                grade[Y][1+X] = 4;
                grade[Y-1][X] = 4;
            } 
            if(IsKeyPressed(262)){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y][1+X] = 0;
                grade[Y-1][X] = 0;
                X++;
                grade[Y][X] = 4;
                grade[Y][X-1] = 4;
                grade[Y][1+X] = 4;
                grade[Y-1][X] = 4;
            }
            if(IsKeyPressed(263)){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y][1+X] = 0;
                grade[Y-1][X] = 0;
                X--;
                grade[Y][X] = 4;
                grade[Y][X-1] = 4;
                grade[Y][1+X] = 4;
                grade[Y-1][X] = 4;
            }
        break;
    
    default:
        break;
    }
}