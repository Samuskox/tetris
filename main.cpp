#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;

int tamanhoCedula = 30;
int grade[20][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, -4, -4, -4, 0, 0, 0},
                    {0, 0, 0, 0, 0, -4, 0, 0, 0, 0},
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
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                    {1, 0, 0, 0, 0, 0, 2, 2, 4, 4},
                    {1, 1, 1, 0, 1, 1, 2, 2, 0, 4}};
//int valorCedula;
int modoRotacao = 0;
int id = -4;
int idPlayer = id * -1;
int seconds = 0;

void tetraminoe(int id);

void move_Down();
void move_Left();
void move_Right();
void rotate();

bool can_Move_Down();
bool can_Move_Left();
bool can_Move_Right();
bool can_Rotate();

int main () {

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "My first TETRIS program!");
    SetTargetFPS(60);

    for(int linhas = 0; linhas < 20; linhas++){
        for(int colunas = 0; colunas < 10; colunas++){
            std::cout << grade[linhas][colunas] << " ";
        }
        std::cout << endl;
    }

    // for(int linhas = 19; linhas >= 0; linhas--){
    //     for(int colunas = 9; colunas >= 0; colunas--){
    //         std::cout << grade[linhas][colunas] << " ";
    //     }
    //     std::cout << endl;
    // }


    // for(int linha = 0; linha < 20; linha++){
    //         for(int coluna = 0; coluna < 10; coluna++){
    //             grade[linha][coluna] = 0;
    //         }
    // }

    // for(int i=0;i<20;i++){
        // for(int j=0;j<10;j++){
            // grade[i][j] = GetRandomValue(0,7);
            // cout << grade[i][j] << " ";
        // }
        // cout << endl;
    // }

    while (!(WindowShouldClose())){ 

        BeginDrawing();
        seconds++;
        

        for(int linhas = 0; linhas < 20; linhas++){
            for(int colunas = 0; colunas < 10; colunas++){
                if(grade[linhas][colunas] == 0){
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, GRAY);
                } else if(grade[linhas][colunas] == 1){  //--------------BEGIN STATIC TETRAMINOE--------------//
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
                } else if(grade[linhas][colunas] == 7){  //--------------FINAL STATIC TETRAMINOE--------------//
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, DARKBLUE);
                } else if(grade[linhas][colunas] == -1){  //--------------BEGIN PLAYER TETRAMINOE--------------//
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, BLUE);
                } else if(grade[linhas][colunas] == -2){
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, YELLOW);
                }else if(grade[linhas][colunas] == -3){
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, RED);
                }else if(grade[linhas][colunas] == -4){
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, PINK);
                }else if(grade[linhas][colunas] == -5){
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, ORANGE);
                }else if(grade[linhas][colunas] == -6){
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, GREEN);
                } else if(grade[linhas][colunas] == -7){
                    DrawRectangle(colunas * tamanhoCedula - 1, linhas * tamanhoCedula - 1, tamanhoCedula - 1, tamanhoCedula - 1, DARKBLUE);
                }                                         //--------------FINAL PLAYER TETRAMINOE--------------//
            }
        }

        tetraminoe(id);
        
            
        if(seconds == 60){
            // id = GetRandomValue(1,7);
            seconds = 0;
            if(can_Move_Down()){
                move_Down();
            }
            
        
        }

        ClearBackground(RAYWHITE);

        //DrawText("Congrats! You created \n your first window!", 100, 200, 10, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void tetraminoe(int id){
    if(IsKeyPressed(264) && can_Move_Down()){
            move_Down();      
        }
        if(IsKeyPressed(262) && can_Move_Right()){
            move_Right();
        }
        if(IsKeyPressed(263) && can_Move_Left()){
            move_Left();
        }if(IsKeyPressed(265)){
            rotate();
        }
}

void move_Down(){
    int countdown = 0;
    for(int i = 19; i >= 0; i--){
        for(int j = 9; j >= 0; j--){
            if(grade[i][j] < 0 && countdown < 4){
                countdown++;
                grade[i][j] = 0;
                grade[i + 1][j] = id;
            }
        }
    }
}

void move_Left(){
    int countdown = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            if(grade[i][j] < 0 && countdown < 4){
                countdown++;
                grade[i][j] = 0;
                grade[i][j - 1] = id;
            }
        }
    }
}

void move_Right(){
    int countdown = 0;
    for(int i = 19; i >= 0; i--){
        for(int j = 9; j >= 0; j--){
            if(grade[i][j] < 0 && countdown < 4){
                countdown++;
                grade[i][j] = 0;
                grade[i][j + 1] = id;
            }
        }
    }
}

bool can_Move_Down(){
    int countdown = 0;
    for(int i = 19; i >= 0; i--){
        for(int j = 9; j >= 0; j--){
            if(grade[i][j] < 0 && countdown < 4){
                countdown++;
                if(grade[i + 1][j] != 0 && grade[i + 1][j] != id){
                    return false;
                }
                if(i + 1 > 19){
                    return false;
                }
            }
        }
    }
    return true;
}

bool can_Move_Left(){
    int countdown = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            if(grade[i][j] < 0 && countdown < 4){
                countdown++;
                if(grade[i][j - 1] != 0 && grade[i][j - 1] != id){
                    return false;
                }
                if(j - 1 < 0){
                    return false;
                }
            }
        }
    }
    return true;
}

bool can_Move_Right(){
    int countdown = 0;
    for(int i = 19; i >= 0; i--){
        for(int j = 9; j >= 0; j--){
            if(grade[i][j] < 0 && countdown < 4){
                countdown++;
                if(grade[i][j + 1] != 0 && grade[i][j + 1] != id){
                    return false;
                }
                if(j + 1 > 9){
                    return false;
                }
            }
        }
    }
    return true;
}