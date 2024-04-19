#include "./vars.h"

void setup() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    SDL_Init(SDL_INIT_TIMER);
    Mix_Init(MIX_INIT_MP3);                            // Initialize the audio library (for MP3 support)
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
    }

    // Initialize SDL_mixer
    int mixFlags = MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC;
    int mixInitResult = Mix_Init(mixFlags);
    if ((mixInitResult & mixFlags) != mixFlags) {
        std::cout << "SDL_mixer initialization failed for required audio formats: " << Mix_GetError() << std::endl;
    }

    // Open audio
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer audio initialization failed: " << Mix_GetError() << std::endl;
    }

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    // Load textures for the character facing left and right, and background
    SDL_Surface* surfaceBackground = IMG_Load("./assets/background1.png");
    SDL_Surface* surfaceLogo = IMG_Load("./assets/logo.png");
    SDL_Surface* surfaceFireSheet = IMG_Load("./assets/fireball2.png");
    SDL_Surface* surfaceHPBar = IMG_Load("./assets/hpBar.png");
    SDL_Surface* surfaceWaterSheet = IMG_Load("./assets/water.png");
    SDL_Surface* surfaceEarthSheet = IMG_Load("./assets/earth.png");
    SDL_Surface* surfaceWindSheet = IMG_Load("./assets/wind.png");
    SDL_Surface* surfaceLightSheet = IMG_Load("./assets/light.png");
    SDL_Surface* surfaceFirelightSheet = IMG_Load("./assets/firelight.png");
    SDL_Surface* surfaceWaterlightSheet = IMG_Load("./assets/waterlight.png");
    SDL_Surface* surfaceFirewaterSheet = IMG_Load("./assets/firewater.png");
    SDL_Surface* surfaceSetting = IMG_Load("./assets/setting.png");
    SDL_Surface* surfacePlay = IMG_Load("./assets/play.png");
    SDL_Surface* surfaceHelp = IMG_Load("./assets/helpButton.png");
    SDL_Surface* surfaceMap = IMG_Load("./assets/map.png");
    SDL_Surface* surfaceReturnback = IMG_Load("./assets/return.png");
    SDL_Surface* surfaceHelpBackground = IMG_Load("./assets/helpbackground.png");
    SDL_Surface* surfaceSettingBackground = IMG_Load("./assets/settingbackground.png");
    SDL_Surface* surfaceRealHelp = IMG_Load("./assets/realhelp.png");
    SDL_Surface* surfaceRealHelpButton = IMG_Load("./assets/realhelpbutton.png");
    SDL_Surface* surfaceFirstMap = IMG_Load("./assets/Map1.png");
    SDL_Surface* surfaceFirstWinMap = IMG_Load("./assets/Map2.png");
    SDL_Surface* surfaceSecondMap = IMG_Load("./assets/Map3.png");
    SDL_Surface* surfaceSecondWinMap = IMG_Load("./assets/Map4.png");
    SDL_Surface* surfaceThirdMap = IMG_Load("./assets/Map5.png");
    SDL_Surface* surfaceThirdWinMap = IMG_Load("./assets/Map6.png");
    SDL_Surface* surfaceForthMap = IMG_Load("./assets/Map7.png");
    SDL_Surface* surfaceForthWinMap = IMG_Load("./assets/Map8.png");
    SDL_Surface* surfaceFifthMap = IMG_Load("./assets/Map9.png");
    SDL_Surface* surfaceFifthWinMap = IMG_Load("./assets/Map10.png");
    SDL_Surface* surfaceSixthMap = IMG_Load("./assets/Map11.png");
    SDL_Surface* surfaceSixthWinMap = IMG_Load("./assets/Map12.png");

    SDL_Surface* surfaceSeventhMap = IMG_Load("./assets/Map13.png");
    SDL_Surface* surfaceSeventhWinMap = IMG_Load("./assets/Map14.png");
    SDL_Surface* surfaceEightMap = IMG_Load("./assets/Map15.png");
    SDL_Surface* surfaceEightWinMap = IMG_Load("./assets/Map16.png");
    SDL_Surface* surfaceNinthMap = IMG_Load("./assets/Map17.png");
    SDL_Surface* surfaceNinthWinMap = IMG_Load("./assets/Map18.png");
    SDL_Surface* surfaceTenthMap = IMG_Load("./assets/Map19.png");
    SDL_Surface* surfaceTenthWinMap = IMG_Load("./assets/Map20.png");
    SDL_Surface* surfaceEleventhMap = IMG_Load("./assets/Map21.png");
    SDL_Surface* surfaceEleventhWinMap = IMG_Load("./assets/Map22.png");
    SDL_Surface* surfaceTwelvethMap = IMG_Load("./assets/Map23.png");
    SDL_Surface* surfaceTwelvethWinMap = IMG_Load("./assets/Map24.png");
    SDL_Surface* surfaceThirteenthMap = IMG_Load("./assets/Map25.png");
    SDL_Surface* surfaceThirteenthWinMap = IMG_Load("./assets/Map26.png");
    SDL_Surface* surfaceFourteenthMap = IMG_Load("./assets/Map27.png");
    SDL_Surface* surfaceFourteenthWinMap = IMG_Load("./assets/Map28.png");
    SDL_Surface* surfaceFifteenthWinMap = IMG_Load("./assets/Map29.png");
    SDL_Surface* surfaceYouWin = IMG_Load("./assets/youwin.jpg");
    SDL_Surface* surfaceHeart = IMG_Load("./assets/heart.png");
    SDL_Surface* surfaceScroll1 = IMG_Load("./assets/scroll1.png");
    SDL_Surface* surfaceScroll2 = IMG_Load("./assets/scroll2.png");
    SDL_Surface* surfaceScroll3 = IMG_Load("./assets/scroll3.png");
    SDL_Surface* surfaceScroll4 = IMG_Load("./assets/scroll4.png");
    SDL_Surface* surfaceScroll5 = IMG_Load("./assets/scroll5.png");
    SDL_Surface* surfaceScroll6 = IMG_Load("./assets/scroll6.png");


    // Create textures from loaded surfaces
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, surfaceBackground);
    logoTexture = SDL_CreateTextureFromSurface(renderer, surfaceLogo);
    heartTexture = SDL_CreateTextureFromSurface(renderer, surfaceHeart);
    spriteSheet1 = SDL_CreateTextureFromSurface(renderer, surfacePlayer);
    fireSheet = SDL_CreateTextureFromSurface(renderer, surfaceFireSheet);
    spriteSheet2 = nullptr;
    // enemySheet2 = SDL_CreateTextureFromSurface(renderer, enemySurface2);
    hpBar = SDL_CreateTextureFromSurface(renderer, surfaceHPBar);
    fireSheet = SDL_CreateTextureFromSurface(renderer, surfaceFireSheet);
    waterSheet = SDL_CreateTextureFromSurface(renderer, surfaceWaterSheet);
    earthSheet = SDL_CreateTextureFromSurface(renderer, surfaceEarthSheet);
    windSheet = SDL_CreateTextureFromSurface(renderer, surfaceWindSheet);
    lightSheet = SDL_CreateTextureFromSurface(renderer, surfaceLightSheet);
    firelightSheet = SDL_CreateTextureFromSurface(renderer, surfaceFirelightSheet);
    waterlightSheet = SDL_CreateTextureFromSurface(renderer, surfaceWaterlightSheet);
    firewaterSheet = SDL_CreateTextureFromSurface(renderer, surfaceFirewaterSheet);
    setting = SDL_CreateTextureFromSurface(renderer, surfaceSetting);
    play = SDL_CreateTextureFromSurface(renderer, surfacePlay);
    map = SDL_CreateTextureFromSurface(renderer, surfaceMap);
    help = SDL_CreateTextureFromSurface(renderer, surfaceHelp);
    returnback = SDL_CreateTextureFromSurface(renderer, surfaceReturnback);
    helpbackground = SDL_CreateTextureFromSurface(renderer, surfaceHelpBackground);
    settingbackground = SDL_CreateTextureFromSurface(renderer, surfaceSettingBackground);
    realhelp = SDL_CreateTextureFromSurface(renderer, surfaceRealHelp);
    realhelpbutton = SDL_CreateTextureFromSurface(renderer, surfaceRealHelpButton);
    first = SDL_CreateTextureFromSurface(renderer, surfaceFirstMap);
    firstwin = SDL_CreateTextureFromSurface(renderer, surfaceFirstWinMap);
    second = SDL_CreateTextureFromSurface(renderer, surfaceSecondMap);
    secondwin = SDL_CreateTextureFromSurface(renderer, surfaceSecondWinMap);
    third = SDL_CreateTextureFromSurface(renderer, surfaceThirdMap);
    thirdwin = SDL_CreateTextureFromSurface(renderer, surfaceThirdWinMap);
    fourth = SDL_CreateTextureFromSurface(renderer, surfaceForthMap);
    forthwin = SDL_CreateTextureFromSurface(renderer, surfaceForthWinMap);
    fifth = SDL_CreateTextureFromSurface(renderer, surfaceFifthMap);
    fifthwin = SDL_CreateTextureFromSurface(renderer, surfaceFifthWinMap);
    sixth = SDL_CreateTextureFromSurface(renderer, surfaceSixthMap);
    sixthwin = SDL_CreateTextureFromSurface(renderer, surfaceSixthWinMap);

    seventh = SDL_CreateTextureFromSurface(renderer, surfaceSeventhMap);
    seventhwin = SDL_CreateTextureFromSurface(renderer, surfaceSeventhWinMap);
    eight = SDL_CreateTextureFromSurface(renderer, surfaceEightMap);
    eightwin = SDL_CreateTextureFromSurface(renderer, surfaceEightWinMap);
    ninth = SDL_CreateTextureFromSurface(renderer, surfaceNinthMap);
    ninthwin = SDL_CreateTextureFromSurface(renderer, surfaceNinthWinMap);
    tenth = SDL_CreateTextureFromSurface(renderer, surfaceTenthMap);
    tenthwin = SDL_CreateTextureFromSurface(renderer, surfaceTenthWinMap);
    eleventh = SDL_CreateTextureFromSurface(renderer, surfaceEleventhMap);
    eleventhwin = SDL_CreateTextureFromSurface(renderer, surfaceEleventhWinMap);
    twelveth = SDL_CreateTextureFromSurface(renderer, surfaceTwelvethMap);
    twelvethwin = SDL_CreateTextureFromSurface(renderer, surfaceTwelvethWinMap);
    thirteenth = SDL_CreateTextureFromSurface(renderer, surfaceThirteenthMap);
    thirteenthwin = SDL_CreateTextureFromSurface(renderer, surfaceThirteenthWinMap);
    fourteenth = SDL_CreateTextureFromSurface(renderer, surfaceFourteenthMap);
    fourteenthwin = SDL_CreateTextureFromSurface(renderer, surfaceFourteenthWinMap);
    fifteenth = SDL_CreateTextureFromSurface(renderer, surfaceFifteenthWinMap);
    youwin = SDL_CreateTextureFromSurface(renderer, surfaceYouWin);
    scroll_1 = SDL_CreateTextureFromSurface(renderer, surfaceScroll1);
    scroll_2 = SDL_CreateTextureFromSurface(renderer, surfaceScroll2);
    scroll_3 = SDL_CreateTextureFromSurface(renderer, surfaceScroll3);
    scroll_4 = SDL_CreateTextureFromSurface(renderer, surfaceScroll4);
    scroll_5 = SDL_CreateTextureFromSurface(renderer, surfaceScroll5);
    scroll_6 = SDL_CreateTextureFromSurface(renderer, surfaceScroll6);

}

