#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <algorithm>
#include <cmath>

namespace
{
QColor getRandomColor(){
    return QColor(
                rand() % 255,
                rand() % 255,
                rand() % 255
                );
}
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    srand(time(0));

    ui->setupUi(this);
    connect(&timer, &QTimer::timeout, this, &MainWindow::update_view);
    timer.setInterval(0);
    timer.start();

    image = QImage(QSize(300,300), QImage::Format_RGB888);

    for(auto i = 0;i<10;i++){
        Metaball ball;

        ball.size = rand() % 10000 + 10000;
        ball.position =
        {
            rand() % 300,
            rand() % 300
        };
        ball.velocity =
        {
            rand() % 10 - 5,
            rand() % 10 - 5
        };

        balls.push_back(ball);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_view()
{

    for(auto i = 0;i < image.width();i++){
        for(auto j = 0;j<image.height();j++){
            float value = 0;
            for(auto& ball : balls){
                auto dx = ball.position.x() - i;
                auto dy = ball.position.y() - j;

                auto d = std::sqrt(dx * dx + dy * dy);
                value += ball.size / d;
            }
            std::size_t _val = value;

            image.setPixelColor(i,j,QColor(_val % 255, _val % 255, _val % 255));
        }
    }

    for(auto& ball : balls)
        ball.update(image.size());

    ui->view->setPixmap(QPixmap::fromImage(image));
}

