#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(0));
    ui->setupUi(this);

    connect(&timer, &QTimer::timeout, this, &MainWindow::update_view);
    connect(ui->speedSlider, &QSlider::valueChanged, this, &MainWindow::set_speed);

    image = QImage(QSize(300, 300), QImage::Format_RGB888);
    timer.setInterval(0);
    timer.start();

    for(auto i = 0; i < 10; i++)
    {
        Metaball ball;

        ball.size = rand() % 10000 + 10000;
        ball.position = QPointF
        (
            rand() % 300,
            rand() % 300
        );
        ball.velocity = QPointF
        (
            rand() % 10 - 5,
            rand() % 10 - 5
        );

        balls.push_back(ball);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_view()
{
    auto begin = std::chrono::system_clock::now();
    for (auto x = 0; x < image.width(); x++)
    {
        for (auto y = 0; y < image.height(); y++)
        {
            float value = 0;

            for(auto& ball: balls)
            {
                auto dx = ball.position.x() - x;
                auto dy = ball.position.y() - y;
                auto dd = std::sqrt(dx * dx + dy * dy);

                value += ball.size / dd;
            }

            std::size_t val = value;
            image.setPixelColor(x, y, QColor::fromHsl(val% 128 + 128, val%128 + 128, val%64));
        }
    }

    for (auto& ball: balls)
        ball.update(image.size(), speed * dt);

    ui->label->setPixmap(QPixmap::fromImage(image));
    auto end = std::chrono::system_clock::now();
    dt = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000.0f;
}

void MainWindow::set_speed(int value)
{
    speed = value / 100.0f;
}

