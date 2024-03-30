#include <SDL2/SDL.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>

// Constants for screen dimensions and player attributes

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 700;
const int PLAYER_HEIGHT = 270;
const int PLAYER_WIDTH = 270;
const int ENEMY_HEIGHT = 250;
const int ENEMY_WIDTH = 250;
const int FRAME_WIDTH = 100; // Width of each frame in the sprite sheet
const int FRAME_HEIGHT = 100; // Height of each frame in the sprite sheet
const int ATTACK_RANGE = 300; // 假设敌人攻击范围为100像素
const int JUMP_FORCE = 20;
const int NUM_FRAMES = 8; // Number of animation frames in the sprite sheet
const int PLAYERSPEED = 6;
const int ENEMYSPEED = 1;
const int GRAVITY = 1;

bool gameisRunning = true;
int playerDir = 2;
int enemyDir = 1;
int fT1;
int fT2;
int fT3;
int fT4;
int fT5;
int fT6;
int fT7;
int bending = 0;
int image_Y = 110;
int inverseDir = 1;
int v1 = 125;
int v2 = 125;

// SDL variables for window, renderer, and textures
SDL_Surface *surfaceSpriteSheet1 = IMG_Load("./assets/sheet4.png");
SDL_Surface *surfaceSpriteSheet2 = IMG_Load("./assets/sheet6.png");

// SDL variables for window, renderer, and textures
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
SDL_Texture *backgroundTexture = nullptr;
SDL_Texture *spriteSheet1 = nullptr;
SDL_Texture *spriteSheet2 = nullptr;
SDL_Texture *fireSheet = nullptr;
SDL_Texture *hpBar = nullptr;
SDL_Texture* waterSheet = nullptr;
SDL_Texture* earthSheet = nullptr;
SDL_Texture* windSheet = nullptr;
SDL_Texture* lightSheet = nullptr;
SDL_Texture* firelightSheet = nullptr;
SDL_Texture* waterlightSheet = nullptr;
SDL_Texture* firewaterSheet = nullptr;
SDL_Texture* texture = nullptr;

// Struct to represent the player with various attributes
struct Character
{
    int x, y;           // Position coordinates
    int dx, dy;         // Velocity components
    bool isJumping;     // Flag for jump state
    bool isMovingLeft;  // Flag for left movement
    bool isMovingRight; // Flag for right movement
    int jumpCount;      // amount of jumps done in succession in one instance
    int health;         // health points of character
    int frame_width;
    int frame_height;
    int frame_number;
};

struct Enemy
{
    int x, y;           // Position coordinates
    int dx, dy;         // Velocity components
    bool isJumping;     // Flag for jump state
    bool isMovingLeft;  // Flag for left movement
    bool isMovingRight; // Flag for right movement
    int jumpCount;      // amount of jumps done in succession in one instance
    int health;         // health points of character
    bool playerAttack;   // whether or not enemy is attacking
    int attacktype;      
    int frame_width;
    int frame_height;
    int frame_number;
};

Character player = {100, 100, 0, 0, false, false, false, 0, 100, false,0, 1}; // Initialize the player object
Enemy enemy = {500, 370, 0, 0, false, false, false, 0, 100, false, 0, 1, 1};
