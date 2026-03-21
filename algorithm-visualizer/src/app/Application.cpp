#include "app/Application.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


Application::Application(){
    m_initialized = false;
    m_running = false;
    m_lastDeltaTimeSeconds = 0.0f;
}

Application::~Application(){


}
Result Application::initialize(){
    if(m_initialized){
       //implementieren, wenn Result fertig
        return true;
    }
    if(createWindow().isFailure){
        //auch hier result
        return false;
    };
    initializeState();
    m_initialized = true;
    return StatusCode::Ok;
}
Result Application::createWindow(){
    int xwidth = 1280;
    int yheight = 720;
    std::string title = "Algorithm Visualizer";
    
}
void Application::initializeState(){
    m_state = AppState();
}
void Application::run(){
    if(!m_initialized){
        return;
    }
    processEvents();
    //hier zeitmessung einfügen
    update(2);
    render();
}
void Application::processEvents()
{
    sf::Event event{};

    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_running = false;
            m_window.close();
            return;
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                m_running = false;
                m_window.close();
                return;
            }
        }

        if (event.type == sf::Event::Resized)
        {
            // Aktuell ignorieren.
        }
    }
}
void Application::update(float deltaTimeSeconds){
    if(m_lastDeltaTimeSeconds < 0.0f)){
        return;
    }
    m_lastDeltaTimeSeconds = deltaTimeSeconds;
}
void Application::render(){
    m_window.clear();
    //hier kommt später was es tun soll

    m_window.display();
}
bool Application::isInitialized() const{
    return m_initialized;
}