// Function to render the background scene
void renderScene() {
    SDL_Rect bgRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    SDL_Rect hpPlayerBarRect = { 25, 12, 4 * player.health, 40 };
    SDL_Rect hpEnemyBarRect = { WINDOW_WIDTH - 400, 12, 4 * enemy.health, 40 };
    SDL_Rect dstTextRectPlayer = { 0, 0, 50, 50 };
    SDL_Rect dstTextRectEnemy = { WINDOW_WIDTH - 50, 0, 50, 50 };
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &bgRect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &hpPlayerBarRect);
    SDL_RenderFillRect(renderer, &hpEnemyBarRect);
    SDL_RenderCopy(renderer, heartTexture, NULL, &heartRect1);
    SDL_RenderCopy(renderer, heartTexture, NULL, &heartRect2);

    if (music == nullptr) {
        printf("No Music\n");
    }
    
}
// Function to render the player character with animations
void renderPlayer()
{
    SDL_Rect dstrectPlayer = { player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT };
    SDL_Rect srcRect = { fT1 * 32, 3 * 32, 32, 32 };
    SDL_Rect srcRect2 = { fT2 * 32, 0, 32, 32 };
    SDL_Rect srcRect3 = { fT3 * 32, 4 * 32, 32, 32 };
    SDL_Rect bend = { fT1 * 32, 8 * 32, 32, 32 };
    SDL_Rect block = { fT1 * 32, 8 * 32, 32, 32 };
    static Uint32 StartTime1 = SDL_GetTicks();

    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - StartTime1) / 150.0f;

    fT1 = static_cast<int>(deltaTime) % 8;
    fT2 = static_cast<int>(deltaTime) % 2;
    fT3 = static_cast<int>(deltaTime) % 6;

    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    if (player.isMovingLeft || player.isMovingRight)
    {
        // Animation frames for walking
        if (player.isMovingLeft) {
            SDL_RenderCopyEx(renderer, spriteSheet1, &srcRect, &dstrectPlayer, 0, NULL, SDL_FLIP_HORIZONTAL);
            playerDir = 1;
        }
        else {
            SDL_RenderCopy(renderer, spriteSheet1, &srcRect, &dstrectPlayer);
            playerDir = 2;
        }
    }
    else if (player.isJumping)
    {
        if (playerDir == 1) {
            flipType = SDL_FLIP_HORIZONTAL;
        }
        else {
            flipType = SDL_FLIP_NONE;
        }
        SDL_RenderCopyEx(renderer, spriteSheet1, &srcRect3, &dstrectPlayer, 0, NULL, flipType);
    }
    else if (playerbend.bending)
    {
        if (playerDir == 1) {
            flipType = SDL_FLIP_HORIZONTAL;
        }
        else {
            flipType = SDL_FLIP_NONE;
        }
        SDL_RenderCopyEx(renderer, spriteSheet1, &bend, &dstrectPlayer, 0, NULL, flipType);
    }
    else
    {
        // Default texture when standing still
        StartTime1 = SDL_GetTicks();
        if (playerDir == 1) {
            flipType = SDL_FLIP_HORIZONTAL;
        }
        else {
            flipType = SDL_FLIP_NONE;
        }
        SDL_RenderCopyEx(renderer, spriteSheet1, &srcRect2, &dstrectPlayer, 0, NULL, flipType);
    }
}

