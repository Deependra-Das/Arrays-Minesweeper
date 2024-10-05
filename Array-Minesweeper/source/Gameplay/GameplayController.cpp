#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;
	using namespace Board;

	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{
		updateRemainingTime();
		if (isTimeOver())
		{
			endGame(GameResult::LOST);
		}
		
	}

	void GameplayController::render()
	{

	}

	void GameplayController::restart()
	{
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
		remaining_time = max_duration;
	}

	bool GameplayController::isTimeOver() 
	{ 
		return (remaining_time <= 1);
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	float GameplayController::getRemainingTime() 
	{ 
		return remaining_time;
	}

	int GameplayController::getMinesCount()
	{
		return ServiceLocator::getInstance()->getBoardService()->getMinesCount();
	}

	void GameplayController::endGame(GameResult result)
	{
		switch (result)
		{
		case GameResult::WON:
			gameWon();
			break;
		case GameResult::LOST:
			gameLost();
			break;
		default:
			break;
		}
	}

	void GameplayController::gameWon()
	{
		
	}

	void GameplayController::gameLost()
	{
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOST;
			beginGameOverTimer();
			ServiceLocator::getInstance()->getBoardService()->showBoard();
			ServiceLocator::getInstance()->getBoardService()->setBoardState(BoardState::COMPLETED);
		}
		else
		{
			showCredits();
		}

	}
	void GameplayController::beginGameOverTimer() 
	{ 
		remaining_time = game_over_time; 
	}

	void GameplayController::showCredits() 
	{ 
		GameService::setGameState(GameState::CREDITS); 
	}
}