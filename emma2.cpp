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
}

Emma2::~Emma2()
{
    delete ui;
}

void Emma2::timerEvent(QTimerEvent *e)
{
    if (e->timerId()== timerId)
    {
        qreal rand = qrand()/1000.0;
        QDateTime now(QDateTime::currentDateTime());
        Line1->setName("line1");
        Line1->append(now.toMSecsSinceEpoch(),rand);
//        qDebug() << now << ":"<<rand;
    }
    else if (e->timerId() == timerId2)
    {
//        qDebug() << "bb";
    }
}

void Emma2::iniChart()
{
    chart = new QChart();
    ui->chart->setChart(chart);

    auto axis_x = new QDateTimeAxis();
    axis_x->setRange(QDateTime::currentDateTime().addSecs(-20),QDateTime::currentDateTime().addSecs(100));
    axis_x->setFormat("mm:ss");
    axis_x->setTickCount(4);
    axis_x->setTitleText("time");

    auto axis_y = new QValueAxis();
    axis_y->setRange(0,100);
    axis_y->setTickCount(10);
    axis_y->setTitleText("value");


    Line1 = new QLineSeries();
    Line1->setName("line1");


    chart->addSeries(Line1);
    chart->addAxis(axis_x,Qt::AlignBottom);
    chart->addAxis(axis_y,Qt::AlignLeft);
    Line1->attachAxis(axis_x);
    Line1->attachAxis(axis_y);
    ui->chart->setRubberBand(QChartView::RectangleRubberBand);
    ui->chart->setRenderHint(QPainter::Antialiasing);

    ui->HBar1->setValue(50);

}

void Emma2::on_btnSuit_clicked()
{
    QDateTimeAxis * axis_x = dynamic_cast<QDateTimeAxis *>(chart->axes(Qt::Horizontal,Line1).at(0));
//    qDebug() <<"max" <<axis_x->max()<<"min"<< axis_x->min();

        QDateTime xmin = QDateTime::currentDateTime().addSecs(BackSec);
        QDateTime xmax = QDateTime::currentDateTime().addSecs(FrontSec);
        axis_x->setRange(xmin, xmax);
        const auto vectorPoints = Line1->pointsVector();

        QVector<qreal> tempvector;
        for(const QPointF points: vectorPoints)
        {
            if (points.x() >= xmin.toMSecsSinceEpoch())
            {
                tempvector.push_back(points.y());
            }
        }
        auto current_ymax = std::max_element(std::begin(tempvector),std::end(tempvector));
        auto current_ymin = std::min_element(std::begin(tempvector),std::end(tempvector));
        QValueAxis * axis_y = dynamic_cast<QValueAxis*>(chart->axes(Qt::Vertical,Line1).at(0));
//        qDebug() << *current_ymax;
        axis_y->setRange(*current_ymin, (*current_ymax)*1.25);
        ui->statusbar->showMessage("btn pushed",500);

}
