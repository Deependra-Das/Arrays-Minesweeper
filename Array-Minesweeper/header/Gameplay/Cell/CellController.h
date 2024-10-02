#pragma once
#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellModel;
		enum class CellState;
		enum class CellValue;

		class CellController
		{
		private:
			CellView* cell_view;
			CellModel* cell_model;
			void destroy();

		public:
			CellController();
			~CellController();

			void initialize(float cell_width, float cell_height);
			void update();
			void render();
			void reset();

			CellState getCellState();
			CellValue getCellValue();
		};
	}
}