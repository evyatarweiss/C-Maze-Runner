#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"
const char *msg_normal[] = {"Press A/S/D/W to move, Q to quit","do not touch the ! its dangerous"};
const char *msg_bye[] = {"Goodbye! come back soon :)", "Goodbye!", "Hope you had fun, see you soon ;)"};
const char *msg_start[] = {"Welcome! Press A/S/D/W to move, Q to quit"};
const char *msg_unknown[] = {"Unknown key pressed", "Only A/S/D/W Buttons are allowed or Q for quiting"};
const char *msg_ouch[] = {"Ouch!", "Ohh you cannot go through a Hashtag", "Be careful you may be injured"};
const char *msg_win[] = {"Hell yeah! you win!", "You are the best! you win", "Congratulations! you defeated the maze"};
const char *msg_door[] = {"You used one key to open the door!"};
const char *msg_not[] = {"You dont have any keys to open the door"};
const char *msg_port[] = {"Wheee!"};
const char *msg_color[] = {COLOR_LT_CYAN, COLOR_LT_GRAY, COLOR_LT_GREEN, COLOR_LT_PURPLE, COLOR_LT_RED,COLOR_PURPLE,COLOR_WHITE,COLOR_YELLOW, COLOR_BLUE, COLOR_BROWN, COLOR_CYAN, COLOR_GRAY, COLOR_GREEN};

int main(int argc, char* argv[])
{
    //please start from peace_and_love.txt maze
    // dont touch the ! ;)
    // reccomended to listen to this song https://www.youtube.com/watch?v=ot6ns6VB4Dc
    // than you can play in the other mazes
    int counter;
    if(argc == 1) 
    {
        printf("No maze was given\n");
        return 0; 
    }
    if(argc > 2) 
    { 
        printf("Too many arguments\n"); 
    }
    char *testvar = argv[1];
    set_terminal(true);
    struct maze* start = NULL;
    start = read_maze(testvar,start);
    if(start != NULL) {
        handle_input(*start);
    }
    if(start->new_maze->new == true){
        maze_end(start);
        struct maze* start = NULL;
        start = read_maze("bobmarley.txt",start);
        if(start != NULL) {
            handle_input(*start);
        }
        if(start->new_maze->new == true){
            maze_end(start);
            struct maze* start = NULL;
            start = read_maze("marihuana.txt",start);
            if(start != NULL) {
                handle_input(*start);
        }
    }
    }    

    maze_end(start);
    set_terminal(false);
    return 0;
}