void renderEnemy()
{
    SDL_Rect dstrectEnemy = { enemy.x, enemy.y, ENEMY_WIDTH, ENEMY_HEIGHT };
    SDL_Rect srcRect = { fT4 * enemy.enemyWidth, (enemy.rowNum * enemy.enemyHeight) + 20, enemy.enemyWidth, enemy.enemyHeight }; // walk
    SDL_Rect srcRect2 = { fT5 * enemy.enemyWidth, 9 * enemy.enemyHeight, enemy.enemyWidth, 104 }; // remain still
    SDL_Rect srcRect3 = { fT6 * enemy.enemyWidth, 2 * enemy.enemyHeight, enemy.enemyHeight, 104 }; // jump
    SDL_Rect bend = { fT7 * enemy.enemyWidth, (enemy.rowNum * enemy.enemyHeight) + 40, enemy.enemyWidth, enemy.enemyHeight }; // attack1
    static Uint32 StartTime = SDL_GetTicks();

    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - StartTime) / 150.0f;

    fT4 = static_cast<int>(deltaTime) % enemy.walkingFrameNum;
    fT5 = static_cast<int>(deltaTime) % 2;
    fT6 = static_cast<int>(deltaTime) % 10;
    fT7 = static_cast<int>(deltaTime) % enemy.bendingFrameNum;

    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    if (enemy.isMovingLeft || enemy.isMovingRight) {
        if (enemy.isMovingLeft) {
            SDL_RenderCopyEx(renderer, spriteSheet2, &srcRect, &dstrectEnemy, 0, NULL, SDL_FLIP_HORIZONTAL);
            enemyDir = 1;
        }
        else {
            SDL_RenderCopy(renderer, spriteSheet2, &srcRect, &dstrectEnemy);
            enemyDir = 2;
        }
    }
    else if (enemy.isJumping) {
        if (enemyDir == 1) {
            flipType = SDL_FLIP_HORIZONTAL;
        }
        else {
            flipType = SDL_FLIP_NONE;
        }
        SDL_RenderCopyEx(renderer, spriteSheet2, &srcRect3, &dstrectEnemy, 0, NULL, flipType);
    }
    else if (enemy.bendingType != 0) {
        if (enemy.bendingType == 1) {
            if (enemyDir == 1) {
                flipType = SDL_FLIP_HORIZONTAL;
            }
            else {
                flipType = SDL_FLIP_NONE;
            }
            SDL_RenderCopyEx(renderer, spriteSheet2, &bend, &dstrectEnemy, 0, NULL, flipType);
        }
    }
    else {
        StartTime = SDL_GetTicks();
        if (enemyDir == 1) {
            flipType = SDL_FLIP_HORIZONTAL;
        }
        else {
            flipType = SDL_FLIP_NONE;
        }
        SDL_RenderCopyEx(renderer, spriteSheet2, &srcRect2, &dstrectEnemy, 0, NULL, flipType);
    }
}

