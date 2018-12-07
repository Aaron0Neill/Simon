// author Aaron O Neill && mantas

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Simon" },
	m_exitGame{ false }, //when true game will exit
	m_redSquare{ sf::Vector2f{ 200.0f, 200.0f } },
	m_yellowSquare{ sf::Vector2f{ 200.0f, 200.0f } },
	m_greenSquare{ sf::Vector2f{200.0f, 200.0f} },
	m_blueSquare{ sf::Vector2f{ 200.0f, 200.0f } },
	m_currentGameMode{ GameMode::Starting }
{
	setupButton();
	setupText();
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	const int COL_1_LEFT = 350;
	const int COL_1_RIGHT = 550;
	const int COL_2_LEFT = 570;
	const int COL_2_RIGHT = 770;
	const int ROW_1_TOP = 20;
	const int ROW_1_BOTTOM = 230;
	const int ROW_2_TOP = 250;
	const int ROW_2_BOTTOM = 450;

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}

		if (sf::Event::MouseButtonReleased == event.type)
		{
			if (event.mouseButton.x > COL_1_LEFT && event.mouseButton.x < COL_1_RIGHT)
			{
				if (event.mouseButton.y > ROW_1_TOP && event.mouseButton.y < ROW_1_BOTTOM)
				{
					m_greenButtonPressed == true;
				}

				if (event.mouseButton.y > ROW_2_TOP && event.mouseButton.y < ROW_2_BOTTOM)
				{
					m_yellowButtonPressed = true;
				}
			}

			if (event.mouseButton.x > COL_2_LEFT && event.mouseButton.x < COL_2_RIGHT)
			{
				if (event.mouseButton.y > ROW_1_TOP && event.mouseButton.y < ROW_1_BOTTOM)
				{
					m_redButtonPressed = true;
				}

				if (event.mouseButton.y > ROW_2_TOP && event.mouseButton.y < ROW_2_BOTTOM)
				{
					m_blueButtonPressed = true;
				}
			}
			
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	switch (m_currentGameMode)
	{
	case GameMode::Showing:
		break;

	case GameMode::Recieving:
		break;

	case GameMode::GameOver:
		break;

	case GameMode::Starting:
		break;

	default:
			break;
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear();
	m_window.draw(m_redSquare);
	m_window.draw(m_yellowSquare);
	m_window.draw(m_greenSquare);
	m_window.draw(m_blueSquare);
	m_window.draw(m_titleText);
	if (GameMode::Starting == m_currentGameMode)
	{
		m_window.draw(m_instructionsTextBlue);
		m_window.draw(m_instructionsTextGreen);
		m_window.draw(m_instructionsTextRed);
		m_window.draw(m_instructionsTextYellow);
	}
	m_window.draw(m_statusText);
	m_window.display();
}
/// <summary>
/// Sets up all the buttons
/// </summary>
void Game::setupButton()
{
	m_redSquare.setFillColor(RED);
	m_redSquare.setPosition(sf::Vector2f{ 570, 30 });

	m_greenSquare.setFillColor(GREEN);
	m_greenSquare.setPosition(sf::Vector2f(350, 30));

	m_yellowSquare.setFillColor(YELLOW);
	m_yellowSquare.setPosition(sf::Vector2f(350, 250));

	m_blueSquare.setFillColor(BLUE);
	m_blueSquare.setPosition(sf::Vector2f(570, 250));
}

/// <summary>
/// function that sets up the text
/// </summary>
void Game::setupText()
{
	if (m_impactFont.loadFromFile("assets/fonts/impact.ttf"))
	{
		std::cout << "font loaded okay\n";
	}
	m_titleText.setFont(m_impactFont);
	m_titleText.setFillColor(WHITE);
	m_titleText.setCharacterSize(64);
	m_titleText.setPosition(50, 30);
	m_titleText.setString("S I M O N");

	m_instructionsTextGreen.setFont(m_impactFont);
	m_instructionsTextGreen.setFillColor(GREEN);
	m_instructionsTextGreen.setCharacterSize(32);
	m_instructionsTextGreen.setPosition(50, 100);
	m_instructionsTextGreen.setString("Press green for \n an easy game");

	m_instructionsTextRed.setFont(m_impactFont);
	m_instructionsTextRed.setFillColor(RED);
	m_instructionsTextRed.setCharacterSize(32);
	m_instructionsTextRed.setPosition(50, 200);
	m_instructionsTextRed.setString("Press red for \n a medium game");

	m_instructionsTextYellow.setFont(m_impactFont);
	m_instructionsTextYellow.setFillColor(YELLOW);
	m_instructionsTextYellow.setCharacterSize(32);
	m_instructionsTextYellow.setPosition(50, 300);
	m_instructionsTextYellow .setString("Press yellow for \n a hard game");

	m_instructionsTextBlue.setFont(m_impactFont);
	m_instructionsTextBlue.setFillColor(BLUE);
	m_instructionsTextBlue.setCharacterSize(32);
	m_instructionsTextBlue.setPosition(50, 400);
	m_instructionsTextBlue.setString("Press blue to \n exit game");

	m_statusText.setFont(m_impactFont);
	m_statusText.setFillColor(WHITE);
	m_statusText.setCharacterSize(22);
	m_statusText.setPosition(500, 453);
	m_statusText.setString(" ");
}