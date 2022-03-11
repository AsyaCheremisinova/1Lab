#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSlider"
#include "QPushButton"
#include "QTextEdit"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ColorButton();
    void ColorText();
    void Clear();
    void Reset();
private:
    Ui::MainWindow *ui;
    QSlider* sld1;
    QSlider* sld2;
    QSlider* sld3;
    QPushButton* button;
    QPushButton* b;
    QTextEdit* text;
    QPushButton* reset;
    QPushButton* clear;

};
#endif // MAINWINDOW_H
