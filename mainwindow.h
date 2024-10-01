#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QRegularExpression>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QPalette>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QLineEdit* display;
    QPushButton* call;
    ~MainWindow();

public slots:
    void add0(){display->setText(display->text() + "0");};
    void add1(){display->setText(display->text() + "1");};
    void add2(){display->setText(display->text() + "2");};
    void add3(){display->setText(display->text() + "3");};
    void add4(){display->setText(display->text() + "4");};
    void add5(){display->setText(display->text() + "5");};
    void add6(){display->setText(display->text() + "6");};
    void add7(){display->setText(display->text() + "7");};
    void add8(){display->setText(display->text() + "8");};
    void add9(){display->setText(display->text() + "9");};
    void addP(){display->setText(display->text() + "+");};
    void remove(){
        if (display->text().size() < 1) {
            return;
        } else {
            display->setText(display->text().remove(display->text().size() -1, 1));
        }
    };
    void clear(){display->setText("");};

private slots:
    void correctNumber();
    void wrongNumber();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
