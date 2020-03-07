#include "chartsetmodel.h"

chartsetmodel::chartsetmodel(QObject *parent) : QObject(parent)
{
    //初始化
    StartSec = -60;
    EndSec = 30;
    y_min = 0;
    y_max = 50;
}

// 设置图表起始时间距离此时的秒数
void chartsetmodel::setStartSec(int sec)
{
    if (sec >= getEndSec())
    {
        emit ErrorInfo("Sec Wrong Setting");
    }
    else
    {
    StartSec = sec;
    }
}

// 设置图表结束时间距离此时的秒数
void chartsetmodel::setEndSec(int sec)
{
    if (sec >= getStartSec())
    {
        emit ErrorInfo("Sec Wrong Setting");
    }
    else
    {
    EndSec = sec;
    }
}

//设置图表的x轴开始和结尾距离此时的时间
void chartsetmodel::setSecRange(int min, int max)
{
    if (min >= max)
    {
        emit ErrorInfo(QStringLiteral("SecSet max <= min"));
    }
    else
    {
        EndSec = max;
        StartSec = min;
    }
}

//设置图表的y轴最大值
void chartsetmodel::setYmax(double val)
{
    if(val <= getYmin())
    {
        emit ErrorInfo("Y value Wrong Setting");
    }
    else
    {
    y_max = val;
    }
}

//设置图表的y轴最小值
void chartsetmodel::setYmin(double val)
{
    if(val <= getYmax())
    {
        emit ErrorInfo("Y value Wrong Setting");
    }
    else
    {
    y_min = val;
    }
}

//设置图表的y轴范围
void chartsetmodel::setYrange(double min, double max)
{
    if (min >= max)
    {
        emit ErrorInfo(QStringLiteral("Y value max <= min"));
    }
    else
    {
        y_min = min;
        y_max = max;
    }
}

// 设置自适应状态
void chartsetmodel::autosize(Qt::CheckState checked)
{
    AutoSizeStatus = checked;
}

double chartsetmodel::getYmax()
{
    return y_max;
}

double chartsetmodel::getYmin()
{
    return y_min;
}

int chartsetmodel::getStartSec()
{
    return StartSec;
}

int chartsetmodel::getEndSec()
{
    return EndSec;
}

// 返回是否自适应
Qt::CheckState chartsetmodel::getAutoStatus()
{
    return AutoSizeStatus;
}
