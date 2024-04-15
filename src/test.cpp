#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

Mix_Music* music = nullptr;

bool initializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("SDL Music Player", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window)
    {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    int flags = MIX_INIT_MP3;
    if ((Mix_Init(flags) & flags) != flags)
    {
        std::cout << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "Failed to open audio: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}

bool loadMusic(const std::string& filePath)
{
    music = Mix_LoadMUS(filePath.c_str());
    if (!music)
    {
        std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}

void playMusic()
{
    if (Mix_PlayMusic(music, -1) < 0)
    {
        std::cout << "Failed to play music: " << Mix_GetError() << std::endl;
    }
}

void cleanup()
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (!initializeSDL())
    {
        cleanup();
        return 1;
    }

    std::string musicFilePath = "./assets/m.mp3";

    if (!loadMusic(musicFilePath))
    {
        cleanup();
        return 1;
    }

    playMusic();

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Add your custom rendering code here if needed

        SDL_RenderPresent(renderer);
    }

    cleanup();
    return 0;
}