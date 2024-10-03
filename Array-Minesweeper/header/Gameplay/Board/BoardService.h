#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../UI/UIElement/ButtonView.h"
#include "../../header/Gameplay/Cell/CellController.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardController;

		class BoardService
		{
		private:
			BoardController* board_controller;

			void destroy();

		public:
			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();
			void resetBoard();
			int getMinesCount();
			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
		};
	}
}