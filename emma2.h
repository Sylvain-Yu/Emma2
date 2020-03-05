#ifndef EMMA2_H
#define EMMA2_H

#include <QMainWindow>
#include <QtCharts>

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

private slots:
    void on_btnSuit_clicked();

private:
    Ui::Emma2 *ui;
    int timerId;
    int timerId2;
    QLineSeries *Line1;
    QChart *chart;
    int FrontSec = 30;
    int BackSec = -120;
};
#endif // EMMA2_H
