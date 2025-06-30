#include "gui.h"
#include "shell.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include <sstream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int FONT_SIZE = 18;
const int LINE_SPACING = 4;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
TTF_Font *font = nullptr;

std::vector<std::string> displayedLines;
std::string currentInput;

bool init_gui()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return false;
    if (TTF_Init() != 0)
        return false;

    window = SDL_CreateWindow("Shell Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
        return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
        return false;

    font = TTF_OpenFont("assets/FiraCode-Light.ttf", FONT_SIZE);
    if (!font)
        return false;

    return true;
}

void render_text(const std::string &text, int y)
{
    SDL_Color color = {255, 255, 255}; // White
    SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    int text_width, text_height;
    SDL_QueryTexture(texture, nullptr, nullptr, &text_width, &text_height);
    SDL_Rect dst = {10, y, text_width, text_height};

    SDL_RenderCopy(renderer, texture, nullptr, &dst);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void render_screen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);

    int y = 10;
    for (const auto &line : displayedLines)
    {
        render_text(line, y);
        y += FONT_SIZE + LINE_SPACING;
    }

    // Draw input line
    render_text("> " + currentInput, y);

    SDL_RenderPresent(renderer);
}

void run_gui(Shell &shell)
{
    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;

            else if (event.type == SDL_TEXTINPUT)
            {
                currentInput += event.text.text;
            }

            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_BACKSPACE:
                    if (!currentInput.empty())
                        currentInput.pop_back();
                    break;

                case SDLK_RETURN:
                {
                    displayedLines.push_back("> " + currentInput);
                    std::string output = shell.execute(currentInput);

                    // Split multi-line output properly
                    std::istringstream iss(output);
                    std::string line;
                    while (std::getline(iss, line))
                    {
                        displayedLines.push_back(line);
                    }

                    currentInput.clear();
                    break;
                }

                case SDLK_ESCAPE:
                    running = false;
                    break;
                }
            }
        }

        render_screen();
        SDL_Delay(16); // ~60 FPS
    }
}

void cleanup_gui()
{
    if (font)
        TTF_CloseFont(font);
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}
