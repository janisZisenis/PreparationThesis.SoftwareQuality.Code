#ifndef QTVIEW_MYQCUSTOMTABLE_H
#define QTVIEW_MYQCUSTOMTABLE_H

#include <QWidget>
#include <memory>
#include <vector>
#include <QPainter>
using namespace std;

class MyQCustomTable : public QWidget {
	class Row;
	class Column;
	class Cell;

public:
	MyQCustomTable(int row, int column, QWidget* parent = 0);
	virtual ~MyQCustomTable();

	virtual void paintEvent(QPaintEvent *);

	virtual void bindCells(int row1, int column1, int row2, int column2);
	virtual void resetBinding(int row, int column);

	virtual void setWidgetHeight(int height);
	virtual void setWidgetWidth(int width);
	virtual void setColumnWidth(int column, int width);
	virtual void setRowHeight(int row, int height);
	virtual void setCellAlignment(int row, int column, Qt::Alignment alignment);
	virtual void setCellColor(int row, int column, QColor color);
	virtual void setText(int row, int column, string text);
	virtual void setWholeCellBorderWidth(int row, int column, int borderWidth);
	virtual void setLeftBorderWidth(int row, int column, int borderWidth);
	virtual void setRightBorderWidth(int row, int column, int borderWidth);
	virtual void setTopBorderWidth(int row, int column, int borderWidth);
	virtual void setBottomBorderWidth(int row, int column, int borderWidth);

private:
	virtual void initializeRows();
	virtual void initializeColumns();
	virtual void initializeCells();

	void setPenWithTo(int width);
	virtual void fillAllCells();
	virtual void fillCell(Cell *cell);
	virtual void paintAllCells();
	virtual void paintCell(Cell *cell);
	virtual void paintLeftBorder(Cell *cell);
	virtual void paintRightBorder(Cell *cell);
	virtual void paintTopBorder(Cell *cell);
	virtual void paintBottomBorder(Cell *cell);
	virtual void paintAllTexts();
	virtual void paintText(Cell* cell);
	void paintWidgetFrame();



	Cell* findCellBy(int row, int column);
	virtual void removeCell(Cell* cell);

	int borderThickness = 2; // borderThickness % 2 == 0 !!!!!!
	int gridLineThickness = 1;
	int margin = borderThickness / 2;
	int row;
	int column;
	vector<Row*> rows;
	vector<Column*> columns;
	vector<Cell*> cells;
	QPainter *painter;


	class Column
	{
	public:
		Column(int columnNumber, int left);
		Column(Column* previous);
		virtual ~Column();

		virtual int getColumnNumber();

		virtual int getLeft();
		virtual int getRight();
		virtual int getWidth();
		virtual void setWidth(int width);
	private:
		Column* previous = nullptr;

		int standardWidth = 100;

		int columnNumber;
		int left;
		int right;
		int width = standardWidth;
	};

	class Row
	{
	public:
		Row(int rowNumber, int top);
		Row(Row* previous);
		virtual ~Row();

		virtual int getRowNumber();

		virtual int getTop();
		virtual int getBottom();
		virtual int getHeight();
		virtual void setHeight(int height);
	private:
		Row* previous = nullptr;

		int standardHeight = 20;

		int rowNumber;
		int top;
		int bottom;
		int height = standardHeight;
	};

	class Cell
	{
	public:
		Cell(Row *row, Column *column);
		virtual ~Cell();

		virtual int getLeft();
		virtual int getRight();
		virtual int getTop();
		virtual int getBottom();
		virtual int getWidth();
		virtual int getHeight();
		virtual QRect getRectangle();
		virtual QRect getTextRectangle();

		virtual QColor getColor();
		virtual void setColor(QColor color);

		virtual void setTextAlignment(Qt::Alignment alignment);
		virtual Qt::Alignment getTextAlignment();

		virtual string getText();
		virtual void setText(string text);

		virtual QFont getFont();
		virtual void setFont(QFont font);

		virtual void setWholeBorderWidth(int borderWidth);
		virtual int getLeftBorderWidth();
		virtual void setLeftBorderWidth(int borderWidth);
		virtual int getRightBorderWidth();
		virtual void setRightBorderWidth(int borderWidth);
		virtual int getTopBorderWidth();
		virtual void setTopBorderWidth(int borderWidth);
		virtual int getBottomBorderWidth();
		virtual void setBottomBorderWidth(int borderWidth);

		virtual Row* getBeginRow();
		virtual void setBeginRow(Row* row);
		virtual Row* getEndRow();
		virtual void setEndRow(Row* row);
		virtual Column* getBeginColumn();
		virtual void setBeginColumn(Column* column);
		virtual Column* getEndColumn();
		virtual void setEndColumn(Column* column);

		virtual bool canBind(Cell* cell);

		virtual bool isInRow(Row* row);
		virtual bool isInColumn(Column* column);
	private:

		Row *beginRow;
		Row *endRow;
		Column *beginColumn;
		Column *endColumn;

		QFont standardFont = QFont("arial", 10);
		Qt::Alignment standardAlignment = Qt::AlignLeft | Qt::AlignVCenter;
		int standartBorderWidth = 1;
		QColor standardColor = Qt::white;

		int textOffset = 10;
		string text;
		QFont font = standardFont;
		Qt::Alignment alignment = standardAlignment;
		QColor color = standardColor;
		int leftBoderWidth = standartBorderWidth;
		int rightBorderWidth = standartBorderWidth;
		int topBoderWidth = standartBorderWidth;
		int bottomBoderWidth = standartBorderWidth;
	};
};

#endif //QTVIEW_MYQCUSTOMTABLE_H