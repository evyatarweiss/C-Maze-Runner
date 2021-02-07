#include <stdbool.h>


#define MSG_NORMAL  msg_normal[rand() % (sizeof(msg_normal) / sizeof(msg_normal[0]))]
#define MSG_BYE msg_bye[rand() % (sizeof(msg_bye) / sizeof(msg_bye[0]))]
#define MSG_START   msg_start[rand() % (sizeof(msg_start) / sizeof(msg_start[0]))]
#define MSG_UNKNOWN msg_unknown[rand() % (sizeof(msg_unknown) / sizeof(msg_unknown[0]))]
#define MSG_OUCH msg_ouch[rand() % (sizeof(msg_ouch) / sizeof(msg_ouch[0]))]
#define MSG_WIN msg_win[rand() % (sizeof(msg_win) / sizeof(msg_win[0]))]
#define MSG_DOOR msg_door[rand() % (sizeof(msg_door) / sizeof(msg_door[0]))]
#define MSG_NOT msg_not[rand() % (sizeof(msg_not) / sizeof(msg_not[0]))]
#define MSG_PORT msg_port[rand() % (sizeof(msg_port) / sizeof(msg_port[0]))]
#define MSG_COLOR msg_color[rand() % (sizeof(msg_color) / sizeof(msg_color[0]))]

struct maze{
    struct location *player;
    char* message;
    unsigned int MAZE_ROWS;
    unsigned int MAZE_COLS;
    bool game_over;
    struct target *target;
    struct target *target2;
    char** tales;
    bool is_tail;
    int keys;
    struct location *port01;
    struct location *port02;
    struct location *port11;
    struct location *port12;
    struct location *port21;
    struct location *port22;
    struct location *port31;
    struct location *port32;
    struct location *port41;
    struct location *port42;
    struct location *port51;
    struct location *port52;
    struct location *port61;
    struct location *port62;
    struct location *port71;
    struct location *port72;
    struct location *port81;
    struct location *port82;
    struct location *port91;
    struct location *port92;
    struct new *new_maze;
};
struct new{
    bool new;
};
struct location{
    unsigned int row;
    unsigned int col;
};
struct target{
    unsigned int row;
    unsigned int col;
    bool visited;
};



void set_terminal(bool start);
struct maze* read_maze(const char *input_file, struct maze* the_maze);
void print_wall(struct maze *current);
void print_wall2(struct maze *current);
void print_maze(struct maze *current);
void maze_end(struct maze* start);
void handle_input(struct maze start);
void print_tile(char symbol, char* color);
bool ouch(int i, int j ,int row, int col);
struct maze* maze_init(unsigned int player_loc_x, unsigned int player_loc_y, const char *message, unsigned int rows, unsigned int cols, unsigned int target_x, unsigned int target_y,unsigned int target_x2, unsigned int target_y2, bool game_over, bool is_tile);

/************************************
 * TERMINAL CODES ("MAGIC STRINGS") *
 ************************************/

#define COLOR_OFF       "\e[0m"
#define COLOR_BLACK     "\e[0;30m"
#define COLOR_GRAY      "\e[1;30m"
#define COLOR_RED       "\e[0;31m"
#define COLOR_LT_RED    "\e[1;31m"
#define COLOR_GREEN     "\e[0;32m"
#define COLOR_LT_GREEN  "\e[1;32m"
#define COLOR_BROWN     "\e[0;33m"
#define COLOR_YELLOW    "\e[1;33m"
#define COLOR_BLUE      "\e[0;34m"
#define COLOR_LT_BLUE   "\e[1;34m"
#define COLOR_PURPLE    "\e[0;35m"
#define COLOR_LT_PURPLE "\e[1;35m"
#define COLOR_CYAN      "\e[0;36m"
#define COLOR_LT_CYAN   "\e[1;36m"
#define COLOR_LT_GRAY   "\e[0;37m"
#define COLOR_WHITE     "\e[1;37m"

#define CLEAR_SCREEN    "\e[2J\e[1;1H"

/*****************************
 * SYMBOLS FOR GAME ELEMENTS *
 *****************************/

#define S_FLOOR     " "
#define S_PLAYER    COLOR_BLUE "@" COLOR_OFF
#define S_WALL      COLOR_GRAY "#" COLOR_OFF
#define S_TARGET      COLOR_YELLOW "$" COLOR_OFF

