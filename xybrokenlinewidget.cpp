#include "xybrokenlinewidget.h"
#include <QPainter>
#include <QEvent>
#include <QResizeEvent>
#include <QDebug>

XYBrokenLineWidget::XYBrokenLineWidget(QWidget *parent)
    : QWidget(parent)
{
    expendTimesY = 1;
    expendTimesX = 20;
    offsetY = 0;
    resize(600, 400);
    calculateThread = new XYCalculateThread(this);
    connect(calculateThread, SIGNAL(finished()), this, SLOT(updatePoints()));
}

XYBrokenLineWidget::~XYBrokenLineWidget()
{

}

QList<int> XYBrokenLineWidget::getAllDatas()
{
    return allDatas;
}

void XYBrokenLineWidget::setDatas(const QList<int> &datas)
{
    allDatas = datas;
    calculateThread->startCalculate(allDatas);
}

void XYBrokenLineWidget::addData(int data)
{
    allDatas.append(data);
    calculateThread->startCalculate(allDatas);
}

void XYBrokenLineWidget::updatePoints()
{
    allPoints = calculateThread->retDatas;
    update();
}

void XYBrokenLineWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QColor("#00000000"));
    painter.setBrush(QColor("white"));
    painter.drawRect(rect() - QMargins(1, 1, 1, 1));

    int curX = 10;
    int curY = height() / 3 * 2 + offsetY;

    painter.setPen(QColor("black"));
    painter.drawLine(QPoint(0, curY), QPoint(width(), curY));

    if (allPoints.size() > 0)
    {
        QPointF lastPoint(curX, (curY - allPoints.at(0) * expendTimesY));
        QPointF curPoint;
        for (int i = 0; i < allPoints.size(); ++i)
        {
            curPoint.setX(curX);
            curPoint.setY((curY - allPoints.at(i) * expendTimesY));
            painter.setPen(QColor("blue"));
            painter.drawLine(lastPoint, curPoint);
            painter.setPen(QColor("red"));
            painter.drawEllipse(curPoint, 5, 5);
            painter.setPen(QColor("black"));
            painter.drawText(curPoint + QPointF(-2, -8), QString::number(allPoints.at(i)));
            lastPoint = curPoint;
            curX += expendTimesX;
        }
        resize(qMax(allPoints.size() * 20 + 50, width()), height());
    }
}

bool XYBrokenLineWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Resize)
    {
        QResizeEvent *resizeEvent = (QResizeEvent *)event;
        int w = resizeEvent->size().width() - 2;
        this->resize(qMax(this->width(), w), resizeEvent->size().height() - 20);
    }
    return QWidget::eventFilter(watched, event);
}

int XYBrokenLineWidget::getOffsetY() const
{
    return offsetY;
}

void XYBrokenLineWidget::setOffsetY(int value)
{
    offsetY = value;
    update();
}

int XYBrokenLineWidget::getExpendTimesX() const
{
    return expendTimesX;
}

void XYBrokenLineWidget::setExpendTimesX(int value)
{
    if (value > 0)
    {
        expendTimesX = value;
        update();
    }
}

int XYBrokenLineWidget::getExpendTimesY() const
{
    return expendTimesY;
}

void XYBrokenLineWidget::setExpendTimesY(int value)
{
    if (value > 0)
    {
        expendTimesY = value;
        update();
    }
}

