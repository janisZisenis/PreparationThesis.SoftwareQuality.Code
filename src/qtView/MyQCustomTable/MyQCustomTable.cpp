#include "MyQCustomTable.h"
#include <QPainter>

MyQCustomTable::MyQCustomTable(int row, int column, QWidget *parent)
        : QWidget(parent),
          row(row),
          column(column) {
    initializeRows();
    initializeColumns();
    initializeCells();
}

MyQCustomTable::~MyQCustomTable() {}

void MyQCustomTable::paintEvent(QPaintEvent *evt) {
    QWidget::paintEvent(evt);

    painter = new QPainter(this);

    fillAllCells();
    paintAllCells();
    paintAllTexts();

    paintWidgetFrame();

    painter->end();
}

void MyQCustomTable::bindCells(int row1, int column1, int row2, int column2) {
    //second cell needs to be right or under the first cell;
    Cell *first = findCellBy(row1, column1);
    Cell *second = findCellBy(row2, column2);

    if (!first->canBind(second) && first != second)
        throw std::logic_error("cells can't be bound!");

    first->setEndRow(second->getEndRow());
    first->setEndColumn(second->getEndColumn());

    removeCell(second);
}

void MyQCustomTable::resetBinding(int row, int column) {
    Cell *cell = findCellBy(row, column);

    Row *beginRow = cell->getBeginRow();
    Row *endRow = cell->getEndRow();
    Column *beginColumn = cell->getBeginColumn();
    Column *endColumn = cell->getEndColumn();

    cell->setEndColumn(beginColumn);
    cell->setEndRow(beginRow);

    for (int i = beginRow->getRowNumber(); i <= endRow->getRowNumber(); i++)
        for (int j = beginColumn->getColumnNumber(); j <= endColumn->getColumnNumber(); j++)
            if (i == beginRow->getRowNumber() && j == beginColumn->getColumnNumber()) continue;
            else cells.push_back(new Cell(rows[i], columns[j]));
}

void MyQCustomTable::setWidgetHeight(int height) {
    this->setFixedHeight(height + margin);
}

void MyQCustomTable::setWidgetWidth(int width) {
    this->setFixedWidth(width + margin);
}

void MyQCustomTable::setColumnWidth(int column, int width) {
    columns[column]->setWidth(width);
    this->setWidgetWidth(columns[columns.size() - 1]->getRight());
}

void MyQCustomTable::setRowHeight(int row, int height) {
    rows[row]->setHeight(height);
    this->setWidgetHeight(rows[rows.size() - 1]->getBottom());
}

void MyQCustomTable::setCellAlignment(int row, int column, Qt::Alignment alignment) {
    findCellBy(row, column)->setTextAlignment(alignment);
}

void MyQCustomTable::setCellColor(int row, int column, QColor color) {
    findCellBy(row, column)->setColor(color);
}

void MyQCustomTable::setText(int row, int column, string text) {
    findCellBy(row, column)->setText(text);
}

void MyQCustomTable::setWholeCellBorderWidth(int row, int column, int borderWidth) {
    findCellBy(row, column)->setWholeBorderWidth(borderWidth);
}

void MyQCustomTable::setLeftBorderWidth(int row, int column, int borderWidth) {
    findCellBy(row, column)->setLeftBorderWidth(borderWidth);
}

void MyQCustomTable::setRightBorderWidth(int row, int column, int borderWidth) {
    findCellBy(row, column)->setRightBorderWidth(borderWidth);
}

void MyQCustomTable::setTopBorderWidth(int row, int column, int borderWidth) {
    findCellBy(row, column)->setTopBorderWidth(borderWidth);
}

void MyQCustomTable::setBottomBorderWidth(int row, int column, int borderWidth) {
    findCellBy(row, column)->setBottomBorderWidth(borderWidth);
}

void MyQCustomTable::initializeRows() {
    int top = margin;
    rows.push_back(new Row(0, margin));

    for (int i = 1; i < row; i++)
        rows.push_back(new Row(rows[i - 1]));

    this->setWidgetHeight(rows[rows.size() - 1]->getBottom());
}

void MyQCustomTable::initializeColumns() {
    columns.push_back(new Column(0, margin));


    for (int i = 1; i < column; i++)
        columns.push_back(new Column(columns[i - 1]));

    this->setWidgetWidth(columns[columns.size() - 1]->getRight());
}

void MyQCustomTable::initializeCells() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cells.push_back(new Cell(rows[i], columns[j]));
}

void MyQCustomTable::setPenWithTo(int width) {
    this->painter->setPen(QPen(Qt::black, width));
}

void MyQCustomTable::fillAllCells() {
    for (Cell *cell : cells)
        fillCell(cell);
}

void MyQCustomTable::fillCell(Cell *cell) {
    painter->fillRect(cell->getRectangle(), cell->getColor());
}

void MyQCustomTable::paintAllCells() {
    for (Cell *cell : cells)
        paintCell(cell);
}

