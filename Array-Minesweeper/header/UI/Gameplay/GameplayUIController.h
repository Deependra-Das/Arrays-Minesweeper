#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			UI::UIElement::TextView* time_text;
			UIElement::TextView* mine_text;
			UIElement::TextView* mine_label_text;
			UIElement::TextView* time_label_text;
			UIElement::ButtonView* restart_button;

			const int font_size = 110;
			const int label_font_size = 30;
			const sf::Color text_color = sf::Color::Red;
			const sf::Color label_text_color = sf::Color::Black;

			const float time_text_top_offset = 68.f;
			const float time_text_left_offset = 1090.f;

			const float mine_text_top_offset = 68.f;
			const float mine_text_left_offset = 660.f;

			const float restart_button_top_offset = 100.f;
			const float restart_button_left_offset = 920.f;

			const float button_height = 80.f;
			const float button_width = 80.f;

			const int tile_height = 32;

			void createTexts();
			void initializeTexts();
			void initializeTimeText();
			void initializeMineText();
			void initializeLabelText();
			void updateTimeText();
			void updateMineText();
			void createButton();
			void initializeButton();
			void registerButtonCallback();
			void restartButtonCallback();
			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
	
		};
	}
}