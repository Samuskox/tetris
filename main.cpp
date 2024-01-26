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
int coolDown = 0;
bool PlayerControlling = false;
int movePerSecond = 1;

void tetraminoe(int id);
void CreateTetraminoe();

void move_Down();
void move_Left();
void move_Right();
void rotate();

bool can_Move_Down();
bool can_Move_Left();
bool can_Move_Right();
bool can_Rotate();

void rotate_Array(double angle);

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
        if(PlayerControlling == false){
            CreateTetraminoe();
            PlayerControlling = true;
        }
        
        //gravity
        if(seconds == 60){
            // id = GetRandomValue(1,7);
            seconds = 0;
            if(can_Move_Down()){
                move_Down();
            } else {
                coolDown++;
                cout << coolDown << " ";
            }
        }

        if(coolDown == 4){
            for(int i = 0; i< 20; i++){
                for(int j=0; j<10;j++){
                    if(grade[i][j] < 0){
                        grade[i][j] = grade[i][j]*-1;
                    }
                }
            }
            coolDown = 0;
            PlayerControlling = false;
        }
        //Mode Psycho
        // for(int i = 0; i< 20; i++){
        //         for(int j=0; j<10;j++){
        //             if(grade[i][j] > 0){
        //                 grade[i][j] = GetRandomValue(1,7);
        //             }
        //         }
        //     }

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

void rotate(){
    
}

void CreateTetraminoe(){
        int numRandom = GetRandomValue(-1,-7);
        id = numRandom;
        switch (numRandom)
        {
        case -1:
            grade[1][5] = -1;
            grade[2][5] = -1;
            grade[3][5] = -1;
            grade[4][5] = -1;
            /* code */
            break;
        case -2:
            grade[1][5] = -2;
            grade[1][6] = -2;
            grade[2][5] = -2;
            grade[2][6] = -2;
            break;
        case -3:
            grade[1][5] = -3;
            grade[2][5] = -3;
            grade[1][4] = -3;
            grade[2][6] = -3;
            break;
        case -4:
            grade[1][5] = -4;
            grade[2][5] = -4;
            grade[2][4] = -4;
            grade[2][6] = -4;
            break;
        case -5:
            grade[1][5] = -5;
            grade[2][5] = -5;
            grade[3][5] = -5;
            grade[3][6] = -5;
            break;
        case -6:
            grade[1][5] = -6;
            grade[2][5] = -6;
            grade[2][4] = -6;
            grade[1][6] = -6;
            break;
        case -7:
            grade[1][5] = -7;
            grade[2][5] = -7;
            grade[3][5] = -7;
            grade[3][4] = -7;
        default:
        
            break;
        }
}

void rotate_Array(double angle){
    int newX;
    int newY;
    //Convert Degree to Radians
    angle *= PI/180;
    //newX = x * cos(angle) - y * sin(angle);
    //newY = x * sin(angle) + y * cos(angle);
}