void MyQCustomTable::paintCell(Cell *cell) {
    QPen pen(Qt::black, gridLineThickness);
    painter->setPen(pen);

    paintTopBorder(cell);
    paintLeftBorder(cell);
    paintBottomBorder(cell);
    paintRightBorder(cell);
}

void MyQCustomTable::paintLeftBorder(Cell *cell) {
    int width = cell->getLeftBorderWidth();
    if (width <= 0) return;

    int accordToTop = width / 2 - cell->getTopBorderWidth() / 2;
    int accordToBottom = -width / 2 + cell->getBottomBorderWidth() / 2;

    setPenWithTo(width);
    painter->drawLine(cell->getLeft(), cell->getTop() + accordToTop, cell->getLeft(),
                      cell->getBottom() + accordToBottom);
}

void MyQCustomTable::paintRightBorder(Cell *cell) {
    int width = cell->getRightBorderWidth();
    if (width <= 0) return;

    int accordToTop = width / 2 - cell->getTopBorderWidth() / 2;
    int accordToBottom = -width / 2 + cell->getBottomBorderWidth() / 2;

    setPenWithTo(width);
    painter->drawLine(cell->getRight(), cell->getTop() + accordToTop, cell->getRight(),
                      cell->getBottom() + accordToBottom);
}

void MyQCustomTable::paintTopBorder(Cell *cell) {
    int width = cell->getTopBorderWidth();
    if (width <= 0) return;

    int accordToleft = width / 2 - cell->getLeftBorderWidth() / 2;
    int accordToRight = -width / 2 + cell->getRightBorderWidth() / 2;

    setPenWithTo(width);
    painter->drawLine(cell->getLeft() + accordToleft, cell->getTop(), cell->getRight() + accordToRight, cell->getTop());
}

void MyQCustomTable::paintBottomBorder(Cell *cell) {
    int width = cell->getBottomBorderWidth();
    if (width <= 0) return;

    int accordToleft = width / 2 - cell->getLeftBorderWidth() / 2;
    int accordToRight = -width / 2 + cell->getRightBorderWidth() / 2;

    setPenWithTo(width);
    painter->drawLine(cell->getLeft() + accordToleft, cell->getBottom(), cell->getRight() + accordToRight,
                      cell->getBottom());
}

void MyQCustomTable::paintAllTexts() {
    for (Cell *cell : cells)
        paintText(cell);
}

void MyQCustomTable::paintText(Cell *cell) {
    painter->setFont(cell->getFont());
    painter->drawText(cell->getTextRectangle(), cell->getTextAlignment(), QString::fromStdString(cell->getText()));
}

void MyQCustomTable::paintWidgetFrame() {
    setPenWithTo(borderThickness);
    painter->drawRect(margin, margin, width() - 2 * margin, height() - 2 * margin);
}

MyQCustomTable::Cell *MyQCustomTable::findCellBy(int row, int column) {
    for (Cell *cell : cells)
        if (cell->isInRow(rows[row]) && cell->isInColumn(columns[column]))
            return cell;

    throw std::logic_error("OutOfBounds!");
}

void MyQCustomTable::removeCell(Cell *cell) {
    vector<Cell *>::iterator it = std::find(cells.begin(), cells.end(), cell);
    if (it != cells.end())
        cells.erase(it);
}

///////////////////////////////////////////////

MyQCustomTable::Column::Column(int columnNumber, int left) {
    this->columnNumber = columnNumber;
    this->left = left;
}

MyQCustomTable::Column::Column(Column *previous) {
    this->previous = previous;
    this->columnNumber = previous->getColumnNumber() + 1;
}

MyQCustomTable::Column::~Column() {

}

int MyQCustomTable::Column::getColumnNumber() {
    if (previous) return previous->columnNumber + 1;
    return this->columnNumber;
}

int MyQCustomTable::Column::getLeft() {
    if (previous) return previous->getRight();
    return this->left;
}

int MyQCustomTable::Column::getRight() {
    return getLeft() + this->width;
}

int MyQCustomTable::Column::getWidth() {
    return this->width;
}

void MyQCustomTable::Column::setWidth(int width) {
    this->width = width;
}

///////////////////////////////////////////////

MyQCustomTable::Row::Row(int rowNumber, int top) {
    this->rowNumber = rowNumber;
    this->top = top;
}

MyQCustomTable::Row::Row(Row *previous) {
    this->previous = previous;
    this->rowNumber = previous->getRowNumber() + 1;
}

MyQCustomTable::Row::~Row() {

}

int MyQCustomTable::Row::getRowNumber() {
    if (previous) return previous->getRowNumber() + 1;
    return this->rowNumber;
}

int MyQCustomTable::Row::getTop() {
    if (previous) return previous->getBottom();
    return this->top;
}

int MyQCustomTable::Row::getBottom() {
    return this->getTop() + height;
}

int MyQCustomTable::Row::getHeight() {
    return this->height;
}

