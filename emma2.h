#ifndef EMMA2_H
#define EMMA2_H

#include <QMainWindow>
#include <QtCharts>
#include "chartsetmodel.h"
#include "chartset.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Emma2; }
QT_END_NAMESPACE

class Emma2 : public QMainWindow
{
    Q_OBJECT

public:
    Emma2(QWidget *parent = nullptr);
    ~Emma2();
    void timerEvent(QTimerEvent *e) override;
    void iniChart();
    void iniSignal_Slot();

private slots:

    void on_actionChart_triggered();
    void chartsetprocess(chartsetmodel &);


private:
    Ui::Emma2 *ui;
    int timerId;
    int timerId2;
    QDateTimeAxis *axis_x;
    QValueAxis *axis_y;
    QLineSeries *Line1;
    QChart *chart;
    chartset *nchartset = nullptr;
};
#endif // EMMA2_H
