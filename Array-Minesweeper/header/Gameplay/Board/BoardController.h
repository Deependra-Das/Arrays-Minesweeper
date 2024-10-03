#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Board
	{
        class BoardView;

		class BoardController
		{
        public:
            static const int number_of_rows = 9;
            static const int number_of_columns = 9;
            static const int mines_count = 8;
            int flagged_cells;
            Cell::CellController* board_cells[number_of_rows][number_of_columns];

            BoardController();
            ~BoardController();

            void initialize();
            void update();
            void render();
            void reset();
            int getMinesCount();
            void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
            void flagCell(sf::Vector2i cell_position);

        private:
            BoardView* board_view;
            Cell::CellController* cell;

            void createBoard();
            void destroy();
            void deleteBoard();
            void deleteCells();
            void initializeCells();
            void openCell(sf::Vector2i cell_position);
		};
	}
}