struct maze* maze_init(unsigned int player_loc_x, unsigned int player_loc_y, const char *message, unsigned int rows, unsigned int cols, unsigned int target_x, unsigned int target_y,unsigned int target_x2, unsigned int target_y2, bool game_over, bool is_tile) 
{
    struct maze *start = NULL;
    if (NULL == (start = (struct maze *)malloc(sizeof(struct maze)))) {
        printf("Error! Allocation failed\n");
        exit(1);
    }
    if (NULL == (start->player = malloc(sizeof(struct location)))) {
        free(start);
        printf("Error! Allocation failed\n");
        exit(1);
    }
    if (NULL == (start->tales = malloc(rows * sizeof(char *)))) {
        free(start->player);
        free(start);
        printf("Error! Allocation failed\n");
        exit(1);
    }
    if (NULL == (start->target = malloc(sizeof(struct target)))) {
        free(start->player);
        free(start);
        free(start->tales);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->target2 = malloc(sizeof(struct target)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->tales);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->message = malloc(sizeof(char)*50))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->tales);
        free(start->target2);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port01 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port02 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port11 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port02);
        free(start->port01);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port12 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port21 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port12);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port22 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port31 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);        
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port32 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);      
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port41 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);        
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port42 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);    
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port51 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);      
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port52 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);       
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port61 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);      
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port62 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);       
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port71 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);
        free(start->port62);        
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port72 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);
        free(start->port62);
        free(start->port71);        
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port81 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);
        free(start->port62);
        free(start->port71);
        free(start->port72);

        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port82 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port12);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);
        free(start->port62);
        free(start->port71);
        free(start->port72);
        free(start->port81);       
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port91 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port12);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);
        free(start->port62);
        free(start->port71);
        free(start->port72);
        free(start->port81);
        free(start->port82);                                     
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->port92 = malloc(sizeof(struct location)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port12);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);
        free(start->port62);
        free(start->port71);
        free(start->port72);
        free(start->port81);
        free(start->port82);
        free(start->port91);        
        printf("Error! Allocation failed\n");
        exit(1);
    }
        if (NULL == (start->new_maze = malloc(sizeof(struct new)))) {
        free(start->target);
        free(start->player);
        free(start);
        free(start->message);
        free(start->tales);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port12);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);
        free(start->port62);
        free(start->port71);
        free(start->port72);
        free(start->port81);
        free(start->port82);
        free(start->port91);
        free(start->port92);        
        printf("Error! Allocation failed\n");
        exit(1);
    }    
    for (int i = 0; i < rows; i++) {
        if (NULL == (start->tales[i] = malloc(cols * sizeof(char)))) {
            free(start->tales);
            free(start->port01);
            free(start->port02);
            free(start->port11);
            free(start->port12);
            free(start->port21);
            free(start->port22);
            free(start->port31);
            free(start->port32);
            free(start->port41);
            free(start->port42);
            free(start->port51);
            free(start->port52);
            free(start->port61);
            free(start->port62);
            free(start->port71);
            free(start->port72);
            free(start->port81);
            free(start->port82);
            free(start->port91);
            free(start->port92);          
            free(start->target);
            free(start->target2);
            free(start->player);
            free(start->message);
            free(start->new_maze);
            free(start);
            printf("Error! Allocation failed\n");
            exit(1);
        }
    }
    start->player->col = player_loc_x;
    start->player->row = player_loc_y;
    start->target->col = target_x;
    start->target->row = target_y;
    start->target->visited = false;
    start->target2->col = target_x2;
    start->target2->row = target_y2;
    start->target2->visited = false;
    start->MAZE_COLS = cols;
    start->MAZE_ROWS = rows;
    strcpy(start->message,message);
    start->game_over = game_over;
    start->is_tail = is_tile;
    start->new_maze->new = false;
    start->keys = 0;
    return start;
}
void maze_end(struct maze* start)
{
    if (start != NULL){
        for (int i = 0; i < start->MAZE_ROWS; i++) {
            free(start->tales[i]);
        }
        free(start->tales);
        free(start->player);
        free(start->target);
        free(start->target2);
        free(start->port01);
        free(start->port02);
        free(start->port11);
        free(start->port12);
        free(start->port21);
        free(start->port22);
        free(start->port31);
        free(start->port32);
        free(start->port41);
        free(start->port42);
        free(start->port51);
        free(start->port52);
        free(start->port61);
        free(start->port62);
        free(start->port71);
        free(start->port72);
        free(start->port81);
        free(start->port82);
        free(start->port91);
        free(start->port92);  
        free(start->new_maze);
        free(start);
    }
}
void handle_input(struct maze start)
{
    print_maze(&start);
    do {
        const char *message = MSG_NORMAL;
        start.message = MSG_NORMAL;

        // get user input
        int key = getchar();
        switch(key) {
            case EOF:
            case 'q':
            case 'Q':   // exit game
                start.message = MSG_BYE;
                start.game_over = true;
                break;
            case 'a':
            case 'A':   // go left
                if (start.player->col > 0) {
                    if (start.tales[start.player->row][start.player->col - 1] == '#' || start.tales[start.player->row][start.player->col - 1] == '|' || start.tales[start.player->row][start.player->col - 1] == '>' || start.tales[start.player->row][start.player->col - 1] == '^' || start.tales[start.player->row][start.player->col - 1] == 'v') {
                        start.message = MSG_OUCH;
                    } else if(start.tales[start.player->row][start.player->col - 1] == '+'){
                        if(start.keys == 0){
                            start.message = MSG_NOT;
                        } else {
                            start.message = MSG_DOOR;
                            start.player->col--;
                        }
                    }else if(start.tales[start.player->row][start.player->col - 1] == '0'){
                        if((start.player->row == start.port01->row) && (start.player->col - 1 == start.port01->col)){
                            start.player->col = start.port02->col;
                            start.player->row = start.port02->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port01->col;
                            start.player->row = start.port01->row;
                            start.message = MSG_PORT;
                        }
                    }else if(start.tales[start.player->row][start.player->col - 1] == '2'){
                        if((start.player->row == start.port21->row) && (start.player->col - 1 == start.port21->col)){
                            start.player->col = start.port22->col;
                            start.player->row = start.port22->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port21->col;
                            start.player->row = start.port21->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col - 1] == '3'){
                        if((start.player->row == start.port31->row) && (start.player->col - 1 == start.port31->col)){
                            start.player->col = start.port32->col;
                            start.player->row = start.port32->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port31->col;
                            start.player->row = start.port31->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col - 1] == '4'){
                        if((start.player->row == start.port41->row) && (start.player->col - 1 == start.port41->col)){
                            start.player->col = start.port42->col;
                            start.player->row = start.port42->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port41->col;
                            start.player->row = start.port41->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col - 1] == '5'){
                        if((start.player->row == start.port51->row) && (start.player->col - 1 == start.port51->col)){
                            start.player->col = start.port52->col;
                            start.player->row = start.port52->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port51->col;
                            start.player->row = start.port51->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col - 1] == '6'){
                        if((start.player->row == start.port61->row) && (start.player->col - 1 == start.port61->col)){
                            start.player->col = start.port62->col;
                            start.player->row = start.port62->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port61->col;
                            start.player->row = start.port61->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col - 1] == '7'){
                        if((start.player->row == start.port71->row) && (start.player->col - 1 == start.port71->col)){
                            start.player->col = start.port72->col;
                            start.player->row = start.port72->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port71->col;
                            start.player->row = start.port71->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col - 1] == '8'){
                        if((start.player->row == start.port81->row) && (start.player->col - 1 == start.port81->col)){
                            start.player->col = start.port82->col;
                            start.player->row = start.port82->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port81->col;
                            start.player->row = start.port81->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col - 1] == '9'){
                        if((start.player->row == start.port91->row) && (start.player->col - 1 == start.port91->col)){
                            start.player->col = start.port92->col;
                            start.player->row = start.port92->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port91->col;
                            start.player->row = start.port91->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col - 1] == '1'){
                        if((start.player->row == start.port11->row) && (start.player->col - 1 == start.port11->col)){
                            start.player->col = start.port12->col;
                            start.player->row = start.port12->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port11->col;
                            start.player->row = start.port11->row;
                            start.message = MSG_PORT;
                        }
                    
                    } else {
                        if (start.tales[start.player->row][start.player->col - 1] == '<'){
                            start.is_tail = true;
                            start.player->col--;
                        }
                        else if((start.player->row == start.target->row) && (start.player->col - 1 == start.target->col)){
                            if(start.target2->visited){
                                start.player->col--;
                                start.message = MSG_WIN;
                                start.game_over = true;
                            } else {
                                start.target->visited = true;
                                start.player->col--;
                            }
                        }
                        else if((start.player->row == start.target2->row) && (start.player->col - 1 == start.target2->col)){
                            if(start.target->visited){
                                start.player->col--;
                                start.message = MSG_WIN;
                                start.game_over = true;
                            } else {
                                start.target2->visited = true;
                                start.player->col--;
                            }
                        } else if (start.tales[start.player->row][start.player->col - 1] == '-'){
                            start.is_tail = true;
                            start.player->col--;
                        } else if (start.tales[start.player->row][start.player->col - 1] == '!'){
                            start.new_maze->new = true;
                            start.game_over = true;
                        } else {
                            start.player->col--;
                        }                       
                    }
                } else {
                    start.message = MSG_OUCH;
                }
                break;
            case 'd':
            case 'D':   // go right
                if (start.player->col < start.MAZE_COLS - 1) {
                    if (start.tales[start.player->row][start.player->col + 1] == '#' || start.tales[start.player->row][start.player->col + 1] == '|' || start.tales[start.player->row][start.player->col + 1] == 'v' || start.tales[start.player->row][start.player->col + 1] == '^' || start.tales[start.player->row][start.player->col + 1] == '<') {
                        start.message = MSG_OUCH;
                    } else if(start.tales[start.player->row][start.player->col + 1] == '+'){
                        if(start.keys == 0){
                            start.message = MSG_NOT;
                        } else {
                            start.player->col++;
                            start.message = MSG_DOOR;
                        }                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '0'){
                        if((start.player->row == start.port01->row) && (start.player->col + 1 == start.port01->col)){
                            start.player->col = start.port02->col;
                            start.player->row = start.port02->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port01->col;
                            start.player->row = start.port01->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '1'){
                        if((start.player->row == start.port11->row) && (start.player->col + 1 == start.port11->col)){
                            start.player->col = start.port12->col;
                            start.player->row = start.port12->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port11->col;
                            start.player->row = start.port11->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '2'){
                        if((start.player->row == start.port21->row) && (start.player->col + 1 == start.port21->col)){
                            start.player->col = start.port22->col;
                            start.player->row = start.port22->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port21->col;
                            start.player->row = start.port21->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '3'){
                        if((start.player->row == start.port31->row) && (start.player->col + 1 == start.port31->col)){
                            start.player->col = start.port32->col;
                            start.player->row = start.port32->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port31->col;
                            start.player->row = start.port31->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '4'){
                        if((start.player->row == start.port41->row) && (start.player->col + 1 == start.port41->col)){
                            start.player->col = start.port42->col;
                            start.player->row = start.port42->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port41->col;
                            start.player->row = start.port41->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '5'){
                        if((start.player->row == start.port51->row) && (start.player->col + 1 == start.port51->col)){
                            start.player->col = start.port52->col;
                            start.player->row = start.port52->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port51->col;
                            start.player->row = start.port51->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '6'){
                        if((start.player->row == start.port61->row) && (start.player->col + 1 == start.port61->col)){
                            start.player->col = start.port62->col;
                            start.player->row = start.port62->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port61->col;
                            start.player->row = start.port61->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '7'){
                        if((start.player->row == start.port71->row) && (start.player->col + 1 == start.port71->col)){
                            start.player->col = start.port72->col;
                            start.player->row = start.port72->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port71->col;
                            start.player->row = start.port71->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '8'){
                        if((start.player->row == start.port81->row) && (start.player->col + 1 == start.port81->col)){
                            start.player->col = start.port82->col;
                            start.player->row = start.port82->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port81->col;
                            start.player->row = start.port81->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row][start.player->col + 1] == '9'){
                        if((start.player->row == start.port91->row) && (start.player->col + 1 == start.port91->col)){
                            start.player->col = start.port92->col;
                            start.player->row = start.port92->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port91->col;
                            start.player->row = start.port91->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else {
                        if (start.tales[start.player->row][start.player->col + 1] == '>'){
                            start.is_tail = true;
                            start.player->col++;
                        }                   
                        else if((start.player->row == start.target->row) && (start.player->col + 1 == start.target->col)){
                            if(start.target2->visited){
                                start.player->col++;
                                start.message = MSG_WIN;
                                start.game_over = true;
                            } else {
                                start.target->visited = true;
                                start.player->col++;
                            }
                        }
                        else if((start.player->row == start.target2->row) && (start.player->col + 1 == start.target2->col)){
                            if(start.target->visited){
                                start.player->col++;
                                start.message = MSG_WIN;
                                start.game_over = true;
                            } else {
                                start.target2->visited = true;
                                start.player->col++;
                            }
                        }
                        else if (start.tales[start.player->row][start.player->col + 1] == '-'){
                            start.is_tail = true;
                            start.player->col++;
                        } else if (start.tales[start.player->row][start.player->col + 1] == '!'){
                            start.new_maze->new = true;
                            start.game_over = true;
                        }else{
                          start.player->col++;  
                        }                             
                    }
                } else {
                    start.message = MSG_OUCH;
                }
                break;
            case 'w':
            case 'W':   // go up
                if (start.player->row > 0) {
                    if (start.tales[start.player->row - 1][start.player->col] == '#' || start.tales[start.player->row - 1][start.player->col] == '-' || start.tales[start.player->row - 1][start.player->col] == '>' || start.tales[start.player->row - 1][start.player->col] == '<' || start.tales[start.player->row - 1][start.player->col] == 'v') {
                        start.message = MSG_OUCH;
                    } else if(start.tales[start.player->row - 1][start.player->col] == '+'){
                        if(start.keys == 0){
                            start.message = MSG_NOT;
                        } else {
                            start.player->row--;
                            start.message = MSG_DOOR;
                        }                     
                    }else if(start.tales[start.player->row - 1][start.player->col] == '0'){
                        if((start.player->row - 1 == start.port01->row) && (start.player->col == start.port01->col)){
                            start.player->col = start.port02->col;
                            start.player->row = start.port02->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port01->col;
                            start.player->row = start.port01->row;
                            start.message = MSG_PORT;
                        }
                    }else if(start.tales[start.player->row - 1][start.player->col] == '1'){
                        if((start.player->row - 1 == start.port11->row) && (start.player->col == start.port11->col)){
                            start.player->col = start.port12->col;
                            start.player->row = start.port12->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port11->col;
                            start.player->row = start.port11->row;
                            start.message = MSG_PORT;
                        } 
                    }else if(start.tales[start.player->row - 1][start.player->col] == '2'){
                        if((start.player->row - 1 == start.port21->row) && (start.player->col == start.port21->col)){
                            start.player->col = start.port22->col;
                            start.player->row = start.port22->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port21->col;
                            start.player->row = start.port21->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row - 1 ][start.player->col] == '3'){
                        if((start.player->row - 1 == start.port31->row) && (start.player->col== start.port31->col)){
                            start.player->col = start.port32->col;
                            start.player->row = start.port32->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port31->col;
                            start.player->row = start.port31->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row - 1 ][start.player->col] == '4'){
                        if((start.player->row - 1 == start.port41->row) && (start.player->col== start.port41->col)){
                            start.player->col = start.port42->col;
                            start.player->row = start.port42->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port41->col;
                            start.player->row = start.port41->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row - 1 ][start.player->col] == '5'){
                        if((start.player->row - 1 == start.port51->row) && (start.player->col== start.port51->col)){
                            start.player->col = start.port52->col;
                            start.player->row = start.port52->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port51->col;
                            start.player->row = start.port51->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row - 1 ][start.player->col] == '6'){
                        if((start.player->row - 1 == start.port61->row) && (start.player->col== start.port61->col)){
                            start.player->col = start.port62->col;
                            start.player->row = start.port62->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port61->col;
                            start.player->row = start.port61->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row - 1 ][start.player->col] == '7'){
                        if((start.player->row - 1 == start.port71->row) && (start.player->col== start.port71->col)){
                            start.player->col = start.port72->col;
                            start.player->row = start.port72->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port71->col;
                            start.player->row = start.port71->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row - 1 ][start.player->col] == '8'){
                        if((start.player->row - 1  == start.port81->row) && (start.player->col == start.port81->col)){
                            start.player->col = start.port82->col;
                            start.player->row = start.port82->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port81->col;
                            start.player->row = start.port81->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row - 1 ][start.player->col] == '9'){
                        if((start.player->row - 1 == start.port91->row) && (start.player->col == start.port91->col)){
                            start.player->col = start.port92->col;
                            start.player->row = start.port92->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port91->col;
                            start.player->row = start.port91->row;
                            start.message = MSG_PORT;
                        }
                    
                    }
                    else {
                        if (start.tales[start.player->row - 1][start.player->col] == '^' || start.tales[start.player->row - 1][start.player->col] == '|'){
                            start.is_tail = true;
                            start.player->row--;
                        }                
                        else if((start.player->row - 1 == start.target->row) && (start.player->col == start.target->col)){
                            if(start.target2->visited){
                                start.player->row--;
                                start.message = MSG_WIN;
                                start.game_over = true;
                            } else {
                                start.target->visited = true;
                                start.player->row--;
                            }
                        }
                        else if((start.player->row - 1 == start.target2->row) && (start.player->col == start.target2->col)){
                            if(start.target->visited){
                                start.player->row--;
                                start.message = MSG_WIN;
                                start.game_over = true;
                            } else {
                                start.target2->visited = true;
                                start.player->row--;
                            }
                        } else if (start.tales[start.player->row - 1][start.player->col] == '!'){
                            start.new_maze->new = true;
                            start.game_over = true;
                        
                        }else {
                            start.player->row--;
                        }                  
                    }                    
                } else {
                    start.message = MSG_OUCH;
                }
                break;
            case 's':
            case 'S':   // go down
                if (start.player->row < start.MAZE_ROWS - 1) {
                    if (start.tales[start.player->row + 1][start.player->col] == '#' || start.tales[start.player->row + 1][start.player->col] == '-' || start.tales[start.player->row + 1][start.player->col] == '>' || start.tales[start.player->row + 1][start.player->col] == '<' || start.tales[start.player->row + 1][start.player->col] == '^') {
                        start.message = MSG_OUCH;
                    } else if(start.tales[start.player->row + 1][start.player->col] == '+'){
                        if(start.keys == 0){
                            start.message = MSG_NOT;
                        } else {
                            start.player->row++;
                            start.message = MSG_DOOR;
                        }                    
                    }else if(start.tales[start.player->row + 1][start.player->col] == '0'){
                        if((start.player->row + 1 == start.port01->row) && (start.player->col== start.port01->col)){
                            start.player->col = start.port02->col;
                            start.player->row = start.port02->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port01->col;
                            start.player->row = start.port01->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row + 1][start.player->col] == '1'){
                        if((start.player->row + 1 == start.port11->row) && (start.player->col == start.port11->col)){
                            start.player->col = start.port12->col;
                            start.player->row = start.port12->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port11->col;
                            start.player->row = start.port11->row;
                            start.message = MSG_PORT;
                        }
                    } else if(start.tales[start.player->row + 1][start.player->col] == '2'){
                        if((start.player->row + 1 == start.port21->row) && (start.player->col == start.port21->col)){
                            start.player->col = start.port22->col;
                            start.player->row = start.port22->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port21->col;
                            start.player->row = start.port21->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row + 1 ][start.player->col] == '3'){
                        if((start.player->row + 1 == start.port31->row) && (start.player->col== start.port31->col)){
                            start.player->col = start.port32->col;
                            start.player->row = start.port32->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port31->col;
                            start.player->row = start.port31->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row + 1 ][start.player->col] == '4'){
                        if((start.player->row + 1 == start.port41->row) && (start.player->col== start.port41->col)){
                            start.player->col = start.port42->col;
                            start.player->row = start.port42->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port41->col;
                            start.player->row = start.port41->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row + 1 ][start.player->col] == '5'){
                        if((start.player->row + 1 == start.port51->row) && (start.player->col== start.port51->col)){
                            start.player->col = start.port52->col;
                            start.player->row = start.port52->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port51->col;
                            start.player->row = start.port51->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row + 1 ][start.player->col] == '6'){
                        if((start.player->row + 1 == start.port61->row) && (start.player->col== start.port61->col)){
                            start.player->col = start.port62->col;
                            start.player->row = start.port62->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port61->col;
                            start.player->row = start.port61->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row + 1 ][start.player->col] == '7'){
                        if((start.player->row + 1 == start.port71->row) && (start.player->col== start.port71->col)){
                            start.player->col = start.port72->col;
                            start.player->row = start.port72->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port71->col;
                            start.player->row = start.port71->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row + 1 ][start.player->col] == '8'){
                        if((start.player->row + 1  == start.port81->row) && (start.player->col == start.port81->col)){
                            start.player->col = start.port82->col;
                            start.player->row = start.port82->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port11->col;
                            start.player->row = start.port11->row;
                            start.message = MSG_PORT;
                        }
                    
                    }else if(start.tales[start.player->row + 1 ][start.player->col] == '9'){
                        if((start.player->row + 1 == start.port91->row) && (start.player->col == start.port91->col)){
                            start.player->col = start.port92->col;
                            start.player->row = start.port92->row;
                            start.message = MSG_PORT;
                        }else{
                            start.player->col = start.port91->col;
                            start.player->row = start.port91->row;
                            start.message = MSG_PORT;
                        }
                    
                    } else {
                    
                        if (start.tales[start.player->row + 1][start.player->col] == 'v' || start.tales[start.player->row + 1][start.player->col] == '|'){
                            start.is_tail = true;
                            start.player->row++;
                        }   
                        else if((start.player->row + 1 == start.target->row) && (start.player->col == start.target->col)){
                            if(start.target2->visited){
                                start.message = MSG_WIN;
                                start.game_over = true;
                            } else {
                                start.target->visited = true;
                                start.player->row++;
                            }
                        }
                        else if((start.player->row + 1 == start.target2->row) && (start.player->col == start.target2->col)){
                            if(start.target->visited){
                                start.message = MSG_WIN;
                                start.game_over = true;
                            } else {
                                start.target2->visited = true;
                                start.player->row++;
                            }
                        } else if (start.tales[start.player->row + 1][start.player->col] == '!'){
                            start.new_maze->new = true;
                            start.game_over = true; 
                        }else {
                            start.player->row++;
                        }                        
                    }                    
                } else {
                    start.message = MSG_OUCH;
                }
                break;
            default:
                start.message = MSG_UNKNOWN;
        }
        // print maze
        print_maze(&start);
    } while (!start.game_over);
}
#define puts_no_newline(s) fputs(s, stdout)
void print_tile(char symbol, char* color)
{
    char string[30] = {0};
    strcpy(string, color);
    strcat(string, &symbol);
    strcat(string, COLOR_OFF);
    printf("%s",string);
}
bool ouch(int i, int j ,int row, int col)
{
    if ((i == row) && (j == col)) {
        return true;
    } else {
        return false;
    }
}
void print_maze(struct maze *current)
{
    static unsigned frame_num; // this variable retains its value between calls
    // clear terminal 
    puts_no_newline(CLEAR_SCREEN);
    // print frame number and message
    strlen(current->message);
    printf("%-*.*skeys:%d%4d\n", current->MAZE_COLS - 8, current->MAZE_COLS - 8, current->message,current->keys, frame_num++);
    // print header row
    print_wall(current);
    putchar('\n');
    // print maze rows (including player)
    for (int i = 0; i < current->MAZE_ROWS; i++) {
        print_tile('#',MSG_COLOR);
        for (int j = 0; j < current->MAZE_COLS; j++)
            if (ouch(i, j, current->player->row,current->player->col) || ouch(i, j, current->target->row, current->target->col) || ouch(i, j, current->target2->row, current->target2->col)){
                if (ouch(i, j, current->player->row, current->player->col) && ouch(i, j, current->target->row, current->target->col)){
                    puts_no_newline(S_PLAYER);
                } else if (ouch(i,j,current->target->row,current->target->col)) {
                    if(current->target->visited){
                        print_tile('$',COLOR_LT_PURPLE);
                    } else {    
                        puts_no_newline(S_TARGET);
                    }   
                } else if (ouch(i,j,current->target2->row,current->target2->col)) {
                    if(current->target2->visited){
                        print_tile('$',COLOR_LT_PURPLE);
                    } else {
                        puts_no_newline(S_TARGET);
                    }
                } else if(current->is_tail == true){
                    current->is_tail = false;
                    print_tile(current->tales[i][j], COLOR_BLUE);
                } else if (current->tales[i][j] == '+') {
                    puts_no_newline(S_PLAYER);
                    current->tales[i][j] = ' ';
                    current->keys--; 
                } else if (current->tales[i][j] == '&') {
                    current->keys++;
                    puts_no_newline(S_PLAYER);
                    current->tales[i][j] = ' '; 
                } else {
                    puts_no_newline(S_PLAYER);
                }  
            } else {
                if(current->tales[i][j] == '#' || current->tales[i][j] == '|' || current->tales[i][j] == '-' || current->tales[i][j] == 'v'|| current->tales[i][j] == '^'|| current->tales[i][j] == '&'|| current->tales[i][j] == '+' || current->tales[i][j] == '<'|| current->tales[i][j] == '>' || current->tales[i][j] == '0' || current->tales[i][j] == '1' || current->tales[i][j] == '2' || current->tales[i][j] == '3' || current->tales[i][j] == '4' || current->tales[i][j] == '5' || current->tales[i][j] == '6' || current->tales[i][j] == '7' || current->tales[i][j] == '8' || current->tales[i][j] == '9' || current->tales[i][j] == '!'){
                    if (ouch(i, j, current->player->row, current->player->col)){
                        print_tile(current->tales[i][j], COLOR_BLUE);    
                    } else {
                    print_tile(current->tales[i][j], COLOR_GRAY);
                    }   
                } else {
                puts_no_newline(S_FLOOR);
                }
            }
        print_tile('#',MSG_COLOR);
        putchar('\n');
    }
    // print footer row
    print_wall2(current);
    putchar('\n');
}
void print_wall(struct maze *current)
{
    for (int j = 0; j < current->MAZE_COLS + 2; j++)
        print_tile('#',MSG_COLOR);
}
void print_wall2(struct maze *current)
{
    for (int j = 0; j < current->MAZE_COLS + 2; j++)
        print_tile('#',MSG_COLOR);
}

struct maze* read_maze(const char *input_file, struct maze* the_maze)
{
    FILE* read = fopen(input_file, "r");
    if (NULL == read) {
        return NULL;
    }
    char message[256];
    char rows_cols[50]={0}, ch;
    fgets(message, 256, read);
    fgets(rows_cols, 50, read); 
    strtok (message,"\r");
    strtok (message,"\n");
    int counter_player = 0, counter_target = 0, col, row,port_zero = 0 ,port_one = 0;
    int port_two = 0, port_three = 0, port_four = 0, port_five = 0, port_six = 0, port_seven = 0, port_eight = 0 ,port_nine = 0;
    bool game_over = false,is_tail = false;
    int i,j;
    char * pch;
    pch = strtok (rows_cols," \n\r");
    row = stringToint(pch);
    pch = strtok (NULL," \n\r");
    col = stringToint(pch);



    the_maze = maze_init(row-1, col-1, message, row, col, 1, 1, 2, 2, false, false);

    for (int i = 0; i < row; i++) {
        char message[256] = {0};
        fgets(message, col+2, read);
        ch = fgetc(read);
        strtok(message, "\r");
        for (int j = 0; j < col; j++) {
            ch = message[j];
            switch (ch)
            {
            case ('$'):
                if (counter_target > 0) {
                    the_maze->target2->row = i;
                    the_maze->target2->col = j;
                    counter_target += 1;                    /* code */
                } else {
                    the_maze->target->row = i;
                    the_maze->target->col = j;
                    counter_target += 1;
                }
                if (counter_target > 2)
                {
                    printf("Invalid format");
                    return NULL;
                }
                continue;
            case ('@'):
                the_maze->player->row = i;
                the_maze->player->col = j;
                counter_player += 1;
                if(counter_player > 1) {
                    printf("Invalid format");
                    return NULL;
                }
                continue;
            case ('0'):
                if(port_zero == 0){
                    the_maze->port01->row = i;
                    the_maze->port01->col = j;
                    the_maze->tales[i][j] = '0';
                    port_zero++;
                    continue;
                } else if(port_zero == 1){
                    the_maze->port02->row = i;
                    the_maze->port02->col = j;
                    the_maze->tales[i][j] = '0'; 
                    port_zero++;
                    continue;                   
                }
            case ('1'):
                if(port_one == 0){
                    the_maze->port11->row = i;
                    the_maze->port11->col = j;
                    the_maze->tales[i][j] = '1';
                    port_one++;
                    continue;
                } else if(port_one == 1){
                    the_maze->port12->row = i;
                    the_maze->port12->col = j;
                    the_maze->tales[i][j] = '1';
                    port_one++;
                    continue;                    
                }
            case ('2'):
                if(port_two == 0){
                    the_maze->port21->row = i;
                    the_maze->port21->col = j;
                    the_maze->tales[i][j] = '2';
                    port_two++;
                    continue;
                } else if(port_two == 1){
                    the_maze->port22->row = i;
                    the_maze->port22->col = j;
                    the_maze->tales[i][j] = '2';
                    port_two++;
                    continue;                    
                }
            case ('3'):
                if(port_one == 0){
                    the_maze->port31->row = i;
                    the_maze->port31->col = j;
                    the_maze->tales[i][j] = '3';
                    port_three++;
                    continue;
                } else if(port_one == 1){
                    the_maze->port32->row = i;
                    the_maze->port32->col = j;
                    the_maze->tales[i][j] = '3';
                    port_three++;
                    continue;                    
                }
            case ('4'):
                if(port_four == 0){
                    the_maze->port41->row = i;
                    the_maze->port41->col = j;
                    the_maze->tales[i][j] = '4';
                    port_four++;
                    continue;
                } else if(port_four == 1){
                    the_maze->port42->row = i;
                    the_maze->port42->col = j;
                    the_maze->tales[i][j] = '4';
                    port_four++;
                    continue;                    
                }
            case ('5'):
                if(port_five == 0){
                    the_maze->port51->row = i;
                    the_maze->port51->col = j;
                    the_maze->tales[i][j] = '5';
                    port_five++;
                    continue;
                } else if(port_five == 1){
                    the_maze->port52->row = i;
                    the_maze->port52->col = j;
                    the_maze->tales[i][j] = '5';
                    port_five++;
                    continue;                    
                }
            case ('6'):
                if(port_six == 0){
                    the_maze->port61->row = i;
                    the_maze->port61->col = j;
                    the_maze->tales[i][j] = '6';
                    port_six++;
                    continue;
                } else if(port_six == 1){
                    the_maze->port62->row = i;
                    the_maze->port62->col = j;
                    the_maze->tales[i][j] = '6';
                    port_six++;
                    continue;                    
                }
            case ('7'):
                if(port_seven == 0){
                    the_maze->port71->row = i;
                    the_maze->port71->col = j;
                    the_maze->tales[i][j] = '7';
                    port_seven++;
                    continue;
                } else if(port_seven == 1){
                    the_maze->port72->row = i;
                    the_maze->port72->col = j;
                    the_maze->tales[i][j] = '7';
                    port_seven++;
                    continue;                    
                } 
            case ('8'):
                if(port_eight == 0){
                    the_maze->port81->row = i;
                    the_maze->port81->col = j;
                    the_maze->tales[i][j] = '8';
                    port_eight++;
                    continue;
                } else if(port_eight == 1){
                    the_maze->port82->row = i;
                    the_maze->port82->col = j;
                    the_maze->tales[i][j] = '8';
                    port_eight++;
                    continue;                    
                }
            case ('9'):
                if(port_nine == 0){
                    the_maze->port91->row = i;
                    the_maze->port91->col = j;
                    the_maze->tales[i][j] = '9';
                    port_nine++;
                    continue;
                } else if(port_nine == 1){
                    the_maze->port92->row = i;
                    the_maze->port92->col = j;
                    the_maze->tales[i][j] = '9';
                    port_nine++;
                    continue;                    
                }                                                                
            case('#'):
                the_maze->tales[i][j] = ch;
                continue;
            case(' '):
                the_maze->tales[i][j] = ch;
                continue;
            case('>'):
                the_maze->tales[i][j] = ch;
                continue;
            case('<'):
                the_maze->tales[i][j] = ch;
                continue;
            case('^'):
                the_maze->tales[i][j] = ch;
                continue;
            case('v'):
                the_maze->tales[i][j] = ch;
                continue;
            case('|'):
                the_maze->tales[i][j] = ch;
                continue;
            case('-'):
                the_maze->tales[i][j] = ch;
                continue;
            case('&'):
                the_maze->tales[i][j] = ch;
                continue;
            case('+'):
                the_maze->tales[i][j] = ch;
                continue;
            case('!'):
                the_maze->tales[i][j] = ch;
                continue;                        
            default:
                printf("Invalid tile type");
                return NULL;
            }     
        }
    }
    fclose(read);
    return the_maze;
}
int stringToint(char* string)
{
    int digit, j = 1, m = 0, i;
    for (i = strlen(string) - 1; i >= 0; i--)
    {
        digit = string[i];
        digit = digit - 48;
        m = m + (digit * j);
        j = j * 10;
    }
    return m;
}