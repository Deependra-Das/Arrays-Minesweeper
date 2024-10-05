#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"
#include <random>

namespace Gameplay
{
	namespace Board
	{
        class BoardView;

        enum class BoardState
        {
            FIRST_CELL,    
            PLAYING,      
            COMPLETED,  

        };
		class BoardController
		{
        public:
            static const int number_of_rows = 9;
            static const int number_of_columns = 9;
            static const int mines_count = 8;

            BoardController();
            ~BoardController();

            void initialize();
            void update();
            void render();
            void reset();
            int getMinesCount();
            void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
            void processCellValue(sf::Vector2i cell_position);
            BoardState getBoardState();
            void setBoardState(BoardState state);

        private:
            BoardView* board_view;
            Cell::CellController* board_cells[number_of_rows][number_of_columns];

            int flagged_cells;
            BoardState board_state;
            std::default_random_engine random_engine;

            // To give random seed to generator.
            std::random_device random_device;

            void createBoard();
            void destroy();
            void deleteBoard();
            void deleteCells();
            void initializeCells();
            void openCell(sf::Vector2i cell_position);
            void openAllCells();
            void flagCell(sf::Vector2i cell_position);
            void populateBoard(sf::Vector2i cell_position);
            void populateMines(sf::Vector2i cell_position);
            void populateCells();
            int countMinesAround(sf::Vector2i cell_position);
            bool isValidCellPosition(sf::Vector2i cell_position);

		};
	}
}