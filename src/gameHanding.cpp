#include "./rendering.cpp"

void decreaseIntOverTime(int* a, Uint32 deltaTime) {
    int decreaseAmount = (int)(decreaseRate * deltaTime);
    if ((*a - decreaseAmount) >= 0) {
        *a -= decreaseAmount;
    }
    else {
        *a = 0;
        startcooldown = 0;
    }
}

int bendingSkill(int& bending, SDL_Texture* texture);
int blockingSkill(int& bending, SDL_Texture* texture);
void setPlayerBendProperties(SDL_Texture& texture, int frame_num, int frame_Y, int frame_width, int frame_height, int invDir, int v1, int v2);

void changeColor(SDL_Texture* imageTexture, SDL_Rect imageRect) {
    // 设置图片颜色为暗色
    //SDL_SetTextureColorMod(imageTexture, 128, 128, 128);
    // 渲染变暗的图片
    for (int i = 255; i > 1; i--) {
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &rect);
        SDL_RenderCopy(renderer, imageTexture, NULL, &imageRect);
        SDL_RenderPresent(renderer);
        SDL_SetTextureAlphaMod(imageTexture, i);
    }

    // 暂停一段时间
        //SDL_Delay(20000);
}

void changeEnemy() {
    printf("Mission:%d\n", mission);
    if (mission == FIRST) {
        spriteSheet2 = SDL_CreateTextureFromSurface(renderer, enemySurface2);
        // enemy.enemyWidth = 78;
        // enemy.enemyHeight = 56;
        enemy.walkingFrameNum = 8;
        enemy.rowNum = 0;
        enemy.bendingType = 2;
    }
    else if (mission == SECOND) {
        spriteSheet2 = SDL_CreateTextureFromSurface(renderer, enemySurface3);
        // enemy.enemyWidth = 160;
        // enemy.enemyHeight = 171;
        enemy.walkingFrameNum = 8;
        enemy.rowNum = 1;
        enemy.bendingType = 3;
    }
    else if (mission == THIRD) {
        spriteSheet2 = SDL_CreateTextureFromSurface(renderer, enemySurface4);
        // enemy.enemyWidth = 183;
        // enemy.enemyHeight = 140;
        enemy.walkingFrameNum = 8;
        enemy.rowNum = 1;
        enemy.bendingType = 4;
    }
    else if (mission == FOURTH) {
        spriteSheet2 = SDL_CreateTextureFromSurface(renderer, enemySurface5);
        // enemy.enemyWidth = 157;
        // enemy.enemyHeight = 152;
        enemy.walkingFrameNum = 8;
        enemy.rowNum = 2;
        enemy.bendingType = 5;
    }
    else if (mission == FIFTH) {
        spriteSheet2 = SDL_CreateTextureFromSurface(renderer, enemySurface6);
    }
    else if (mission == SIXTH) {
        spriteSheet2 = SDL_CreateTextureFromSurface(renderer, enemySurface7);
    }
}

void resetGameState() {
    // 重置玩家和敌人的状态到初始值
    player.x = 100;
    player.y = 100;
    player.dx = 0;
    player.dy = 0;
    player.isJumping = false;
    player.jumpCount = 0;
    player.health = 100;
    // 敌人状态也被重置
    enemy.x = 500;
    enemy.y = 310;
    enemy.dx = 0;
    enemy.dy = 0;
    enemy.isJumping = false;
    enemy.health = 100;
    xpValue = 0;
}

void handleInputatHelp() {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            if (mouseX > realhelpButtonRect.x && mouseX < realhelpButtonRect.x + realhelpButtonRect.w &&
                mouseY > realhelpButtonRect.y && mouseY < realhelpButtonRect.y + realhelpButtonRect.h) {
                // changeColor(realhelpbutton, realhelpButtonRect);

                gameState = REALHELP;

            }
            else if (mouseX > returnbackButton.x && mouseX < returnbackButton.x + returnbackButton.w &&
                mouseY > returnbackButton.y && mouseY < returnbackButton.y + returnbackButton.h) {
                changeColor(returnback, returnbackButton);

                gameState = MENU;
            }


        }
    }
}

void handleInputatMenu() {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            // 检查是否点击Play按钮
            if (mouseX > playButton.x && mouseX < playButton.x + playButton.w &&
                mouseY > playButton.y && mouseY < playButton.y + playButton.h) {
                // 重置游戏状态来重新开始
                changeColor(play, playButton);
                resetGameState();
                gameState = PLAYING;
            }
            else if (mouseX > settingButton.x && mouseX < settingButton.x + settingButton.w &&
                mouseY > settingButton.y && mouseY < settingButton.y + settingButton.h) {
                changeColor(setting, settingButton);
                gameState = SETTING;
            }
            else if (mouseX > helpButton.x && mouseX < helpButton.x + helpButton.w &&
                mouseY > helpButton.y && mouseY < helpButton.y + helpButton.h) {
                changeColor(help, helpButton);
                gameState = HELP;
            }
        }
    }
}

