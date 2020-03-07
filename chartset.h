#ifndef CHARTSET_H
#define CHARTSET_H

#include <QDialog>
#include "chartsetmodel.h"


namespace Ui {
class chartset;
}

class chartset : public QDialog
{
    Q_OBJECT

public:
    explicit chartset(QWidget *parent = nullptr);
    ~chartset();


private slots:
    void on_btnOKgroup_accepted();

    void on_btnOKgroup_rejected();

private:
    Ui::chartset *ui;
    chartsetmodel nChartSet;

signals:
    void applied(chartsetmodel &);
};

#endif // CHARTSET_H
