#pragma once

#include "Button.h"


class AnimControlButton: public Button
{

public:
     /**
     * @brief Default Contructor 
     *   
     * Only setting button outline thickness for 0
     */
	AnimControlButton();

    /**
     * @brief Default Contructor
     *
     * @param pos The position of the AnimControlButton
     *
     * Setting postition and defaults look and size of button.
     *    Buttons outline thicness: 0
     *    Buttons size: 50x50
     *    Buttons icon: button 'play'
     *    
     */
	AnimControlButton(const sf::Vector2f &pos);
    
     /**
     * @brief Default destrucor 
     */
	~AnimControlButton() = default;
    
     /**
     * @brief Gets the information if an Animation is actvite 
     *        (is paused or continue but not ended) currently.
     * 
     * @return  bool value of m_isAnimationActive
     */
	bool isAnimationActive() const;

     /**
     * @brief Reders instatntion of AnimControlButton on sf::RenderTarget.
     *
     * @param RenderTarget The target on which the instatntion is rendered.
     */
	void render(sf::RenderTarget *target) override;

     /**
     * @brief Updates instatntion content
     *
     * @param mousePos The current mouse position 
     * @param event The event hedning clicing of the AnimControlButton 
     */
	void update(sf::Vector2i mousePos, sf::Event &event) override;

     /**
     * @brief Setting bool value of state of currnet/last animation 
     *
     * @param isActive The boolean information of state of animation  
     */
	static void setAnimationActivity(const bool isActive);

protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	static const unsigned int m_x;
	static const unsigned int m_y;

private:
	static bool m_isAnimationActive;

	
};