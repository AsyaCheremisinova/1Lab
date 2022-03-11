#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSlider"
#include "QPushButton"
#include "QTextEdit"
#include "QGridLayout"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sld1 = new QSlider(nullptr);
    sld1->setMinimum(0);
    sld1->setMaximum(255);
    sld2 = new QSlider(nullptr);
    sld2->setMinimum(0);
    sld2->setMaximum(255);
    sld3 = new QSlider(nullptr);
    sld3->setMinimum(0);
    sld3->setMaximum(255);
    text = new QTextEdit();
    button = new QPushButton("ОК");
    text->setStyleSheet("font-size: 15pt");
    b = new QPushButton(" ");
    reset = new QPushButton("Сбросить");
    clear = new QPushButton("Очистить");



    QGridLayout* glayout = new QGridLayout();
    glayout->addWidget(clear,0,0);
    glayout->addWidget(reset,0,1,1,3);
    glayout->addWidget(text,1,0);
    glayout->addWidget(sld1,1,1);
    glayout->addWidget(sld2,1,2);
    glayout->addWidget(sld3,1,3);
    glayout->addWidget(button,2,0);
    glayout->addWidget(b,2,1,1,3);

    QWidget* wdg = new QWidget();
    wdg->setLayout(glayout);

    this->setCentralWidget(wdg);


    connect(sld1, &QSlider::valueChanged, this, &MainWindow::ColorButton);
    connect(sld2, &QSlider::valueChanged, this, &MainWindow::ColorButton);
    connect(sld3, &QSlider::valueChanged, this, &MainWindow::ColorButton);
    connect(button, &QPushButton::clicked, this, &MainWindow::ColorText);
    connect(clear, &QPushButton::clicked, this, &MainWindow::Clear);
    connect(reset, &QPushButton::clicked, this, &MainWindow::Reset);

}
void MainWindow::ColorButton()
{
    QString stl = "background-color: rgb(%1,%2,%3)";
    QString stl2 = stl.arg(sld1->value()).arg(sld2->value()).arg(sld3->value());

    b->setStyleSheet(stl2);
}

void MainWindow::ColorText()
{
    QString stl = "color: rgb(%1,%2,%3); font-size: 15pt";
    QString stl2 = stl.arg(sld1->value()).arg(sld2->value()).arg(sld3->value());

    text->setStyleSheet(stl2);
}
void MainWindow::Clear()
{
    text->clear();
}

void MainWindow::Reset()
{
    sld1->setValue(0);
    sld2->setValue(0);
    sld3->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

