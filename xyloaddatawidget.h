#ifndef XYLOADDATAWIDGET_H
#define XYLOADDATAWIDGET_H

#include <QWidget>
#include "xybrokenlinewidget.h"

namespace Ui {
class XYLoadDataWidget;
}

class XYLoadDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit XYLoadDataWidget(QWidget *parent = 0);
    ~XYLoadDataWidget();
    void setBrokenLineWidget(XYBrokenLineWidget *widget);
    void setText(const QString &text);

private slots:
    void on_pushButton_clicked();

private:
    Ui::XYLoadDataWidget *ui;
    XYBrokenLineWidget *brokenLineWidget;
};

#endif // XYLOADDATAWIDGET_H
