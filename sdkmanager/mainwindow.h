#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

#include "hostslistmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void runProcess(QString const& name);
    void setLockAll(bool lock);
    void setUntoggledAll();
    QString dllControlMode();

public slots:
    void on_pushButtonColor_openSDK_toggled(bool checked);
    void on_pushButton_showInExplorer_toggled(bool checked);
    void on_pushButton_deploy_toggled(bool checked);
    void on_pushButton_revertHosts_toggled(bool checked);
    void on_pushButtonSColor_depolyYes_clicked();
    void on_pushButtonColor_depolyNo_clicked();
    void on_pushButtonSColor_revertYes_clicked();
    void on_pushButtonColor_revertNo_clicked();
    void on_toolButtonQuit_clicked();
    void on_toolButtonMinimize_clicked();

    void on_finished(int exitCode, QProcess::ExitStatus exitStatus);
    void on_readyReadStandartOutput();
    void on_hostChange();

    void handleMessage(const QString& message);

private:
    Ui::MainWindow *ui;
    QProcess       m_process;
    HostsListModel *m_model;
};

#endif // MAINWINDOW_H
