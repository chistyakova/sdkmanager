#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint | Qt::Window),
    ui(new Ui::MainWindow)
{
    qDebug() << "Constructor";
    ui->setupUi(this);

    QFile _file(":/metro.qss");
    if (_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream _in(&_file);
        setStyleSheet( _in.readAll() );
    }

    ui->stackedWidgetHosts->setCurrentIndex(0);

    QObject::connect(&m_process, SIGNAL(finished(int,QProcess::ExitStatus)),
                     this, SLOT(on_finished(int, QProcess::ExitStatus)));
    QObject::connect(&m_process, SIGNAL(readyReadStandardOutput()),
                     this, SLOT(on_readyReadStandartOutput()));

    connect(ui->pushButton_MFD, SIGNAL(clicked()), this, SLOT(on_hostChange()));
    connect(ui->pushButton_HUD, SIGNAL(clicked()), this, SLOT(on_hostChange()));

    ui->pushButtonSColor_depolyYes->setMode(ColorButton::Mode2);
    ui->pushButtonColor_depolyNo->setMode(ColorButton::Mode2);
    ui->pushButtonSColor_revertYes->setMode(ColorButton::Mode2);
    ui->pushButtonColor_revertNo->setMode(ColorButton::Mode2);

    m_model = new HostsListModel(this);
    ui->listViewHosts->setModel(m_model);
    connect(ui->listViewHosts,SIGNAL(clicked(const QModelIndex)),
            m_model, SLOT(onClickText(const QModelIndex)));

    on_hostChange();
    setWindowIcon(QIcon(":/img/icon-sdk.ico"));
    setWindowTitle("SDK manager");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonColor_openSDK_toggled(bool checked)
{
    if(checked)
    {
        runProcess("process.bat open");
    }
}

void MainWindow::on_pushButton_showInExplorer_toggled(bool checked)
{
    if(checked)
    {
        runProcess("process.bat showinexplorer");
    }
}

void MainWindow::on_pushButton_deploy_toggled(bool checked)
{
    if(checked)
    {
        ui->stackedWidgetHosts->setCurrentIndex(1);
        setLockAll(true);
    }
}

void MainWindow::on_pushButton_revertHosts_toggled(bool checked)
{
    if(checked)
    {
        ui->stackedWidgetHosts->setCurrentIndex(2);
        setLockAll(true);
    }
}

void MainWindow::on_pushButtonSColor_depolyYes_clicked()
{
    runProcess("process.bat deploy "+dllControlMode());
    ui->stackedWidgetHosts->setCurrentIndex(0);
}

void MainWindow::on_pushButtonColor_depolyNo_clicked()
{
    ui->stackedWidgetHosts->setCurrentIndex(0);
    setLockAll(false);
    setUntoggledAll();
}

void MainWindow::on_pushButtonSColor_revertYes_clicked()
{
    runProcess("process.bat reverthosts "+dllControlMode());
    ui->stackedWidgetHosts->setCurrentIndex(0);
}

void MainWindow::on_pushButtonColor_revertNo_clicked()
{
    ui->stackedWidgetHosts->setCurrentIndex(0);
    setLockAll(false);
    setUntoggledAll();
}

void MainWindow::on_toolButtonQuit_clicked()
{
    close();
}

void MainWindow::on_toolButtonMinimize_clicked()
{
    showMinimized();
}

void MainWindow::runProcess(QString const& name)
{
    setLockAll(true);
    ui->textBrowserCmd->clear();
    ui->textBrowserCmd->setStyleSheet("QTextEdit {background-color: rgb(255, 255, 255)}"); // белый
    m_process.start( QCoreApplication::applicationDirPath()+"/"+ name );
}

void MainWindow::on_finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitStatus);
    if(exitCode > 0)
    {
        ui->textBrowserCmd->setStyleSheet("QTextEdit {background-color: rgb(253, 220, 193)}"); // красный
    }
    else
    {
        ui->textBrowserCmd->setStyleSheet("QTextEdit {background-color: rgb(184, 230, 181)}"); // зеленый
    }
    setLockAll(false);
    on_hostChange();
    setUntoggledAll();
}

void MainWindow::on_readyReadStandartOutput()
{
    ui->textBrowserCmd->append(m_process.readAllStandardOutput().trimmed());
}

void MainWindow::setLockAll(bool lock)
{
    ui->pushButtonColor_openSDK->setEnabled(!lock);
    ui->pushButton_showInExplorer->setEnabled(!lock);
    ui->pushButton_deploy->setEnabled(!lock);
    ui->pushButton_revertHosts->setEnabled(!lock);

    ui->pushButton_MFD->setEnabled(!lock);
    ui->pushButton_HUD->setEnabled(!lock);
}

void MainWindow::setUntoggledAll()
{
    ui->pushButtonColor_openSDK->setChecked(false);
    ui->pushButton_showInExplorer->setChecked(false);
    ui->pushButton_deploy->setChecked(false);
    ui->pushButton_revertHosts->setChecked(false);
}

QString MainWindow::dllControlMode()
{
    QString hostString = " ";
    if(ui->pushButton_MFD->isChecked())
        hostString+="1 ";
    else
        hostString+="0 ";
    if(ui->pushButton_HUD->isChecked())
        hostString+="1";
    else
        hostString+="0";
    return hostString;
}

void MainWindow::on_hostChange()
{
    bool state = false;
    if(ui->pushButton_MFD->isChecked() ||
       ui->pushButton_HUD->isChecked())
    {
        state = true;
    }
    ui->pushButton_deploy->setEnabled(state);
    ui->pushButton_revertHosts->setEnabled(state);
}

void MainWindow::handleMessage(const QString& message)
{
    Q_UNUSED(message);
    this->showNormal();
    this->activateWindow();
    this->raise();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    m_model->onExit();
}
