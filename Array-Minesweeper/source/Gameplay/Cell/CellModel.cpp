#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel(int index)
		{
			reset();
			cell_index = index;
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

		int CellModel::getCellIndex()
		{
			return cell_index;
		}
	}
}