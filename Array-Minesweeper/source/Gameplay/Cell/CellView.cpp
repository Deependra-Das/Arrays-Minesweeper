#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Global/Config.h"


namespace Gameplay
{
	namespace Cell
	{
        using namespace UI::UIElement;
        using namespace Global;

        CellView::CellView(CellController* controller)
        {
            cell_controller = controller;
            cell_button = new ButtonView();
        }

        CellView::~CellView() 
        { 
            delete (cell_button); 
        }

        void CellView::initialize(float cell_width, float cell_height)
        {
            initializeButtonImage(cell_width, cell_height);
        }

        void CellView::initializeButtonImage(float width, float height)
        {
            sf::Vector2f cell_screen_position = getCellScreenPosition();
            cell_button->initialize("Cell", Config::cells_texture_path, width * slice_count, height, cell_screen_position);
        }

        void CellView::update()
        {
            cell_button->update();
        }

        void CellView::render()
        {
            setCellTexture();
            cell_button->render();
        }

        void CellView::setCellTexture()
        {
            
            int index = static_cast<int>(cell_controller->getCellValue());

            switch (cell_controller->getCellState())
            {
            case::Gameplay::Cell::CellState::HIDDEN:
            
                cell_button->setTextureRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
                break;

            case::Gameplay::Cell::CellState::OPEN:
              
                cell_button->setTextureRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
                break;

            case::Gameplay::Cell::CellState::FLAGGED:
              
                cell_button->setTextureRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
                break;
            }
        }

        sf::Vector2f CellView::getCellScreenPosition()
        {
            return sf::Vector2f(cell_left_offset, cell_top_offset);
        }

	}
}