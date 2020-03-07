#include "emma2.h"
#include "ui_emma2.h"
#include <QtDebug>


Emma2::Emma2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Emma2)
{
    ui->setupUi(this);
    timerId = startTimer(500);
    timerId2 = startTimer(700);
    iniChart();
    iniSignal_Slot();
}

Emma2::~Emma2()
{
    delete ui;
}


void Emma2::iniSignal_Slot()
{

}


void Emma2::timerEvent(QTimerEvent *e)
{
    if (e->timerId()== timerId)
    {
        qreal rand = qrand()/1000.0;
        QDateTime now(QDateTime::currentDateTime());
        Line1->setName("line1");
        Line1->append(now.toMSecsSinceEpoch(),rand);
    }
    else if (e->timerId() == timerId2)
    {
//        qreal rand = qrand()/1000.0;
//        QDateTime now(QDateTime::currentDateTime());
//        Line1->setName("line1");
//        Line1->append(now.toMSecsSinceEpoch(),rand);
    }
}

void Emma2::iniChart()
{
    chart = new QChart();
    ui->chart->setChart(chart);
    // 初始化x轴
    axis_x = new QDateTimeAxis();
    axis_x->setRange(QDateTime::currentDateTime()
                     ,QDateTime::currentDateTime().addSecs(60));
    axis_x->setFormat("mm:ss");
    axis_x->setTickCount(5);
    axis_x->setTitleText("time");
    // 初始化y轴
    axis_y = new QValueAxis();
    axis_y->setRange(0,100);
    axis_y->setTickCount(10);
    axis_y->setTitleText("value");

    // 坐标轴关联
    chart->addAxis(axis_x,Qt::AlignBottom);
    chart->addAxis(axis_y,Qt::AlignLeft);

    ui->chart->setRubberBand(QChartView::RectangleRubberBand);
    ui->chart->setRenderHint(QPainter::Antialiasing);

    Line1 = new QLineSeries();
    Line1->setName("line1");
    Line1->setVisible(true);

    chart->addSeries(Line1);
    Line1->attachAxis(axis_x);
    Line1->attachAxis(axis_y);
}


void Emma2::chartsetprocess(chartsetmodel & model)
{
    ui->statusbar->showMessage("Chart Parameter Changed",200);
    axis_x->setRange(QDateTime::currentDateTime().addSecs(model.getStartSec())
                     ,QDateTime::currentDateTime().addSecs(model.getEndSec()));
    axis_y->setRange(model.getYmin(),model.getYmax());
}
//        const auto vectorPoints = Line1->pointsVector();
//        QVector<qreal> tempvector;
//        for(const QPointF points: vectorPoints)
//        {
//            if (points.x() >= xmin.toMSecsSinceEpoch())
//            {
//                tempvector.push_back(points.y());
//            }
//        }
//        auto current_ymax = std::max_element(std::begin(tempvector),std::end(tempvector));
//        auto current_ymin = std::min_element(std::begin(tempvector),std::end(tempvector));
//
//        qDebug() << *current_ymax;
//        axis_y->setRange(*current_ymin, (*current_ymax)*1.25);
//        ui->statusbar->showMessage("btn pushed",500);

void Emma2::on_actionChart_triggered()
{
    if (nchartset == nullptr)
    {
        nchartset = new chartset;
        nchartset->setWindowTitle("Chart Setting");
        nchartset->setWindowIcon(QIcon(":/icon/Image/setting.png"));
        nchartset->show();
    }
    else
    {
        nchartset->show();
    }
    // transfer the information to this.
    connect(nchartset,&chartset::applied,this,&Emma2::chartsetprocess);
}
