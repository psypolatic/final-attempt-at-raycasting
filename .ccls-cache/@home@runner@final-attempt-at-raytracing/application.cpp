#include "application.hpp"
#include "helper.hpp"
#include "player.hpp"
Application::Application()
{
    m_window = SDL_CreateWindow("SDL2 Window",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                600, 600,
                                0);

    if(!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
    m_renderer = NULL;
    m_window_surface = SDL_GetWindowSurface(m_window);

    if(!m_window_surface)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    // FINNALY I GOT THIS STUPID ASS SHIT TO LOAD OH MY FUCKING GOSH
    // I DON'T EVEN KNOW WHAT I'M DOING WITH THIS
    // I HATE THE RENDERER
    //ONLY PART THAT GAVE ME ANY TYPE OF ISSUE
    //SMH 
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);
    //hindsight 14 days later we dont have a graphics card and i probably shouldve looked
    //at the docs
    
    if (!m_renderer){
        std::cout << "Failed to create renderer\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

}

Application::~Application()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

void Application::loop()
{
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&m_window_event) > 0)
        {
            player.handle_events(m_window_event);
            switch(m_window_event.type)
            {
    
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }

        update(1.0/30.0);
        draw();
    }
}

void Application::update(double delta_time)
{
   player.update(delta_time);

    
}

void Application::draw()
{
    SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 200, 0, 0));
    player.draw(m_window_surface,m_renderer);
    SDL_RenderPresent( m_renderer );
    SDL_UpdateWindowSurface(m_window);
}