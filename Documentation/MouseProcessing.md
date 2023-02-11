# MouseProcessing
**MouseProcessing** – обработчик взаимодействий с мышью. Основным назначением является определение статуса графического объекта относительно курсора.

## Описание методов

`MouseProcessing()`

Стандартный конструктор.
___

**void** `initialize(sf::RenderWindow* MainWindow)`

Инициализатор: задаёт используемое окно. Вызывать после установки всех свойств.

 _Аргументы:_

 * **sf::RenderWindow** `MainWindow` – указатель на окно отрисовки.
___

**void** `setPosition(float PositionX, float PositionY)`

Устанавливает позицию обрабатываемой области в окне.

_Аргументы:_

* **float** `PositionX` – позиция обрабатываемой области по оси X;
* **float** `PositionY` – позиция обрабатываемой области по оси Y.
___

**void** `setPosition(sf::Vector2f Position)`

Устанавливает позицию обрабатываемой области в окне.

_Аргументы:_

* **sf::Vector2f** `Position` – позиция обрабатываемой области.
___

**void** `setScale(sf::Vector2f Scale)`

Устанавливает масштаб обрабатываемой области.

_Аргументы:_

* **sf::Vector2f** `Scale` – масштаб обрабатываемой области.
___

**void** `setSize(sf::Vector2u Size)`

Устанавливает размер обрабатываемой области.

_Аргументы:_

* **sf::Vector2u** `Size` – указатель на окно отрисовки.
___

**void** `setSize(unsigned int SizeX, unsigned int SizeY)`

Устанавливает размер обрабатываемой области.

_Аргументы:_

* **unsigned int** `SizeX` – размер обрабатываемой области по оси X;
* **unsigned int** `SizeY` – размер обрабатываемой области по оси Y.
___

**void** `showDebugRectangle(bool IsShowDebugRectangle)`

Переключает отображение обрабатываемой области. Если включено, обрабатываемая область будет покрашена в определённый цвет.

По умолчанию: false

_Аргументы:_

* **bool** `IsShowDebugRectangle` – режим отображения обрабатываемой области.

___

**void** `showDebugRectangle(bool IsShowDebugRectangle, sf::Color DebugRectangleColor)`

Переключает отображение обрабатываемой области и устанавливает цвет для неё. Если включено, обрабатываемая область будет покрашена в установленный цвет.

По умолчанию: false, RGBA(255, 0, 0, 128)

_Аргументы:_

* **sf::Vector2f** `Scale` – масштаб обрабатываемой области;
* **sf::Color** `DebugRectangleColor` – цвет обрабатываемой области.

___
		
**void** `updateMouseButton(sf::Mouse::Button MouseButton)`

Обрабатывает взаимодействие с указанной кнопкой мыши.