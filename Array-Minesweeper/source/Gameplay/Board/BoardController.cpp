#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;

		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
			cell = new CellController();
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			cell->initialize(cell_width, cell_height);
		}

		void BoardController::update()
		{
			board_view->update();
			cell->update();
		}

		void BoardController::render()
		{
			board_view->render();
			cell->render();
		}

		void BoardController::reset()
		{
		}

		void BoardController::deleteBoard()
		{
			delete(cell);
		}

		void BoardController::destroy()
		{
			delete(board_view);
		}
	}
}