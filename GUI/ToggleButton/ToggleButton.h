#pragma once

#include "../EvolvGen.h"

namespace DUBGUI {

	// Кнопка-переключатель.
	class ToggleButton {
	public:

		// Статусы переключателя.
		enum class Status { Normal = 0, Hover, Active, Clicked };

		// Направление разбивки текстуры.
		enum class SlicingOrientation { Vertical, Horizontal };

		// Варианты разбики текстуры переключателя.
		enum class SlicingType { Single = 1, Double, Triple };

	private:

		//---> Данные.
		//=======================================================================================================================//
		// Координаты в окне.
		sf::Vector2f Position = { 0.f, 0.f };
		// Размер переключателя.
		sf::Vector2u Size;
		// Текущее состояние переключателя.
		Status ButtonStatus = Status::Normal;
		// Была ли нажата ЛКМ в предыдущем цикле.
		bool ButtonWasPressed = false;
		// Была ли нажата ЛКМ до наведения на переключатель.
		bool ButtonWasPressedOnAway = false;
		// Масштаб спрайта.
		sf::Vector2f Scale = { 1.f, 1.f };
		// Логический статус переключателя.
		bool ButtonValue = false;
		// Количество спрайтов для каждой вариации переключателя.
		unsigned int SpriteLinesCount = 3;

		//---> Графические компоненты.
		//=======================================================================================================================//
		// Указатель на окно отрисовки.
		sf::RenderWindow* MainWindow;
		// Текстура переключателя.
		sf::Texture ButtonTexture;
		// Спрайты переключателя.
		std::vector<sf::Sprite> ButtonSprites;

	protected:

		//---> Функции обработки.
		//=======================================================================================================================//
		// Проверяет попадание курсора в область переключателя.
		bool CheckMouseHover();
		// Возвращает индекс спрайта в зависимости от настроек, статуса и значения переключателя.
		unsigned int GetSpriteIndexs();

	public:

		// Конструктор: стандартный.
		ToggleButton();

		// Инициализатор: задаёт окно отрисовки. 
		// Примечание: вызывать после установки всех свойств и загрузки текстуры.
		void initialize(sf::RenderWindow* MainWindow);

		// Устанавливает позицию в окне.
		void setPosition(sf::Vector2f Position);

		// Устанавливает позицию в окне.
		void setPosition(float PositionX, float PositionY);

		// Устанавливает масштаб спрайта.
		void setScale(float Scale);

		// Загружает текстуру переключателя и разрезает её на спрайты согласно выбранному режиму.
		bool loadTexture(std::string Path, sf::Vector2u SpriteSize, SlicingType Type);

		// Загружает текстуру переключателя и разрезает её на спрайты согласно выбранному режиму и направлению.
		bool loadTexture(std::string Path, sf::Vector2u SpriteSize, SlicingType SlicingType, SlicingOrientation Orientation);

		// Возвращает значение переключателя.
		bool getValue();

		// Устанавливает значение переключателя.
		void setValue(bool Value);

		// Отрисовывание и обновление переключателя. Возвращает статус переключателя.
		Status update();

	};

}