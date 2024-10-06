#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"

namespace UI
{
	namespace Instructions
	{
		class InstructionsScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float menu_button_y_position = 850.f;
			const float background_alpha = 85.f;

			static const int number_of_instructions = 9;
			const float top_offset = 80.f;
			const float text_spacing = 80.f;
			const int font_size = 40;

			const sf::Color text_color = sf::Color::White;

			sf::String instructions[number_of_instructions] = { "The Mines are hidden in a grid of cells",
																"Numbered cell tells you how many Mines are adjacent to that cell",
																"You can use the numbered cells as clues to solve the board by opening all of the safe cells",
																"If you click on a cell with Mine, you Lose the game!",
																"Use Left Mouse Button to open the cells & Right Mouse Button to put Flags on the cells",
																"If you open an Empty cell, the adjacent Empty cells will be opened automatically as a hint",
																"The Counter on the top-left shows the number of Mines left to be flagged",
																"The Timer on the top-right shows time in seconds left to find all the mines",
																"You can restart the game anytime by resetting the board using the restart button at the top.", };


			UIElement::ImageView* background_image;
			UIElement::ButtonView* menu_button;

			std::vector<UIElement::TextView*> instructions_text_list;

			void createImage();
			void createButtons();
			void createText();
			void initializeBackgroundImage();
			void initializeButtons();
			void initializeTexts();
			void registerButtonCallback();

			void menuButtonCallback();

			void destroy();

		public:
			InstructionsScreenUIController();
			~InstructionsScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}