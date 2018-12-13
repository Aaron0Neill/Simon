// author Aaron O Neill && mantas
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
/// <summary>
/// The four different modes the game can be in
/// </summary>
enum class GameMode
{
	Showing,
	Recieving,
	GameOver,
	Starting
};
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	GameMode m_currentGameMode; // current mode the game is in

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setupButton(); //function to setup all the buttons
	void setupText();  //function to setup text

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
	bool m_redButtonPressed; //controls if the red button is pressed
	bool m_yellowButtonPressed; //controls if the yellow button is pressed
	bool m_blueButtonPressed; //controls if the blue button is pressed
	bool m_greenButtonPressed; //controls if the green button is pressed
	sf::RectangleShape m_redSquare; // it's rectangle shape for a red button.
	sf::RectangleShape m_yellowSquare; // it's rectangle shape for a yellow button.
	sf::RectangleShape m_blueSquare; // it's rectangle shape for a blue button.
	sf::RectangleShape m_greenSquare; // it's rectangle shape for a green button.
	sf::Font m_impactFont; //font used in text
	sf::Text m_titleText; // main title text for simon
	sf::Text m_instructionsTextBlue; // text for blue instructions
	sf::Text m_instructionsTextRed; // text for red instructions
	sf::Text m_instructionsTextGreen; // text for green instructions
	sf::Text m_instructionsTextYellow; // text for yellow instructions
	sf::Text m_statusText; // text for status
};

#endif // !GAME

