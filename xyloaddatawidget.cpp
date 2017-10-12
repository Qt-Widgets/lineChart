#include "xyloaddatawidget.h"
#include "ui_xyloaddatawidget.h"
#include <QString>

XYLoadDataWidget::XYLoadDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::XYLoadDataWidget)
{
    ui->setupUi(this);
}

XYLoadDataWidget::~XYLoadDataWidget()
{
    delete ui;
}

void XYLoadDataWidget::setBrokenLineWidget(XYBrokenLineWidget *widget)
{
    brokenLineWidget = widget;
}

void XYLoadDataWidget::setText(const QString &text)
{
    ui->textEdit->setPlainText(text);
}

void XYLoadDataWidget::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    text.replace(",", "");

    QStringList dataStrings = text.split(" ", QString::SkipEmptyParts);
    QList<int> datas;
    bool ok = false;
    for (int i = 0; i < dataStrings.size(); ++i)
    {
        QString datastr = dataStrings.at(i);
        int datai  = datastr.toInt(&ok);
        if (ok)
        {
            datas.append(datai);
        }
    }

    brokenLineWidget->setDatas(datas);
}
