#include "xycalculatethread.h"

XYCalculateThread::XYCalculateThread(QObject *parent)
    : QThread(parent)
{

}

void XYCalculateThread::startCalculate(const QList<int> &datas)
{
    this->datas = datas;
    retDatas.clear();
    QThread::start();
}

void XYCalculateThread::run()
{
    int index = 0;
    while (index + 5 <= datas.size())
    {
        qreal total5 = 0;
        for (int i = index; i < datas.size() && i < index + 5; ++i)
        {
            total5 += datas.at(i);
        }
        retDatas.append(total5 / 5);
        ++index;
    }
}
