#include "app/Application.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace av;
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
        return Result::success("already initialized");
    }
    if(createWindow().isError()){
        //auch hier result
        return Result::failure(StatusCode::InitializationFailed, "failed to create window");
    };
    initializeState();
    m_initialized = true;
    return Result::success();
}
Result Application::createWindow(){
   
    int xwidth = 1280;
    int yheight = 720;
    std::string title = "Algorithm Visualizer";
    
    // You are missing the actual creation call here!
    // Without this, m_window remains uninitialized and nothing will show up.
    m_window.create(sf::VideoMode(xwidth, yheight), title); 

    return Result::success();
}
    

void Application::initializeState(){
    m_state = AppState();
}
void Application::run(){
    if(!m_initialized){
        return;
    }
    m_running = true;
    while(m_running){
    processEvents();
    //deltatime berechnen
    update(2);
    render();
    }
    m_running = false;
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
    if(m_lastDeltaTimeSeconds < 0.0f){
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
const AppState& Application::getState() const{
    return m_state;
}
AppState& Application::getState(){
    return m_state;
}
