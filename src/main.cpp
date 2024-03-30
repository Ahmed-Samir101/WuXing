#include "./rendering.h"

void enemyAttack();
void playerAttack();

bool enemyCollision() {
    if(enemyDir == 1){
        if(enemy.x <= player.x + PLAYER_WIDTH/1.7 && player.y+PLAYER_HEIGHT >= enemy.y+ENEMY_HEIGHT){
                return true;
        }
    }else if((enemy.x + ENEMY_WIDTH/1.7 >= player.x && enemy.x+ ENEMY_WIDTH/1.7 <= player.x + PLAYER_WIDTH/1.7) && player.y+PLAYER_HEIGHT >= enemy.y+ENEMY_HEIGHT) {
        return true;
    }
    // No collision
    return false;
}

bool wallCollision() {
    if(player.x >= WINDOW_WIDTH - 190){
        return true;
    }
    else if(player.x <= -70) {
        return true;
    }
    // No collision
    return false;
}

bool bendingCollision(SDL_Rect dstrect) {
    if(enemyDir == 1){
        if(enemy.x <= dstrect.x + player.frame_width/1.7 && dstrect.y+player.frame_height >= enemy.y+ENEMY_HEIGHT){
                playerAttack();
                return true;
        }
    }else if((enemy.x + ENEMY_WIDTH/1.7 >= dstrect.x && enemy.x+ ENEMY_WIDTH/1.7 <= dstrect.x + player.frame_width/2) && dstrect.y+player.frame_height >= enemy.y+ENEMY_HEIGHT) {
        playerAttack();
        return true;
    }
    // No collision
    return false;
}

void setup() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    TTF_Init;
    //Mix_Init(MIX_INIT_MP3);                            // Initialize the audio library (for MP3 support)
    //Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024); // Open the audio device*/

    window = SDL_CreateWindow("Game Character", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //Mix_Music *music = Mix_LoadMUS("./assets/m.mp3");

    // Load textures for the character facing left and right, and background
    SDL_Surface *surfaceBackground = IMG_Load("./assets/background2.jpg");
    SDL_Surface *surfaceFireSheet = IMG_Load("./assets/fireball2.png");
    SDL_Surface *surfaceHPBar = IMG_Load("./assets/hpBar.png");
    SDL_Surface* surfaceWaterSheet = IMG_Load("./assets/water.png");
    SDL_Surface* surfaceEarthSheet = IMG_Load("./assets/earth.png");
    SDL_Surface* surfaceWindSheet = IMG_Load("./assets/wind.png");
    SDL_Surface* surfaceLightSheet = IMG_Load("./assets/light.png");
    SDL_Surface* surfaceFirelightSheet = IMG_Load("./assets/firelight.png");
    SDL_Surface* surfaceWaterlightSheet = IMG_Load("./assets/waterlight.png");
    SDL_Surface* surfaceFirewaterSheet = IMG_Load("./assets/firewater.png");


    // Create textures from loaded surfaces
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, surfaceBackground);
    spriteSheet1 = SDL_CreateTextureFromSurface(renderer, surfaceSpriteSheet1);
    fireSheet = SDL_CreateTextureFromSurface(renderer, surfaceFireSheet);
    spriteSheet2 = SDL_CreateTextureFromSurface(renderer, surfaceSpriteSheet2);
    hpBar = SDL_CreateTextureFromSurface(renderer, surfaceHPBar);
    fireSheet = SDL_CreateTextureFromSurface(renderer, surfaceFireSheet);
    waterSheet = SDL_CreateTextureFromSurface(renderer, surfaceWaterSheet);
    earthSheet = SDL_CreateTextureFromSurface(renderer, surfaceEarthSheet);
    windSheet = SDL_CreateTextureFromSurface(renderer, surfaceWindSheet);
    lightSheet = SDL_CreateTextureFromSurface(renderer, surfaceLightSheet);
    firelightSheet = SDL_CreateTextureFromSurface(renderer, surfaceFirelightSheet);
    waterlightSheet = SDL_CreateTextureFromSurface(renderer, surfaceWaterlightSheet);
    firewaterSheet = SDL_CreateTextureFromSurface(renderer, surfaceFirewaterSheet);
}