void handleInputatSetting() {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            if (mouseX > returnbackButton.x && mouseX < returnbackButton.x + returnbackButton.w &&
                mouseY > returnbackButton.y && mouseY < returnbackButton.y + returnbackButton.h) {
                changeColor(returnback, returnbackButton);
                gameState = MENU;
            }
            if (mouseX > voiceRect.x && mouseX < voiceRect.x + voiceRect.w &&
                mouseY > voiceRect.y && mouseY < voiceRect.y + voiceRect.h) {
                chooseclosemusic = !chooseclosemusic;
                renderVoicePicture();

            }
        }
    }
}

void handleInputatRealHelp() {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN && isPaused == false)
        {
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            if (mouseX > returnbackButton.x && mouseX < returnbackButton.x + returnbackButton.w &&
                mouseY > returnbackButton.y && mouseY < returnbackButton.y + returnbackButton.h) {
                changeColor(returnback, returnbackButton);

                gameState = MENU;

            }
        }
        else if (event.type == SDL_KEYDOWN && isPaused == true)
        {

            if (event.key.keysym.sym == SDLK_p) {

                gameState = PLAYING;
                isPaused = false;
            }
        }
    }
}

void handleInputatMap() {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) {
            gameisRunning = false;
        }

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                gameState = PLAYING;
                isWin = false;
                mapRendered = false;
                changeEnemy();
            }
        }
    }
}

void attacklasttime() {
    if (startcooldown == 0) {
        lastAttackTime = SDL_GetTicks();
    }
}

