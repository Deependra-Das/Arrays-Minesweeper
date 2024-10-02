#pragma once
#include "../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Cell
	{
		class CellController;

		class CellView
		{	
		private:
			UI::UIElement::ButtonView* cell_button;
			CellController* cell_controller;

			const int tile_size = 32;
			void initializeButtonImage(float width, float height);

		public:
			CellView(CellController* controller);
			~CellView();

			void initialize();
			void update();
			void render();
		};
	}
}