#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include <metaball.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private slots:

    void update_view();

private:
    Ui::MainWindow *ui;
    QImage image;
    QTimer timer;
    std::vector<Metaball> balls;
};

#endif // MAINWINDOW_H
