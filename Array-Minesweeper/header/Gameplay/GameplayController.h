#pragma once

namespace Gameplay
{
	class GameplayController
	{
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();
		void reset();
	
	};
}