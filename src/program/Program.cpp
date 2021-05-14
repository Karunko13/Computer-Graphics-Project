#include "../../include/program/Program.h"

Program::Program()
{
    std::string title = "BCG - Slides Animations";
    sf::VideoMode window_bounds(1280, 720);
    window_bounds.bitsPerPixel = sf::VideoMode::getDesktopMode().bitsPerPixel;
    unsigned fps_limit = 60;
    bool vertical_sync_enabled = 0;

	m_window = new sf::RenderWindow(window_bounds, title, sf::Style::Close | sf::Style::Titlebar);
	m_window->setFramerateLimit(fps_limit);
	m_window->setVerticalSyncEnabled(vertical_sync_enabled);
}

Program::~Program()
{
	
}

void Program::endApp()
{
    std::cout << "Ending Application" << std::endl;
}

void Program::updateDeltaTime()
{
    /*Updates the deltaTime variable with the time it takes to update and render one frame*/
   m_deltaTime = m_dtClock.restart().asSeconds();
}

void Program::updateSFMLEvents()
{
    while(m_window->pollEvent(m_event))
    {
    	switch(m_event.type)
    	{
    		case sf::Event::Closed:
    		{
    			m_window->close();
    			break;
    		}
    		default: break;
    	}//switch
    }//while
}

void Program::update()
{    
    if(m_window->isOpen())
    {
		this->updateDeltaTime();
		this->updateSFMLEvents();

		//here there will be panels updated

    }
    else//Applications end
    {
    	this->endApp();
    }
}

void Program::render()
{
   m_window->clear();

   //here there will be panels rendered

   m_window->display();
}

void Program::run()
{
    while(m_window->isOpen())
    {
       this->update();
       this->render();
    }
}