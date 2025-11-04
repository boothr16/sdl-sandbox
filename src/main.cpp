#include <SDL3/SDL.h>
#include <iostream>

int main() 
{
    if (!SDL_Init(SDL_INIT_VIDEO)) 
    {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << '\n';
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Hello SDL3!",
        800, 600,
        SDL_WINDOW_RESIZABLE);
    if (!window) 
    {
        std::cerr << "Error creating window: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;
    while (running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }
        // Fill the window with a color (red, green, blue, alpha)
        SDL_Surface *surface = SDL_GetWindowSurface(window);
        SDL_FillSurfaceRect(surface, nullptr, SDL_MapRGB(SDL_GetPixelFormatDetails(surface->format),
            nullptr,
            100, 149, 237)); // cornflower blue
        SDL_UpdateWindowSurface(window);

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
