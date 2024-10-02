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
			int slice_count = 12;
			const int tile_size = 32;
			void initializeButtonImage(float width, float height);
			void setCellTexture();

		public:
			CellView(CellController* controller);
			~CellView();

			void initialize();
			void update();
			void render();
		};
	}
}