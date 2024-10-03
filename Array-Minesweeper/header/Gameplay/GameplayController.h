#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private:
		const float max_duration = 300.f;
		float remaining_time;

		void updateRemainingTime();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();
		void restart();
		float getRemainingTime();
		int getMinesCount();	
	};
}