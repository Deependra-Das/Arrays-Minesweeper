#pragma once
#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
        enum class CellState
        {
            HIDDEN,
            OPEN,
            FLAGGED,
        };

        enum class CellValue
        {
            EMPTY,
            ONE,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            MINE,
        };

        class CellModel
        {
        private:
            CellState cell_state;
            CellValue cell_value;
            int cell_index;

        public:
            CellModel(int index);
            ~CellModel();

            CellState getCellState();
            void setCellState(CellState state);

            CellValue getCellValue();
            void setCellValue(CellValue value);
            int getCellIndex();
            void reset();

        };
	}
}