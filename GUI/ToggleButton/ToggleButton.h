#pragma once

#include "../EvolvGen.h"

namespace DUBGUI {

	// Кнопка-переключатель.
	class ToggleButton {
	public:

		// Статусы переключателя.
		enum class Status { Normal = 0, Hover, Active, Clicked };

		// Варианты разбики текстур переключателя.
		enum class TextureSlicingType { Single = 1, Double, Triple };

	private:

		//---> Данные.
		//=======================================================================================================================//
		// Координаты в окне.
		sf::Vector2f Position = { 0.f, 0.f };
		// Размер кнопки.
		sf::Vector2u Size;
		// Текущее состояние кнопки.
		Status ButtonStatus = Status::Normal;
		// Была ли нажата ЛКМ в предыдущем цикле.
		bool ButtonWasPressed = false;
		// Была ли нажата ЛКМ до наведения на переключатель.
		bool ButtonWasPressedOnAway = false;
		// Масштаб спрайта.
		sf::Vector2f Scale = { 1.f, 1.f };
		// Логический статус кнопки.
		bool ButtonValue = false;
		// Количество спрайтов для каждой вариации переключателя.
		unsigned int SpriteLinesCount = 3;

		//---> Графические компоненты.
		//=======================================================================================================================//
		// Указатель на окно отрисовки.
		sf::RenderWindow* MainWindow;
		// Текстура кнопки.
		sf::Texture ButtonTexture;
		// Спрайты кнопки.
		std::vector<sf::Sprite> ButtonSprites;

	protected:

		//---> Функции обработки.
		//=======================================================================================================================//
		// Проверяет попадание курсора в область кнопки.
		bool CheckMouseHover();
		// Возвращает индекс спрайта в зависимости от настроек, статуса и значения переключателя.
		unsigned int GetSpriteIndexs();

	public:

		// Конструктор: стандартный.
		ToggleButton();

		// Инициализатор: задаёт окно отрисовки. 
		// Примечание: вызывать после установки всех свойств и загрузки текстуры.
		void Initialize(sf::RenderWindow* MainWindow);

		// Устанавливает позицию в окне.
		void SetPosition(sf::Vector2f Position);

		// Устанавливает позицию в окне.
		void SetPosition(float PositionX, float PositionY);

		// Устанавливает масштаб спрайта.
		void SetScale(float Scale);

		// Загружает текстуру кнопки и разрезает её на спрайты согласно выбранному режиму.
		bool LoadTexture(std::string Path, sf::Vector2u SpriteSize, TextureSlicingType Type);

		// Возвращает значение переключателя.
		bool GetValue();

		// Устанавливает значение кнопки.
		void SetValue(bool Value);

		// Отрисовывание и обновление переключателя. Возвращает статус переключателя.
		Status Update();

	};

}