int bendingSkill(int& bending,int& image_Y,SDL_Texture* texture,int& inverseDir,int& v1,int& v2) {

    static int initialX = player.x + 200;
    static int initialDir = playerDir;
    static Uint32 bendingStartTime = SDL_GetTicks();  // Get the starting time of the bending action
    int elapsedTicks = SDL_GetTicks() - bendingStartTime;
    int frameIndex = (elapsedTicks / v1) % player.frame_number;
    SDL_Rect srcRect4 = { frameIndex * player.frame_width, image_Y, player.frame_width, player.frame_height };  // Calculate the source rectangle using the elapsed time
    int totalX = initialX + ((initialDir == 2) ? player.frame_width / 2 : -player.frame_width / 2) * (elapsedTicks / v2);
    static int initialY = player.y + 64;
    SDL_Rect dstrect2 = { totalX, initialY, 272, 170 }; // Use initialY as the y-coordinate

    // Check if the first animation has finished
    if (bending == 0 && frameIndex == (player.frame_number-1)) {
        // Start the inverse animation
        bending = 1;
        bendingStartTime = SDL_GetTicks();  // Reset the starting time for the inverse animation
       // initialX = totalX; // Update initialX to the current position
        initialDir = (initialDir == 1) ? 2 : 1; // Invert the direction
    }

    // Calculate the frame index for the inverse animation
    int inverseFrameIndex = (player.frame_number-1) - frameIndex;
    SDL_Rect inverseSrcRect = { inverseFrameIndex * player.frame_width, image_Y, player.frame_width, player.frame_height };

    if (bending != 0) {
        if (totalX >= (initialX + player.frame_width / 2 * (player.frame_number-2)) || totalX <= (initialX - player.frame_width / 2* (player.frame_number-2))) {
            bending = 0;
            bendingStartTime = SDL_GetTicks();  // Reset the starting time when bending is finished
            return 0;
        }

        if (initialDir == inverseDir) {
            SDL_RenderCopyEx(renderer, texture, &srcRect4, &dstrect2, 0, NULL, SDL_FLIP_HORIZONTAL);
        }
        else {
            SDL_RenderCopy(renderer, texture, &srcRect4, &dstrect2);
        }
    }
    else {
        initialX = player.x + ((initialDir == 2) ? 200 : -200); // Reset initialX when bending is finished
        initialY = player.y + 96; // Keep initialY the same when bending is finished
        initialDir = playerDir;
        bendingStartTime = SDL_GetTicks();  // Reset the starting time when bending is finished
    }

    return 0;
}

