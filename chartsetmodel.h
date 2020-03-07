#ifndef CHARTSETMODEL_H
#define CHARTSETMODEL_H

#include <QObject>

class chartsetmodel : public QObject
{
    Q_OBJECT
public:
    explicit chartsetmodel(QObject *parent = nullptr);
    void setStartSec(int sec);
    void setEndSec(int sec);
    void setSecRange(int min,int max);
    void setYmin(double min);
    void setYmax(double max);
    void setYrange(double min, double max);
    void autosize(Qt::CheckState checked);
    double getYmax();
    double getYmin();
    int getStartSec();
    int getEndSec();
    Qt::CheckState getAutoStatus();

private:
    int StartSec;
    int EndSec;
    double y_min;
    double y_max;
    Qt::CheckState AutoSizeStatus;

signals:
    void ErrorInfo(QString);
};

#endif // CHARTSETMODEL_H
