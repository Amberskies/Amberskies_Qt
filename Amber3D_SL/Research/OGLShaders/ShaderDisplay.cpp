#include "ShaderDisplay.h"
#include "ui_ShaderDisplay.h"

ShaderDisplay::ShaderDisplay(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShaderDisplay),
      m_timer(new QTimer(this)),
      m_result(1.0)
{
    ui->setupUi(this);
    m_timer->setTimerType(Qt::PreciseTimer);

    connect(m_timer, SIGNAL(timeout()),
            this, SLOT(timerUpdate()));

    m_timer->start(2000);
}

ShaderDisplay::~ShaderDisplay()
{
    delete ui;
}

/* ***** Private Slots **** */

void ShaderDisplay::on_pushButton_clicked()
{
    this->close();
}

void ShaderDisplay::timerUpdate()
{
    double count = ui->displayOGL->getCount();

    m_result += (count / ELAPSED_TIME);
    m_result *= 0.5;

    ui->counter->display(m_result);


    ui->displayOGL->resetCount();
    m_timer->start(2000);
}
