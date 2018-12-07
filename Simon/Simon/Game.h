// author Aaron O Neill
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setupButton();

	const sf::Color RED{ 255, 30, 30, 255 }; // it's the color red
	const sf::Color GREEN{ 51, 255, 51, 255 }; // it's the color green
	const sf::Color BLUE{ 0, 255, 255, 255 }; // it's the color blue
	const sf::Color YELLOW{ 255, 255, 0, 255 }; // it's the color yellow
	const sf::Color WHITE{ 255, 255, 255, 255 }; // it's the color white


	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	sf::RectangleShape m_redSquare; // it's rectangle shape for a red button.
	sf::RectangleShape m_yellowSquare; // it's rectangle shape for a yellow button.
	sf::RectangleShape m_blueSquare; // it's rectangle shape for a blue button.
	sf::RectangleShape m_greenSquare; // it's rectangle shape for a green button.

};

#endif // !GAME