void  renderLoseMenu(SDL_Renderer* renderer) {
    SDL_SetTextureAlphaMod(setting, 255);
    SDL_SetTextureAlphaMod(play, 255);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect);
    SDL_RenderCopy(renderer, setting, NULL, &settingButton);
    SDL_RenderCopy(renderer, play, NULL, &playButton);
}

void  renderMainMenu(SDL_Renderer* renderer) {
    SDL_SetTextureAlphaMod(setting, 255);
    SDL_SetTextureAlphaMod(help, 255);
    SDL_SetTextureAlphaMod(play, 255);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect);
    SDL_RenderCopy(renderer, logoTexture, NULL, &logoRect);
    SDL_RenderCopy(renderer, setting, NULL, &settingButton);
    SDL_RenderCopy(renderer, play, NULL, &playButton);
    SDL_RenderCopy(renderer, help, NULL, &helpButton);

}

void  renderHelp(SDL_Renderer* renderer) {
    SDL_SetTextureAlphaMod(returnback, 255);
    SDL_RenderCopy(renderer, helpbackground, NULL, &rect);
    SDL_RenderCopy(renderer, returnback, NULL, &returnbackButton);
    SDL_RenderCopy(renderer, realhelpbutton, NULL, &realhelpButtonRect);

}

