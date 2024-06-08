#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "raylib.h"

#define HEIGHT 600
#define WIDTH 600

#define GRID_HEIGHT 30
#define GRID_WIDTH 30

#define BACKGROUND WHITE

typedef enum {
    DEAD,
    ALIVE,
}State;

typedef struct {
    State state;
}Cell;

typedef enum {
    DRAW,
    PLAY,
    PAUSE,
    CLEAR,
}GameState;



Cell grid[GRID_HEIGHT][GRID_WIDTH] = {0};
Vector2 rectanglePosition = {0, 0};
int currentState;

void init_grid(){
    for(size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for(size_t j = 0; j < GRID_WIDTH; j++)
        {
            grid[i][j].state = DEAD;
        }
    }
}

void draw_mode() {
    BeginDrawing();
    DrawText("MODE: Draw", 10, 10, 20, LIGHTGRAY);
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        rectanglePosition = GetMousePosition();
        //Gives the 30x30 grid values
        int x = ((int)rectanglePosition.x >> 1) / 10;
        int y = ((int)rectanglePosition.y >> 1) / 10; 

        DrawRectangle(x * 20, y * 20, 20, 20, BLACK);
        grid[x][y].state = ALIVE;
    }
    EndDrawing();
}

void gen_next() {
    Cell new_grid[GRID_HEIGHT][GRID_WIDTH] = {0};
    for(size_t i = 0; i < GRID_HEIGHT; i++){
        for(size_t j = 0; j < GRID_WIDTH; j++) {
            new_grid[i][j] = grid[i][j];
            // Alive count of the 8 Cells sorrounding the central one
            int alive_count = 0;
            for(int k = -1; k <= 1; k++) {
                for(int l = -1; l <= 1; l++) {
                    if(k == 0 && l == 0) continue;
                    if(i + k <= GRID_HEIGHT && (int)i + k >= 0 && j + l <= GRID_WIDTH && (int)j + l >= 0) {
                        if(grid[i+k][j+l].state == ALIVE){
                            alive_count++;
                        }
                    }
                }
            }
            switch(alive_count) {
                case 0:
                    new_grid[i][j].state = DEAD;
                    break;
                case 1:
                    new_grid[i][j].state = DEAD;
                    break;
                case 2:
                case 3:
                    if(grid[i][j].state == DEAD && alive_count == 3) {
                        new_grid[i][j].state = ALIVE;
                    }
                    break;
                default:
                    new_grid[i][j].state = DEAD;
                    break;
            }
        }
    }
    for(size_t i = 0; i < GRID_HEIGHT; i++){
        for(size_t j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }

}

int draw_grid(){
    BeginDrawing();
    ClearBackground(BACKGROUND);
    DrawText("MODE: Play", 10, 10, 20, LIGHTGRAY);
    int alive_count = 0;
    for(size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for(size_t j = 0; j < GRID_WIDTH; j++)
        {
            if(grid[i][j].state == ALIVE) {
                alive_count++;
                DrawRectangle(i*20, j*20, 20, 20, BLACK);
            } 
        }
    }
    EndDrawing();
    return alive_count;
}

void play_mode() {
    if(draw_grid() != 0){
        draw_grid();
        gen_next();
    } else {
    ClearBackground(BACKGROUND);
    currentState = DRAW;
    }
}

void pause_mode() {
    draw_grid();
    draw_mode();
}

void clear_mode() {
    init_grid();
    ClearBackground(BACKGROUND);
    currentState = DRAW;
}

void modeswitch() {
    switch(currentState){
        case DRAW:{
            draw_mode();
        } break;
        case PLAY:{
            play_mode();
        }break;
        case PAUSE:{
            pause_mode();
        }break;
        case CLEAR:{
            clear_mode();
        }break;
        default: break;
    }
}


int main() {
    InitWindow(WIDTH, HEIGHT, "Conway's Game of Life"); 
    SetTargetFPS(10);
    BeginDrawing();
    ClearBackground(BACKGROUND);
    EndDrawing();
    init_grid();
    currentState = DRAW;
    while(!WindowShouldClose()) {
        switch(currentState){
            case DRAW:{
                if (IsKeyPressed(KEY_U)) {
                    currentState = PLAY;
                } else if(IsKeyPressed(KEY_O)) {
                    currentState = CLEAR;
                }
            } break;
            case PLAY:{
                if (IsKeyPressed(KEY_I)) {
                    currentState = PAUSE;
                } else if(IsKeyPressed(KEY_O)) {
                    currentState = CLEAR;
                }
            }  break;
            default: break;
        }
        modeswitch();
    }

    CloseWindow();

    return 0;
}
