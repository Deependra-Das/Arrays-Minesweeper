#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel(sf::Vector2i position)
		{
			reset();
			cell_position = position;
		}

		CellModel::~CellModel() = default;

		CellState CellModel::getCellState()
		{
			return cell_state;
		}

		void CellModel::setCellState(CellState state)
		{
			cell_state = state;
		}

		CellValue CellModel::getCellValue()
		{
			return cell_value;
		}

		void CellModel::setCellValue(CellValue value)
		{
			cell_value = value;
		}

		void CellModel::reset()
		{
			cell_state = CellState::HIDDEN;
			cell_value = CellValue::EMPTY;
		}

		sf::Vector2i CellModel::getCellPosition()
		{
			return cell_position;
		}

		void CellModel::setCellPosition(sf::Vector2i new_position)
		{
			cell_position = new_position;
		}
	}
}