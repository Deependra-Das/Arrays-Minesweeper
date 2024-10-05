#pragma once

namespace Gameplay
{
	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController
	{
	private:
		const float max_duration = 300.f;
		float remaining_time;
		const float game_over_time = 11.f;
		GameResult game_result;

		void updateRemainingTime();
		void beginGameOverTimer();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();
		void restart();
		float getRemainingTime();
		int getMinesCount();	
		void endGame(GameResult result);
		void gameWon();
		void gameLost();
		void showCredits();
	};
}