#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loadDataWidget = NULL;
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addData()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(showAllDatas()));

    QScrollArea *scrollArea = new QScrollArea;
    brokenLine = new XYBrokenLineWidget(scrollArea);
    scrollArea->installEventFilter(brokenLine);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(brokenLine);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(scrollArea);
    ui->widget_2->setLayout(layout);
    resize(950, 680);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addData()
{
    bool ok = false;
    int data = ui->lineEdit->text().toDouble(&ok);
    if (ok)
    {
        brokenLine->addData(data);
    }
}

void MainWindow::showAllDatas()
{
    QList<int> datas = brokenLine->getAllDatas();
    QString text;
    for (int i = 0; i < datas.size(); ++i)
    {
        if (!text.isEmpty())
        {
            text += ", ";
        }
        text += QString::number(datas.at(i));
    }
    if (loadDataWidget == NULL)
    {
        loadDataWidget = new XYLoadDataWidget;
        loadDataWidget->setBrokenLineWidget(brokenLine);
    }
    loadDataWidget->setText(text);
    loadDataWidget->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    brokenLine->setExpendTimesY(brokenLine->getExpendTimesY() + 1);
}

void MainWindow::on_pushButton_3_clicked()
{
    brokenLine->setExpendTimesY(brokenLine->getExpendTimesY() - 1);
}

void MainWindow::on_pushButton_6_clicked()
{
    brokenLine->setExpendTimesX(brokenLine->getExpendTimesX() + 1);
}

void MainWindow::on_pushButton_5_clicked()
{
    brokenLine->setExpendTimesX(brokenLine->getExpendTimesX() - 1);
}

void MainWindow::on_pushButton_7_clicked()
{
    brokenLine->setDatas(QList<int>());
}

void MainWindow::on_pushButton_8_clicked()
{
    brokenLine->setOffsetY(brokenLine->getOffsetY() - 5);
}

void MainWindow::on_pushButton_9_clicked()
{
    brokenLine->setOffsetY(brokenLine->getOffsetY() + 5);
}
