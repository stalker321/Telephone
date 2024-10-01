#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    display = ui->lineEdit;
    call = ui->pushButtonCALL;

    wrongNumber();
    QObject::connect(display, &QLineEdit::textChanged, [this](QString text){
        QRegularExpression mobileNumber("^\\+\\d{11}$");
        QRegularExpression homeNumber("^\\d{6}$");
        if (mobileNumber.match(text).hasMatch()) correctNumber();
        else if (homeNumber.match(text).hasMatch()) correctNumber();
        else wrongNumber();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::correctNumber()
{
    call->setStyleSheet("QPushButton {background-color: green}");
    call->setEnabled(true);
}

void MainWindow::wrongNumber()
{
    call->setStyleSheet("QPushButton {background-color: red}");
    call->setEnabled(false);
}