void MyQCustomTable::Row::setHeight(int height) {
    this->height = height;
}

///////////////////////////////////////////////

MyQCustomTable::Cell::Cell(Row *row, Column *column) {
    this->beginRow = row;
    this->endRow = row;
    this->beginColumn = column;
    this->endColumn = column;
}

MyQCustomTable::Cell::~Cell() {}

int MyQCustomTable::Cell::getLeft() {
    return this->beginColumn->getLeft();
}

int MyQCustomTable::Cell::getRight() {
    return this->endColumn->getRight();
}

int MyQCustomTable::Cell::getTop() {
    return this->beginRow->getTop();
}

int MyQCustomTable::Cell::getBottom() {
    return this->endRow->getBottom();
}

int MyQCustomTable::Cell::getWidth() {
    return endColumn->getRight() - beginColumn->getLeft();
}

int MyQCustomTable::Cell::getHeight() {
    return endRow->getBottom() - beginRow->getTop();
}

QRect MyQCustomTable::Cell::getRectangle() {
    return QRect(getLeft(), getTop(), getWidth(), getHeight());
}

QRect MyQCustomTable::Cell::getTextRectangle() {
    return QRect(getRectangle().x() + textOffset, getRectangle().y(), getRectangle().width() - 2 * textOffset,
                 getRectangle().height());
}


QColor MyQCustomTable::Cell::getColor() {
    return this->color;
}

void MyQCustomTable::Cell::setColor(QColor color) {
    this->color = color;
}

void MyQCustomTable::Cell::setTextAlignment(Qt::Alignment alignment) {
    this->alignment = alignment;
}

Qt::Alignment MyQCustomTable::Cell::getTextAlignment() {
    return this->alignment;
}

string MyQCustomTable::Cell::getText() {
    return this->text;
}

void MyQCustomTable::Cell::setText(string text) {
    this->text = text;
}

QFont MyQCustomTable::Cell::getFont() {
    return this->font;
}

void MyQCustomTable::Cell::setFont(QFont font) {
    this->font = font;
}

void MyQCustomTable::Cell::setWholeBorderWidth(int borderWidth) {
    this->setLeftBorderWidth(borderWidth);
    this->setRightBorderWidth(borderWidth);
    this->setTopBorderWidth(borderWidth);
    this->setBottomBorderWidth(borderWidth);
}

int MyQCustomTable::Cell::getLeftBorderWidth() {
    return this->leftBoderWidth;
}

void MyQCustomTable::Cell::setLeftBorderWidth(int borderWidth) {
    this->leftBoderWidth = borderWidth;
}

int MyQCustomTable::Cell::getRightBorderWidth() {
    return this->rightBorderWidth;
}

void MyQCustomTable::Cell::setRightBorderWidth(int borderWidth) {
    this->rightBorderWidth = borderWidth;
}

int MyQCustomTable::Cell::getTopBorderWidth() {
    return this->topBoderWidth;
}

void MyQCustomTable::Cell::setTopBorderWidth(int borderWidth) {
    this->topBoderWidth = borderWidth;
}

int MyQCustomTable::Cell::getBottomBorderWidth() {
    return this->bottomBoderWidth;
}

void MyQCustomTable::Cell::setBottomBorderWidth(int borderWidth) {
    this->bottomBoderWidth = borderWidth;
}

MyQCustomTable::Row *MyQCustomTable::Cell::getBeginRow() {
    return this->beginRow;
}

void MyQCustomTable::Cell::setBeginRow(Row *row) {
    this->beginRow = row;
}

MyQCustomTable::Row *MyQCustomTable::Cell::getEndRow() {
    return this->endRow;
}

void MyQCustomTable::Cell::setEndRow(Row *row) {
    this->endRow = row;
}

MyQCustomTable::Column *MyQCustomTable::Cell::getBeginColumn() {
    return this->beginColumn;
}

void MyQCustomTable::Cell::setBeginColumn(Column *column) {
    this->beginColumn = column;
}

MyQCustomTable::Column *MyQCustomTable::Cell::getEndColumn() {
    return this->endColumn;
}

void MyQCustomTable::Cell::setEndColumn(Column *column) {
    this->endColumn = column;
}

bool MyQCustomTable::Cell::canBind(Cell *cell) {
    bool bindable = false;

    bindable = (cell->beginRow == beginRow && cell->endRow == endRow);
    bindable = bindable || (cell->beginColumn == beginColumn && cell->endColumn == endColumn);

    return bindable;
}

bool MyQCustomTable::Cell::isInRow(Row *row) {
    return (row->getRowNumber() >= this->beginRow->getRowNumber() &&
            row->getRowNumber() <= this->endRow->getRowNumber());
}

bool MyQCustomTable::Cell::isInColumn(Column *column) {
    return (column->getColumnNumber() >= this->beginColumn->getColumnNumber() &&
            column->getColumnNumber() <= this->endColumn->getColumnNumber());
}