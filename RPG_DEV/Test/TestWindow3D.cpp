#include "TestWindow3D.h"
#include "ui_TestWindow3D.h"

TestWindow3D::TestWindow3D(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestWindow3D)
    , m_loop(new QTimer(this))
    , m_FPS(new QTimer(this))
    , m_frameCounter(0)

{
    ui->setupUi(this);
    
    m_loop->setTimerType(Qt::PreciseTimer);
    m_FPS->setTimerType(Qt::PreciseTimer);

    connect(m_loop, SIGNAL(timeout()), this, SLOT(Loop()));
    m_loop->start(LOOP_DELAY);

    
    connect(m_FPS, SIGNAL(timeout()), this, SLOT(FPS()));
    m_FPS->start(FPS_TIME_SPAN);
}

TestWindow3D::~TestWindow3D()
{
    delete m_loop;
    delete m_FPS;
    delete ui;
}

////////////////// Private Slots ////////////////////////

void TestWindow3D::on_MenuButton_clicked()
{
    // empty
}

void TestWindow3D::on_F1pushButton_clicked()
{
    // Log on

    this->ui->stackedWidget->setCurrentIndex(1);
    this->ui->openGL_ViewPort->setFunctionKey(1);
}

void TestWindow3D::on_F2pushButton_clicked()
{
    // Welcome Screen/Main control menu (Character Generator)(Status)...etc
    
    this->ui->stackedWidget->setCurrentIndex(2);
    this->ui->openGL_ViewPort->setFunctionKey(2);
}

void TestWindow3D::on_F3pushButton_clicked()
{
    // MMO Development
    this->ui->stackedWidget->setCurrentIndex(0);
    this->ui->openGL_ViewPort->setFunctionKey(3);
}

void TestWindow3D::on_ExitButton_clicked()
{
    this->close();
}

void TestWindow3D::Loop()
{
    m_loop->stop();




    m_frameCounter++;
    ui->openGL_ViewPort->update();

    m_loop->start(LOOP_DELAY);
}

void TestWindow3D::FPS()
{
    m_FPS->stop();
    double l_fps = 0.0;

    l_fps = static_cast<double>(m_frameCounter) / (FPS_TIME_SPAN / MS_IN_SEC);
    this->ui->FPSlcdNumber->display(l_fps);

    m_frameCounter = 0;
    m_FPS->start(FPS_TIME_SPAN);
}