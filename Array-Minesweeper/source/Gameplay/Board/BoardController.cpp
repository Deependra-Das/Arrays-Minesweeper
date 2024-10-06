#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace Global;
		using namespace Sound;

		BoardController::BoardController() : random_engine(random_device())
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
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board_cells[i][j] = new CellController(sf::Vector2i(i, j));
				}
			}
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
			
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board_cells[i][j]->initialize(cell_width, cell_height);
				}
			}

		}

		void BoardController::update()
		{
			board_view->update();
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board_cells[i][j]->update();
				}
			}
		}

		void BoardController::render()
		{
			board_view->render();
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board_cells[i][j]->render();
				}
			}
		}

		void BoardController::reset()
		{
			flagged_cells = 0;
			setBoardState(BoardState::FIRST_CELL);
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board_cells[i][j]->reset();
				}
			}
		}

		void BoardController::deleteBoard()
		{
			delete(board_view);
		}

		void BoardController::deleteCells()
		{
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					delete(board_cells[i][j]);
				}
			}

		}

		void BoardController::destroy()
		{
			deleteCells();
			deleteBoard();
		}

		int BoardController::getMinesCount()
		{
			return mines_count - flagged_cells;
		}

		void BoardController::openCell(sf::Vector2i cell_position)
		{
			if (board_cells[cell_position.x][cell_position.y]->canOpenCell())
			{
				if (board_state == BoardState::FIRST_CELL)
				{
					populateBoard(cell_position);
					board_state = BoardState::PLAYING;
				}
				processCellValue(cell_position);
				board_cells[cell_position.x][cell_position.y]->openCell();

				if (areAllCellOpen())
				{
					ServiceLocator::getInstance()->getGameplayService()->endGame(GameResult::WON);
				}
					
			}

		}

		void BoardController::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
		{
			if (board_state == BoardState::COMPLETED)
				return;

			switch (button_type)
			{
			case UI::UIElement::ButtonType::LEFT_MOUSE_BUTTON:
				openCell(cell_controller->getCellPosition());
				break;
			case UI::UIElement::ButtonType::RIGHT_MOUSE_BUTTON:
				flagCell(cell_controller->getCellPosition());
				break;
			}
		}

		void BoardController::processCellValue(sf::Vector2i cell_position)
		{
			switch (board_cells[cell_position.x][cell_position.y]->getCellValue())
			{
			case::Gameplay::Cell::CellValue::EMPTY:
				processEmptyCell(cell_position);
				break;
			case::Gameplay::Cell::CellValue::MINE:
				processMineCell(cell_position);
				break;
			default:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
				break;
			}
		}

		void BoardController::processMineCell(sf::Vector2i cell_position)
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);
			ServiceLocator::getInstance()->getGameplayService()->endGame(GameResult::LOST);
		}

		void BoardController::processEmptyCell(sf::Vector2i cell_position)
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			openEmptyCells(cell_position);
		}

		void BoardController::populateBoard(sf::Vector2i cell_position)
		{
			populateMines(cell_position);
			populateCells();
		}

		void BoardController::populateMines(sf::Vector2i cell_position)
		{
			std::uniform_int_distribution<int> x_distribution(0, number_of_columns - 1);
			std::uniform_int_distribution<int> y_distribution(0, number_of_rows - 1);

			for (int a = 0; a < mines_count; a++)
			{
				int i = static_cast<int>(x_distribution(random_engine));
				int j = static_cast<int>(y_distribution(random_engine));

				if (board_cells[i][j]->getCellValue() == CellValue::MINE || (cell_position.x == i && cell_position.y == j))
				{
					a--;
				}
				else
				{
					board_cells[i][j]->setCellValue(CellValue::MINE);
				}
			}
			printf("\n");

			for (int a = 0; a < number_of_rows; ++a)
			{
				for (int b = 0; b < number_of_columns; ++b)
				{
					if (board_cells[a][b]->getCellValue() == CellValue::MINE)
					{
						printf("\n %d %d",a,b);
					}
				}
			}

		}

		int BoardController::countMinesAround(sf::Vector2i cell_position)
		{
			int mines_around = 0;

			for (int a = -1; a < 2; a++)
			{
				for (int b = -1; b < 2; b++)
				{
					if ((a == 0 && b == 0) || !isValidCellPosition(sf::Vector2i(cell_position.x + a, cell_position.y + b)))
					{
						continue;
					}

					if (board_cells[a + cell_position.x][b + cell_position.y]->getCellValue() == CellValue::MINE)
					{
						mines_around++;
					}
				}
			}

			return mines_around;
		}

		bool BoardController::isValidCellPosition(sf::Vector2i cell_position)
		{
			return (cell_position.x >= 0 && cell_position.y >= 0 && cell_position.x < number_of_columns && cell_position.y < number_of_rows);
		}

		void BoardController::populateCells()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					if (board_cells[a][b]->getCellValue() != CellValue::MINE)
					{
						CellValue value = static_cast<CellValue>(countMinesAround(sf::Vector2i(a, b)));
						board_cells[a][b]->setCellValue(value);
					}
				}
			}
		}

		void BoardController::showBoard()
		{

			switch (ServiceLocator::getInstance()->getBoardService()->getBoardState())
			{
			case Gameplay::Board::BoardState::FIRST_CELL:
				populateBoard(sf::Vector2i(0, 0));
				openAllCells();
				break;
			case Gameplay::Board::BoardState::PLAYING:
				openAllCells();
				break;
			case Gameplay::Board::BoardState::COMPLETED:
				break;
			default:
				break;
			}
		}


		void BoardController::openAllCells()
		{
			for (int a = 0; a < number_of_rows; ++a)
			{
				for (int b = 0; b < number_of_columns; ++b)
				{
					board_cells[a][b]->openCell();
				}
			}
		}

		void BoardController::openEmptyCells(sf::Vector2i cell_position)
		{
			switch (board_cells[cell_position.x][cell_position.y]->getCellState())
			{
			case::Gameplay::Cell::CellState::OPEN:
				return;
			case::Gameplay::Cell::CellState::FLAGGED:
				flagged_cells--;
			default:
				board_cells[cell_position.x][cell_position.y]->openCell();
			}

			for (int a = -1; a < 2; a++)
			{
				for (int b = -1; b < 2; b++)
				{
					if ((a == 0 && b == 0) || !isValidCellPosition(sf::Vector2i(a + cell_position.x, b + cell_position.y)))
						continue;

					sf::Vector2i next_cell_position = sf::Vector2i(a + cell_position.x, b + cell_position.y);
					openCell(next_cell_position);
				}
			}
		}

		void BoardController::flagCell(sf::Vector2i cell_position)
		{
			switch (board_cells[cell_position.x][cell_position.y]->getCellState())
			{
			case::Gameplay::Cell::CellState::FLAGGED:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::FLAG);
				flagged_cells--;
				break;
			case::Gameplay::Cell::CellState::HIDDEN:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::FLAG);
				flagged_cells++;
				break;
			}

			board_cells[cell_position.x][cell_position.y]->flagCell();
		}

		void BoardController::flagAllMines()
		{
			for (int row = 0; row < number_of_rows; ++row)
			{
				for (int col = 0; col < number_of_columns; ++col)
				{
					if (board_cells[row][col]->getCellValue() == CellValue::MINE && board_cells[row][col]->getCellState() != CellState::FLAGGED)
						flagCell(sf::Vector2i(row, col));
				}
			}
		}

		BoardState BoardController::getBoardState()
		{
			return board_state;
		}

		void BoardController::setBoardState(BoardState state)
		{
			board_state = state;
		}


		bool BoardController::areAllCellOpen()
		{
			int total_cell_count = number_of_rows * number_of_columns;
			int open_cell_count = 0;

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					if (board_cells[a][b]->getCellState() == CellState::OPEN)
					{
						open_cell_count++;
					}
				}
			}

			return (total_cell_count - open_cell_count == mines_count);
		}
	}
}