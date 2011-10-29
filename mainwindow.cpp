#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ledServer->setText( "db.silihost.hu" );
    ui->ledDatabase->setText( "shh_macs" );
    ui->ledUser->setText( "shh_macs" );
    ui->ledPassword->setText( "lz9jku87" );

    ui->pbDisconnect->setEnabled( false );

    m_db = new QSqlDatabase( QSqlDatabase::addDatabase( "QMYSQL" ) );
}

MainWindow::~MainWindow()
{
    delete m_db;
    delete ui;
}

void MainWindow::on_pbConnect_clicked()
{
    m_db->setHostName( ui->ledServer->text() );
    m_db->setDatabaseName( ui->ledDatabase->text() );
    m_db->setUserName( ui->ledUser->text() );
    m_db->setPassword( ui->ledPassword->text() );

    bool ok = m_db->open();

    if( !ok )
    {
        ui->listWidget->addItem( m_db->lastError().text() );
    }

    ui->pbDisconnect->setEnabled( ok );
}

void MainWindow::on_pbDisconnect_clicked()
{
    m_db->close();
}
