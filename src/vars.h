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
int collisionFlag = 0;
int inverseDir = 1;
int v1 = 125;
int v2 = 125;
int enemyAttackType = 0;