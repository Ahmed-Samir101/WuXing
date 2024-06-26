#include "./vars.h"

void setup() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    SDL_Init(SDL_INIT_TIMER);
    TTF_Init();
    int flags = MIX_INIT_MP3;
    if ((Mix_Init(flags) & flags) != flags)
    {
        std::cout << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "Failed to open audio: " << Mix_GetError() << std::endl;
    }

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    music = Mix_LoadMUS("./assets/m.mp3");
    if (!music)
    {
        std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
    }
    // Load textures for the Player facing left and right, and background
    SDL_Surface* surfaceBackground = IMG_Load("./assets/background1.png");
    SDL_Surface* surfaceBG1 = IMG_Load("./assets/bg1.jpg");
    SDL_Surface* surfaceBG2 = IMG_Load("./assets/bg2.jpg");
    SDL_Surface* surfaceBG3 = IMG_Load("./assets/bg3.jpg");
    SDL_Surface* surfaceBG4 = IMG_Load("./assets/bg4.jpg");
    SDL_Surface* surfaceBG5 = IMG_Load("./assets/bg5.jpg");
    SDL_Surface* surfaceBG6 = IMG_Load("./assets/bg6.jpg");
    SDL_Surface* surfaceShield = IMG_Load("./assets/shield.png");
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
    SDL_Surface* surfaceYouWin = IMG_Load("./assets/youwin.png");
    SDL_Surface* surfaceHeart = IMG_Load("./assets/heart.png");
    SDL_Surface* surfaceVoiceOpen = IMG_Load("./assets/soundON.png");
    SDL_Surface* surfaceVoiceClose = IMG_Load("./assets/soundOFF.png");
    SDL_Surface* surfaceScroll_1 = IMG_Load("./assets/scroll1.png");
    SDL_Surface* surfaceScroll_2 = IMG_Load("./assets/scroll2.png");

    // Create textures from loaded surfaces
    shieldTexture = SDL_CreateTextureFromSurface(renderer, surfaceShield);
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, surfaceBackground);
    bg1Texture = SDL_CreateTextureFromSurface(renderer, surfaceBG1);
    bg2Texture = SDL_CreateTextureFromSurface(renderer, surfaceBG2);
    bg3Texture = SDL_CreateTextureFromSurface(renderer, surfaceBG3);
    bg4Texture = SDL_CreateTextureFromSurface(renderer, surfaceBG4);
    bg5Texture = SDL_CreateTextureFromSurface(renderer, surfaceBG5);
    bg6Texture = SDL_CreateTextureFromSurface(renderer, surfaceBG6);
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
    soundON = SDL_CreateTextureFromSurface(renderer, surfaceVoiceOpen);
    soundOFF = SDL_CreateTextureFromSurface(renderer, surfaceVoiceClose);
    scroll_1 = SDL_CreateTextureFromSurface(renderer, surfaceScroll_1);
    scroll_2 = SDL_CreateTextureFromSurface(renderer, surfaceScroll_2);

    currentBackgroundTexture = bg1Texture;

}

SDL_Rect initialButtonSize1 = { (WINDOW_WIDTH - 280) / 2, 365, 280, 60 };
SDL_Rect initialButtonSize2 = { (WINDOW_WIDTH - 280) / 2, 465, 280, 60 };
SDL_Rect initialButtonSize3 = { (WINDOW_WIDTH - 280) / 2, 565, 280, 60 };
SDL_Rect hoverButtonSize1 = { (WINDOW_WIDTH - 310) / 2, 365, 310, 65 };
SDL_Rect hoverButtonSize2 = { (WINDOW_WIDTH - 310) / 2, 465, 310, 65 };
SDL_Rect hoverButtonSize3 = { (WINDOW_WIDTH - 310) / 2, 565, 310, 65 };

