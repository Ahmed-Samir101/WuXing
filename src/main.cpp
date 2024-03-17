#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

//Code created by xiaolong(ç´¢é‡Œæ›¼ï¼‰, at 2:03AM 2024/3/6

// Constants for screen dimensions and player attributes
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 700;
const int PLAYER_WIDTH = 270;
const int PLAYER_HEIGHT = 270;
const int JUMP_FORCE = 20;
const int WALKSPEED = 6;
const int GRAVITY = 1;
const int NUM_FRAMES = 8; // Number of animation frames in the sprite sheet
const int FRAME_WIDTH = 100; // Width of each frame in the sprite sheet
const int FRAME_HEIGHT = 100; // Height of each frame in the sprite sheet
int cT = 2;
int fT1;
int fT2;
int fT3;

// SDL variables for window, renderer, and textures
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Texture* backgroundTexture = nullptr;
SDL_Texture* spriteSheet1 = nullptr;
SDL_Texture* spriteSheet2 = nullptr;

// Struct to represent the player with various attributes
struct Player {
    int x, y; // Position coordinates
    int dx, dy; // Velocity components
    bool isJumping; // Flag for jump state
    bool isMovingLeft; // Flag for left movement
    bool isMovingRight; // Flag for right movement
};

//Code created by xiaolong(ç´¢é‡Œæ›¼ï¼‰, at 9ï¼š00pm 2024/3/8

// Function to handle user input events
void handleInput(Player& player) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
        else if(event.key.keysym.sym == SDLK_ESCAPE) {
            exit(0);
        }
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_SPACE && !player.isJumping) {
                player.dy = -JUMP_FORCE;
                player.isJumping = true;
            }
            if (event.key.keysym.sym == SDLK_LEFT) {
                player.isMovingLeft = true;
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                player.isMovingRight = true;
            }
        }
        if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_LEFT) {
                player.isMovingLeft = false;
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                player.isMovingRight = false;
            }
        }
    }
}

//Code created and edited by xiaolong(ç´¢é‡Œæ›¼ï¼‰, at 11ï¼š00pm 2024/3/13

// Function to update the player's position and state
void updatePlayer(Player& player) {
    // Update player's horizontal movement based on input
    if (player.isMovingLeft && player.x >= -70) {
        player.dx = -WALKSPEED;
    }
    else if (player.isMovingRight && player.x < SCREEN_WIDTH-190) {
        player.dx = WALKSPEED;
    }
    else {
        player.dx = 0;
    }

    // Update player's position and apply gravity
    player.x += player.dx;
    player.y += player.dy;
    player.dy += GRAVITY;

    // Check for ground to stop falling and jumping
    if (player.y >= SCREEN_HEIGHT - PLAYER_HEIGHT - 60) {
        player.y = SCREEN_HEIGHT - PLAYER_HEIGHT - 60;
        player.dy = 0;
        player.isJumping = false;
    }
    printf("%d\n", player.x);
}

//Code created by åˆ˜ç‚ç’‡ and èµµå—æ˜Ÿ, at 6:30pm 2024/3/10

// Function to render the background scene
void renderScene() {
    SDL_Rect rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect);
}

// Function to render the player character with animations
void renderPlayer(Player& player) {
    SDL_Rect rect = { player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT };
    //SDL_Rect srcRect = {cT * FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGHT};
    SDL_Rect srcRect = {fT1 * 32, 3*32 , 32, 32};
    SDL_Rect srcRect2 = {fT2 * 32, 0, 32, 32};
    SDL_Rect srcRect3 = {fT3 * 32, 4 * 32, 32, 32};
    fT1 = (SDL_GetTicks()/ 200) % 8;
    fT2 = (SDL_GetTicks()/ 200) % 2;
    fT3 = (SDL_GetTicks()/ 200) % 6;
    //printf("%d\n", cT);
    SDL_Texture* currentTexture = nullptr;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    if (player.isMovingLeft || player.isMovingRight) {
        // Animation frames for walking
        //int frame = (SDL_GetTicks() / 200) % 2; // Change every 200 ms
        if (player.isMovingLeft) {
            SDL_RenderCopyEx(renderer, spriteSheet1, &srcRect, &rect, 0, NULL, SDL_FLIP_HORIZONTAL);
            cT = 1;
        } else {
            SDL_RenderCopy(renderer, spriteSheet1, &srcRect, &rect);
            cT = 2;
        }
    } else if(player.isJumping){
        if (cT == 1) {
            flipType = SDL_FLIP_HORIZONTAL;
        } else{
            flipType = SDL_FLIP_NONE;
        }
        SDL_RenderCopyEx(renderer, spriteSheet1, &srcRect3, &rect, 0, NULL, flipType);
    } else {
        // Default texture when standing still
        if (cT == 1) {
            flipType = SDL_FLIP_HORIZONTAL;
        } else{
            flipType = SDL_FLIP_NONE;
        }
        SDL_RenderCopyEx(renderer, spriteSheet1, &srcRect2, &rect, 0, NULL, flipType);
    }
    //SDL_RenderCopy(renderer, currentTexture, &srcRect2, &rect);
    //SDL_RenderCopyEx(renderer, spriteSheet1, &srcRect2, &rect, 0, NULL, flipType);
}

//Code created by xiaolong(ç´¢é‡Œæ›¼ï¼‰and é­æ™“å½¤, at 8:00PM 2024/3/6
// Main function where the game loop runs
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Game Character", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load textures for the character facing left and right, and background
    SDL_Surface* surfaceBackground = IMG_Load("./assets/background2.jpg");
    SDL_Surface* surfaceSpriteSheet1 = IMG_Load("./assets/sheet4.png");
    SDL_Surface* surfaceSpriteSheet2 = IMG_Load("./assets/sheet5.png");

    // Create textures from loaded surfaces
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, surfaceBackground);
    spriteSheet1 = SDL_CreateTextureFromSurface(renderer, surfaceSpriteSheet1);
    spriteSheet2 = SDL_CreateTextureFromSurface(renderer, surfaceSpriteSheet2);

    Player player = {100, 100, 0, 0, false}; // Initialize the player object

    bool isRunning = true;
    while (isRunning) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        handleInput(player); // Handle user input
        updatePlayer(player); // Update player state
        renderScene(); // Render background scene
        renderPlayer(player); // Render player character

        SDL_RenderPresent(renderer);
        SDL_Delay(10); // Delay for smoother animation
    }

    // Clean up resources before exiting
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();

    return 0;
}
