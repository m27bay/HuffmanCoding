/**
 * Tiltewidget.cpp : You can found here all functions implemented for
 * the Tiltewidget class.
 * Author : Mickael.
 **/

#include "Tiltewidget.hpp"
#include <QFontDatabase>
#include <QPainter>

/**
 * *Description : Constructor with parameters.
 * @param parent, the widget parent.
 * @param winSizeX, the widht.
 * @param winSizeX, the height.
 * */
TilteWidget::TilteWidget(QWidget *parent, int winSizeX, int winSizeY)
    : QWidget(parent)
{
    widgetWidth = winSizeX;
    widgetHeight = winSizeY;
}

/**
 * *Description : Draw the tilte window.
 * */
void TilteWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED((event)); // Unused parameter.

    // The the project tilte.
    QPainter painter(this);
    painter.setPen(Qt::black);
    int police = widgetHeight*15/100;
    painter.setFont(QFont("Helvetica", police));
    painter.drawText(widgetWidth/4, widgetHeight/2 - police, "Huffman");
    painter.drawText(widgetWidth/2 - widgetWidth*5/100, widgetHeight/2 + 2*police, "Coding");

    // The the autors names.
    painter.setFont(QFont("Helvetica", police/4));
    int littlePolice = police/4;
    painter.drawText(5, widgetHeight - littlePolice, "LE DENMAT Mickael");
    painter.drawText(widgetWidth - widgetWidth/4, littlePolice + 5, "GRUCHET Quentin");
}

