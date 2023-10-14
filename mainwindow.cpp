#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtDebug>
#include <QPushButton>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->play_button->setStyleSheet("background: transparent; color: rgb(255, 178, 102)");
    ui->settings_button->setStyleSheet("background: transparent; color: rgb(255, 178, 102)");
    ui->exit_button->setStyleSheet("background: transparent; color: rgb(255, 178, 102)");
    ui->label_tag_adventure->setStyleSheet("color: rgb(255, 178, 102)");

    connect(ui->play_button, SIGNAL(clicked()), this, SLOT(slot_play_button_clicked()));
    connect(ui->settings_button, SIGNAL(clicked()), this, SLOT(slot_settings_button_clicked()));
    connect(ui->exit_button, SIGNAL(clicked()), this, SLOT(slot_exit_button_clicked()));

    connect(this, &MainWindow::signal_button_to_red, this, &MainWindow::slot_button_to_red);
    connect(this, &MainWindow::signal_button_to_orange, this, &MainWindow::slot_button_to_orange);

    setMouseTracking(true);
    centralWidget()->setMouseTracking(true);
    ui->verticalLayoutWidget->setMouseTracking(true);

    current_button = ui->play_button;

    connect(this, &MainWindow::signal_key_down, this, &MainWindow::slot_key_down);
    connect(this, &MainWindow::signal_key_up, this, &MainWindow::slot_key_up);
    slot_button_to_red(current_button);

    connect(this, &MainWindow::signal_push_button, this, &MainWindow::slot_push_button);

    connect(this, &MainWindow::signal_open_game, this, &MainWindow::slot_open_game);
    connect(this, &MainWindow::signal_open_settings, this, &MainWindow::slot_open_settings);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_play_button_clicked()
{
    qDebug() << "play button was clicked";
    emit signal_open_game();
}

void MainWindow::slot_settings_button_clicked()
{
    qDebug() << "settings button was clicked";
    emit signal_open_settings();
}

void MainWindow::slot_exit_button_clicked(){

    qDebug() << "exit button was clicked";
    qApp->exit();
}

void MainWindow::slot_button_to_red(QPushButton *button)
{
    button->setStyleSheet("background: transparent; color: rgb(255, 51, 51)");
}

void MainWindow::slot_button_to_orange(QPushButton *button)
{
    button->setStyleSheet("background: transparent; color: rgb(255, 178, 102)");
}


void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    int x = ui->play_button->pos().x() + ui->verticalLayoutWidget->pos().x();
    int y = ui->play_button->pos().y() + ui->verticalLayoutWidget->pos().y();
    int width = ui->play_button->width();
    int heigth = ui->play_button->height();
    if (x <= ev->pos().x() && x+width >= ev->pos().x() &&
        y <= ev->pos().y() && y+heigth >= ev->pos().y()){
        current_button = ui->play_button;
        emit signal_button_to_red(current_button);
    }
    else if (current_button != ui->play_button)
        emit signal_button_to_orange(ui->play_button);


    x = ui->settings_button->pos().x() + ui->verticalLayoutWidget->pos().x();
    y = ui->settings_button->pos().y() + ui->verticalLayoutWidget->pos().y();
    width = ui->play_button->width();
    heigth = ui->play_button->height();
    if (x <= ev->pos().x() && x+width >= ev->pos().x() &&
        y <= ev->pos().y() && y+heigth >= ev->pos().y()){
        current_button = ui->settings_button;
        emit signal_button_to_red(current_button);
    }
    else if (current_button != ui->settings_button)
        emit signal_button_to_orange(ui->settings_button);

    x = ui->exit_button->pos().x() + ui->verticalLayoutWidget->pos().x();
    y = ui->exit_button->pos().y() + ui->verticalLayoutWidget->pos().y();
    width = ui->exit_button->width();
    heigth = ui->exit_button->height();
    if (x <= ev->pos().x() && x+width >= ev->pos().x() &&
        y <= ev->pos().y() && y+heigth >= ev->pos().y()){
        current_button = ui->exit_button;
        emit signal_button_to_red(current_button);
    }
    else if (current_button != ui->exit_button)
        emit signal_button_to_orange(ui->exit_button);
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "mouse pressed";
    qDebug() << ev->position();
}

void MainWindow::slot_key_up()
{

    if (current_button == ui->play_button)
        current_button = ui->exit_button;
    else if (current_button == ui->settings_button)
        current_button = ui->play_button;
    else if (current_button == ui->exit_button)
        current_button = ui->settings_button;

}

void MainWindow::slot_key_down()
{

    if (current_button == ui->play_button)
        current_button = ui->settings_button;
    else if (current_button == ui->settings_button)
        current_button = ui->exit_button;
    else if (current_button == ui->exit_button)
        current_button = ui->play_button;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_E)
        emit signal_push_button(current_button);
    else{
    emit signal_button_to_orange(current_button);
    if (ev->key() == Qt::Key_W)
        emit signal_key_up();
    else if (ev->key() == Qt::Key_S)
        emit signal_key_down();
    emit signal_button_to_red(current_button);
    }
}

void MainWindow::slot_push_button(QPushButton* button){
    if (button == ui->play_button)
        slot_play_button_clicked();
    else if (button == ui->settings_button)
        slot_settings_button_clicked();
    else if (button == ui->exit_button)
        slot_exit_button_clicked();
}

void MainWindow::slot_open_game(){
    win_game.show();
    this->close();
}

void MainWindow::slot_open_settings(){
    QWidget wig_settings;

}