// Function to render the background scene
void renderScene() {
    std::string xpText = std::to_string(xpValue);
    SDL_Rect bgRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    SDL_Rect hpPlayerBarRect = { 25, 12, 4 * player.health, 40 };
    SDL_Rect Playercooldownbar = { 25, 600, player.cooldown*3, 20 };
    SDL_Rect hpEnemyBarRect = { WINDOW_WIDTH - 400, 12, 4 * enemy.health, 40 };
    SDL_Rect dstTextRectPlayer = { (WINDOW_WIDTH-100)/2, 50, 100, 100};
    SDL_Rect dstTextRectEnemy = { WINDOW_WIDTH - 50, 0, 50, 50 };
    TTF_Font* font = TTF_OpenFont("./assets/font1.ttf", 100);
    SDL_Color textColor = { 255, 255, 255, 255 }; // White color for the text
    text = TTF_RenderText_Blended(font, xpText.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, text);
    
    SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &bgRect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &hpPlayerBarRect);
    SDL_RenderFillRect(renderer, &hpEnemyBarRect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &Playercooldownbar);
    SDL_RenderCopy(renderer, heartTexture, NULL, &heartRect1);
    SDL_RenderCopy(renderer, heartTexture, NULL, &heartRect2);
    SDL_RenderCopy(renderer, textTexture, NULL, &dstTextRectPlayer);
}
// Function to render the player Player with animations
void renderPlayer()
{
    SDL_Rect dstrectPlayer = { player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT };
    SDL_Rect srcRect  = { fT1 * player.width, 3 * player.height, player.width, player.height };
    SDL_Rect srcRect2 = { fT2 * 180, 0, 180, 192 };
    SDL_Rect srcRect3 = { fT3 * 180, 8 * 180, 180, 192 };
    SDL_Rect bend     = { fT1 * 180, 8 * 180, 180, 192 };
    SDL_Rect block    = { fT1 * 180, 8 * 180, 180, 192 };
    static Uint32 StartTime1 = SDL_GetTicks();

    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - StartTime1) / 150.0f;

    fT1 = static_cast<int>(deltaTime) % 8;
    fT2 = static_cast<int>(deltaTime) % 8;
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

bool isMouseInsideRect(const SDL_Point& mousePosition, const SDL_Rect& rect) {
    return mousePosition.x >= rect.x && mousePosition.x < rect.x + rect.w &&
           mousePosition.y >= rect.y && mousePosition.y < rect.y + rect.h;
}

void renderMainMenu() {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_Point mousePosition = { mouseX, mouseY };

    if (isMouseInsideRect(mousePosition, settingButton)) {
        settingButton = hoverButtonSize3;
    } else {
        settingButton = initialButtonSize3;
    }

    if (isMouseInsideRect(mousePosition, playButton)) {
        playButton = hoverButtonSize1;
    } else {
        playButton = initialButtonSize1;
    }

    if (isMouseInsideRect(mousePosition, helpButton)) {
        helpButton = hoverButtonSize2;
    } else {
        helpButton = initialButtonSize2;
    }
    SDL_SetTextureAlphaMod(setting, 255);
    SDL_SetTextureAlphaMod(help, 255);
    SDL_SetTextureAlphaMod(play, 255);
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, &rect);
    SDL_RenderCopy(renderer, logoTexture, nullptr, &logoRect);
    SDL_RenderCopy(renderer, play, nullptr, &playButton);
    SDL_RenderCopy(renderer, help, nullptr, &helpButton);
    SDL_RenderCopy(renderer, setting, nullptr, &settingButton);
}

void renderLoseMenu(){
    SDL_SetTextureAlphaMod(setting, 255);
    SDL_SetTextureAlphaMod(play, 255);
    SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &rect);
    SDL_RenderCopy(renderer, setting, NULL, &settingButton);
    SDL_RenderCopy(renderer, play, NULL, &playButton);
}

void  renderHelp(){
    SDL_SetTextureAlphaMod(returnback, 255);
    SDL_RenderCopy(renderer, helpbackground, NULL, &rect);
    SDL_RenderCopy(renderer, returnback, NULL, &returnbackButton);
    SDL_RenderCopy(renderer, realhelpbutton, NULL, &realhelpButtonRect);

}

void  renderSetting(){
    SDL_SetTextureAlphaMod(returnback, 255);
    SDL_RenderCopy(renderer, settingbackground, NULL, &rect);
    SDL_RenderCopy(renderer, returnback, NULL, &returnbackButton);
    if (chooseclosemusic == false) {
        SDL_RenderCopy(renderer, soundON, NULL, &voiceRect);
    }
    else {
        SDL_RenderCopy(renderer, soundOFF, NULL, &voiceRect);
    }
}

