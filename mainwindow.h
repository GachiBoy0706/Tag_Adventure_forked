#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QCursor>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton* current_button = nullptr;

signals:
    void signal_button_to_red(QPushButton* button);
    void signal_button_to_orange(QPushButton* button);
    void signal_key_up();
    void signal_key_down();
    void signal_push_button(QPushButton* button);
    void signal_open_game();
    void signal_open_settings();

private slots:
    void slot_play_button_clicked();
    void slot_settings_button_clicked();
    void slot_exit_button_clicked();

    void slot_button_to_red(QPushButton* button);
    void slot_button_to_orange(QPushButton* button);

    void slot_key_up();
    void slot_key_down();

    void slot_push_button(QPushButton* button);

    void slot_open_game();
    void slot_open_settings();
private:
    void mouseMoveEvent(QMouseEvent* ev) override;
    void mousePressEvent(QMouseEvent* ev) override;
    void keyPressEvent(QKeyEvent *ev) override;
    Ui::MainWindow *ui;
    QMainWindow win_game;
};
#endif // MAINWINDOW_H
