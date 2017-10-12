#ifndef XYBROKENLINEWIDGET_H
#define XYBROKENLINEWIDGET_H

#include <QWidget>
#include "xycalculatethread.h"

class XYBrokenLineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit XYBrokenLineWidget(QWidget *parent = 0);
    ~XYBrokenLineWidget();
    QList<int> getAllDatas();
    void setDatas(const QList<int> &datas);

    int getExpendTimesY() const;
    void setExpendTimesY(int value);

    int getExpendTimesX() const;
    void setExpendTimesX(int value);

    int getOffsetY() const;
    void setOffsetY(int value);

public slots:
    void addData(int data);
    void updatePoints();

protected:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QList<int>  allDatas;
    QList<qreal> allPoints;
    XYCalculateThread *calculateThread;

    int expendTimesY;
    int expendTimesX;
    int offsetY;
};

#endif // XYBROKENLINEWIDGET_H
