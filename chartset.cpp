#include "chartset.h"
#include "ui_chartset.h"

chartset::chartset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chartset)
{
    ui->setupUi(this);
    ui->spinYmax->setValue(nChartSet.getYmax());
    ui->spinYmin->setValue(nChartSet.getYmin());
    ui->spinEndSec->setValue(nChartSet.getEndSec());
    ui->spinStartSec->setValue(nChartSet.getStartSec());
    ui->ck_autoajust->setCheckState(nChartSet.getAutoStatus());
}

chartset::~chartset()
{
    delete ui;
}

void chartset::on_btnOKgroup_accepted()
{
    nChartSet.setYrange(ui->spinYmin->value(),ui->spinYmax->value());
    nChartSet.setSecRange(ui->spinStartSec->value(),ui->spinEndSec->value());
    nChartSet.autosize(ui->ck_autoajust->checkState());
    emit applied(nChartSet);
    hide();
}

void chartset::on_btnOKgroup_rejected()
{
    hide();
}
