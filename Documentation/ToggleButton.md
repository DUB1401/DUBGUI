# ToggleButton
**ToggleButton** – это кнопка-переключатель, которая имеет два логических состояния: вкл/выкл. Функционально данный объект GUI аналогичен [CheckBox](https://github.com/DUB1401/DUBGUI/blob/main/Documentation/CheckBox.md), и используется лишь для логического разграничения.

## Описание свойств

**enum class** `Status` { Normal = 0, Hover, Active, Clicked }

Статусы объекта GUI.

* _**Normal**_ – обычное состояние переключателя.
* _**Hover**_ – курсор мыши наведён на переключатель.
* _**Active**_ – курсор мыши наведён на переключатель, и нажата ЛКМ.
* _**Clicked**_ – статус переключателя в момент клика: когда ЛКМ перестаёт быть нажата при наведённом на переключатель курсоре.
___

**enum class** `SlicingOrientation` { Vertical, Horizontal }

Направления разбивки текстуры.
		
* _**Vertical**_ – текстура будет делиться на спрайты в вертикальном направлении.
* _**Horizontal**_ – текстура будет делиться на спрайты в горизонтальном направлении.
___

**enum class** `SlicingType` { Single = 1, Double, Triple }

Режимы разбики текстуры.

* _**Single**_ – вертикальная текстура содержит два спрайта для двух значений переключателя: true и false.
* _**Double**_ – вертикальная текстура содержит четыре спрайта для двух значений переключателя: true и false. Спрайты соответствуют статусам: _Normal_, _Hover_.
* _**Triple**_ – вертикальная текстура содержит шесть спрайтов для двух значений переключателя: true и false. Спрайты соответствуют статусам: _Normal_, _Hover_, _Active_.

## Описание методов

`ToggleButton()`

Стандартный конструктор.
___

**void** `initialize(sf::RenderWindow* MainWindow)`

Инициализатор: задаёт окно отрисовки. Вызывать после установки всех свойств и загрузки текстуры.

_Аргументы:_

* **sf::RenderWindow\*** `MainWindow` – указатель на окно отрисовки.
___

**bool** `getValue()`

Возвращает значение переключателя.

_Возвращаемое значение:_ **bool** — значение переключателя.
___

**bool** `loadTexture(std::string Path, sf::Vector2u SpriteSize, SlicingType Type)`

Загружает текстуру переключателя и разрезает её на спрайты согласно выбранному режиму.

_Аргументы:_

* **std::string** `Path` – путь к файлу текстуры;
* **sf::Vector2u** `SpriteSize` – размер одного спрайта;
* **SlicingType** `Type` – режим разбики текстуры переключателя.

_Возвращаемое значение:_ **bool** – успешна ли загрузки текстуры.
___

**bool** `loadTexture(std::string Path, sf::Vector2u SpriteSize, SlicingType SlicingType, SlicingOrientation Orientation)`

Загружает текстуру переключателя и разрезает её на спрайты согласно выбранному режиму и направлению.

_Аргументы:_

* **std::string** `Path` – путь к файлу текстуры;
* **sf::Vector2u** `SpriteSize` – размер одного спрайта;
* **SlicingType** `Type` – режим разбики текстуры переключателя;
* **SlicingOrientation** `Orientation` – режим разбики текстуры переключателя.

_Возвращаемое значение:_ **bool** – успешна ли загрузки текстуры.
___

**void** `setPosition(float PositionX, float PositionY)`

Устанавливает позицию в окне.

_Аргументы:_

* **float** `PositionX` – позиция в окне по оси X;
* **float** `PositionY` – позиция в окне по оси Y.
___

**void** `setPosition(sf::Vector2f Position)`

Устанавливает позицию в окне.

_Аргументы:_

* **sf::Vector2f** `Position` – позиция в окне.
___

**void** `setScale(float Scale)`
	
Устанавливает масштаб спрайта.

_Аргументы:_

* **float** `Scale` – масштаб спрайта.
___
	
**void** `setValue(bool Value)`

_Аргументы:_

* **bool** `Value` – значение переключателя.

Устанавливает значение переключателя.
___
	
**Status** `update()`

Отрисовывает и обновляет переключатель. Блоком для расчёта статуса объекта GUI считается минимальных размеров прямоугольник, в который возможно поместить переключатель.

_Возвращаемое значение:_ **Status** – текущий статус объекта GUI.
	