// Function to handle user input events
void handleInput() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            gameisRunning = false;
        }
        else if(event.key.keysym.sym == SDLK_ESCAPE) {
            gameisRunning = false;
        }
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_SPACE && player.jumpCount < 2) {
                player.dy = -JUMP_FORCE;
                player.isJumping = true;
                player.jumpCount++;
                printf("%d\n", player.jumpCount);
            }
            if (event.key.keysym.sym == SDLK_LEFT) {
                player.isMovingLeft = true;
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                player.isMovingRight = true;
            }
            if(event.key.keysym.sym == SDLK_e){
                bending = 1;
                player.frame_number = 10;
                image_Y = 310;
                player.frame_width = 53;
                player.frame_height = 51;
                texture = fireSheet;
                inverseDir = 1;
                v1 = 125;
                v2 = 125;
                bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
            }
            if(event.key.keysym.sym == SDLK_r){
                bending = 1;
                player.frame_number = 5;
                image_Y = 0;
                player.frame_width = 192;
                player.frame_height = 192;
                texture = waterSheet;
                inverseDir = 2;
                v1 = 210;
                v2 = 315;
                bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
            }
            if(event.key.keysym.sym == SDLK_f){
                bending = 1;
                player.frame_number = 5;
                image_Y = 0;
                player.frame_width = 192;
                player.frame_height = 192;
                texture = earthSheet;
                inverseDir = 1;
                v1 = 210;
                v2 = 420;
                bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
            }
            if(event.key.keysym.sym == SDLK_g){
                bending = 1;
                player.frame_number = 5;
                image_Y = 0;
                player.frame_width = 192;
                player.frame_height = 200;
                texture = windSheet;
                inverseDir = 1;
                v1 = 210;
                v2 = 420;
                bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
            }
            if(event.key.keysym.sym == SDLK_h){
                bending = 1;
                player.frame_number = 5;
                image_Y = 192;
                player.frame_width = 192;
                player.frame_height = 192;
                texture = lightSheet;
                inverseDir = 1;
                v1 = 210;
                v2 = 315;
                bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
            }
            if(event.key.keysym.sym == SDLK_v){
                bending = 1;
                player.frame_number = 5;
                image_Y = 0;
                player.frame_width = 192;
                player.frame_height = 192;
                texture = firelightSheet;
                inverseDir = 1;
                v1 = 210;
                v2 = 315;
                bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
            }
            if(event.key.keysym.sym == SDLK_b){
                bending = 1;
                player.frame_number = 5;
                image_Y = 384;
                player.frame_width = 192;
                player.frame_height = 192;
                texture = waterlightSheet;
                inverseDir = 1;
                v1 = 210;
                v2 = 315;
                bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
            }
            if(event.key.keysym.sym == SDLK_n){
                bending = 1;
                player.frame_number = 5;
                image_Y = 0;
                player.frame_width = 192;
                player.frame_height = 192;
                texture = firewaterSheet;
                inverseDir = 2;
                v1 = 210;
                v2 = 315;
                bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
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

// Function to update the player's position and state
void updatePlayer() {
    // Update player's horizontal movement based on input
    if (player.isMovingLeft && player.x >= -70){
        player.dx = -PLAYERSPEED;
    }
    else if (player.isMovingRight && player.x < WINDOW_WIDTH - 190){
        player.dx = PLAYERSPEED;
    }
    else{
        player.dx = 0;
    }
    SDL_Rect collPlayer = {player.x, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
    SDL_Rect collEnemy = {enemy.x, 0, ENEMY_WIDTH, ENEMY_HEIGHT};
    // Update player's position and apply gravity
    player.x += player.dx;
    player.x;

    player.y += player.dy;
    player.dy += GRAVITY;

    // Check for ground to stop falling and jumping
    if (player.y >= WINDOW_HEIGHT - PLAYER_HEIGHT - 60)
    {
        player.y = WINDOW_HEIGHT - PLAYER_HEIGHT - 60;
        player.dy = 0;
        player.isJumping = false;
    }
    if (player.y == WINDOW_HEIGHT - PLAYER_HEIGHT - 60)
    {
        player.jumpCount = 0;
    }
}

void updateEnemy() {
    SDL_Rect collPlayer = {player.x, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
    SDL_Rect collEnemy = {enemy.x, 0, ENEMY_WIDTH, ENEMY_HEIGHT};
    // Enemy movement towards the player
    if (player.x > enemy.x) {
        enemy.x += ENEMYSPEED; // when the player is to the right of the enemy
        enemy.isMovingRight = true;
        enemy.isMovingLeft = false;
    }
    else if (player.x < enemy.x) {

        enemy.x -= ENEMYSPEED; // when the player is to the left of the enemy
        enemy.isMovingRight = false;
        enemy.isMovingLeft = true;
    }

    // if player jumps enemy also jumps
    if (player.isJumping) {
        enemy.isJumping = true;
    }
    else {
        enemy.isJumping = false;
    }

    // if the enemy is within range
    if (abs(player.x - enemy.x) < ATTACK_RANGE) {
        //srand(time(NULL));
        enemy.playerAttack = true;
        enemy.attacktype = 1;
    }
}

void enemyAttack() {
    if(player.health >= 0) {
        player.health -= 10;
    }
    else{
        player.health = 0;
    }
}

void playerAttack() {
    if(enemy.health >= 0) {
        enemy.health -= 10;
    }
    else{
        enemy.health = 0;
    }
}

void bounce() {
    player.dx = 10;
    player.dx = ((enemyDir == 1) ? -6: 6)*player.dx; // Reverse the player's velocity
    player.x += player.dx;  // Update the player's position using the reversed velocity
}

void dont() {
    player.dx = -player.dx; // Reverse the player's velocity
    player.x += player.dx;  // Update the player's position using the reversed velocity
}

//  Main function where the game loop runs
int main(int argc, char *argv[]) {

    setup();
    while (gameisRunning) {
        
        if(enemyCollision()){ bounce(); enemyAttack(); }
        if(wallCollision()) dont();

        handleInput();      // Handle user input
        renderScene();      // Render background scene
        updatePlayer();     // Update player state
        updateEnemy();
        renderPlayer();     // Render player character
        bendingSkill(bending,image_Y,texture,inverseDir,v1,v2);
        renderEnemy();      // Render enemy character
        SDL_RenderPresent(renderer);
        SDL_Delay(10);      // Delay for smoother animation
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}