#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>

#include <vector>
#include <chrono>

#include "Metaball.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update_view();
    void set_speed(int value);

private:
    Ui::MainWindow *ui;
    QImage image;
    QTimer timer;
    std::vector<Metaball> balls;
    float speed = 1;
    float dt = 1;
};
#endif // MAINWINDOW_H
