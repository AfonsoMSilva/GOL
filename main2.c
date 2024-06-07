#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 51
#define WIDTH 51

#define CELL '#'
#define BACKGROUND '-'

typedef enum {
    DEAD,
    ALIVE,
}State;

typedef struct {
    State state;
}Cell;

Cell grid[HEIGHT][WIDTH] = {0};

void init_grid(){
    for(size_t i = 0; i < HEIGHT; i++)
    {
        for(size_t j = 0; j < WIDTH; j++)
        {
            grid[i][j].state = DEAD;
        }
    }
}
// Generates the next generation of Cells
void gen_next() {
    Cell new_grid[HEIGHT][WIDTH] = {0};
    for(size_t i = 0; i < HEIGHT; i++){
        for(size_t j = 0; j < WIDTH; j++) {
            new_grid[i][j] = grid[i][j];
            // Alive count of the 8 Cells sorrounding the central one
            int alive_count = 0;
            for(int k = -1; k <= 1; k++) {
                for(int l = -1; l <= 1; l++) {
                    if(k == 0 && l == 0) continue;
                    if(i + k <= HEIGHT && (int)i + k >= 0 && j + l <= WIDTH && (int)j + l >= 0) {
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
    for(size_t i = 0; i < HEIGHT; i++){
        for(size_t j = 0; j < WIDTH; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    
}

int print_grid(){
    int alive_count = 0;
    for(size_t i = 0; i < HEIGHT; i++)
    {
        for(size_t j = 0; j < WIDTH; j++)
        {
            if(grid[i][j].state == ALIVE) {
                alive_count++;
                printf("%c", CELL);
            } else {
                printf("%c", BACKGROUND);
            }
        }
        printf("\n");
    }
    return alive_count;
}

void init_pulsar() {
    //Top And Bottom (TOP LAYER)
    grid[20][22].state = ALIVE;
    grid[20][23].state = ALIVE;
    grid[20][24].state = ALIVE;
    grid[20][28].state = ALIVE;
    grid[20][29].state = ALIVE;
    grid[20][30].state = ALIVE;
    grid[25][22].state = ALIVE;
    grid[25][23].state = ALIVE;
    grid[25][24].state = ALIVE;
    grid[25][28].state = ALIVE;
    grid[25][29].state = ALIVE;
    grid[25][30].state = ALIVE;
    //Sides (TOP LAYER)
    grid[22][20].state= ALIVE;
    grid[23][20].state= ALIVE;
    grid[24][20].state= ALIVE;
    grid[22][25].state= ALIVE;
    grid[23][25].state= ALIVE;
    grid[24][25].state= ALIVE;
    grid[22][27].state= ALIVE;
    grid[23][27].state= ALIVE;
    grid[24][27].state= ALIVE;
    grid[22][32].state= ALIVE;
    grid[23][32].state= ALIVE;
    grid[24][32].state= ALIVE;
    //Top And Bottom (Bottom LAYER)
    grid[27][22].state = ALIVE;
    grid[27][23].state = ALIVE;
    grid[27][24].state = ALIVE;
    grid[27][28].state = ALIVE;
    grid[27][29].state = ALIVE;
    grid[27][30].state = ALIVE;
    grid[32][22].state = ALIVE;
    grid[32][23].state = ALIVE;
    grid[32][24].state = ALIVE;
    grid[32][28].state = ALIVE;
    grid[32][29].state = ALIVE;
    grid[32][30].state = ALIVE;
    //Sides (Bottom LAYER)
    grid[28][20].state= ALIVE;
    grid[29][20].state= ALIVE;
    grid[30][20].state= ALIVE;
    grid[28][25].state= ALIVE;
    grid[29][25].state= ALIVE;
    grid[30][25].state= ALIVE;
    grid[28][27].state= ALIVE;
    grid[29][27].state= ALIVE;
    grid[30][27].state= ALIVE;
    grid[28][32].state= ALIVE;
    grid[29][32].state= ALIVE;
    grid[30][32].state= ALIVE;
}

int main(){
    init_grid();
    init_pulsar();
    while(print_grid() != 0) {
        usleep(500 * 1000);
        system("clear");
        gen_next();
    }
}