void  renderSetting(SDL_Renderer* renderer) {
    SDL_SetTextureAlphaMod(returnback, 255);
    SDL_RenderCopy(renderer, settingbackground, NULL, &rect);
    SDL_RenderCopy(renderer, returnback, NULL, &returnbackButton);
}

void  renderRealHelp(SDL_Renderer* renderer) {

    SDL_RenderCopy(renderer, realhelp, NULL, &rect);
    if (isPaused == false) {
        SDL_SetTextureAlphaMod(returnback, 255);
        SDL_RenderCopy(renderer, returnback, NULL, &returnbackButton);
    }

}

void  renderWinAndScroll(SDL_Renderer* renderer, SDL_Texture* scroll) {
    if (!youwinRendered) {
        for (int i = 0; i <= 255; i++) {
            SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect); // 绘制背景
            SDL_SetTextureAlphaMod(youwin, i); // 设置youwin的透明度
            SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 绘制youwin
            SDL_RenderPresent(renderer); // 更新渲染器
            SDL_Delay(4); // 小延时
        }

        // 在继续之前确保youwin保持显示
        SDL_SetTextureAlphaMod(youwin, 255); // 确保youwin完全不透明
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect); // 重新绘制背景
        SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 重新绘制youwin

        // 然后开始逐渐显示scroll
        for (int i = 0; i <= 255; i++) {
            SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect); // 再次绘制背景
            SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 保持youwin显示
            SDL_SetTextureAlphaMod(scroll, i); // 设置scroll的透明度
            SDL_RenderCopy(renderer, scroll, NULL, &scrollRect); // 绘制scroll
            SDL_RenderPresent(renderer); // 更新渲染器
            SDL_Delay(4); // 小延时
        }

        // 最后确保scroll也保持显示
        SDL_SetTextureAlphaMod(scroll, 255); // 确保scroll完全不透明
        youwinRendered = true;
    }
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect); // 最后一次绘制背景
    SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 确保youwin显示
    SDL_RenderCopy(renderer, scroll, NULL, &scrollRect); // 确保scroll显示
    SDL_RenderPresent(renderer); // 更新渲染器
}

void  renderYouWin(SDL_Renderer* renderer) {
    SDL_SetTextureAlphaMod(youwin, 0);
    for (int i = 0; i <= 255; i++) {
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect);
        SDL_RenderCopy(renderer, youwin, NULL, &youwinRect);
        SDL_RenderPresent(renderer);
        SDL_SetTextureAlphaMod(youwin, i);
    }
    SDL_Delay(700);
    gameState = MAP;
    isWin = false;
    // gameisRunning = false;
}

void renderaMap(SDL_Texture* backmap, SDL_Texture* backmappluswin, SDL_Texture* latermap) {
    if (!mapRendered) {
        SDL_RenderCopy(renderer, backmap, NULL, &rect);
        for (int i = 0; i <= 255 && !mapRendered; i++) {
            SDL_RenderCopy(renderer, backmap, NULL, &rect);
            SDL_RenderCopy(renderer, backmappluswin, NULL, &rect);
            SDL_RenderPresent(renderer);
            SDL_SetTextureAlphaMod(backmappluswin, i);
        }
        SDL_Delay(1000);
        for (int j = 0; j <= 255 && !mapRendered; j++) {
            SDL_RenderCopy(renderer, backmappluswin, NULL, &rect);
            SDL_RenderCopy(renderer, latermap, NULL, &rect);
            SDL_RenderPresent(renderer);
            SDL_SetTextureAlphaMod(latermap, j);
            if (j == 255) {
                mapRendered = true; // 表示latermap已经完全渲染
            }
        }
    }
    SDL_RenderCopy(renderer, latermap, NULL, &rect);

}