void  renderRealHelp(){

    SDL_SetTextureAlphaMod(returnback, 255);
    SDL_RenderCopy(renderer, settingbackground, NULL, &rect);
    SDL_RenderCopy(renderer, returnback, NULL, &returnbackButton);
    if (chooseclosemusic == false) {
        SDL_RenderCopy(renderer, soundON, NULL, &voiceRect);
    }
    else {
        SDL_RenderCopy(renderer, soundOFF, NULL, &voiceRect);
    }

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

void  renderWinAndScroll(SDL_Renderer* renderer, SDL_Texture* scroll) {
    if (!youwinRendered) {
        for (int i = 0; i <= 255; i++) {
            SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &rect); // 绘制背景
            SDL_SetTextureAlphaMod(youwin, i); // 设置youwin的透明度
            SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 绘制youwin
            SDL_RenderPresent(renderer); // 更新渲染器
            SDL_Delay(4); // 小延时
        }

        // 在继续之前确保youwin保持显示
        SDL_SetTextureAlphaMod(youwin, 255); // 确保youwin完全不透明
        SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &rect); // 重新绘制背景
        SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 重新绘制youwin

        // 然后开始逐渐显示scroll
        for (int i = 0; i <= 255; i++) {
            SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &rect); // 再次绘制背景
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
    SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &rect); // 最后一次绘制背景
    SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 确保youwin显示
    SDL_RenderCopy(renderer, scroll, NULL, &scrollRect); // 确保scroll显示
    SDL_RenderPresent(renderer); // 更新渲染器
    //isWin = false;
    //gameState = MAP;
}

void  renderYouWin() {
    if (!youwinRendered) {
        for (int i = 0; i <= 255; i++) {
            SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &rect); // 绘制背景
            SDL_SetTextureAlphaMod(youwin, i); // 设置youwin的透明度
            SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 绘制youwin
            SDL_RenderPresent(renderer); // 更新渲染器
            SDL_Delay(4); // 小延时
        }
        // 在继续之前确保youwin保持显示
        SDL_SetTextureAlphaMod(youwin, 255); // 确保youwin完全不透明
        youwinRendered = true;
    }
    SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &rect); // 最后一次绘制背景
    SDL_RenderCopy(renderer, youwin, NULL, &youwinRect); // 确保youwin显示
    SDL_RenderPresent(renderer); // 更新渲染器
    //SDL_Delay(700);
    //isWin = false;
    //gameState = MAP;
    // gameisRunning = false;
}

// void  renderDailogue(){
//     SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &bgRect);
//     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//     SDL_RenderFillRect(renderer, &hpPlayerBarRect);
//     SDL_RenderFillRect(renderer, &hpEnemyBarRect);
//     SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//     SDL_RenderFillRect(renderer, &Playercooldownbar);
//     SDL_RenderCopy(renderer, heartTexture, NULL, &heartRect1);
//     SDL_RenderCopy(renderer, heartTexture, NULL, &heartRect2);
//     SDL_RenderCopy(renderer, textTexture, NULL, &dstTextRectPlayer);
// }

void renderVoicePicture() {
    int i;
    if (chooseclosemusic == true) {
        if (!voiceRendered) {

            for (i = 0; i <= 255 && !voiceRendered; i++) {
                SDL_RenderCopy(renderer, soundON, NULL, &voiceRect);
                SDL_RenderCopy(renderer, soundOFF, NULL, &voiceRect);
                SDL_RenderPresent(renderer);
                SDL_SetTextureAlphaMod(soundOFF, i);
            }
            if (i == 255) {
                voiceRendered = true; // 表示latermap已经完全渲染

            }
            SDL_Delay(20);

        }
        SDL_RenderCopy(renderer, soundOFF, NULL, &voiceRect);
    }
    
    else if (chooseclosemusic == false) {
        if (!voiceRendered) {

            for (i = 255; i >= 0 && !voiceRendered; i--) {
                SDL_RenderCopy(renderer, soundON, NULL, &voiceRect);
                SDL_RenderCopy(renderer, soundOFF, NULL, &voiceRect);
                SDL_RenderPresent(renderer);
                SDL_SetTextureAlphaMod(soundOFF, i);
            }
          

        }
        SDL_RenderCopy(renderer, soundON, NULL, &voiceRect);
    }
    voiceRendered = false;
}