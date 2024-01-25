#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;

int tamanhoCedula = 30;
int grade[20][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0,-4, 0, 0, 0, 0},
                    {0, 0, 0, 0, -4, -4, -4, 0, 0, 0},
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
                    {1, 1, 1, 1, 1, 0, 2, 2, 0, 4}};
//int valorCedula;
int modoRotacao = 0;
int id = -4;
int idPlayer = id * -1;
int X = 3;
int Y = 5;
int seconds = 0;

int countdown = 0;

void tetraminoe(int id, int X, int Y);

void move_T_Down();
void move_T_Left();
void move_T_Right();

bool can_Move_T_Down();

void move_Square_Down();
void move_Square_Left();
void move_Square_Right();

void move_I_Down();
void move_I_Left();
void move_I_Right();

void move_S_Down();
void move_S_Left();
void move_S_Right();

void move_L_Down();
void move_L_Left();
void move_L_Right();

void move_Z_Down();
void move_Z_Left();
void move_Z_Right();

void move_J_Down();
void move_J_Left();
void move_J_Right();

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

           

    //cout << "Hello World" << endl;



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

        tetraminoe(id, X, Y);

            
        if(seconds == 60){
            seconds = 0;
            // id = GetRandomValue(1,7);
            if(id == -4 && Y < 19){
                // if(can_Move_T_Down()){
                    move_T_Down();
                // }
            } else if(id == -2 && (Y+1) < 19){
                move_Square_Down();
            } else if(id == -1 && (Y + 2) < 19){
                move_I_Down();
            } else if(id == -3 && Y < 19){
                move_S_Down();
            } else if(id == -5 && Y < 19){
                move_L_Down();
            } else if(id == -6 && Y < 19){
                move_Z_Down();
            } else if(id == -7 && Y < 19){
                move_J_Down();
            }
           

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

void tetraminoe(int id, int X, int Y){
    switch (id)
    {
    case -1:
        if(IsKeyPressed(264) && (Y + 2) < 19){
            move_I_Down();      
        }
        if(IsKeyPressed(262) && X < 9){
            move_I_Right();
        }
        if(IsKeyPressed(263) && X > 0){
            move_I_Left();
        }
        break;
    case -2:
        if(IsKeyPressed(264) && Y<19){
            move_Square_Down();      
        }
        if(IsKeyPressed(262) && (X+1)<9){
            move_Square_Right();
        }
        if(IsKeyPressed(263) && (X)>0){
            move_Square_Left();
        }
        break;
    case -3:
        if(IsKeyPressed(264) && Y < 19){
            move_S_Down();
        }
        if(IsKeyPressed(262) && (X + 1) < 9){
            move_S_Right();
        }
        if(IsKeyPressed(263) && (X - 1) > 0){
            move_S_Left();
        }
        break;
    case -4:
        if(IsKeyPressed(264) && Y < 19 && grade[Y+1][X] == 0){
            move_T_Down();      
        }
        if(IsKeyPressed(262) && (X+1) < 9){
            move_T_Right();
        }
        if(IsKeyPressed(263) && (X-1) > 0){
            move_T_Left();
        }
        break;
    case -5:
        if(IsKeyPressed(264) && Y < 19){
            move_L_Down();      
        }
        if(IsKeyPressed(262) && (X + 1) < 9){
            move_L_Right();
        }
        if(IsKeyPressed(263) && X > 0){
            move_L_Left();
        }
        break;
    case -6: 
        if(IsKeyPressed(264) && Y < 19){
            move_Z_Down();
        }
        if(IsKeyPressed(262) && (X + 1) < 9){
            move_Z_Right();
        }
        if(IsKeyPressed(263) && (X - 1) > 0){
            move_Z_Left();
        }
        break;
    case -7:
        if(IsKeyPressed(264) && Y < 19){
            move_J_Down();      
        }
        if(IsKeyPressed(262) && X < 9){
            move_J_Right();
        }
        if(IsKeyPressed(263) && (X - 1) > 0){
            move_J_Left();
        }
        break;
    default:
        break;
    }
}

//MOVE T
void move_T_Left(){
    countdown = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            if(grade[i][j] < 0 && countdown < 4){
                countdown++;
                grade[i][j] = 0;
                grade[i][j - 1] = id;
            }
        }
    }
    countdown = 0;
    for(int linhas = 0; linhas < 20; linhas++){
        for(int colunas = 0; colunas < 10; colunas++){
            std::cout << grade[linhas][colunas] << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;
                // grade[Y][X] = 0;
                // grade[Y][X-1] = 0;
                // grade[Y][1+X] = 0;
                // grade[Y-1][X] = 0;
                // X--;
                // grade[Y][X] = -4;
                // grade[Y][X-1] = -4;
                // grade[Y][1+X] = -4;
                // grade[Y-1][X] = -4;
}

void move_T_Right(){
    countdown = 0;
    for(int i = 19; i >= 0; i--){
        for(int j = 9; j >= 0; j--){
            if(grade[i][j] < 0 && countdown < 4){
                countdown++;
                grade[i][j] = 0;
                grade[i][j + 1] = id;
            }
        }
    }
    countdown = 0;
    for(int linhas = 0; linhas < 20; linhas++){
        for(int colunas = 0; colunas < 10; colunas++){
            std::cout << grade[linhas][colunas] << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;

                // grade[Y][X] = 0;
                // grade[Y][X-1] = 0;
                // grade[Y][1+X] = 0;
                // grade[Y-1][X] = 0;
                // X++;
                // grade[Y][X] = -4;
                // grade[Y][X-1] = -4;
                // grade[Y][1+X] = -4;
                // grade[Y-1][X] = -4;
}

void move_T_Down(){
    countdown = 0;
    for(int i = 19; i >= 0; i--){
        for(int j = 9; j >= 0; j--){
            if(grade[i][j] < 0 && countdown < 4){
                cout << "NAO TA FUNFANDO";
                cout << countdown;
                countdown++;
                grade[i][j] = 0;
                grade[i + 1][j] = id;
            }
        }
    }
    countdown = 0;
    for(int linhas = 0; linhas < 20; linhas++){
        for(int colunas = 0; colunas < 10; colunas++){
            std::cout << grade[linhas][colunas] << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;
                // if(can_Move_T_Down()){
                //     grade[Y][X] = 0;
                //     grade[Y][X-1] = 0;
                //     grade[Y][1+X] = 0;
                //     grade[Y-1][X] = 0;
                //     Y++;
                //     grade[Y][X] = -4;
                //     grade[Y][X-1] = -4;
                //     grade[Y][1+X] = -4;
                //     grade[Y-1][X] = -4;
                // }
}

//MOVE SQUARE
void move_Square_Down(){
            grade[Y][X] = 0;
            grade[Y][X+1] = 0;
            grade[Y-1][X] = 0;
            grade[Y-1][X+1] = 0;
            Y++;
            grade[Y][X] = -2;
            grade[Y][X+1] = -2;
            grade[Y-1][X] = -2;
            grade[Y-1][X+1] = -2;
}
void move_Square_Left(){
            grade[Y][X] = 0;
            grade[Y][X+1] = 0;
            grade[Y-1][X] = 0;
            grade[Y-1][X+1] = 0;
            X--;
            grade[Y][X] = -2;
            grade[Y][X+1] = -2;
            grade[Y-1][X] = -2;
            grade[Y-1][X+1] = -2;
}
void move_Square_Right(){
            grade[Y][X] = 0;
            grade[Y][X+1] = 0;
            grade[Y-1][X] = 0;
            grade[Y-1][X+1] = 0;
            X++;
            grade[Y][X] = -2;
            grade[Y][X+1] = -2;
            grade[Y-1][X] = -2;
            grade[Y-1][X+1] = -2;
}

//MOVE I
void move_I_Down(){
                grade[Y][X] = 0;
                grade[Y-1][X] = 0;
                grade[Y+1][X] = 0;
                grade[Y+2][X] = 0;
                Y++;
                grade[Y][X] = -1;
                grade[Y-1][X] = -1;
                grade[Y+1][X] = -1;
                grade[Y+2][X] = -1;
}
void move_I_Left(){
                grade[Y][X] = 0;
                grade[Y-1][X] = 0;
                grade[Y+1][X] = 0;
                grade[Y+2][X] = 0;
                X--;
                grade[Y][X] = -1;
                grade[Y-1][X] = -1;
                grade[Y+1][X] = -1;
                grade[Y+2][X] = -1;
}
void move_I_Right(){
                grade[Y][X] = 0;
                grade[Y-1][X] = 0;
                grade[Y+1][X] = 0;
                grade[Y+2][X] = 0;
                X++;
                grade[Y][X] = -1;
                grade[Y-1][X] = -1;
                grade[Y+1][X] = -1;
                grade[Y+2][X] = -1;
}

//MOVE S
void move_S_Down(){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-1][X+1] = 0;
                Y++;
                grade[Y][X] = -3;
                grade[Y][X-1] = -3;
                grade[Y-1][X] = -3;
                grade[Y-1][X+1] = -3;
}
void move_S_Left(){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-1][X+1] = 0;
                X--;
                grade[Y][X] = -3;
                grade[Y][X-1] = -3;
                grade[Y-1][X] = -3;
                grade[Y-1][X+1] = -3;
}
void move_S_Right(){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-1][X+1] = 0;
                X++;
                grade[Y][X] = -3;
                grade[Y][X-1] = -3;
                grade[Y-1][X] = -3;
                grade[Y-1][X+1] = -3;
}

//MOVE L
void move_L_Down(){
                grade[Y][X] = 0;
                grade[Y][X+1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-2][X] = 0;
                Y++;
                grade[Y][X] = -5;
                grade[Y][X+1] = -5;
                grade[Y-1][X] = -5;
                grade[Y-2][X] = -5;
}
void move_L_Left(){
                grade[Y][X] = 0;
                grade[Y][X+1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-2][X] = 0;
                X--;
                grade[Y][X] = -5;
                grade[Y][X+1] = -5;
                grade[Y-1][X] = -5;
                grade[Y-2][X] = -5;
}
void move_L_Right(){
                grade[Y][X] = 0;
                grade[Y][X+1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-2][X] = 0;
                X++;
                grade[Y][X] = -5;
                grade[Y][X+1] = -5;
                grade[Y-1][X] = -5;
                grade[Y-2][X] = -5;
}

//MOVE Z
void move_Z_Down(){
                grade[Y][X] = 0;
                grade[Y][X+1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-1][X-1] = 0;
                Y++;
                grade[Y][X] = -6;
                grade[Y][X+1] = -6;
                grade[Y-1][X] = -6;
                grade[Y-1][X-1] = -6;
}
void move_Z_Left(){
                grade[Y][X] = 0;
                grade[Y][X+1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-1][X-1] = 0;
                X--;
                grade[Y][X] = -6;
                grade[Y][X+1] = -6;
                grade[Y-1][X] = -6;
                grade[Y-1][X-1] = -6;
}
void move_Z_Right(){
                grade[Y][X] = 0;
                grade[Y][X+1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-1][X-1] = 0;
                X++;
                grade[Y][X] = -6;
                grade[Y][X+1] = -6;
                grade[Y-1][X] = -6;
                grade[Y-1][X-1] = -6;
}

//MOVE J
void move_J_Down(){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-2][X] = 0;
                Y++;
                grade[Y][X] = -7;
                grade[Y][X-1] = -7;
                grade[Y-1][X] = -7;
                grade[Y-2][X] = -7;
}
void move_J_Left(){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-2][X] = 0;
                X--;
                grade[Y][X] = -7;
                grade[Y][X-1] = -7;
                grade[Y-1][X] = -7;
                grade[Y-2][X] = -7;
}
void move_J_Right(){
                grade[Y][X] = 0;
                grade[Y][X-1] = 0;
                grade[Y-1][X] = 0;
                grade[Y-2][X] = 0;
                X++;
                grade[Y][X] = -7;
                grade[Y][X-1] = -7;
                grade[Y-1][X] = -7;
                grade[Y-2][X] = -7;
}

bool can_Move_T_Down(){
    if((grade[Y + 1][X] != 0) && (grade[Y + 1][X] != id)){
        return false;
    }
    if((grade[Y + 1][X-1] != 0) && (grade[Y + 1][X-1] != id)){
        return false;
    }
    if((grade[Y + 1][1 + X] != 0) && (grade[Y + 1][1 + X] != id)){
        return false;
    }
    if((grade[Y][X] != 0) && (grade[Y][X] != id)){
        return false;
    }
    return true;
}