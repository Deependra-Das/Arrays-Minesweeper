#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Cell/CellController.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace UI::UIElement;

		BoardService::BoardService()
		{
			board_controller = new BoardController();
		}

		BoardService::~BoardService()
		{

		}

		void BoardService::initialize()
		{
			board_controller->initialize();
		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}

		void BoardService::destroy()
		{
			delete(board_controller);
		}

		int BoardService::getMinesCount()
		{
			return board_controller->getMinesCount();
		}

		void BoardService::processCellInput(Cell::CellController* cell_controller, ButtonType button_type)
		{
			board_controller->processCellInput(cell_controller, button_type);
		}

		void BoardService::showBoard() 
		{ 
			board_controller->showBoard(); 
		}

		BoardState BoardService::getBoardState()
		{
			return board_controller->getBoardState();
		}

		void BoardService::setBoardState(BoardState state)
		{
			board_controller->setBoardState(state);
		}
	}
}