#include "ToggleButton.h"

// ---> ToggleButton
//=======================================================================================================================//

namespace DUBGUI {

	// Проверяет попадание курсора в область кнопки.
	bool ToggleButton::CheckMouseHover() {
		// Сохранение координат мыши.
		sf::Vector2i MouseCoords = sf::Mouse::getPosition(*MainWindow);
		// Попадание по осям X и Y.
		bool AxisX = false, AxisY = false;
		// Проверка попадания по оси X.
		if (MouseCoords.x > Position.x && MouseCoords.x < Position.x + Size.x * Scale.x) AxisX = true;
		// Проверка попадания по оси Y.
		if (MouseCoords.y > Position.y && MouseCoords.y < Position.y + Size.y * Scale.y) AxisY = true;
		// Проверка полного попадания.
		if (AxisX && AxisY) return true; else return false;
	}

	// Возвращает индекс спрайта в зависимости от настроек, статуса и значения.
	unsigned int ToggleButton::GetSpriteIndexs() {
		// Индекс спрайта.
		unsigned int SpriteIndex = 0;
		// Модификатор статуса кнопки.
		unsigned int ButtonStatusModificator;

		// Если кнопка имеет статус без соответствующего спрайта, дать ей максимальный индекс, иначе преобразовать статус в индекс.
		if (ButtonStatus == Status::Clicked) ButtonStatusModificator = 3;
		else ButtonStatusModificator = static_cast<unsigned int>(ButtonStatus) + 1;
		// Если индекс спрайта больше заданного количества спрайтов на значение переключателя, то установить максимально возможный индекс.
		if (ButtonStatusModificator > SpriteLinesCount) ButtonStatusModificator = SpriteLinesCount;
		// Если переключатель включен, то задать индекс со сдвигом, иначе к индексу со сдвигом прибавить количество спрайтов включённой формы переключателя.
		if (ButtonValue) SpriteIndex = ButtonStatusModificator - 1;
		else SpriteIndex = ButtonStatusModificator - 1 + SpriteLinesCount;

		return SpriteIndex;
	}

	// Конструктор: стандартный.
	ToggleButton::ToggleButton() {

	}

	// Инициализатор: задаёт окно отрисовки. 
	// Примечание: вызывать после установки всех свойств и загрузки текстуры.
	void ToggleButton::Initialize(sf::RenderWindow* MainWindow) {

		//---> Передача аргументов.
		//=======================================================================================================================//
		this->MainWindow = MainWindow;

		// Настройка спрайтов.
		for (unsigned int i = 0; i < SpriteLinesCount * 2; i++) {
			ButtonSprites[i].setPosition(Position);
			ButtonSprites[i].setScale(Scale);
		}
	}

	// Устанавливает позицию в окне.
	void ToggleButton::SetPosition(sf::Vector2f Position) {
		this->Position = Position;
	}

	// Устанавливает позицию в окне.
	void ToggleButton::SetPosition(float PositionX, float PositionY) {
		this->Position = sf::Vector2f(PositionX, PositionY);
	}

	// Устанавливает масштаб спрайта.
	void ToggleButton::SetScale(float Scale) {
		this->Scale = sf::Vector2f(Scale, Scale);
	}

	// Загружает текстуру кнопки и разрезает её на спрайты согласно выбранному режиму.
	bool ToggleButton::LoadTexture(std::string Path, sf::Vector2u SpriteSize, TextureSlicingType SlicingType) {

		//---> Передача аргументов.
		//=======================================================================================================================//
		this->SpriteLinesCount = static_cast<unsigned int>(SlicingType);
		this->Size = SpriteSize;

		// Проверка загрузки текстуры.
		if (ButtonTexture.loadFromFile(Path)) {
			// Буфер подгрузки спрайтов.
			sf::Sprite ButtonSpriteBufer;

			// Настройка спрайтов.
			for (unsigned int i = 0; i < SpriteLinesCount * 2; i++) {
				ButtonSprites.push_back(ButtonSpriteBufer);
				ButtonSprites[i].setPosition(Position);
				ButtonSprites[i].setTexture(ButtonTexture);
				ButtonSprites[i].setTextureRect(sf::IntRect(0, Size.y * i, Size.x, Size.y));
				ButtonSprites[i].setScale(Scale);
			}
			return true;
		}
		else return false;
	}

	// Возвращает значение переключателя.
	bool ToggleButton::GetValue() {
		return ButtonValue;
	}

	// Устанавливает значение кнопки.
	void ToggleButton::SetValue(bool Value) {
		ButtonValue = Value;
	}

	// Отрисовывание и обновление переключателя. Возвращает статус переключателя.
	ToggleButton::Status ToggleButton::Update() {

		// Если курсор попадает на переключатель.
		if (CheckMouseHover()) {
			// Если ЛКМ не нажата.
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !ButtonWasPressed) { 
				ButtonStatus = Status::Hover;
				ButtonWasPressedOnAway = false;
			}

			// Если ЛКМ нажата сейчас, а в прошлом цикле – нет.
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !ButtonWasPressed && !ButtonWasPressedOnAway) {
				ButtonWasPressed = true;
				ButtonStatus = Status::Active;
			}

			// Если ЛКМ была нажата в прошлом цикле, а сейчас – нет.
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && ButtonWasPressed && !ButtonWasPressedOnAway) {
				ButtonWasPressed = false;
				ButtonStatus = Status::Clicked;
				ButtonValue = DUBLIB::InvertBool(ButtonValue);
			}
		}
		else {
			ButtonStatus = Status::Normal;
			// Фикс срабатывания переключателя в случае, когда зажатая ЛКМ уходит с области фокуса.
			ButtonWasPressed = false;
			// Фикс срабатывания переключателя в случае, когда зажатая ЛКМ приходит в область фокуса.
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !ButtonWasPressedOnAway) ButtonWasPressedOnAway = true;
		}

		MainWindow->draw(ButtonSprites[GetSpriteIndexs()]);

		return ButtonStatus;
	}

}