// Function to handle user input events
void handleInput() {
    SDL_Event event;
    Uint32 currentTime = SDL_GetTicks();

    // Calculate the time elapsed since the last key press
    Uint32 elapsedTime = currentTime - lastKeyPressTime;

    // Set a cooldown period of set milliseconds (adjust as needed)
    Uint32 cooldown = 100;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            gameisRunning = false;
        }
        else if (event.key.keysym.sym == SDLK_ESCAPE) {
            gameisRunning = false;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN && (isLosed || isPaused))
        {
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            // 检查是否点击Play按钮
            if (mouseX > playButton.x && mouseX < playButton.x + playButton.w &&
                mouseY > playButton.y && mouseY < playButton.y + playButton.h && !isPaused && isLosed) {
                // 重置游戏状态来重新开始
                isLosed = false;
                changeColor(play, playButton);
                resetGameState();

            }
            else if (mouseX > settingButton.x && mouseX < settingButton.x + settingButton.w &&
                mouseY > settingButton.y && mouseY < settingButton.y + settingButton.h && isLosed && !isPaused) {
                changeColor(setting, settingButton);
                gameState = MENU;
                isLosed = false;
                return;
            }
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.repeat == 0)
            {
                // Check if the cooldown has expired or if it's a specific key (e.g., SDLK_LEFT or SDLK_RIGHT)
                if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT)
                {
                    // Reset player.jumpCount when the player lands on the ground
                    if (event.key.keysym.sym == SDLK_SPACE)
                    {
                        if (player.jumpCount < 2 || player.y + PLAYER_HEIGHT >= WINDOW_HEIGHT - yLimit) {
                            player.dy = -JUMP_FORCE;
                            player.isJumping = true;
                            player.jumpCount++;
                        }
                    }
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        player.isMovingLeft = true;
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT) {
                        player.isMovingRight = true;
                    }
                    if (event.key.keysym.sym == SDLK_q) {
                        // Perform action if cooldown has expired or it's a specific key
                        if (elapsedTime >= cooldown - cooldown / 2 || event.key.keysym.sym == SDLK_q) {
                            player.isBlocking = true;
                            // setPlayerBendProperties(*shieldTexture, 5, 0, 192, 192, 1, 210, 420);
                            blockingSkill(playerbend.bending, shieldTexture);
                            lastKeyPressTime = currentTime; // Update the last key press time
                            // attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_e) {
                        // Perform action if cooldown has expired or it's a specific key
                        if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_e) {
                            player.playerAttack = true;
                            setPlayerBendProperties(*fireSheet, 10, 310, 53, 51, 1, 125, 125);
                            bendingSkill(playerbend.bending, playerbend.texture);
                            lastKeyPressTime = currentTime; // Update the last key press time
                            attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_r && skills [1]) {
                        if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_r) {
                            player.playerAttack = true;
                            setPlayerBendProperties(*waterSheet, 5, 0, 192, 192, 2, 210, 315);
                            bendingSkill(playerbend.bending, playerbend.texture);
                            lastKeyPressTime = currentTime;
                            attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_f && skills [2]) {
                        if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_f) {
                            player.playerAttack = true;
                            setPlayerBendProperties(*earthSheet, 5, 0, 192, 192, 1, 210, 420);
                            bendingSkill(playerbend.bending, playerbend.texture);
                            lastKeyPressTime = currentTime;
                            attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_g && skills [3]) {
                        if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_g) {
                            player.playerAttack = true;
                            setPlayerBendProperties(*windSheet, 5, 0, 192, 200, 1, 210, 315);
                            bendingSkill(playerbend.bending, playerbend.texture);
                            lastKeyPressTime = currentTime;
                            attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_h && skills [4]) {
                        if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_h) {
                            player.playerAttack = true;
                            setPlayerBendProperties(*lightSheet, 5, 192, 192, 192, 1, 210, 315);
                            bendingSkill(playerbend.bending, playerbend.texture);
                            lastKeyPressTime = currentTime;
                            attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_v && skills [5])
                    {
                        if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_v) {
                            player.playerAttack = true;
                            setPlayerBendProperties(*firelightSheet, 5, 0, 192, 192, 1, 210, 315);
                            bendingSkill(playerbend.bending, playerbend.texture);
                            lastKeyPressTime = currentTime;
                            attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_b && skills [6])
                    {
                        if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_b) {
                            player.playerAttack = true;
                            setPlayerBendProperties(*waterlightSheet, 5, 384, 192, 192, 1, 210, 315);
                            bendingSkill(playerbend.bending, playerbend.texture);
                            lastKeyPressTime = currentTime;
                            attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_n && skills [7])
                    {
                        if (elapsedTime >= cooldown || event.key.keysym.sym == SDLK_n) {
                            player.playerAttack = true;
                            setPlayerBendProperties(*firewaterSheet, 5, 0, 192, 192, 1, 210, 315);
                            bendingSkill(playerbend.bending, playerbend.texture);
                            lastKeyPressTime = currentTime;
                            attacklasttime();
                        }
                    }
                    if (event.key.keysym.sym == SDLK_p && isPaused == false && isLosed == false) {
                        isPaused = true; // Toggle pause state
                        gameState = REALHELP;
                        return; // Early return to skip other inputs when paused
                    }
                }
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

    Uint32 cooldowncurrentTime = SDL_GetTicks();
    Uint32 deltaTime = cooldowncurrentTime - lastAttackTime;
    // elapsedTime = cooldowncurrentTime;

    if (startcooldown) {
        // printf("%d\n",deltaTime);
        decreaseIntOverTime(&player.cooldown, deltaTime);
    }

    if (startcooldown == 0 && playerbend.bending == 1) {
        player.cooldown = 200;
        startcooldown = 1;
    }

}

void handleInputatYouwin() {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                if (mission == ZERO) {
                    mission = FIRST;
                    currentBackgroundTexture = bg2Texture;
                }
                else if (mission == FIRST) {
                    mission = SECOND;
                    currentBackgroundTexture = bg3Texture;
                    skills [1] = true;
                }
                else if (mission == SECOND) {
                    mission = THIRD;
                    currentBackgroundTexture = bg4Texture;
                }
                else if (mission == THIRD) {
                    mission = FOURTH;
                    currentBackgroundTexture = bg5Texture;
                }
                else if (mission == FOURTH) {
                    mission = FIFTH;
                    currentBackgroundTexture = bg6Texture;
                }
                else if (mission == FIFTH) {
                    mission = SIXTH;
                }
                else if (mission == SIXTH) {
                    mission = SEVENTH;
                }
                else if (mission == SEVENTH) {
                    mission = EIGHT;
                }
                else if (mission == EIGHT) {
                    mission = NINTH;
                }
                else if (mission == NINTH) {
                    mission = TENTH;
                }
                else if (mission == TENTH) {
                    mission = ELEVENTH;
                }
                else if (mission == ELEVENTH) {
                    mission = TWELVETH;
                }
                else if (mission == TWELVETH) {
                    mission = THIRTEENTH;
                }
                else if (mission == THIRTEENTH) {
                    mission = FOURTEENTH;
                }
                else if (mission == FOURTEENTH) {
                    mission = FIFTEENTH;
                }
                gameState = MAP;
                youwinRendered = false;
                isWin = false;
            }
        }

    }
}
