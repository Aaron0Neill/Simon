// author Aaron O Neill && mantas
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

	void resetButtons();
	void setupButton(); //function to setup all the buttons
	void setupText();  //function to setup text
	void setupAudio(); //load audio file and setup sounds

	void startingUpdate(sf::Time t_deltaTime); //update game in menu mode
	void randomiseNotes(); //assign a new set of notes to the array
	void showingUpdate(sf::Time t_deltaTime); //update game in demo mode
	void countdownTimers(); //manage timers

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
	bool m_redButtonPressed{ false }; //controls if the red button is pressed
	bool m_yellowButtonPressed{ false }; //controls if the yellow button is pressed
	bool m_blueButtonPressed{ false }; //controls if the blue button is pressed
	bool m_greenButtonPressed{ false }; //controls if the green button is pressed
	int m_noteSequence[32]; //array of notes
	int m_difficultyLevel; //difficulty 8,16,32
	int m_currentNote; //current note count
	int m_currentCount; //current sequence length


	sf::SoundBuffer m_toneBuffer;
	sf::Sound m_blueTone;
	sf::Sound m_redTone;
	sf::Sound m_greenTone;
	sf::Sound m_yellowTone;

	int m_blueTimer = 0; //time till blue button returns to normal color
	int m_redTimer = 0; //time till red button returns to normal color
	int m_greenTimer = 0; //time till green button returns to normal color
	int m_yellowTimer = 0; //time till yellow button returns to normal color
	int m_flashTime = 15; //current time delay for buttons to return to normal color

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

