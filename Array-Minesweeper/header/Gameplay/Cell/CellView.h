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
			const float cell_top_offset = 274.f;
			const float cell_left_offset = 583.f;
			void initializeButtonImage(float width, float height);
			void setCellTexture();
			sf::Vector2f getCellScreenPosition(float width, float height);

		public:
			CellView(CellController* controller);
			~CellView();

			void initialize(float cell_width, float cell_height);
			void update();
			void render();
		};
	}
}