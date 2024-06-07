
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

