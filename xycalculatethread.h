#ifndef XYCALCULATETHREAD_H
#define XYCALCULATETHREAD_H

#include <QThread>

class XYCalculateThread : public QThread
{
    Q_OBJECT
public:
    explicit XYCalculateThread(QObject *parent = 0);
    void startCalculate(const QList<int> &datas);

protected:
    void run();

private:
    QList<int> datas;
    QList<qreal> retDatas;

    friend class XYBrokenLineWidget;

};

#endif // XYCALCULATETHREAD_H
