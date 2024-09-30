#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"

namespace Gameplay
{
	namespace Board
	{

		BoardController::BoardController()
		{
			board_view = new BoardView(this);
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
		}

		void BoardController::initialize()
		{
			board_view->initialize();
		}

		void BoardController::update()
		{
			board_view->update();
		}

		void BoardController::render()
		{
			board_view->render();
		}

		void BoardController::reset()
		{
		}

		void BoardController::deleteBoard()
		{
		}

		void BoardController::destroy()
		{
			delete(board_view);
		}
	}
}