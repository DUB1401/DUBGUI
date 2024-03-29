#include "CheckBox.h"

//---> CheckBox
//========================================================================================================================//

namespace DUBGUI {

	// Возвращает индекс спрайта в зависимости от настроек, статуса и значения.
	unsigned int CheckBox::GetSpriteIndex() {
		// Индекс спрайта.
		unsigned int SpriteIndex = 0;
		// Модификатор статуса флаговой кнопки.
		unsigned int CheckBoxStatusModificator;

		// Если флаговая кнопка имеет статус без соответствующего спрайта, дать ей максимальный индекс, иначе преобразовать статус в индекс.
		if (CheckBoxStatus == Status::Clicked) CheckBoxStatusModificator = 3;
		else CheckBoxStatusModificator = static_cast<unsigned int>(CheckBoxStatus) + 1;
		// Если индекс спрайта больше заданного количества спрайтов на значение флаговой кнопки, то установить максимально возможный индекс.
		if (CheckBoxStatusModificator > SpriteLinesCount) CheckBoxStatusModificator = SpriteLinesCount;
		// Компенсировать сдвиг индекса.
		SpriteIndex = CheckBoxStatusModificator - 1;

		return SpriteIndex;
	}

	// Стандартный конструктор.
	CheckBox::CheckBox() {

	}

	// Инициализатор: задаёт окно отрисовки. Вызывать после установки всех свойств и загрузки текстур.
	void CheckBox::initialize(sf::RenderWindow* MainWindow) {

		//---> Передача аргументов.
		//========================================================================================================================//
		this->MainWindow = MainWindow;

		// Настройка спрайтов.
		for (unsigned int i = 0; i < SpriteLinesCount; i++) {
			CheckBoxSprites[i].setPosition(Position);
			CheckBoxSprites[i].setScale(Scale);
		}

		// Настройка обработчика взаимодействия с мышью.
		MouseProcessingObject.setPosition(Position);
		MouseProcessingObject.setScale(Scale);
		MouseProcessingObject.setSize(Size);
		MouseProcessingObject.initialize(MainWindow);
	}

	// Возвращает значение флаговой кнопки.
	bool CheckBox::getValue() {
		return CheckBoxValue;
	}

	// Загружает текстуру флага. Текстура флага может быть больше размера флаговой кнопки.
	bool CheckBox::loadFlagTexture(std::string Path) {

		// Проверка загрузки текстуры.
		if (FlagTexture.loadFromFile(Path)) {
			FlagSprite.setTexture(FlagTexture);
			FlagSprite.setOrigin(0, FlagTexture.getSize().y);
			FlagSprite.setPosition(Position.x, Position.y + FlagTexture.getSize().y);
			return true;
		}
		else return false;
	}

	// Загружает текстуру флаговой кнопки и разрезает её на спрайты согласно выбранному режиму.
	bool CheckBox::loadTexture(std::string Path, sf::Vector2u SpriteSize, SlicingType SlicingType) {

		//---> Передача аргументов.
		//========================================================================================================================//
		this->SpriteLinesCount = static_cast<unsigned int>(SlicingType);
		this->Size = SpriteSize;

		// Проверка загрузки текстуры.
		if (CheckBoxTexture.loadFromFile(Path)) {
			// Буфер подгрузки спрайтов.
			sf::Sprite CheckBoxSpriteBufer;

			// Настройка спрайтов.
			for (unsigned int i = 0; i < SpriteLinesCount; i++) {
				CheckBoxSprites.push_back(CheckBoxSpriteBufer);
				CheckBoxSprites[i].setPosition(Position);
				CheckBoxSprites[i].setTexture(CheckBoxTexture);
				CheckBoxSprites[i].setTextureRect(sf::IntRect(0, Size.y * i, Size.x, Size.y));
				CheckBoxSprites[i].setScale(Scale);
			}
			return true;
		}
		else return false;
	}

	// Загружает текстуру флаговой кнопки и разрезает её на спрайты согласно выбранному режиму и направлению.
	bool CheckBox::loadTexture(std::string Path, sf::Vector2u SpriteSize, SlicingType SlicingType, SlicingOrientation Orientation) {

		//---> Передача аргументов.
		//========================================================================================================================//
		this->SpriteLinesCount = static_cast<unsigned int>(SlicingType);
		this->Size = SpriteSize;

		// Проверка загрузки текстуры.
		if (CheckBoxTexture.loadFromFile(Path)) {
			// Буфер подгрузки спрайтов.
			sf::Sprite CheckBoxSpriteBufer;

			// Настройка спрайтов.
			for (unsigned int i = 0; i < SpriteLinesCount; i++) {
				CheckBoxSprites.push_back(CheckBoxSpriteBufer);
				CheckBoxSprites[i].setPosition(Position);
				CheckBoxSprites[i].setTexture(CheckBoxTexture);
				if (Orientation == SlicingOrientation::Vertical) CheckBoxSprites[i].setTextureRect(sf::IntRect(0, Size.y * i, Size.x, Size.y));
				else CheckBoxSprites[i].setTextureRect(sf::IntRect(Size.x * i, 0, Size.x, Size.y));
				CheckBoxSprites[i].setScale(Scale);
			}
			return true;
		}
		else return false;
	}

	// Устанавливает масштаб спрайта флага. Не применяется к спрайту флаговой кнопки.
	void CheckBox::setFlagScale(float FlagScale) {
		this->Scale = sf::Vector2f(FlagScale, FlagScale);
	}

	// Устанавливает позицию в окне.
	void CheckBox::setPosition(float PositionX, float PositionY) {
		this->Position = sf::Vector2f(PositionX, PositionY);
		FlagSprite.setPosition(Position.x, Position.y + FlagTexture.getSize().y);
	}

	// Устанавливает позицию в окне.
	void CheckBox::setPosition(sf::Vector2f Position) {
		this->Position = Position;
		FlagSprite.setPosition(Position.x, Position.y + FlagTexture.getSize().y);
	}

	// Устанавливает масштаб спрайта флаговой кнопки. Не применяется к спрайту флага.
	void CheckBox::setScale(float Scale) {
		this->Scale = sf::Vector2f(Scale, Scale);
	}

	// Устанавливает логическое значение флаговой кнопки.
	void CheckBox::setValue(bool Value) {
		CheckBoxValue = Value;
	}

	// Отрисовывает и обновляет флаговую кнопку.
	CheckBox::Status CheckBox::update() {

		// Отрисовка флаговой кнопки и флага.
		MainWindow->draw(CheckBoxSprites[GetSpriteIndex()]);
		if (CheckBoxValue) MainWindow->draw(FlagSprite);

		// Обновление статуса флаговой кнопки.
		CheckBoxStatus = MouseProcessingObject.updateMouseButton(sf::Mouse::Left);

		return CheckBoxStatus;
	}

}