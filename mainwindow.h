#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QSqlDatabase    *m_db;

private slots:
    void on_pbDisconnect_clicked();
    void on_pbConnect_clicked();
};

#endif // MAINWINDOW_H
